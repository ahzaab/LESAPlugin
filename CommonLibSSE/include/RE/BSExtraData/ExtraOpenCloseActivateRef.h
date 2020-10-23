#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraOpenCloseActivateRef : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraOpenCloseActivateRef;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kOpenCloseActivateRef;


		virtual ~ExtraOpenCloseActivateRef();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kOpenCloseActivateRef; }


		// members
		ObjectRefHandle activateRef;  // 10
		std::uint32_t	pad14;		  // 14
	};
	static_assert(sizeof(ExtraOpenCloseActivateRef) == 0x18);
}
