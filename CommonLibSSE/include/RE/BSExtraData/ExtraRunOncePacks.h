#pragma once

#include "RE/BSCore/BSTList.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	struct RunOncePackage
	{
		TESPackage*	  package;	// 00
		std::int8_t	  day;		// 08
		std::uint8_t  pad09;	// 09
		std::uint16_t pad0A;	// 0A
		std::uint32_t pad0C;	// 0C
	};
	static_assert(sizeof(RunOncePackage) == 0x10);


	class ExtraRunOncePacks : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraRunOncePacks;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kRunOncePacks;


		virtual ~ExtraRunOncePacks();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kRunOncePacks; }


		// members
		BSSimpleList<RunOncePackage*>* packages;  // 10
	};
	static_assert(sizeof(ExtraRunOncePacks) == 0x18);
}
