#pragma once

#include "RE/BSCore/BSAtomic.h"
#include "RE/BSCore/BSTHashMap.h"
#include "RE/BSScript/IProfilePolicy.h"


namespace RE
{
	namespace SkyrimScript
	{
		class Profiler : public BSScript::IProfilePolicy
		{
		public:
			inline static constexpr auto RTTI = RTTI_SkyrimScript__Profiler;


			virtual ~Profiler();  // 00

			// override (BSScript::IProfilePolicy)
			virtual void StackFramePushQueued(std::uint32_t a_arg1, std::uint32_t a_arg2, const BSTSmartPointer<BSScript::Internal::IFuncCallQuery>& a_arg3) override;														 // 01
			virtual void StackFramePushed(std::uint32_t a_arg1, std::uint32_t a_arg2, const BSScript::Variable& a_arg3, const BSFixedString& a_arg4, const BSFixedString& a_arg5, const BSFixedString& a_arg6) override;	 // 02
			virtual void StackFramePopQueued(std::uint32_t a_arg1, std::uint32_t a_arg2, const BSScript::Variable& a_arg3, const BSFixedString& a_arg4, const BSFixedString& a_arg5, const BSFixedString& a_arg6) override;	 // 03
			virtual void StackFramePopped(std::uint32_t a_arg1, std::uint32_t a_arg2, const BSScript::Variable& a_arg3, const BSFixedString& a_arg4, const BSFixedString& a_arg5, const BSFixedString& a_arg6) override;	 // 04


			// members
			mutable BSSpinLock			 unk08;	 // 08
			BSTHashMap<UnkKey, UnkValue> unk10;	 // 10
			BSTHashMap<UnkKey, UnkValue> unk40;	 // 40
			BSTHashMap<UnkKey, UnkValue> unk70;	 // 70
			std::uint64_t				 unkA0;	 // A0
			std::uint64_t				 unkA8;	 // A8
			std::uint64_t				 unkB0;	 // B0
			std::uint64_t				 unkB8;	 // B8
			std::uint64_t				 unkC0;	 // C0
			std::uint64_t				 unkC8;	 // C8
			std::uint64_t				 unkD0;	 // D0
			std::uint64_t				 unkD8;	 // D8
		};
		static_assert(sizeof(Profiler) == 0xE0);
	}
}
