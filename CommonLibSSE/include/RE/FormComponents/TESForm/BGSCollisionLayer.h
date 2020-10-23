#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/FormComponents/Components/Color.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESDescription.h"
#include "RE/FormComponents/TESForm/TESForm.h"


namespace RE
{
	class BGSCollisionLayer :
		public TESForm,		   // 00
		public TESDescription  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSCollisionLayer;
		inline static constexpr auto FORMTYPE = FormType::CollisionLayer;


		enum class FLAG	 // GNAM
		{
			kNone = 0,
			kTriggerVolume = 1 << 0,
			kSensor = 1 << 1,
			kNavmeshObstacle = 1 << 2
		};


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSCollisionLayer();  // 00

		// override (TESForm)
		virtual void ClearData() override;			  // 05
		virtual bool Load(TESFile* a_mod) override;	  // 06
		virtual void InitItemImpl() override;		  // 13
		virtual void SetDelete(bool a_set) override;  // 23 - { TESForm::SetDelete(a_set); }


		// members
		std::uint32_t						  collisionIdx;	 // 30 - BNAM
		Color								  debugColor;	 // 34 - FNAM
		stl::enumeration<FLAG, std::uint32_t> flags;		 // 38 - GNAM
		std::uint32_t						  pad3C;		 // 3C
		BSFixedString						  name;			 // 40 - MNAM
		BSTArray<BGSCollisionLayer*>		  collidesWith;	 // 48 - CNAM
	};
	static_assert(sizeof(BGSCollisionLayer) == 0x60);
}
