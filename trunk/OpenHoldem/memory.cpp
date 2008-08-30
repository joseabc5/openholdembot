#include "stdafx.h"

#include "memory.h"
#include "CSymbols.h"
#include "CGlobal.h"

#include "grammar.h"

Memory		memory;

Memory::Memory()
{
    __SEH_SET_EXCEPTION_HANDLER

    __SEH_HEADER

    int			i;

    var_count=-1;

    for (i=0; i<512; i++)
    {
        strcpy_s(var_name[i], 64, "");
        var_value[i]=0.0;
    }

    __SEH_LOGFATAL("Memory::constructor\n");
}


double Memory::process_query(const char * pquery, CEvalInfoFunction **logCallingFunction, int *e)
{
    __SEH_HEADER

    if (memcmp(pquery,"me_st_", 6)==0)
    {
        *e = SUCCESS;
        store_value(pquery, logCallingFunction, e);
        return 0.0;
    }

    if (memcmp(pquery,"me_re_", 6)==0)
    {
        *e = SUCCESS;
        return retrieve_value(pquery, e);
    }

    *e = ERR_INVALID_SYM;
    return 0.0;

    __SEH_LOGFATAL("Memory::process_query > %s\n", pquery);
}


void Memory::store_value(const char * pquery, CEvalInfoFunction **logCallingFunction, int *e)
{
    __SEH_HEADER
    int			i, index=0;
    char		var[512], value[512];
    double		result;

    strcpy_s(var, 512, &pquery[6]);

    if (strstr(var, "_")!=NULL)
        var[strstr(var, "_")-var]='\0';

    strcpy_s(value, 512, &pquery[6+strlen(var)+1]);

    // see if we already have this variable name
    index=var_count+1;
    for (i=0; i<=var_count; i++)
    {
        if (strlen(var)==strlen(var_name[i]) && memcmp(var, var_name[i], strlen(var))==0)
        {
            index=i;
        }
    }

    // if we didn't find the var, put it in a new slot
    if (index==var_count+1)
        var_count++;

    //store the value
    if (memcmp(value,"f$",2)==0)
    {
        *e = SUCCESS;
        result = do_calc_f$symbol(&p_global->formula, value, logCallingFunction, logCallingFunction!=NULL, e);

        if (*e==SUCCESS)
        {
            var_value[index] = result;
            strcpy_s(var_name[index], 64, var);
        }
        else
        {
            *e = ERR_INVALID_EXPR;
        }

    }

    else
    {
        if (strstr(value, "_")!=NULL)
            value[strstr(value, "_")-value]='.';

        var_value[index] = atof(value);

        strcpy_s(var_name[index], 64, var);
    }

    __SEH_LOGFATAL("Memory::store_value > %s\n", pquery);
}

double Memory::retrieve_value(const char * pquery, int *e)
{
    __SEH_HEADER

    int			i;
    char		var[512];

    strcpy_s(var, 512, &pquery[6]);

    for (i=0; i<=var_count; i++)
    {
        if (strlen(var)==strlen(var_name[i]) && memcmp(var, var_name[i], strlen(var))==0)
        {
            return var_value[i];
        }
    }

    *e = ERR_INVALID_EXPR;
    return 0.0;

    __SEH_LOGFATAL("Memory::retrieve_value > %s\n", pquery);
}
