#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/BSCore/BSTList.h"
#include "RE/FormComponents/BGSPreloadable.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESForm.h"


namespace RE
{
	namespace BSResource
	{
		struct ID;
	}


	struct BGSDebrisData
	{
	public:
		enum class BGSDebrisDataFlags
		{
			kNone = 0,
			kCollisionData = 1 << 0
		};


		// members
		std::int8_t										   percentage;	// 00 - DATA~
		stl::enumeration<BGSDebrisDataFlags, std::uint8_t> flags;		// 01 - ~DATA
		std::uint16_t									   pad02;		// 02
		std::uint32_t									   pad04;		// 04
		const char*										   fileName;	// 08
		BSTArray<BSResource::ID>						   textureIDs;	// 10 - MODT
		BSTArray<std::uint32_t>							   addons;		// 28
	};
	static_assert(sizeof(BGSDebrisData) == 0x40);


	class BGSDebris :
		public TESForm,		   // 00
		public BGSPreloadable  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSDebris;
		inline static constexpr auto FORMTYPE = FormType::Debris;


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSDebris();  // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04 - { return; }
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06


		// members
		BSSimpleList<BGSDebrisData*> data;	// 28
	};
	static_assert(sizeof(BGSDebris) == 0x38);
}
