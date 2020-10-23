#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESForm.h"
#include "RE/NetImmerse/NiColor.h"


namespace RE
{
	class BGSMaterialType : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMaterialType;
		inline static constexpr auto FORMTYPE = FormType::MaterialType;


		enum class FLAG
		{
			kNone = 0,
			kStairs = 1 << 0,
			kArrowsStick = 1 << 1
		};


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSMaterialType();	 // 00

		// override (TESForm)
		virtual void ClearData() override;			 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		BGSMaterialType*					  parentType;		   // 20 - PNAM
		BSFixedString						  materialName;		   // 28 - MNAM
		std::uint32_t						  materialID;		   // 30
		NiColor								  materialColor;	   // 34 - CNAM
		float								  buoyancy;			   // 40 - BNAM
		stl::enumeration<FLAG, std::uint32_t> flags;			   // 44 - FNAM
		BGSImpactDataSet*					  havokImpactDataSet;  // 48 - HNAM
	};
	static_assert(sizeof(BGSMaterialType) == 0x50);
}
