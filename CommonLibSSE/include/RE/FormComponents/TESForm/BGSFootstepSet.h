#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESForm.h"


namespace RE
{
	struct ACTOR_MOVEMENT_TYPES
	{
		enum ACTOR_MOVEMENT_TYPE : std::uint32_t
		{
			kWalk = 0,
			kRun = 1,
			kSneak = 2,
			kBleedout = 3,
			kSwim = 4,

			kTotal = 5
		};
	};
	using ACTOR_MOVEMENT_TYPE = ACTOR_MOVEMENT_TYPES::ACTOR_MOVEMENT_TYPE;


	class BGSFootstepSet : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSFootstepSet;
		inline static constexpr auto FORMTYPE = FormType::FootstepSet;


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSFootstepSet();	// 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		BSTArray<BGSFootstep*> entries[ACTOR_MOVEMENT_TYPES::kTotal];  // 20
	};
	static_assert(sizeof(BGSFootstepSet) == 0x98);
}
