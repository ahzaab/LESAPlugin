#pragma once

#include "RE/Menus/IMenu/Components/JournalTab/JournalTab.h"
#include "RE/Scaleform/GFxPlayer/GFxValue.h"


namespace RE
{
	class Journal_QuestsTab : public JournalTab
	{
	public:
		inline static constexpr auto RTTI = RTTI_Journal_QuestsTab;


		virtual ~Journal_QuestsTab();  // 00

		// override (JournalTab)
		virtual void Accept(CallbackProcessor* a_cbReg) override;  // 01


		// members
		GFxValue	  unk18;  // 18
		bool		  unk30;  // 30
		std::uint8_t  unk31;  // 31
		std::uint16_t unk32;  // 32
		std::uint32_t unk34;  // 34
	};
	static_assert(sizeof(Journal_QuestsTab) == 0x38);
}
