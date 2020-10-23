#pragma once

#include "RE/Events/InputEvent/IDEvent/IDEvent.h"


namespace RE
{
	class ThumbstickEvent : public IDEvent
	{
	public:
		inline static constexpr auto RTTI = RTTI_ThumbstickEvent;


		struct InputTypes
		{
			enum InputType : std::uint32_t
			{
				kLeftThumbstick = 0x0B,
				kRightThumbstick = 0x0C
			};
		};
		using InputType = InputTypes::InputType;


		bool IsLeft() const;
		bool IsRight() const;


		// members
		float xValue;  // 28
		float yValue;  // 2C
	};
	static_assert(sizeof(ThumbstickEvent) == 0x30);
}
