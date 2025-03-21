﻿#include <sstream>
#include <algorithm>
#include "SourceCodeScript.h"
#include "SlkInc.h"
#include "SlkParse.h"
#include "ByteCode.h"

#define MAX_ACTION_NUM	45

//--------------------------------------------------------------------------------------
class ActionForSourceCodeScript : public SlkAction, public RuntimeBuilderT<ActionForSourceCodeScript>
{
    using BaseType = RuntimeBuilderT<ActionForSourceCodeScript>;
public:
    inline char* getLastToken() const;
    inline int getLastLineNumber() const;
    inline int getCommentNum(int& commentOnNewLine) const;
    inline char* getComment(int index) const;
    inline void resetComments();
    inline void setCanFinish(int val);
    inline void setStringDelimiter(const char* begin, const char* end);
    inline void setScriptDelimiter(const char* begin, const char* end);
public:
    ActionForSourceCodeScript(SlkToken& scanner, DslParser::DslFile& dataFile);
public:
    inline void    pushId();
    inline void    pushStr();
    inline void    pushNum();
    inline void    pushDollarStr();
    inline void    pushComma();
    inline void    pushSemiColon();
    void    (ActionForSourceCodeScript::* Action[MAX_ACTION_NUM]) ();
    inline void    initialize_table();
    inline void 	 execute(int  number) { (this->*Action[number]) (); }
private:
    SlkToken* mScanner;
};
//--------------------------------------------------------------------------------------
inline char* ActionForSourceCodeScript::getLastToken() const
{
    if (nullptr != mScanner) {
        return mScanner->getLastToken();
    }
    else {
        return nullptr;
    }
}
inline int ActionForSourceCodeScript::getLastLineNumber() const
{
    if (nullptr != mScanner) {
        return mScanner->getLastLineNumber();
    }
    else {
        return -1;
    }
}
inline int ActionForSourceCodeScript::getCommentNum(int& commentOnNewLine) const
{
    if (nullptr != mScanner) {
        return mScanner->getCommentNum(commentOnNewLine);
    }
    else {
        commentOnNewLine = FALSE;
        return 0;
    }
}
inline char* ActionForSourceCodeScript::getComment(int index) const
{
    if (nullptr != mScanner) {
        return mScanner->getComment(index);
    }
    else {
        return nullptr;
    }
}
inline void ActionForSourceCodeScript::resetComments()
{
    if (nullptr != mScanner) {
        mScanner->resetComments();
    }
}
inline void ActionForSourceCodeScript::setCanFinish(int val)
{
    if (nullptr != mScanner) {
        mScanner->setCanFinish(val);
    }
}
inline void ActionForSourceCodeScript::setStringDelimiter(const char* begin, const char* end)
{
    if (nullptr != mScanner) {
        mScanner->setStringDelimiter(begin, end);
    }
}
inline void ActionForSourceCodeScript::setScriptDelimiter(const char* begin, const char* end)
{
    if (nullptr != mScanner) {
        mScanner->setScriptDelimiter(begin, end);
    }
}
//--------------------------------------------------------------------------------------
//标识符
inline void ActionForSourceCodeScript::pushId()
{
    char* lastToken = getLastToken();
    if (nullptr != lastToken) {
        mData.push(RuntimeBuilderData::TokenInfo(lastToken, RuntimeBuilderData::ID_TOKEN));
    }
}
inline void ActionForSourceCodeScript::pushNum()
{
    char* lastToken = getLastToken();
    if (nullptr != lastToken) {
        mData.push(RuntimeBuilderData::TokenInfo(lastToken, RuntimeBuilderData::NUM_TOKEN));
    }
}
inline void ActionForSourceCodeScript::pushStr()
{
    char* lastToken = getLastToken();
    if (nullptr != lastToken) {
        mData.push(RuntimeBuilderData::TokenInfo(lastToken, RuntimeBuilderData::STRING_TOKEN));
    }
}
inline void ActionForSourceCodeScript::pushDollarStr()
{
    char* lastToken = getLastToken();
    if (nullptr != lastToken) {
        mData.push(RuntimeBuilderData::TokenInfo(lastToken, RuntimeBuilderData::DOLLAR_STRING_TOKEN));
    }
}
inline void ActionForSourceCodeScript::pushComma()
{
    mData.push(RuntimeBuilderData::TokenInfo(",", RuntimeBuilderData::STRING_TOKEN));
}
inline void ActionForSourceCodeScript::pushSemiColon()
{
    mData.push(RuntimeBuilderData::TokenInfo(";", RuntimeBuilderData::STRING_TOKEN));
}
//--------------------------------------------------------------------------------------
inline ActionForSourceCodeScript::ActionForSourceCodeScript(SlkToken& scanner, DslParser::DslFile& dataFile) :mScanner(&scanner), BaseType(dataFile)
{
    mApi.SetImpl(this);
    scanner.SetDslActionApi(mApi);
    initialize_table();
    setEnvironmentObjRef(*this);
}
//--------------------------------------------------------------------------------------
inline void ActionForSourceCodeScript::initialize_table()
{
    Action[0] = 0;
    Action[1] = &ActionForSourceCodeScript::markSeparator;
    Action[2] = &ActionForSourceCodeScript::endStatement;
    Action[3] = &ActionForSourceCodeScript::pushId;
    Action[4] = &ActionForSourceCodeScript::buildOperator;
    Action[5] = &ActionForSourceCodeScript::buildFirstTernaryOperator;
    Action[6] = &ActionForSourceCodeScript::buildSecondTernaryOperator;
    Action[7] = &ActionForSourceCodeScript::beginStatement;
    Action[8] = &ActionForSourceCodeScript::addFunction;
    Action[9] = &ActionForSourceCodeScript::setFunctionId;
    Action[10] = &ActionForSourceCodeScript::markParenthesisParam;
    Action[11] = &ActionForSourceCodeScript::buildHighOrderFunction;
    Action[12] = &ActionForSourceCodeScript::markBracketParam;
    Action[13] = &ActionForSourceCodeScript::markQuestionParenthesisParam;
    Action[14] = &ActionForSourceCodeScript::markQuestionBracketParam;
    Action[15] = &ActionForSourceCodeScript::markQuestionBraceParam;
    Action[16] = &ActionForSourceCodeScript::markStatement;
    Action[17] = &ActionForSourceCodeScript::markExternScript;
    Action[18] = &ActionForSourceCodeScript::setExternScript;
    Action[19] = &ActionForSourceCodeScript::markBracketColonParam;
    Action[20] = &ActionForSourceCodeScript::markParenthesisColonParam;
    Action[21] = &ActionForSourceCodeScript::markAngleBracketColonParam;
    Action[22] = &ActionForSourceCodeScript::markBracePercentParam;
    Action[23] = &ActionForSourceCodeScript::markBracketPercentParam;
    Action[24] = &ActionForSourceCodeScript::markParenthesisPercentParam;
    Action[25] = &ActionForSourceCodeScript::markAngleBracketPercentParam;
    Action[26] = &ActionForSourceCodeScript::markColonColonParam;
    Action[27] = &ActionForSourceCodeScript::setMemberId;
    Action[28] = &ActionForSourceCodeScript::markColonColonParenthesisParam;
    Action[29] = &ActionForSourceCodeScript::markColonColonBracketParam;
    Action[30] = &ActionForSourceCodeScript::markColonColonBraceParam;
    Action[31] = &ActionForSourceCodeScript::markPeriodParam;
    Action[32] = &ActionForSourceCodeScript::markPeriodParenthesisParam;
    Action[33] = &ActionForSourceCodeScript::markPeriodBracketParam;
    Action[34] = &ActionForSourceCodeScript::markPeriodBraceParam;
    Action[35] = &ActionForSourceCodeScript::markQuestionPeriodParam;
    Action[36] = &ActionForSourceCodeScript::markPointerParam;
    Action[37] = &ActionForSourceCodeScript::markPeriodStarParam;
    Action[38] = &ActionForSourceCodeScript::markQuestionPeriodStarParam;
    Action[39] = &ActionForSourceCodeScript::markPointerStarParam;
    Action[40] = &ActionForSourceCodeScript::pushStr;
    Action[41] = &ActionForSourceCodeScript::pushNum;
    Action[42] = &ActionForSourceCodeScript::pushDollarStr;
    Action[43] = &ActionForSourceCodeScript::pushComma;
    Action[44] = &ActionForSourceCodeScript::pushSemiColon;
}
//--------------------------------------------------------------------------------------

namespace DslParser
{
    class CachedScriptSource : public IScriptSource
    {
    public:
        explicit CachedScriptSource(const char* p) :m_Source(p)
        {}
    protected:
        virtual int Load()
        {
            return FALSE;
        }
        virtual const char* GetBuffer()const
        {
            return m_Source;
        }
    private:
        const char* m_Source;
    };
    //------------------------------------------------------------------------------------------------------
    char* DslTokenApi::getCurToken() const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->getCurToken();
    }
    char* DslTokenApi::getLastToken() const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->getLastToken();
    }
    int DslTokenApi::getLineNumber() const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->getLineNumber();
    }
    int DslTokenApi::getLastLineNumber() const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->getLastLineNumber();
    }
    void DslTokenApi::setCurToken(char* tok)const
    {
        if (!m_Impl)
            return;
        m_Impl->setCurToken(tok);
    }
    void DslTokenApi::setLastToken(char* tok)const
    {
        if (!m_Impl)
            return;
        m_Impl->setLastToken(tok);
    }
    bool DslTokenApi::enqueueToken(char* tok, short val, int line)const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->enqueueToken(tok, val, line);
    }
    char DslTokenApi::curChar()const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->curChar();
    }
    char DslTokenApi::nextChar()const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->nextChar();
    }
    char DslTokenApi::peekChar(int ix)const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->peekChar(ix);
    }
    char DslTokenApi::peekNextValidChar(int beginIx)const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->peekNextValidChar(beginIx);
    }
    char DslTokenApi::peekNextValidChar(int beginIx, int& index)const
    {
        index = -1;
        if (!m_Impl)
            return 0;
        return m_Impl->peekNextValidChar(beginIx, index);
    }
    void DslTokenApi::getOperatorToken()
    {
        if (!m_Impl)
            return;
        m_Impl->getOperatorToken();
    }
    short DslTokenApi::getOperatorTokenValue()const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->getOperatorTokenValue();
    }
    int DslTokenApi::isNotIdentifierAndEndParenthesis(char c)const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->isNotIdentifierAndEndParenthesis(c);
    }
    int DslTokenApi::isWhiteSpace(char c) const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->isWhiteSpace(c);
    }
    int DslTokenApi::isDelimiter(char c) const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->isDelimiter(c);
    }
    int DslTokenApi::isBeginParentheses(char c) const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->isBeginParentheses(c);
    }
    int DslTokenApi::isEndParentheses(char c) const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->isEndParentheses(c);
    }
    int DslTokenApi::isOperator(char c) const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->isOperator(c);
    }
    int DslTokenApi::isQuote(char c) const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->isQuote(c);
    }
    int DslTokenApi::isSpecialChar(char c) const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->isSpecialChar(c);
    }
    //------------------------------------------------------------------------------------------------------
    void DslActionApi::markSeparator()const
    {
        if (!m_Impl)
            return;
        m_Impl->markSeparator();
    }
    void DslActionApi::endStatement()const
    {
        if (!m_Impl)
            return;
        m_Impl->endStatement();
    }
    void DslActionApi::buildOperator()const
    {
        if (!m_Impl)
            return;
        m_Impl->buildOperator();
    }
    void DslActionApi::buildFirstTernaryOperator()const
    {
        if (!m_Impl)
            return;
        m_Impl->buildFirstTernaryOperator();
    }
    void DslActionApi::buildSecondTernaryOperator()const
    {
        if (!m_Impl)
            return;
        m_Impl->buildSecondTernaryOperator();
    }
    void DslActionApi::beginStatement()const
    {
        if (!m_Impl)
            return;
        m_Impl->beginStatement();
    }
    void DslActionApi::addFunction()const
    {
        if (!m_Impl)
            return;
        m_Impl->addFunction();
    }
    void DslActionApi::setFunctionId()const
    {
        if (!m_Impl)
            return;
        m_Impl->setFunctionId();
    }
    void DslActionApi::markParenthesisParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markParenthesisParam();
    }
    void DslActionApi::buildHighOrderFunction()const
    {
        if (!m_Impl)
            return;
        m_Impl->buildHighOrderFunction();
    }
    void DslActionApi::markBracketParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markBracketParam();
    }
    void DslActionApi::markQuestionParenthesisParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markQuestionParenthesisParam();
    }
    void DslActionApi::markQuestionBracketParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markQuestionBracketParam();
    }
    void DslActionApi::markQuestionBraceParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markQuestionBraceParam();
    }
    void DslActionApi::markStatement()const
    {
        if (!m_Impl)
            return;
        m_Impl->markStatement();
    }
    void DslActionApi::markExternScript()const
    {
        if (!m_Impl)
            return;
        m_Impl->markExternScript();
    }
    void DslActionApi::markBracketColonParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markBracketColonParam();
    }
    void DslActionApi::markParenthesisColonParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markParenthesisColonParam();
    }
    void DslActionApi::markAngleBracketColonParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markAngleBracketColonParam();
    }
    void DslActionApi::markBracePercentParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markBracePercentParam();
    }
    void DslActionApi::markBracketPercentParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markBracketPercentParam();
    }
    void DslActionApi::markParenthesisPercentParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markParenthesisPercentParam();
    }
    void DslActionApi::markAngleBracketPercentParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markAngleBracketPercentParam();
    }
    void DslActionApi::markColonColonParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markColonColonParam();
    }
    void DslActionApi::markColonColonParenthesisParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markColonColonParenthesisParam();
    }
    void DslActionApi::markColonColonBracketParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markColonColonBracketParam();
    }
    void DslActionApi::markColonColonBraceParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markColonColonBraceParam();
    }
    void DslActionApi::setExternScript()const
    {
        if (!m_Impl)
            return;
        m_Impl->setExternScript();
    }
    void DslActionApi::markPeriodParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markPeriodParam();
    }
    void DslActionApi::setMemberId()const
    {
        if (!m_Impl)
            return;
        m_Impl->setMemberId();
    }
    void DslActionApi::markPeriodParenthesisParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markPeriodParenthesisParam();
    }
    void DslActionApi::markPeriodBracketParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markPeriodBracketParam();
    }
    void DslActionApi::markPeriodBraceParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markPeriodBraceParam();
    }
    void DslActionApi::markQuestionPeriodParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markQuestionPeriodParam();
    }
    void DslActionApi::markPointerParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markPointerParam();
    }
    void DslActionApi::markPeriodStarParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markPeriodStarParam();
    }
    void DslActionApi::markQuestionPeriodStarParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markQuestionPeriodStarParam();
    }
    void DslActionApi::markPointerStarParam()const
    {
        if (!m_Impl)
            return;
        m_Impl->markPointerStarParam();
    }
    void DslActionApi::push(char* token, int type)const
    {
        if (!m_Impl)
            return;
        m_Impl->getRuntimeBuilderData().push(RuntimeBuilderData::TokenInfo(token, type));
    }
    StatementData* DslActionApi::getCurStatement()const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->getRuntimeBuilderData().getCurStatement();
    }
    FunctionData* DslActionApi::getLastFunction()const
    {
        if (!m_Impl)
            return 0;
        return m_Impl->getRuntimeBuilderData().getLastFunction();
    }
    void DslActionApi::setLastFunction(FunctionData* p)const
    {
        if (!m_Impl)
            return;
        m_Impl->getRuntimeBuilderData().setLastFunction(p);
    }
    //------------------------------------------------------------------------------------------------------
    bool Mac2Unix(char* buf, int len)
    {
        bool r = false;
        char* p = strchr(buf, '\r');
        if (p && *(p + 1) != '\n') {
            for (int ix = 0; ix < len; ++ix) {
                if (buf[ix] == '\r')
                    buf[ix] = '\n';
            }
            r = true;
        }
        return r;
    }
    void Parse(const char* buf, DslFile& file)
    {
        if (0 == buf)
            return;
        CachedScriptSource source(buf);
        Parse(source, file);
    }
    void Parse(IScriptSource& source, DslFile& file)
    {
        file.ClearErrorInfo();
        SlkToken tokens(source, file);
        SlkError error(file);
        ActionForSourceCodeScript action(tokens, file);
        SlkParse(action, tokens, error, 0);
        if (tokens.getStringBeginDelimiter()[0] && tokens.getStringEndDelimiter()[0]) {
            file.SetStringDelimiter(tokens.getStringBeginDelimiter(), tokens.getStringEndDelimiter());
        }
        if (tokens.getScriptBeginDelimiter()[0] && tokens.getScriptEndDelimiter()[0]) {
            file.SetScriptDelimiter(tokens.getScriptBeginDelimiter(), tokens.getScriptEndDelimiter());
        }
    }
    static std::string TransformPreprocess(const char* input, int len, const char* beginDelim, const char* endDelim);
    void ParseGpp(const char* buf, DslFile& file, const char* beginDelim, const char* endDelim, char* gppBuf, int& len)
    {
        std::string str = TransformPreprocess(buf, static_cast<int>(strlen(buf)), beginDelim, endDelim);
        Parse(str.c_str(), file);
        if (gppBuf && len > 0) {
            tsnprintf(gppBuf, len, "%s", str.c_str());
            len = static_cast<int>(str.length());
        }
    }
    static inline void ltrim(std::string& s) {
        s.erase(s.begin(), std::find_if_not(s.begin(), s.end(), [](unsigned char ch) {
            return std::isspace(ch);
        }));
    }
    static inline void rtrim(std::string& s) {
        s.erase(std::find_if_not(s.rbegin(), s.rend(), [](unsigned char ch) {
            return std::isspace(ch);
        }).base(), s.end());
    }
    static inline void trim(std::string& s) {
        ltrim(s);
        rtrim(s);
    }
    static inline std::size_t replace_all(std::string& inout, const std::string& what, const std::string& with)
    {
        std::size_t count = 0;
        for (std::string::size_type pos = 0; inout.npos != (pos = inout.find(what.data(), pos, what.length())); pos += with.length(), ++count) {
            inout.replace(pos, what.length(), with.data(), with.length());
        }
        return count;
    }
    static inline bool isWhiteSpace(char c)
    {
        if (c == 0)
            return false;
        else
            return 0 != strchr(" \t\r\n", c);
    }
    static inline std::string quoteString(const std::string& str, const char* beginDelim, const char* endDelim)
    {
        std::stringstream ss;
        ss << beginDelim;
        for (int i = 0; i < static_cast<int>(str.length()); ++i) {
            char c = str[i];
            switch (c) {
            case '\\':
                ss << "\\\\";
                break;
            case '"':
                ss << "\\\"";
                break;
            case '\'':
                ss << "\\'";
                break;
            case '\0':
                ss << "\\\0";
                break;
            default:
                ss << c;
                break;
            }
        }
        ss << endDelim;
        return ss.str();
    }
    static inline void TryEmitStartCodeBlock(std::stringstream& ss, const char* delim, bool& codeBlockNeedClose)
    {
        if (!codeBlockNeedClose) {
            ss << "@@code";
            ss << std::endl;
            ss << delim;
            ss << std::endl;
            codeBlockNeedClose = true;
        }
    }
    static inline void TryEmitCloseCodeBlock(std::stringstream& ss, const char* delim, bool& codeBlockNeedClose)
    {
        if (codeBlockNeedClose) {
            ss << delim;
            ss << ';';
            ss << std::endl;
            codeBlockNeedClose = false;
        }
    }
    static inline bool SkipWhiteSpaces(const char* input, int len, int& ix)
    {
        bool isSkip = false;
        for (; ix < len && input[ix] != '\n' && isWhiteSpace(input[ix]); ++ix) {
            isSkip = true;
        }
        return isSkip;
    }
    static inline bool SkipComments(const char* input, int len, int& ix)
    {
        bool isSkip = false;
        //单行注释
        if (ix + 1 < len && input[ix] == '/' && input[ix + 1] == '/') {
            for (; ix < len && input[ix] != '\n'; ++ix);
            isSkip = true;
        }
        //多行注释
        if (ix + 1 < len && input[ix] == '/' && input[ix + 1] == '*') {
            ++ix;
            ++ix;
            for (; ix + 1 < len; ++ix) {
                if (input[ix] == '*' && input[ix + 1] == '/') {
                    ++ix;
                    ++ix;
                    break;
                }
            }
            isSkip = true;
        }
        return isSkip;
    }
    static bool IsSimpleDefine(const std::string& str)
    {
        for (int i = 0; i < static_cast<int>(str.length()); ++i) {
            char c = str[i];
            if (!::isalnum(c) && c != '_' && c != ' ' && c != '\t')
                return false;
        }
        return true;
    }
    static bool MyIsDigit(char ch)
    {
        return (ch >= '0' && ch <= '9');
    }
    static bool MyIsLetterOrDigit(char ch)
    {
        return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F') || ch == '_';
    }
    static std::string TransformPreprocess(const char* input, int len, const char* beginDelim, const char* endDelim)
    {
        std::stringstream ss;
        std::stringstream tokenBuilder;
        bool codeBlockNeedClose = false;
        if (beginDelim && endDelim) {
            ss << "@@delimiter(script, \"" << beginDelim << "\", \"" << endDelim << "\");" << std::endl;
        }
        else {
            beginDelim = "{:";
            endDelim = ":}";
        }
        for (int i = 0; i < len; ++i) {
            char ch = input[i];
            switch (ch) {
            case '/': {
                TryEmitStartCodeBlock(ss, beginDelim, codeBlockNeedClose);
                ss << ch;
                if (i + 1 < len) {
                    char c = input[i + 1];
                    if (c == '/') {
                        ss << c;
                        for (int j = i + 2; j < len; ++j) {
                            c = input[j];
                            ss << c;
                            if (c == '\n') {
                                i = j;
                                break;
                            }
                            else if (j == len - 1) {
                                i = j;
                            }
                        }
                    }
                    else if (c == '*') {
                        ss << c;
                        char lc = '\0';
                        for (int j = i + 2; j < len; ++j) {
                            c = input[j];
                            ss << c;
                            if (lc == '*' && c == '/') {
                                i = j;
                                break;
                            }
                            lc = c;
                        }
                    }
                }
                break;
            }
            case '\'':
            case '"': {
                TryEmitStartCodeBlock(ss, beginDelim, codeBlockNeedClose);
                ss << ch;
                for (int j = i + 1; j < len; ++j) {
                    char c = input[j];
                    ss << c;
                    if (c == '\\') {
                        ++j;
                        if (j < len) {
                            c = input[j];
                            ss << c;
                        }
                        else {
                            i = j - 1;
                            break;
                        }
                    }
                    else if (c == ch) {
                        i = j;
                        break;
                    }
                }
                break;
            }
            case '#': {
                //预处理（define, undef, include, if, ifdef, ifndef, else, elif, elifdef, elifndef (since C++23), endif, line, error, pragma）
                int j = i + 1;
                tokenBuilder.str(std::string());
                bool isSkip = true;
                for (; isSkip && j < len;) {
                    bool s1 = SkipWhiteSpaces(input, len, j);
                    bool s2 = SkipComments(input, len, j);
                    isSkip = s1 || s2;
                }
                for (; j < len && ::isalpha(input[j]); ++j) {
                    tokenBuilder << input[j];
                }
                std::string key = tokenBuilder.str();
                tokenBuilder.str(std::string());
                std::string arg;
                for (; j < len && input[j] != '\n' && isWhiteSpace(input[j]); ++j);
                if (j < len && input[j] != '\n') {
                    bool isExpression = key == "define" || (key.length() >= 2 && ((key[0] == 'i' && key[1] == 'f') || (key[0] == 'e' && key[1] == 'l') || (key[0] == 'e' && key[1] == 'n')));
                    char lc = '\0';
                    for (; j < len; ++j) {
                        SkipComments(input, len, j);
                        if (j >= len)
                            break;
                        char cc = input[j];
                        if ((cc == '\r' && lc != '\\') || (cc == '\n' && lc != '\r' && lc != '\\')) {
                            if (cc == '\r')
                                ++j;
                            break;
                        }
                        if (isExpression && (cc == '"' || cc == '\'')) {
                            //字符串
                            tokenBuilder << cc;
                            ++j;
                            while (j + 1 < len && input[j] != cc) {
                                char c = input[j];
                                tokenBuilder << c;
                                ++j;
                                if (c == '\\') {
                                    tokenBuilder << input[j];
                                    ++j;
                                }
                            }
                            tokenBuilder << input[j];
                        }
                        else if (cc == '\\' && (input[j + 1] == '\r' || input[j + 1] == '\n')) {
                            //续行符不输出
                        }
                        else {
                            tokenBuilder << cc;
                        }
                        lc = input[j];
                    }
                    arg = tokenBuilder.str();
                    trim(arg);
                }
                TryEmitCloseCodeBlock(ss, endDelim, codeBlockNeedClose);
                if (key.length() >= 2 && ((key[0] == 'i' && key[1] == 'f') || (key[0] == 'e' && key[1] == 'l') || (key[0] == 'e' && key[1] == 'n'))) {
                    //语句块
                    if (key[0] == 'i' && key[1] == 'f') {
                        ss << "@@";
                        ss << key;
                        ss << '(';
                        ss << arg;
                        ss << ')';
                        ss << std::endl;
                        ss << "{";
                        ss << std::endl;
                    }
                    else if (key[0] == 'e' && key[1] == 'l') {
                        ss << "}";
                        ss << std::endl;
                        ss << "@@";
                        ss << key;
                        ss << '(';
                        ss << arg;
                        ss << ')';
                        ss << std::endl;
                        ss << "{";
                        ss << std::endl;
                    }
                    else {
                        ss << "}";
                        ss << std::endl;
                        ss << "@@";
                        ss << key;
                        ss << '(';
                        ss << arg;
                        ss << ')';
                        ss << std::endl;
                    }
                }
                else {
                    //函数
                    ss << "@@";
                    if (key.empty())
                        ss << "ignore";
                    else
                        ss << key;
                    ss << '(';
                    if ((key == "define" && IsSimpleDefine(arg)) || key == "undef") {
                        ss << arg;
                    }
                    else {
                        std::string quoteArg = quoteString(arg, "\"", "\"");
                        ss << quoteArg;
                    }
                    ss << ')';
                    ss << ';';
                    ss << std::endl;
                }
                i = j;
                break;
            }
            case ' ':
            case '\t':
            case '\r':
            case '\n':
                TryEmitStartCodeBlock(ss, beginDelim, codeBlockNeedClose);
                ss << ch;
                break;
            default:
                TryEmitStartCodeBlock(ss, beginDelim, codeBlockNeedClose);
                ss << ch;
                if (MyIsLetterOrDigit(ch)) {
                    bool firstIsDigit = MyIsDigit(ch);
                    for (int j = i + 1; j < len; ++j) {
                        char c = input[j];
                        if (c == '\\') {
                            ss << c;
                            ++j;
                            if (j < len) {
                                c = input[j];
                                ss << c;
                            }
                            else {
                                i = j - 1;
                                break;
                            }
                        }
                        else if ((firstIsDigit && c == '\'') || MyIsLetterOrDigit(c)) {
                            ss << c;
                        }
                        else {
                            i = j - 1;
                            break;
                        }
                    }
                }
                break;
            }
        }
        ss.seekg(-1, std::ios::end);
        if (!isWhiteSpace(static_cast<char>(ss.get()))) {
            ss << std::endl;
        }
        TryEmitCloseCodeBlock(ss, endDelim, codeBlockNeedClose);
        return ss.str();
    }
}