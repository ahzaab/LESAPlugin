#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraAnimNoteReceiver : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraAnimNoteReceiver;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kAnimNoteReceiver;


		virtual ~ExtraAnimNoteReceiver();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kAnimNoteReceiver; }


		// members
		void* unk10;  // 10
	};
	static_assert(sizeof(ExtraAnimNoteReceiver) == 0x18);
}
