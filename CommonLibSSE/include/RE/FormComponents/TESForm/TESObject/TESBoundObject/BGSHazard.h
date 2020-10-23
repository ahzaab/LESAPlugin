#pragma once

#include "RE/FormComponents/BGSPreloadable.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundObject.h"
#include "RE/FormComponents/TESFullName.h"
#include "RE/FormComponents/TESImageSpaceModifiableForm.h"
#include "RE/FormComponents/TESModel/TESModel.h"


namespace RE
{
	struct BGSHazardData  // DATA
	{
	public:
		enum class BGSHazardFlags
		{
			kNone = 0,
			kPCOnly = 1 << 0,
			kInheritDuration = 1 << 1,
			kAlignToNormal = 1 << 2,
			kInheritRadius = 1 << 3,
			kDropToGround = 1 << 4
		};


		std::uint32_t									limit;			   // 00
		float											radius;			   // 04
		float											lifetime;		   // 08
		float											imageSpaceRadius;  // 0C
		float											targetInterval;	   // 10
		stl::enumeration<BGSHazardFlags, std::uint32_t> flags;			   // 14
		SpellItem*										spell;			   // 18
		TESObjectLIGH*									light;			   // 20
		BGSImpactDataSet*								impactDataSet;	   // 28
		BGSSoundDescriptorForm*							sound;			   // 30
	};
	static_assert(sizeof(BGSHazardData) == 0x38);


	class BGSHazard :
		public TESBoundObject,				// 00
		public TESFullName,					// 30
		public TESModel,					// 40
		public BGSPreloadable,				// 68
		public TESImageSpaceModifiableForm	// 70
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSHazard;
		inline static constexpr auto FORMTYPE = FormType::Hazard;


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSHazard();  // 00

		// override (TESBoundObject)
		virtual void InitializeData() override;		 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		BGSHazardData data;	 // 80 - DATA
	};
	static_assert(sizeof(BGSHazard) == 0xB8);
}
