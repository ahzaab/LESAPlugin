#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class SeenData;


	class ExtraSeenData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraSeenData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kSeenData;


		virtual ~ExtraSeenData();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kSeenData; }


		// members
		SeenData* seenData;	 // 10
	};
	static_assert(sizeof(ExtraSeenData) == 0x18);
}
