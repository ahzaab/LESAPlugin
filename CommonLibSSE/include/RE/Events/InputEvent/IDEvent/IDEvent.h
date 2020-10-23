#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/Events/InputEvent/InputEvent.h"


namespace RE
{
	class IDEvent : public InputEvent
	{
	public:
		inline static constexpr auto RTTI = RTTI_IDEvent;


		virtual ~IDEvent();	 // 00

		// override
		virtual bool				 HasIDCode() const override;   // 01 - { return true; }
		virtual const BSFixedString& QUserEvent() const override;  // 02 - { return userEvent; }

		[[nodiscard]] constexpr std::uint32_t GetIDCode() const noexcept { return idCode; }


		// members
		BSFixedString userEvent;  // 18
		std::uint32_t idCode;	  // 20
		std::uint32_t pad24;	  // 24
	};
	static_assert(sizeof(IDEvent) == 0x28);
}
