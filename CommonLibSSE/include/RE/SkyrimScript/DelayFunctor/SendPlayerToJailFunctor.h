#pragma once

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
		class SendPlayerToJailFunctor : public DelayFunctor
		{
		public:
			inline static constexpr auto RTTI = RTTI_SkyrimScript____SendPlayerToJailFunctor;


			enum class Flag
			{
				kNone = 0,
				kRemoveInventory = 1 << 0,
				kRealJail = 1 << 1
			};


			virtual ~SendPlayerToJailFunctor();	 // 00

			// override (DelayFunctor)
			virtual RE::BSScript::Variable operator()() override;															   // 01
			virtual bool				   IsLatent() const override;														   // 02 - { return true; }
			virtual bool				   SaveImpl(BSStorage& a_storage) const override;									   // 04
			virtual FunctorType			   GetType() const override;														   // 05 - { return 19; }
			virtual bool				   LoadImpl(const BSStorage& a_storage, std::uint32_t a_arg2, bool& a_arg3) override;  // 06


			// members
			FormID									   faction;	 // 10
			stl::enumeration<Flag, std::uint8_t>	   flags;	 // 14
			std::uint8_t							   pad15;	 // 15
			std::uint16_t							   pad16;	 // 16
			BSTSmartPointer<BSScript::IVirtualMachine> vm;		 // 18
		};
		static_assert(sizeof(SendPlayerToJailFunctor) == 0x20);
	}
}
