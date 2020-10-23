#pragma once

#include "RE/BSDevices/PlayerInputHandler/HeldStateHandler/HeldStateHandler.h"


namespace RE
{
	struct ActivateHandler : public HeldStateHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_ActivateHandler;


		virtual ~ActivateHandler();	 // 00

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;									// 01
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;	// 04

		constexpr inline void SetHeldButtonActionSuccess(bool a_success) noexcept { heldButtonActionSuccess = a_success; }


		// members
		std::uint8_t  unk18;					// 18
		std::uint8_t  unk19;					// 19
		bool		  heldButtonActionSuccess;	// 1A
		bool		  disabled;					// 1B
		std::uint32_t unk1C;					// 1C
	};
	static_assert(sizeof(ActivateHandler) == 0x20);
}
