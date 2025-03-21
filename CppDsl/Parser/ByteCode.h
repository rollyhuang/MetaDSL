﻿#ifndef __ByteCode_H__
#define __ByteCode_H__

#include "DslParser.h"
#include "RuntimeBuilderData.h"
#include "tsnprintf.h"

namespace DslParser
{
    template<typename RealTypeT>
    class RuntimeBuilderT
    {
    public:
        RuntimeBuilderT(DslFile& dataFile) :mThis(nullptr), mDataFile(&dataFile), mApi()
        {
            MyAssert(mDataFile);
            mData.GetNullFunctionPtrRef() = mDataFile->GetNullFunctionPtr();
        }
        inline void    setEnvironmentObjRef(RealTypeT& thisObj)
        {
            mThis = &thisObj;
            MyAssert(mThis);
        }
    public:
        inline void    markSeparator();
        inline void    endStatement();
        inline void    buildOperator();
        inline void    buildFirstTernaryOperator();
        inline void    buildSecondTernaryOperator();
        inline void    beginStatement();
        inline void    addFunction();
        inline void    setFunctionId();
        inline void    markParenthesisParam();
        inline void    buildHighOrderFunction();
        inline void    markBracketParam();
        inline void    markQuestionParenthesisParam();
        inline void    markQuestionBracketParam();
        inline void    markQuestionBraceParam();
        inline void    markStatement();
        inline void    markExternScript();
        inline void    markBracketColonParam();
        inline void    markParenthesisColonParam();
        inline void    markAngleBracketColonParam();
        inline void    markBracePercentParam();
        inline void    markBracketPercentParam();
        inline void    markParenthesisPercentParam();
        inline void    markAngleBracketPercentParam();
        inline void    markColonColonParam();
        inline void    markColonColonParenthesisParam();
        inline void    markColonColonBracketParam();
        inline void    markColonColonBraceParam();
        inline void    setExternScript();
        inline void    markPeriodParam();
        inline void    setMemberId();
        inline void    markPeriodParenthesisParam();
        inline void    markPeriodBracketParam();
        inline void    markPeriodBraceParam();
        inline void    markQuestionPeriodParam();
        inline void    markPointerParam();
        inline void    markPeriodStarParam();
        inline void    markQuestionPeriodStarParam();
        inline void    markPointerStarParam();
    public:
        RuntimeBuilderData& getRuntimeBuilderData() { return mData; }
        const RuntimeBuilderData& getRuntimeBuilderData()const { return mData; }
    private:
        inline ISyntaxComponent& simplifyStatement(StatementData& data)const;
        inline ValueOrFunctionData& simplifyStatement(FunctionData& data)const;
        inline void simplifyFunction(FunctionData& data)const;
        inline bool	preconditionCheck()const
        {
            return nullptr != mThis && nullptr != mDataFile;
        }
    protected:
        RuntimeBuilderData		        mData;
        DslActionApi mApi;
        DslFile* mDataFile;
        RealTypeT* mThis;
    };
}

#include "ByteCode.inl"

#endif //__ByteCode_H__