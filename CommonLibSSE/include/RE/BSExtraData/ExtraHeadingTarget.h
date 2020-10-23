#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraHeadingTarget : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraHeadingTarget;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kHeadingTarget;


		virtual ~ExtraHeadingTarget();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kHeadingTarget; }


		// members
		ObjectRefHandle target;	 // 10
		std::uint32_t	pad14;	 // 14
	};
	static_assert(sizeof(ExtraHeadingTarget) == 0x18);
}
