#pragma once

#include "RE/BSAudio/BSISoundDescriptor/BGSSoundDescriptor.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/BSResource/FileID/ID.h"
#include "RE/FormComponents/Enums/FormTypes.h"


namespace RE
{
	class TESCondition;


	class BGSStandardSoundDef : public BGSSoundDescriptor
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSStandardSoundDef;


		struct SoundPlaybackCharacteristics : public BSISoundDescriptor::BSIPlaybackCharacteristics	 // BNAM
		{
		public:
			inline static constexpr auto RTTI = RTTI_BGSStandardSoundDef__SoundPlaybackCharacteristics;


			// override (BSIPlaybackCharacteristics)
			virtual std::uint8_t  GetFrequencyShift() override;		// 01 - { return frequencyShift; }
			virtual std::uint8_t  GetFrequencyVariance() override;	// 02 - { return frequencyVariance; }
			virtual std::uint8_t  GetPriority() override;			// 03 - { return priority; }
			virtual std::uint16_t GetStaticAttenuation() override;	// 04 - { return staticAttenuation; }
			virtual std::uint8_t  GetDBVariance() override;			// 05 - { return dbVariance; }


			// members
			std::uint8_t  frequencyShift;	  // 08
			std::uint8_t  frequencyVariance;  // 09
			std::uint8_t  priority;			  // 0A
			std::uint8_t  dbVariance;		  // 0B
			std::uint16_t staticAttenuation;  // 0C - CK Value * 100
			std::uint16_t pad0E;			  // 0E
		};
		static_assert(sizeof(SoundPlaybackCharacteristics) == 0x10);


		struct LengthCharacteristics  // LNAM
		{
			enum class Looping
			{
				kNone = 0,
				kLoop = 1 << 3,
				kEnvelopeFast = 1 << 4,
				kEnvelopeSlow = 1 << 5
			};


			std::uint8_t							unk0;			  // 0
			stl::enumeration<Looping, std::uint8_t> looping;		  // 1
			std::uint8_t							unk2;			  // 2
			std::uint8_t							rumbleSendValue;  // 3
		};
		static_assert(sizeof(LengthCharacteristics) == 0x4);


		virtual ~BGSStandardSoundDef();	 // 00

		// override (BGSSoundDescriptor)
		virtual void		  Unk_01(void) override;			   // 01
		virtual void		  Unk_02(void) override;			   // 02
		virtual void		  InitSound(TESForm* a_src) override;  // 03
		virtual bool		  LoadSound(TESFile* a_mod) override;  // 04
		virtual std::uint32_t GetType() const override;			   // 05 - "BGSStandardSoundDef"
		virtual void		  Unk_06(void) override;			   // 06


		// members
		BSTArray<BSResource::ID>	 soundFiles;			 // 18 - ANAM
		SoundPlaybackCharacteristics soundCharacteristics;	 // 30 - BNAM
		TESCondition*				 conditions;			 // 40 - CTDA
		BGSSoundOutput*				 outputModel;			 // 48 - ONAM
		LengthCharacteristics		 lengthCharacteristics;	 // 50 - LNAM
		std::int32_t				 unk54;					 // 54
	};
	static_assert(sizeof(BGSStandardSoundDef) == 0x58);
}
