#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraWornLeft : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraWornLeft;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kWornLeft;


		virtual ~ExtraWornLeft();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kWorn; }
	};
	static_assert(sizeof(ExtraWornLeft) == 0x10);
}
