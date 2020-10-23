#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/SkyrimScript/DelayFunctor/DelayFunctor.h"


namespace RE
{
	namespace BSScript
	{
		class IVirtualMachine;
	}


	namespace SkyrimScript
	{
		class SetMotionTypeFunctor : public DelayFunctor
		{
		public:
			inline static constexpr auto RTTI = RTTI_SkyrimScript____SetMotionTypeFunctor;


			virtual ~SetMotionTypeFunctor();  // 00

			// override (DelayFunctor)
			virtual RE::BSScript::Variable operator()() override;															   // 01
			virtual bool				   IsLatent() const override;														   // 02 - { return true; }
			virtual bool				   SaveImpl(BSStorage& a_storage) const override;									   // 04
			virtual FunctorType			   GetType() const override;														   // 05 - { return 8; }
			virtual bool				   LoadImpl(const BSStorage& a_storage, std::uint32_t a_arg2, bool& a_arg3) override;  // 06


			// members
			ObjectRefHandle							   objectToChange;	// 10
			std::uint32_t							   type;			// 14
			BSTSmartPointer<BSScript::IVirtualMachine> vm;				// 18
			bool									   allowActivate;	// 20
			std::uint8_t							   pad21;			// 21
			std::uint16_t							   pad22;			// 22
			std::uint32_t							   pad24;			// 24
		};
		static_assert(sizeof(SetMotionTypeFunctor) == 0x28);
	}
}
