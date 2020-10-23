#pragma once

#include "RE/Scaleform/GRefCount/GRefCountImplCore.h"


namespace RE
{
	class GRefCountImpl : GRefCountImplCore
	{
	public:
		inline static constexpr auto RTTI = RTTI_GRefCountImpl;


		virtual ~GRefCountImpl() = default;	 // 00

		void AddRef();
		void Release();
	};
	static_assert(sizeof(GRefCountImpl) == 0x10);
}
