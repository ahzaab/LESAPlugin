#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraGhost : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraGhost;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kGhost;


		virtual ~ExtraGhost();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kGhost; }


		// members
		bool		  ghost;  // 10
		std::uint8_t  pad11;  // 11
		std::uint16_t pad12;  // 12
		std::uint32_t pad14;  // 14
	};
	static_assert(sizeof(ExtraGhost) == 0x18);
}
