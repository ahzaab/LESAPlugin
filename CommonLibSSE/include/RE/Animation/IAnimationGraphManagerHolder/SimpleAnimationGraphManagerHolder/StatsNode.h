#pragma once

#include "RE/Animation/IAnimationGraphManagerHolder/SimpleAnimationGraphManagerHolder/SimpleAnimationGraphManagerHolder.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/BSCore/BSTEvent.h"
#include "RE/BSSystem/BSIntrusiveRefCounted.h"


namespace RE
{
	struct BSAnimationGraphEvent;


	class StatsNode :
		public SimpleAnimationGraphManagerHolder,	// 00
		public BSIntrusiveRefCounted,				// 20
		public BSTEventSink<BSAnimationGraphEvent>	// 18
	{
	public:
		inline static constexpr auto RTTI = RTTI_StatsNode;


		virtual ~StatsNode();  // 00

		// override (SimpleAnimationGraphManagerHolder)
		virtual bool SetupAnimEventSinks(const BSTSmartPointer<BShkbAnimationGraph>& a_animGraph) override;	 // 08
		virtual void Unk_0C(void) override;																	 // 0C

		// override (BSTEventSink<BSAnimationGraphEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSAnimationGraphEvent* a_event, BSTEventSource<BSAnimationGraphEvent>* a_eventSource) override;	 // 01 - runs PlaySound on BSAnimationGraphEvent::optionalStr


		// members
		std::uint32_t									 unk24;	 // 24
		BSTArray<BSTSmartPointer<BSIntrusiveRefCounted>> unk28;	 // 28
		std::uint64_t									 unk40;	 // 40
		std::uint64_t									 unk48;	 // 48
		BSTSmartPointer<BSIntrusiveRefCounted>			 unk50;	 // 50
		BSTSmartPointer<BSIntrusiveRefCounted>			 unk58;	 // 58
		std::uint64_t									 unk60;	 // 60
	};
	static_assert(sizeof(StatsNode) == 0x68);
}
