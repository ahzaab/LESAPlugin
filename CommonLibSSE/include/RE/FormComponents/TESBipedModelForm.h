#pragma once

#include "RE/FormComponents/BGSMessageIcon.h"
#include "RE/FormComponents/BaseFormComponent.h"
#include "RE/FormComponents/TESModel/TESModelRDT.h"
#include "RE/FormComponents/TESModel/TESModelTextureSwap.h"
#include "RE/FormComponents/TESTexture/TESIcon.h"


namespace RE
{
	class TESBipedModelForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESBipedModelForm;


		struct Sexes
		{
			enum
			{
				kMale = 0,
				kFemale,
				kTotal
			};
		};


		virtual ~TESBipedModelForm();  // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03


		// members
		TESModelTextureSwap worldModels[Sexes::kTotal];		// 08
		TESIcon				inventoryIcons[Sexes::kTotal];	// 78
		BGSMessageIcon		messageIcons[Sexes::kTotal];	// 98
		TESModelRDT			constraintTemplate;				// C8
	};
	static_assert(sizeof(TESBipedModelForm) == 0xF0);
}
