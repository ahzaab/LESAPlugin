#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/FormComponents/Components/Movement.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESForm.h"


namespace RE
{
	class BGSMovementType : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMovementType;
		inline static constexpr auto FORMTYPE = FormType::MovementType;


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSMovementType();	 // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		Movement::TypeData movementTypeData;  // 20
	};
	static_assert(sizeof(BGSMovementType) == 0x60);
}
