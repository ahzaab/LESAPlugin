#pragma once

#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundObject.h"
#include "RE/FormComponents/TESLeveledList.h"


namespace RE
{
	class TESLevSpell :
		public TESBoundObject,	// 00
		public TESLeveledList	// 30
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESLevSpell;
		inline static constexpr auto FORMTYPE = FormType::LeveledSpell;


		struct ChangeFlags
		{
			enum ChangeFlag : std::uint32_t
			{
				kAddedObject = (std::uint32_t)1 << 31
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESLevSpell();	 // 00

		// override (TESBoundObject)
		virtual bool Load(TESFile* a_mod) override;				   // 06
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;  // 0E
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;  // 0F
		virtual void Revert(BGSLoadFormBuffer* a_buf) override;	   // 12
		virtual void InitItemImpl() override;					   // 13

		// override (TESLeveledList)
		virtual bool GetCanContainFormsOfType(FormType a_type) const override;	// 07
	};
	static_assert(sizeof(TESLevSpell) == 0x58);
}
