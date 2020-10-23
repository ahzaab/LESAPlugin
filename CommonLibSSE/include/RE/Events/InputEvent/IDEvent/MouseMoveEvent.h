#pragma once

#include "RE/Events/InputEvent/IDEvent/IDEvent.h"


namespace RE
{
	class MouseMoveEvent : public IDEvent
	{
	public:
		inline static constexpr auto RTTI = RTTI_MouseMoveEvent;


		virtual ~MouseMoveEvent();	// 00


		// members
		std::int32_t mouseInputX;  // 28
		std::int32_t mouseInputY;  // 2C
	};
	static_assert(sizeof(MouseMoveEvent) == 0x30);
}
