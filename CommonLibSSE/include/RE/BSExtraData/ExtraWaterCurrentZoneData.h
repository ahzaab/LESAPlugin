#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSCore/BSTHashMap.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"
#include "RE/NetImmerse/NiPoint3.h"


namespace RE
{
	namespace BSCurrent
	{
		struct Action;
	}


	class TESObjectCELL;


	class ExtraWaterCurrentZoneData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraWaterCurrentZoneData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kWaterCurrentZoneData;


		virtual ~ExtraWaterCurrentZoneData();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kWaterCurrentZoneData; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		BSTHashMap<ObjectRefHandle, BSCurrent::Action*> referenceToActionMap;  // 10
		BSCurrent::Action*								cellAction;			   // 40
		TESObjectCELL*									affectedCell;		   // 48
		NiPoint3										angularVelocity;	   // 50
		NiPoint3										linearVelocity;		   // 5C
	};
	static_assert(sizeof(ExtraWaterCurrentZoneData) == 0x68);
}
