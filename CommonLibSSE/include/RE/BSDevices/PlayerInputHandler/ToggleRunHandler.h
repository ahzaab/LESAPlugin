#pragma once

#include "RE/BSDevices/PlayerInputHandler/PlayerInputHandler.h"


namespace RE
{
	struct ToggleRunHandler : public PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_ToggleRunHandler;


		virtual ~ToggleRunHandler();  // 00

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;									// 01
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;	// 04
	};
	static_assert(sizeof(ToggleRunHandler) == 0x10);
}
