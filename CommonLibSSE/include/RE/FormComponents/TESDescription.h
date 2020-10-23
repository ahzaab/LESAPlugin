#pragma once

#include "RE/BSCore/BGSLocalizedStringDL.h"
#include "RE/BSCore/BSString.h"
#include "RE/FormComponents/BaseFormComponent.h"


namespace RE
{
	class TESForm;


	class TESDescription : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESDescription;


		virtual ~TESDescription();	// 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		void GetDescription(BSString& a_out, TESForm* a_parent, std::uint32_t a_fieldType = 'CSED');


		// members
		std::uint32_t		 fileOffset;	   // 08
		BGSLocalizedStringDL descriptionText;  // 0C
	};
	static_assert(sizeof(TESDescription) == 0x10);
}
