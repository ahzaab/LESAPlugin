#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	struct OcclusionPlaneLinkedRefData
	{
		ObjectRefHandle linkedRefs[4];	// 00
	};
	static_assert(sizeof(OcclusionPlaneLinkedRefData) == 0x10);


	class ExtraOcclusionPlaneRefData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraOcclusionPlaneRefData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kOcclusionPlaneRefData;


		virtual ~ExtraOcclusionPlaneRefData();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kOcclusionPlaneRefData; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		OcclusionPlaneLinkedRefData* data;	// 10
	};
	static_assert(sizeof(ExtraOcclusionPlaneRefData) == 0x18);
}
