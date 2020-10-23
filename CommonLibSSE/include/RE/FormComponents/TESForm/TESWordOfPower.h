#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESForm.h"
#include "RE/FormComponents/TESFullName.h"


namespace RE
{
	class TESWordOfPower :
		public TESForm,		// 00
		public TESFullName	// 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESWordOfPower;
		inline static constexpr auto FORMTYPE = FormType::WordOfPower;


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESWordOfPower();	// 00

		// override (TESForm)
		virtual bool Load(TESFile* a_mod) override;	 // 06


		// members
		BSFixedString translation;	// 30 - TNAM
	};
	static_assert(sizeof(TESWordOfPower) == 0x38);
}
