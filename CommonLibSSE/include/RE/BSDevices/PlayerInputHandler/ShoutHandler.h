#pragma once

#include "RE/BSDevices/PlayerInputHandler/PlayerInputHandler.h"


namespace RE
{
	struct ShoutHandler : public PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_ShoutHandler;


		virtual ~ShoutHandler();  // 00

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;									// 01
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;	// 04


		// members
		std::uint64_t unk10;  // 10
		std::uint64_t unk18;  // 18
	};
	static_assert(sizeof(ShoutHandler) == 0x20);
}
