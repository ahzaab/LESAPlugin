#pragma once

#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESInitScriptEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> objectInitialized;	 // 0
	};
	static_assert(sizeof(TESInitScriptEvent) == 0x8);
}
