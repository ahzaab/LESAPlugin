#pragma once

#include "RE/FormComponents/BGSDestructibleObjectForm.h"
#include "RE/FormComponents/BGSKeywordForm.h"
#include "RE/FormComponents/BGSMessageIcon.h"
#include "RE/FormComponents/BGSPickupPutdownSounds.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESDescription.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundObject.h"
#include "RE/FormComponents/TESFullName.h"
#include "RE/FormComponents/TESModel/TESModelTextureSwap.h"
#include "RE/FormComponents/TESTexture/TESIcon.h"
#include "RE/FormComponents/TESValueForm.h"
#include "RE/FormComponents/TESWeightForm.h"


namespace RE
{
	struct AMMO_DATA  // DATA
	{
	public:
		enum class Flag
		{
			kNone = 0,
			kIgnoresNormalWeaponResistance = 1 << 0,
			kNonPlayable = 1 << 1,
			kNonBolt = 1 << 2
		};


		// members
		BGSProjectile*						 projectile;  // 00
		stl::enumeration<Flag, std::uint8_t> flags;		  // 08
		std::uint8_t						 pa09;		  // 09
		std::uint16_t						 pa0A;		  // 0A
		float								 damage;	  // 0C
	};
	static_assert(sizeof(AMMO_DATA) == 0x10);


	class TESAmmo :
		public TESBoundObject,			   // 000
		public TESFullName,				   // 030
		public TESModelTextureSwap,		   // 040
		public TESIcon,					   // 078
		public BGSMessageIcon,			   // 088
		public TESValueForm,			   // 0A0
		public TESWeightForm,			   // 0B0
		public BGSDestructibleObjectForm,  // 0C0
		public BGSPickupPutdownSounds,	   // 0D0
		public TESDescription,			   // 0E8
		public BGSKeywordForm			   // 0F8
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESAmmo;
		inline static constexpr auto FORMTYPE = FormType::Ammo;


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kNonPlayable = 1 << 2,
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESAmmo();	 // 00

		// override (TESBoundObject)
		virtual void		InitializeData() override;											 // 04
		virtual bool		Load(TESFile* a_mod) override;										 // 06
		virtual void		SaveGame(BGSSaveFormBuffer* a_buf) override;						 // 0E
		virtual void		LoadGame(BGSLoadFormBuffer* a_buf) override;						 // 0F
		virtual void		InitItemImpl() override;											 // 13
		virtual bool		GetPlayable() const override;										 // 19 - { return ~((data.flags >> 1) & 1); }
		virtual NiAVObject* Clone3D(TESObjectREFR* a_ref, bool a_arg3) override;				 // 40
		virtual void		HandleRemoveItemFromContainer(TESObjectREFR* a_container) override;	 // 4E

		// override (BGSKeywordForm)
		virtual BGSKeyword* GetDefaultKeyword() const override;	 // 05

		bool IgnoresNormalWeaponResistance();
		bool IsBolt();


		// members
		AMMO_DATA	  data;		  // 110 - DATA
		BSFixedString shortDesc;  // 120 - ONAM
	};
	static_assert(sizeof(TESAmmo) == 0x128);
}
