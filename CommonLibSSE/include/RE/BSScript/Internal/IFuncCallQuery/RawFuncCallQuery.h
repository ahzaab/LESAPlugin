#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/BSScript/Internal/IFuncCallQuery/IFuncCallQuery.h"
#include "RE/BSScript/Variable.h"


namespace RE
{
	namespace BSScript
	{
		class ObjectTypeInfo;


		namespace Internal
		{
			class RawFuncCallQuery : public IFuncCallQuery
			{
			public:
				inline static constexpr auto RTTI = RTTI_BSScript__Internal__RawFuncCallQuery;


				virtual ~RawFuncCallQuery();  // 00

				// override (IFuncCallQuery)
				virtual bool GetFunctionCallInfo(CallType& a_callType, BSTSmartPointer<ObjectTypeInfo>& a_arg2, BSFixedString& a_arg3, Variable& a_arg4, BSScrapArray<Variable>& a_arg5) override;	// 01


				// members
				CallType						callType;  // 10
				std::uint32_t					pad14;	   // 14
				BSTSmartPointer<ObjectTypeInfo> objType;   // 18
				BSFixedString					name;	   // 20
				Variable						self;	   // 28
				BSTArray<Variable>				args;	   // 38
			};
			static_assert(sizeof(RawFuncCallQuery) == 0x50);
		}
	}
}
