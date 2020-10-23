#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraWorn : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraWorn;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kWorn;


		virtual ~ExtraWorn();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kWorn; }
	};
	static_assert(sizeof(ExtraWorn) == 0x10);
}
