#pragma once

#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkpCharacterState/bhkCharacterState/bhkCharacterState.h"


namespace RE
{
	class bhkCharacterStateFlying : public bhkCharacterState
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkCharacterStateFlying;


		virtual ~bhkCharacterStateFlying();	 // 00

		// override (bhkCharacterState)
		virtual hkpCharacterStateType GetType() const override;	 // 03 - { return kFlying; }
		virtual void				  Unk_08(void) override;	 // 08
	};
	static_assert(sizeof(bhkCharacterStateFlying) == 0x10);
}
