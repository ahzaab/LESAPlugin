#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class QueuedFile;


	class ExtraRaceData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraRaceData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kRaceData;


		virtual ~ExtraRaceData();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kRaceData; }


		// members
		NiPointer<QueuedFile> preloadedRaceData;  // 10
	};
	static_assert(sizeof(ExtraRaceData) == 0x18);
}
