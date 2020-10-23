#pragma once

#include "RE/Animation/IAnimationGraphManagerHolder/IAnimationGraphManagerHolder.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class SimpleAnimationGraphManagerLoadingTask;


	class SimpleAnimationGraphManagerHolder : public IAnimationGraphManagerHolder
	{
	public:
		inline static constexpr auto RTTI = RTTI_SimpleAnimationGraphManagerHolder;


		// override (IAnimationGraphManagerHolder)
		virtual bool GetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>& a_out) const override;	// 02 - { a_out = animationGraphManager; return a_out; }
		virtual bool SetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>& a_in) override;			// 03 - { animationGraphManager = a_in; return true; }
		virtual bool ConstructAnimationGraph(BSTSmartPointer<BShkbAnimationGraph>& a_out) override;					// 05

		// add
		virtual void Unk_13(void);	// 13 - { return; }


		// members
		BSTSmartPointer<BSAnimationGraphManager>		  animationGraphManager;  // 08
		NiPointer<SimpleAnimationGraphManagerLoadingTask> loadingTask;			  // 10
	};
	static_assert(sizeof(SimpleAnimationGraphManagerHolder) == 0x18);
}
