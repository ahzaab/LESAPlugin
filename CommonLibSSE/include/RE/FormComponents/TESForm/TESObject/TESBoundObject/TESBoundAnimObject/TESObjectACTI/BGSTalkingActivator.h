#pragma once

#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESObjectACTI/TESObjectACTI.h"


namespace RE
{
	class BGSTalkingActivator : public TESObjectACTI
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSTalkingActivator;
		inline static constexpr auto FORMTYPE = FormType::TalkingActivator;


		struct ChangeFlags
		{
			enum ChangeFlag : std::uint32_t
			{
				kSpeaker = 1 << 23
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kHiddenFromLocalMap = 1 << 9,
				kIgnored = 1 << 12,
				kRandomAnimStart = 1 << 16,
				kRadioStation = 1 << 17
			};
		};


		virtual ~BGSTalkingActivator();	 // 00

		// override (TESObjectACTI)
		virtual void		  InitializeData() override;																															  // 04
		virtual bool		  Load(TESFile* a_mod) override;																														  // 06
		virtual void		  SaveGame(BGSSaveFormBuffer* a_buf) override;																											  // 0E
		virtual void		  LoadGame(BGSLoadFormBuffer* a_buf) override;																											  // 0F
		virtual void		  Revert(BGSLoadFormBuffer* a_buf) override;																											  // 12
		virtual void		  InitItemImpl() override;																																  // 13
		virtual bool		  GetDangerous() const override;																														  // 1B - { return 0; }
		virtual bool		  Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_arg4, std::int32_t a_targetCount) override;  // 37
		virtual void		  SetObjectVoiceType(BGSVoiceType* a_voiceType) override;																								  // 48 - { voiceType = a_voiceType; }
		virtual BGSVoiceType* GetObjectVoiceType() const override;																													  // 49 - { return voiceType; }

		// add
		virtual bool GetReflectedByAutoWater();	 // 53 - { return false; }


		// members
		TESObjectREFR* tempRef;	   // C8
		BGSVoiceType*  voiceType;  // D0 - VNAM
	};
	static_assert(sizeof(BGSTalkingActivator) == 0xD8);
}
