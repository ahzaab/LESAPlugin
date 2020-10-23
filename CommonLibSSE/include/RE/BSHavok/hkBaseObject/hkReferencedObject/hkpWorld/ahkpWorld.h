#pragma once

#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkpWorld/hkpWorld.h"


namespace RE
{
	class ahkpWorld : public hkpWorld
	{
	public:
		inline static constexpr auto RTTI = RTTI_ahkpWorld;


		virtual ~ahkpWorld();  // 00


		// members
		std::uint64_t unk430;  // 430
		std::uint64_t unk438;  // 438
	};
	static_assert(sizeof(ahkpWorld) == 0x440);
}
