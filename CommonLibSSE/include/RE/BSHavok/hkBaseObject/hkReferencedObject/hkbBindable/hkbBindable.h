#pragma once

#include "RE/BSHavok/hkArray.h"
#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkReferencedObject.h"
#include "RE/BSHavok/hkRefPtr/hkRefPtr.h"


namespace RE
{
	class hkRefVariant;
	class hkbVariableBindingSet;


	class hkbBindable : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbBindable;


		virtual ~hkbBindable();	 // 00

		// add
		virtual void Unk_03(void);	// 03


		// members
		hkRefPtr<hkbVariableBindingSet> variableBindingSet;	 // 10
		hkArray<hkRefVariant>			cachedBindables;	 // 18
		bool							areBindablesCached;	 // 28
		std::uint8_t					pad29;				 // 29
		std::uint16_t					pad2A;				 // 2A
		std::uint32_t					pad2C;				 // 2C
	};
	static_assert(sizeof(hkbBindable) == 0x30);
}
