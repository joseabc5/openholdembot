#ifndef INC_CODESNIPPETS_H
#define INC_CODESNIPPETS_H

static const char *k_code_snippet_license =
	"//************************************************************************\n"
	"//                                                                        \n"
	"// Converted with OpenPPL 1.0                                             \n"
	"//                                                                        \n"
	"// OpenPPL is part of the OpenHoldem project                              \n"
	"//   Download page:         http://code.google.com/p/openholdembot/       \n"
	"//   Forums:                http://www.maxinmontreal.com/forums/index.php \n"
	"//   Licensed under GPL v3: http://www.gnu.org/licenses/gpl.html          \n"
	"//                                                                        \n" 
	"// The original PPL (Poker Programming Language) got invented by          \n"
	"//   Shanky Bonusbost:      http://www.bonusbots.com/supportforum/YaBB.pl \n"
	"//                                                                        \n"
	"//************************************************************************\n\n\n";

static const char *k_code_snippet_options =
	"//***********************************************************\n"
	"//                                                           \n"
	"//  Option settings                                          \n"
	"//  ===============                                          \n"
	"//                                                           \n"
	"//  To be ignored,                                           \n"
	"//  as nearly all of them are for the built-in default bot,  \n"
	"//  which is not supported.                                  \n"
	"//                                                           \n"
	"//***********************************************************\n\n\n";

static const char *k_code_snippet_predefined_constants =
	"//***********************************************************\n"
	"//                                                           \n"
	"//  Predefined action constants                              \n"
	"//  ===========================                              \n"
	"//                                                           \n"
	"//  Positive values mean: betsizes (in big-blinds)           \n"
	"//                                                           \n"
	"//  Negative values mean: predefined actions,                \n"
	"//  that have to be translated later to standard             \n"
	"//  OpenHoldem autoplayer actions.                           \n"
	"//                                                           \n"
	"//  Note: Beep is not supported.                             \n"
	"//                                                           \n"
	"//***********************************************************\n"
	"\n"
	"\n"
	"##f$Action_Call##\n"
	"  -1\n"
	"\n"
	"##f$Action_Play##\n"
	"  f$Action_Call\n"
	"\n"
	"##f$Action_Raise##\n"
	"  -2\n"
	"\n"
	"##f$Action_RaiseMin##\n"
	"  f$Action_Raise\n"
	"\n"
	"##f$Action_RaiseHalfPot##\n"
	"  [1/2 * pot]n"
	"\n"
	"##f$Action_RaisePot##\n"
	"  pot\n"
	"\n"
	"##f$Action_RaiseMax##\n"
	"  -3\n"
	"\n"
	"##f$Action_Fold##\n"
	"  -4\n"
	"\n"
	"##f$Action_Bet##\n"
	"  f$Action_Raise\n"
	"\n"
	"##f$Action_BetMin##\n"
	"  f$Action_Bet\n"
	"\n"
	"##f$Action_BetHalfPot##\n"
	"  f$Action_RaiseHalfPot\n"
	"\n"
	"##f$Action_BetPot##\n"
	"  f$Action_RaiseHalfPot\n"
	"\n"
	"##f$Action_Betmax##\n"
	"  f$Action_RaiseMax\n"
	"\n"
	"##f$Action_SitOut##\n"
	"  -5\n"
	"\n"
	"\n";

static const char *k_code_snippet_technical_functions =
	"//***********************************************************\n"
	"//                                                           \n"
	"//  Technical functions                                      \n"
	"//  ===================                                      \n"
	"//                                                           \n"
	"//  Functions needed for integration into OpenHoldem.        \n"
	"//                                                           \n"
	"//***********************************************************\n"
	"\n"
	"\n"
	"##f$Decision##\n"
	"  [betround == 1] ? f$preflop :\n"
	"  [betround == 2] ? f$flop :\n"
	"  [betround == 3] ? f$turn :\n"
	"  [betround == 4] ? f$river :\n"
	"  // This should not happen\n"
	"  f$Action_Fold\n"
	"\n"
	"##f$RememberToSitoutIfNecessary\n##"
	"// OpenHoldem handles autoplayer actions when it is heros turn,\n"
	"// but f$sitin, f$sitout and f$leave once every N heartbeats,\n"
	"// contrary to OpenPPL were both can happen only at heros turn.\n" 
	"// Therefore we have to remember a decision to SitOut somehow\n"
	"// and recall it later.\n"
	"  [f$Decision == f$Action_SitOut] ? me_st_GoBuddyTakeABreakAndABeer_1 : 0]\n"
	"\n"
	"##f$alli##\n"
	"  [f$RememberToSitoutIfNecessary * 0]\n"
	"  + [(f$Decision == f$Action_RaiseMsx)\n"
	"    || (f$Decision > balance)]\n"
	"\n"
	"##f$betsize##\n"
	"  f$alli ? [balance + currrentbet] :\n"
	"  [f$Decision > 0] ? f$Decision:\n"
	"  0\n"
	"\n"
	"##f$rais##\n"
	"  [f$betsize > 0]\n"
	"  || [f$Decision == f$Action_Raise]\n"
	"\n"
	"##f$call##\n"
	"  f$rais\n"
	"  || [f$Decision == f$Action_Check]\n"
	"  || [f$Decision == f$Action_Call]\n"
	"  || [f$AmountToCall == 0]\n"
	"\n"
	"##f$sitout##\n"
	"  me_re_GoBuddyTakeABreakAndABeer\n"
	"\n";

#endif INC_CODESNIPPETS_H