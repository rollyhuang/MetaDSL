
// DslString.cs - generated by the SLK parser generator 

namespace Dsl.Parser {

class DslString {

private static string[] Nonterminal_name ={"0"

,"PROGRAM"
,"STATEMENTS"
,"STATEMENT"
,"OPERATOR_STATEMENT_0"
,"OPERATOR_STATEMENT_1"
,"OPERATOR_STATEMENT_COLON"
,"OPERATOR_STATEMENT_QUESTION_COLON"
,"OPERATOR_STATEMENT_4"
,"OPERATOR_STATEMENT_5"
,"OPERATOR_STATEMENT_6"
,"OPERATOR_STATEMENT_7"
,"OPERATOR_STATEMENT_8"
,"OPERATOR_STATEMENT_9"
,"OPERATOR_STATEMENT_10"
,"OPERATOR_STATEMENT_11"
,"OPERATOR_STATEMENT_12"
,"OPERATOR_STATEMENT_13"
,"OPERATOR_STATEMENT_14"
,"OPERATOR_STATEMENT_15"
,"OPERATOR_STATEMENT_DESC_0"
,"OPERATOR_STATEMENT_DESC_1"
,"OPERATOR_STATEMENT_DESC_2"
,"OPERATOR_STATEMENT_DESC_COLON"
,"OPERATOR_STATEMENT_DESC_QUESTION_COLON"
,"OPERATOR_STATEMENT_DESC_3"
,"OPERATOR_STATEMENT_DESC_4"
,"OPERATOR_STATEMENT_DESC_5"
,"OPERATOR_STATEMENT_DESC_6"
,"OPERATOR_STATEMENT_DESC_7"
,"OPERATOR_STATEMENT_DESC_8"
,"OPERATOR_STATEMENT_DESC_9"
,"OPERATOR_STATEMENT_DESC_10"
,"OPERATOR_STATEMENT_DESC_11"
,"OPERATOR_STATEMENT_DESC_12"
,"OPERATOR_STATEMENT_DESC_13"
,"OPERATOR_STATEMENT_DESC_14"
,"OPERATOR_STATEMENT_DESC_15"
,"FUNCTION_STATEMENT"
,"FUNCTION_STATEMENT_DESC"
,"FUNCTION_CALLS"
,"FUNCTION_EX_CALL"
,"FUNCTION_EX_CALL_SPECIAL"
,"FUNCTION_PARAMS"
,"STATIC_MEMBER_DESC"
,"MEMBER_DESC"
,"MEMBER_DESC2"
,"MEMBER_DESC3"
,"MEMBER_DESC4"
,"MEMBER_DESC5"
,"MEMBER_DESC6"
,"FUNCTION_ID"
,"SEP"
,"SEP_STATEMENT_*"
,"OP_TOKEN_0_OPERATOR_STATEMENT_0_opt"
,"OP_TOKEN_1_OPERATOR_STATEMENT_1_opt"
,"OP_TOKEN_2_OPERATOR_STATEMENT_COLON_*"
,"OP_TOKEN_COLON_OPERATOR_STATEMENT_QUESTION_COLON_*"
,"OP_TOKEN_QUESTION_OPERATOR_STATEMENT_QUESTION_COLON_OP_TOKEN_COLON_OPERATOR_STATEMENT_QUESTION_COLON_opt"
,"OP_TOKEN_3_OPERATOR_STATEMENT_4_*"
,"OP_TOKEN_4_OPERATOR_STATEMENT_5_*"
,"OP_TOKEN_5_OPERATOR_STATEMENT_6_*"
,"OP_TOKEN_6_OPERATOR_STATEMENT_7_*"
,"OP_TOKEN_7_OPERATOR_STATEMENT_8_*"
,"OP_TOKEN_8_OPERATOR_STATEMENT_9_*"
,"OP_TOKEN_9_OPERATOR_STATEMENT_10_*"
,"OP_TOKEN_10_OPERATOR_STATEMENT_11_*"
,"OP_TOKEN_11_OPERATOR_STATEMENT_12_*"
,"OP_TOKEN_12_OPERATOR_STATEMENT_13_*"
,"OP_TOKEN_13_OPERATOR_STATEMENT_14_*"
,"OP_TOKEN_14_OPERATOR_STATEMENT_15_*"
,"OP_TOKEN_15_FUNCTION_STATEMENT_*"
,"FUNCTION_EX_CALL_*"
,"FUNCTION_EX_CALL_2_*"
,"FUNCTION_PARAMS_opt"
,"FUNCTION_PARAMS_2_opt"
,"FUNCTION_PARAMS_3_opt"
,"FUNCTION_PARAMS_4_opt"
,"FUNCTION_PARAMS_5_opt"
,"FUNCTION_PARAMS_6_opt"
,"FUNCTION_PARAMS_7_opt"
,"FUNCTION_PARAMS_8_opt"
,"FUNCTION_PARAMS_9_opt"
,"FUNCTION_PARAMS_10_opt"
,"FUNCTION_PARAMS_11_opt"
,"FUNCTION_PARAMS_12_opt"
,"FUNCTION_PARAMS_13_opt"
,"FUNCTION_PARAMS_14_opt"
,"FUNCTION_PARAMS_15_opt"
,"FUNCTION_PARAMS_16_opt"
,"FUNCTION_PARAMS_17_opt"
,"FUNCTION_PARAMS_18_opt"
,"FUNCTION_PARAMS_19_opt"
,"FUNCTION_PARAMS_20_opt"
,"FUNCTION_PARAMS_21_opt"
,"FUNCTION_PARAMS_22_opt"
};

private static string[] Terminal_name ={"0"

,"OP_TOKEN_0"
,"OP_TOKEN_1"
,"OP_TOKEN_2"
,"OP_TOKEN_COLON"
,"OP_TOKEN_QUESTION"
,"OP_TOKEN_3"
,"OP_TOKEN_4"
,"OP_TOKEN_5"
,"OP_TOKEN_6"
,"OP_TOKEN_7"
,"OP_TOKEN_8"
,"OP_TOKEN_9"
,"OP_TOKEN_10"
,"OP_TOKEN_11"
,"OP_TOKEN_12"
,"OP_TOKEN_13"
,"OP_TOKEN_14"
,"OP_TOKEN_15"
,"("
,")"
,"["
,"]"
,"::"
,"."
,"QUESTION_PERIOD"
,"QUESTION_PARENTHESIS"
,"QUESTION_BRACKET"
,"QUESTION_BRACE"
,"}"
,"POINTER"
,"PERIOD_STAR"
,"QUESTION_PERIOD_STAR"
,"POINTER_STAR"
,"{"
,"SCRIPT_CONTENT"
,"BRACKET_COLON_BEGIN"
,"BRACKET_COLON_END"
,"PARENTHESIS_COLON_BEGIN"
,"PARENTHESIS_COLON_END"
,"ANGLE_BRACKET_COLON_BEGIN"
,"ANGLE_BRACKET_COLON_END"
,"BRACE_PERCENT_BEGIN"
,"BRACE_PERCENT_END"
,"BRACKET_PERCENT_BEGIN"
,"BRACKET_PERCENT_END"
,"PARENTHESIS_PERCENT_BEGIN"
,"PARENTHESIS_PERCENT_END"
,"ANGLE_BRACKET_PERCENT_BEGIN"
,"ANGLE_BRACKET_PERCENT_END"
,"IDENTIFIER"
,"STRING"
,"NUMBER"
,"DOLLAR_STRING"
,","
,";"
,"END_OF_SLK_INPUT"
};

private static string[] Action_name ={"0"

,"_action_markSeparator"
,"_action_endStatement"
,"_action_pushId"
,"_action_buildOperator"
,"_action_buildFirstTernaryOperator"
,"_action_buildSecondTernaryOperator"
,"_action_beginStatement"
,"_action_addFunction"
,"_action_setFunctionId"
,"_action_markParenthesisParam"
,"_action_buildHighOrderFunction"
,"_action_markBracketParam"
,"_action_markQuestionParenthesisParam"
,"_action_markQuestionBracketParam"
,"_action_markQuestionBraceParam"
,"_action_markStatement"
,"_action_markExternScript"
,"_action_setExternScript"
,"_action_markBracketColonParam"
,"_action_markParenthesisColonParam"
,"_action_markAngleBracketColonParam"
,"_action_markBracePercentParam"
,"_action_markBracketPercentParam"
,"_action_markParenthesisPercentParam"
,"_action_markAngleBracketPercentParam"
,"_action_markColonColonParam"
,"_action_setMemberId"
,"_action_markColonColonParenthesisParam"
,"_action_markColonColonBracketParam"
,"_action_markColonColonBraceParam"
,"_action_markPeriodParam"
,"_action_markPeriodParenthesisParam"
,"_action_markPeriodBracketParam"
,"_action_markPeriodBraceParam"
,"_action_markQuestionPeriodParam"
,"_action_markPointerParam"
,"_action_markPeriodStarParam"
,"_action_markQuestionPeriodStarParam"
,"_action_markPointerStarParam"
,"_action_pushStr"
,"_action_pushNum"
,"_action_pushDollarStr"
,"_action_pushComma"
,"_action_pushSemiColon"
};

private static string[] Production_name ={"0"

,"PROGRAM --> STATEMENTS"
,"STATEMENTS --> STATEMENT SEP_STATEMENT_*"
,"STATEMENT --> OPERATOR_STATEMENT_DESC_0 _action_endStatement"
,"OPERATOR_STATEMENT_0 --> OPERATOR_STATEMENT_DESC_0 _action_endStatement"
,"OPERATOR_STATEMENT_1 --> OPERATOR_STATEMENT_DESC_1 _action_endStatement"
,"OPERATOR_STATEMENT_COLON --> OPERATOR_STATEMENT_DESC_COLON _action_endStatement"
,"OPERATOR_STATEMENT_QUESTION_COLON --> OPERATOR_STATEMENT_DESC_QUESTION_COLON _action_endStatement"
,"OPERATOR_STATEMENT_4 --> OPERATOR_STATEMENT_DESC_4 _action_endStatement"
,"OPERATOR_STATEMENT_5 --> OPERATOR_STATEMENT_DESC_5 _action_endStatement"
,"OPERATOR_STATEMENT_6 --> OPERATOR_STATEMENT_DESC_6 _action_endStatement"
,"OPERATOR_STATEMENT_7 --> OPERATOR_STATEMENT_DESC_7 _action_endStatement"
,"OPERATOR_STATEMENT_8 --> OPERATOR_STATEMENT_DESC_8 _action_endStatement"
,"OPERATOR_STATEMENT_9 --> OPERATOR_STATEMENT_DESC_9 _action_endStatement"
,"OPERATOR_STATEMENT_10 --> OPERATOR_STATEMENT_DESC_10 _action_endStatement"
,"OPERATOR_STATEMENT_11 --> OPERATOR_STATEMENT_DESC_11 _action_endStatement"
,"OPERATOR_STATEMENT_12 --> OPERATOR_STATEMENT_DESC_12 _action_endStatement"
,"OPERATOR_STATEMENT_13 --> OPERATOR_STATEMENT_DESC_13 _action_endStatement"
,"OPERATOR_STATEMENT_14 --> OPERATOR_STATEMENT_DESC_14 _action_endStatement"
,"OPERATOR_STATEMENT_15 --> OPERATOR_STATEMENT_DESC_15 _action_endStatement"
,"OPERATOR_STATEMENT_DESC_0 --> OPERATOR_STATEMENT_DESC_1 OP_TOKEN_0_OPERATOR_STATEMENT_0_opt"
,"OPERATOR_STATEMENT_DESC_1 --> OPERATOR_STATEMENT_DESC_2 OP_TOKEN_1_OPERATOR_STATEMENT_1_opt"
,"OPERATOR_STATEMENT_DESC_2 --> OPERATOR_STATEMENT_DESC_COLON OP_TOKEN_2_OPERATOR_STATEMENT_COLON_*"
,"OPERATOR_STATEMENT_DESC_COLON --> OPERATOR_STATEMENT_DESC_QUESTION_COLON OP_TOKEN_COLON_OPERATOR_STATEMENT_QUESTION_COLON_*"
,"OPERATOR_STATEMENT_DESC_QUESTION_COLON --> OPERATOR_STATEMENT_DESC_3 OP_TOKEN_QUESTION_OPERATOR_STATEMENT_QUESTION_COLON_OP_TOKEN_COLON_OPERATOR_STATEMENT_QUESTION_COLON_opt"
,"OPERATOR_STATEMENT_DESC_3 --> OPERATOR_STATEMENT_DESC_4 OP_TOKEN_3_OPERATOR_STATEMENT_4_*"
,"OPERATOR_STATEMENT_DESC_4 --> OPERATOR_STATEMENT_DESC_5 OP_TOKEN_4_OPERATOR_STATEMENT_5_*"
,"OPERATOR_STATEMENT_DESC_5 --> OPERATOR_STATEMENT_DESC_6 OP_TOKEN_5_OPERATOR_STATEMENT_6_*"
,"OPERATOR_STATEMENT_DESC_6 --> OPERATOR_STATEMENT_DESC_7 OP_TOKEN_6_OPERATOR_STATEMENT_7_*"
,"OPERATOR_STATEMENT_DESC_7 --> OPERATOR_STATEMENT_DESC_8 OP_TOKEN_7_OPERATOR_STATEMENT_8_*"
,"OPERATOR_STATEMENT_DESC_8 --> OPERATOR_STATEMENT_DESC_9 OP_TOKEN_8_OPERATOR_STATEMENT_9_*"
,"OPERATOR_STATEMENT_DESC_9 --> OPERATOR_STATEMENT_DESC_10 OP_TOKEN_9_OPERATOR_STATEMENT_10_*"
,"OPERATOR_STATEMENT_DESC_10 --> OPERATOR_STATEMENT_DESC_11 OP_TOKEN_10_OPERATOR_STATEMENT_11_*"
,"OPERATOR_STATEMENT_DESC_11 --> OPERATOR_STATEMENT_DESC_12 OP_TOKEN_11_OPERATOR_STATEMENT_12_*"
,"OPERATOR_STATEMENT_DESC_12 --> OPERATOR_STATEMENT_DESC_13 OP_TOKEN_12_OPERATOR_STATEMENT_13_*"
,"OPERATOR_STATEMENT_DESC_13 --> OPERATOR_STATEMENT_DESC_14 OP_TOKEN_13_OPERATOR_STATEMENT_14_*"
,"OPERATOR_STATEMENT_DESC_14 --> OPERATOR_STATEMENT_DESC_15 OP_TOKEN_14_OPERATOR_STATEMENT_15_*"
,"OPERATOR_STATEMENT_DESC_15 --> FUNCTION_STATEMENT_DESC OP_TOKEN_15_FUNCTION_STATEMENT_*"
,"FUNCTION_STATEMENT --> FUNCTION_STATEMENT_DESC _action_endStatement"
,"FUNCTION_STATEMENT_DESC --> _action_beginStatement FUNCTION_CALLS"
,"FUNCTION_CALLS --> FUNCTION_EX_CALL_*"
,"FUNCTION_CALLS --> _action_addFunction FUNCTION_EX_CALL_SPECIAL FUNCTION_EX_CALL_2_*"
,"FUNCTION_EX_CALL --> FUNCTION_ID _action_setFunctionId FUNCTION_PARAMS_opt"
,"FUNCTION_EX_CALL_SPECIAL --> FUNCTION_PARAMS"
,"FUNCTION_PARAMS --> _action_markParenthesisParam ( STATEMENTS ) FUNCTION_PARAMS_2_opt"
,"FUNCTION_PARAMS --> _action_markBracketParam [ STATEMENTS ] FUNCTION_PARAMS_3_opt"
,"FUNCTION_PARAMS --> :: STATIC_MEMBER_DESC FUNCTION_PARAMS_4_opt"
,"FUNCTION_PARAMS --> . MEMBER_DESC FUNCTION_PARAMS_5_opt"
,"FUNCTION_PARAMS --> QUESTION_PERIOD MEMBER_DESC2 FUNCTION_PARAMS_6_opt"
,"FUNCTION_PARAMS --> _action_markQuestionParenthesisParam QUESTION_PARENTHESIS STATEMENTS ) FUNCTION_PARAMS_7_opt"
,"FUNCTION_PARAMS --> _action_markQuestionBracketParam QUESTION_BRACKET STATEMENTS ] FUNCTION_PARAMS_8_opt"
,"FUNCTION_PARAMS --> _action_markQuestionBraceParam QUESTION_BRACE STATEMENTS } FUNCTION_PARAMS_9_opt"
,"FUNCTION_PARAMS --> POINTER MEMBER_DESC3 FUNCTION_PARAMS_10_opt"
,"FUNCTION_PARAMS --> PERIOD_STAR MEMBER_DESC4 FUNCTION_PARAMS_11_opt"
,"FUNCTION_PARAMS --> QUESTION_PERIOD_STAR MEMBER_DESC5 FUNCTION_PARAMS_12_opt"
,"FUNCTION_PARAMS --> POINTER_STAR MEMBER_DESC6 FUNCTION_PARAMS_13_opt"
,"FUNCTION_PARAMS --> _action_markStatement { STATEMENTS } FUNCTION_PARAMS_14_opt"
,"FUNCTION_PARAMS --> _action_markExternScript SCRIPT_CONTENT _action_setExternScript FUNCTION_PARAMS_15_opt"
,"FUNCTION_PARAMS --> _action_markBracketColonParam BRACKET_COLON_BEGIN STATEMENTS BRACKET_COLON_END FUNCTION_PARAMS_16_opt"
,"FUNCTION_PARAMS --> _action_markParenthesisColonParam PARENTHESIS_COLON_BEGIN STATEMENTS PARENTHESIS_COLON_END FUNCTION_PARAMS_17_opt"
,"FUNCTION_PARAMS --> _action_markAngleBracketColonParam ANGLE_BRACKET_COLON_BEGIN STATEMENTS ANGLE_BRACKET_COLON_END FUNCTION_PARAMS_18_opt"
,"FUNCTION_PARAMS --> _action_markBracePercentParam BRACE_PERCENT_BEGIN STATEMENTS BRACE_PERCENT_END FUNCTION_PARAMS_19_opt"
,"FUNCTION_PARAMS --> _action_markBracketPercentParam BRACKET_PERCENT_BEGIN STATEMENTS BRACKET_PERCENT_END FUNCTION_PARAMS_20_opt"
,"FUNCTION_PARAMS --> _action_markParenthesisPercentParam PARENTHESIS_PERCENT_BEGIN STATEMENTS PARENTHESIS_PERCENT_END FUNCTION_PARAMS_21_opt"
,"FUNCTION_PARAMS --> _action_markAngleBracketPercentParam ANGLE_BRACKET_PERCENT_BEGIN STATEMENTS ANGLE_BRACKET_PERCENT_END FUNCTION_PARAMS_22_opt"
,"STATIC_MEMBER_DESC --> _action_markColonColonParam _action_beginStatement _action_addFunction FUNCTION_ID _action_setMemberId _action_endStatement"
,"STATIC_MEMBER_DESC --> _action_markColonColonParenthesisParam ( STATEMENTS )"
,"STATIC_MEMBER_DESC --> _action_markColonColonBracketParam [ STATEMENTS ]"
,"STATIC_MEMBER_DESC --> _action_markColonColonBraceParam { STATEMENTS }"
,"MEMBER_DESC --> _action_markPeriodParam _action_beginStatement _action_addFunction FUNCTION_ID _action_setMemberId _action_endStatement"
,"MEMBER_DESC --> _action_markPeriodParenthesisParam ( STATEMENTS )"
,"MEMBER_DESC --> _action_markPeriodBracketParam [ STATEMENTS ]"
,"MEMBER_DESC --> _action_markPeriodBraceParam { STATEMENTS }"
,"MEMBER_DESC2 --> _action_markQuestionPeriodParam _action_beginStatement _action_addFunction FUNCTION_ID _action_setMemberId _action_endStatement"
,"MEMBER_DESC3 --> _action_markPointerParam _action_beginStatement _action_addFunction FUNCTION_ID _action_setMemberId _action_endStatement"
,"MEMBER_DESC4 --> _action_markPeriodStarParam _action_beginStatement _action_addFunction FUNCTION_ID _action_setMemberId _action_endStatement"
,"MEMBER_DESC5 --> _action_markQuestionPeriodStarParam _action_beginStatement _action_addFunction FUNCTION_ID _action_setMemberId _action_endStatement"
,"MEMBER_DESC6 --> _action_markPointerStarParam _action_beginStatement _action_addFunction FUNCTION_ID _action_setMemberId _action_endStatement"
,"FUNCTION_ID --> IDENTIFIER _action_pushId"
,"FUNCTION_ID --> STRING _action_pushStr"
,"FUNCTION_ID --> NUMBER _action_pushNum"
,"FUNCTION_ID --> DOLLAR_STRING _action_pushDollarStr"
,"SEP --> , _action_pushComma"
,"SEP --> ; _action_pushSemiColon"
,"SEP_STATEMENT_* --> SEP _action_markSeparator STATEMENT SEP_STATEMENT_*"
,"SEP_STATEMENT_* -->"
,"OP_TOKEN_0_OPERATOR_STATEMENT_0_opt --> OP_TOKEN_0 _action_pushId _action_buildOperator OPERATOR_STATEMENT_0"
,"OP_TOKEN_0_OPERATOR_STATEMENT_0_opt -->"
,"OP_TOKEN_1_OPERATOR_STATEMENT_1_opt --> OP_TOKEN_1 _action_pushId _action_buildOperator OPERATOR_STATEMENT_1"
,"OP_TOKEN_1_OPERATOR_STATEMENT_1_opt -->"
,"OP_TOKEN_2_OPERATOR_STATEMENT_COLON_* --> OP_TOKEN_2 _action_pushId _action_buildOperator OPERATOR_STATEMENT_COLON OP_TOKEN_2_OPERATOR_STATEMENT_COLON_*"
,"OP_TOKEN_2_OPERATOR_STATEMENT_COLON_* -->"
,"OP_TOKEN_COLON_OPERATOR_STATEMENT_QUESTION_COLON_* --> OP_TOKEN_COLON _action_pushId _action_buildOperator OPERATOR_STATEMENT_QUESTION_COLON OP_TOKEN_COLON_OPERATOR_STATEMENT_QUESTION_COLON_*"
,"OP_TOKEN_COLON_OPERATOR_STATEMENT_QUESTION_COLON_* -->"
,"OP_TOKEN_QUESTION_OPERATOR_STATEMENT_QUESTION_COLON_OP_TOKEN_COLON_OPERATOR_STATEMENT_QUESTION_COLON_opt --> OP_TOKEN_QUESTION _action_pushId _action_buildFirstTernaryOperator OPERATOR_STATEMENT_QUESTION_COLON OP_TOKEN_COLON _action_pushId _action_buildSecondTernaryOperator OPERATOR_STATEMENT_QUESTION_COLON"
,"OP_TOKEN_QUESTION_OPERATOR_STATEMENT_QUESTION_COLON_OP_TOKEN_COLON_OPERATOR_STATEMENT_QUESTION_COLON_opt -->"
,"OP_TOKEN_3_OPERATOR_STATEMENT_4_* --> OP_TOKEN_3 _action_pushId _action_buildOperator OPERATOR_STATEMENT_4 OP_TOKEN_3_OPERATOR_STATEMENT_4_*"
,"OP_TOKEN_3_OPERATOR_STATEMENT_4_* -->"
,"OP_TOKEN_4_OPERATOR_STATEMENT_5_* --> OP_TOKEN_4 _action_pushId _action_buildOperator OPERATOR_STATEMENT_5 OP_TOKEN_4_OPERATOR_STATEMENT_5_*"
,"OP_TOKEN_4_OPERATOR_STATEMENT_5_* -->"
,"OP_TOKEN_5_OPERATOR_STATEMENT_6_* --> OP_TOKEN_5 _action_pushId _action_buildOperator OPERATOR_STATEMENT_6 OP_TOKEN_5_OPERATOR_STATEMENT_6_*"
,"OP_TOKEN_5_OPERATOR_STATEMENT_6_* -->"
,"OP_TOKEN_6_OPERATOR_STATEMENT_7_* --> OP_TOKEN_6 _action_pushId _action_buildOperator OPERATOR_STATEMENT_7 OP_TOKEN_6_OPERATOR_STATEMENT_7_*"
,"OP_TOKEN_6_OPERATOR_STATEMENT_7_* -->"
,"OP_TOKEN_7_OPERATOR_STATEMENT_8_* --> OP_TOKEN_7 _action_pushId _action_buildOperator OPERATOR_STATEMENT_8 OP_TOKEN_7_OPERATOR_STATEMENT_8_*"
,"OP_TOKEN_7_OPERATOR_STATEMENT_8_* -->"
,"OP_TOKEN_8_OPERATOR_STATEMENT_9_* --> OP_TOKEN_8 _action_pushId _action_buildOperator OPERATOR_STATEMENT_9 OP_TOKEN_8_OPERATOR_STATEMENT_9_*"
,"OP_TOKEN_8_OPERATOR_STATEMENT_9_* -->"
,"OP_TOKEN_9_OPERATOR_STATEMENT_10_* --> OP_TOKEN_9 _action_pushId _action_buildOperator OPERATOR_STATEMENT_10 OP_TOKEN_9_OPERATOR_STATEMENT_10_*"
,"OP_TOKEN_9_OPERATOR_STATEMENT_10_* -->"
,"OP_TOKEN_10_OPERATOR_STATEMENT_11_* --> OP_TOKEN_10 _action_pushId _action_buildOperator OPERATOR_STATEMENT_11 OP_TOKEN_10_OPERATOR_STATEMENT_11_*"
,"OP_TOKEN_10_OPERATOR_STATEMENT_11_* -->"
,"OP_TOKEN_11_OPERATOR_STATEMENT_12_* --> OP_TOKEN_11 _action_pushId _action_buildOperator OPERATOR_STATEMENT_12 OP_TOKEN_11_OPERATOR_STATEMENT_12_*"
,"OP_TOKEN_11_OPERATOR_STATEMENT_12_* -->"
,"OP_TOKEN_12_OPERATOR_STATEMENT_13_* --> OP_TOKEN_12 _action_pushId _action_buildOperator OPERATOR_STATEMENT_13 OP_TOKEN_12_OPERATOR_STATEMENT_13_*"
,"OP_TOKEN_12_OPERATOR_STATEMENT_13_* -->"
,"OP_TOKEN_13_OPERATOR_STATEMENT_14_* --> OP_TOKEN_13 _action_pushId _action_buildOperator OPERATOR_STATEMENT_14 OP_TOKEN_13_OPERATOR_STATEMENT_14_*"
,"OP_TOKEN_13_OPERATOR_STATEMENT_14_* -->"
,"OP_TOKEN_14_OPERATOR_STATEMENT_15_* --> OP_TOKEN_14 _action_pushId _action_buildOperator OPERATOR_STATEMENT_15 OP_TOKEN_14_OPERATOR_STATEMENT_15_*"
,"OP_TOKEN_14_OPERATOR_STATEMENT_15_* -->"
,"OP_TOKEN_15_FUNCTION_STATEMENT_* --> OP_TOKEN_15 _action_pushId _action_buildOperator FUNCTION_STATEMENT OP_TOKEN_15_FUNCTION_STATEMENT_*"
,"OP_TOKEN_15_FUNCTION_STATEMENT_* -->"
,"FUNCTION_EX_CALL_* --> _action_addFunction FUNCTION_EX_CALL FUNCTION_EX_CALL_*"
,"FUNCTION_EX_CALL_* -->"
,"FUNCTION_EX_CALL_2_* --> _action_addFunction FUNCTION_EX_CALL FUNCTION_EX_CALL_2_*"
,"FUNCTION_EX_CALL_2_* -->"
,"FUNCTION_PARAMS_opt --> FUNCTION_PARAMS"
,"FUNCTION_PARAMS_opt -->"
,"FUNCTION_PARAMS_2_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_2_opt -->"
,"FUNCTION_PARAMS_3_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_3_opt -->"
,"FUNCTION_PARAMS_4_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_4_opt -->"
,"FUNCTION_PARAMS_5_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_5_opt -->"
,"FUNCTION_PARAMS_6_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_6_opt -->"
,"FUNCTION_PARAMS_7_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_7_opt -->"
,"FUNCTION_PARAMS_8_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_8_opt -->"
,"FUNCTION_PARAMS_9_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_9_opt -->"
,"FUNCTION_PARAMS_10_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_10_opt -->"
,"FUNCTION_PARAMS_11_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_11_opt -->"
,"FUNCTION_PARAMS_12_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_12_opt -->"
,"FUNCTION_PARAMS_13_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_13_opt -->"
,"FUNCTION_PARAMS_14_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_14_opt -->"
,"FUNCTION_PARAMS_15_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_15_opt -->"
,"FUNCTION_PARAMS_16_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_16_opt -->"
,"FUNCTION_PARAMS_17_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_17_opt -->"
,"FUNCTION_PARAMS_18_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_18_opt -->"
,"FUNCTION_PARAMS_19_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_19_opt -->"
,"FUNCTION_PARAMS_20_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_20_opt -->"
,"FUNCTION_PARAMS_21_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_21_opt -->"
,"FUNCTION_PARAMS_22_opt --> _action_buildHighOrderFunction FUNCTION_PARAMS"
,"FUNCTION_PARAMS_22_opt -->"
};

private const short   START_SYMBOL = 57;
private const short   START_ACTION = 152;
private const short   END_ACTION = 196;

public static string  GetSymbolName ( short symbol )
{
  if ( symbol >= START_ACTION && symbol < END_ACTION ) {
      return ( Action_name [symbol - (START_ACTION-1)] );
  } else if ( symbol >= START_SYMBOL ) {
      return ( Nonterminal_name [symbol - (START_SYMBOL-1)] );
  } else if ( symbol > 0 ) {
      return ( Terminal_name [ symbol ] );
  }
  return ( "not a symbol" );
}

public static string  GetProductionName ( short production_number )
{
  return ( Production_name [production_number] );
}


};


}
