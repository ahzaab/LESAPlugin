#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/NetImmerse/NiPoint3.h"
#include "RE/SkyrimScript/DelayFunctor/DelayFunctor.h"


namespace RE
{
	namespace BSScript
	{
		class IVirtualMachine;
	}


	namespace SkyrimScript
	{
		class MoveToFunctor : public DelayFunctor
		{
		public:
			inline static constexpr auto RTTI = RTTI_SkyrimScript____MoveToFunctor;


			virtual ~MoveToFunctor();  // 00

			// override (DelayFunctor)
			virtual RE::BSScript::Variable operator()() override;															   // 01
			virtual bool				   IsLatent() const override;														   // 02 - { return true; }
			virtual bool				   SaveImpl(BSStorage& a_storage) const override;									   // 04
			virtual FunctorType			   GetType() const override;														   // 05 - { return 0; }
			virtual bool				   LoadImpl(const BSStorage& a_storage, std::uint32_t a_arg2, bool& a_arg3) override;  // 06


			// members
			ObjectRefHandle							   source;			// 10
			ObjectRefHandle							   destination;		// 14
			NiPoint3								   offset;			// 18
			NiPoint3								   rotationOffset;	// 24
			bool									   matchRotation;	// 30
			bool									   exactTranslate;	// 31
			std::uint16_t							   pad32;			// 32
			std::uint32_t							   pad34;			// 34
			BSTSmartPointer<BSScript::IVirtualMachine> vm;				// 38
		};
		static_assert(sizeof(MoveToFunctor) == 0x40);
	}
}
