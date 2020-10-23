#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraRefractionProperty : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraRefractionProperty;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kRefractionProperty;


		virtual ~ExtraRefractionProperty();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kRefractionProperty; }


		// members
		float		  refractionPower;	// 10
		std::uint32_t unk14;			// 14
	};
	static_assert(sizeof(ExtraRefractionProperty) == 0x18);
}
