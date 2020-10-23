#pragma once

#include "RE/Scaleform/GFxLog/GFxLogConstants.h"


namespace RE
{
	template <class Derived>
	class GFxLogBase : public GFxLogConstants
	{
	public:
		virtual ~GFxLogBase() {}  // 00

		// add
		virtual bool IsVerboseActionErrors() const { return true; }	 // 01
	};
	static_assert(sizeof(GFxLogBase<void*>) == 0x8);
}
