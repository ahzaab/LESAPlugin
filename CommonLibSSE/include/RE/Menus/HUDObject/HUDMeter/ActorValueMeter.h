#pragma once

#include "RE/FormComponents/Enums/ActorValues.h"
#include "RE/Menus/HUDObject/HUDMeter/HUDMeter.h"


namespace RE
{
	class ActorValueMeter : public HUDMeter
	{
	public:
		inline static constexpr auto RTTI = RTTI_ActorValueMeter;


		virtual ~ActorValueMeter();	 // 00

		// override (HUDMeter)
		virtual bool  ProcessMessage(UIMessage* a_message) override;  // 02
		virtual float GetFillPct() override;						  // 05


		// members
		ActorValue	  actorValue;  // 48
		std::uint32_t pad4C;	   // 4C
	};
	static_assert(sizeof(ActorValueMeter) == 0x50);
}
