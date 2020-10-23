#pragma once

#include "RE/FormComponents/BGSDestructibleObjectForm.h"
#include "RE/FormComponents/Components/BGSOpenCloseForm.h"
#include "RE/FormComponents/Components/TESMagicCasterForm.h"
#include "RE/FormComponents/Components/TESMagicTargetForm.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESContainer.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESBoundAnimObject.h"
#include "RE/FormComponents/TESFullName.h"
#include "RE/FormComponents/TESModel/TESModelTextureSwap.h"
#include "RE/FormComponents/TESWeightForm.h"


namespace RE
{
	struct CONT_DATA
	{
		enum class Flag
		{
			kNone = 0,
			kAllowsSoundsWhenAnimation = 1 << 0,
			kRespawn = 1 << 1,
			kShowOwner = 1 << 2
		};


		stl::enumeration<Flag, std::uint8_t> flags;	 // 0
	};
	static_assert(sizeof(CONT_DATA) == 0x1);


	class TESObjectCONT :
		public TESBoundAnimObject,		   // 00
		public TESContainer,			   // 30
		public TESFullName,				   // 48
		public TESModelTextureSwap,		   // 58
		public TESWeightForm,			   // 90
		public TESMagicCasterForm,		   // B8
		public TESMagicTargetForm,		   // B9
		public BGSDestructibleObjectForm,  // A0
		public BGSOpenCloseForm			   // B0
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObjectCONT;
		inline static constexpr auto FORMTYPE = FormType::Container;


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kHasDistantLOD = 1 << 15,
				kRandomAnimStart = 1 << 16,
				kObstacle = 1 << 25,
				kNavMeshGeneration_Filter = 1 << 26,
				kNavMeshGeneration_BoundingBox = 1 << 27,
				kNavMeshGeneration_Ground = 1 << 30
			};
		};


		virtual ~TESObjectCONT();  // 00

		// override (TESBoundAnimObject)
		virtual void InitializeData() override;																																   // 04
		virtual bool Load(TESFile* a_mod) override;																															   // 06
		virtual void InitItemImpl() override;																																   // 13
		virtual bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 37
		virtual bool GetActivateText(TESObjectREFR* a_activator, BSString& a_dst) override;																					   // 4C
		virtual bool CalculateDoFavor(Actor* a_activator, bool a_arg2, TESObjectREFR* a_toActivate, float a_arg3) override;													   // 4D

		// override (BGSOpenCloseForm)
		virtual void HandleOpen(TESObjectREFR* a_target, TESObjectREFR* a_activator) override;	 // 01
		virtual void HandleClose(TESObjectREFR* a_target, TESObjectREFR* a_activator) override;	 // 02


		// members
		CONT_DATA				data;		 // B9 - DATA
		std::uint16_t			padBA;		 // BA
		std::uint32_t			padBC;		 // BC
		BGSSoundDescriptorForm* openSound;	 // C0 - SNAM
		BGSSoundDescriptorForm* closeSound;	 // C8 - QNAM
	};
	static_assert(offsetof(TESObjectCONT, data) == 0xB9);
	static_assert(sizeof(TESObjectCONT) == 0xD0);
}
