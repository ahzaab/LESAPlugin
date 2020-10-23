#pragma once

#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESObjectACTI/TESObjectACTI.h"
#include "RE/FormComponents/TESProduceForm.h"


namespace RE
{
	class TESFlora :
		public TESObjectACTI,  // 00
		public TESProduceForm  // C8
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESFlora;
		inline static constexpr auto FORMTYPE = FormType::Flora;


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESFlora();  // 00

		// override (TESObjectACTI)
		virtual bool Load(TESFile* a_mod) override;																															   // 06
		virtual void InitItemImpl() override;																																   // 13
		virtual bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 37
		virtual bool GetActivateText(TESObjectREFR* a_activator, BSString& a_dst) override;																					   // 4C
		virtual bool CalculateDoFavor(Actor* a_activator, bool a_arg2, TESObjectREFR* a_toActivate, float a_arg3) override;													   // 4D
	};
	static_assert(sizeof(TESFlora) == 0xE8);
}
