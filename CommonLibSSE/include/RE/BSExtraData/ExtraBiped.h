#pragma once

#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class BipedAnim;


	class ExtraBiped : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraBiped;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kBiped;


		virtual ~ExtraBiped();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kBiped; }


		// members
		BSTSmartPointer<BipedAnim> biped;  // 10
	};
	static_assert(sizeof(ExtraBiped) == 0x18);
}
