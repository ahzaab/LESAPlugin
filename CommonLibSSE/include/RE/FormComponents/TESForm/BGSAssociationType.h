#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESForm.h"


namespace RE
{
	class BGSAssociationType : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSAssociationType;
		inline static constexpr auto FORMTYPE = FormType::AssociationType;


		enum class FLAGS  // DATA
		{
			kNone = 0,
			kFamily = 1 << 0
		};


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Members
		{
			enum
			{
				kParent,
				kChild,

				kTotal
			};
		};


		struct Sexes
		{
			enum
			{
				kMale,
				kFemale,

				kTotal
			};
		};


		virtual ~BGSAssociationType();	// 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06


		// members
		BSFixedString						   associationLabels[Members::kTotal][Sexes::kTotal];  // 20 - MPRT - FCHT
		stl::enumeration<FLAGS, std::uint32_t> flags;											   // 40 - DATA
		std::uint32_t						   pad44;											   // 44
	};
	static_assert(sizeof(BGSAssociationType) == 0x48);
}
