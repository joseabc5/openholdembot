//
// nhands 
//

BEGIN_TESTCASE
    TESTCASE_ID ("0136")
    HEURISTIC_RULE (false)
    REASONING ("Range check for symbol nhands")
    PRECONDITION (true)
    POSTCONDITION ((gws("nhands") >= 0) && (gws("nhands") <= 2652))
    SYMBOLS_POSSIBLY_AFFECTED ("nhands")
END_TESTCASE


BEGIN_TESTCASE
    TESTCASE_ID ("0137")
    HEURISTIC_RULE (false)
    REASONING ("Range check for symbol nhandshi")
    PRECONDITION (true)
    POSTCONDITION ((gws("nhandshi") >= 0) && (gws("nhandshi") <= 2652))
    SYMBOLS_POSSIBLY_AFFECTED ("nhandshi")
END_TESTCASE


BEGIN_TESTCASE
    TESTCASE_ID ("0138")
    HEURISTIC_RULE (false)
    REASONING ("Range check for symbol nhandslo")
    PRECONDITION (true)
    POSTCONDITION ((gws("nhandslo") >= 0) && (gws("nhandslo") <= 2652))
    SYMBOLS_POSSIBLY_AFFECTED ("nhandslo")
END_TESTCASE


BEGIN_TESTCASE
    TESTCASE_ID ("0139")
    HEURISTIC_RULE (false)
    REASONING ("Range check for symbol nhandsti")
    PRECONDITION (true)
    POSTCONDITION ((gws("nhandsti") >= 0) && (gws("nhandsti") <= 2652))
    SYMBOLS_POSSIBLY_AFFECTED ("nhandsti")
END_TESTCASE