#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraFlags : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraFlags;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kFlags;


		enum class Flag
		{
			kNone = 0,
			kBlockActivate = 1 << 0,
			kBlockPlayerActivate = 1 << 1,
			kBlockLoadEvents = 1 << 2,
			kBlockActivateText = 1 << 3,
			kPlayerHasTaken = 1 << 5
		};


		virtual ~ExtraFlags();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kFlags; }

		[[nodiscard]] constexpr bool IsActivationBlocked() const noexcept { return flags.all(Flag::kBlockActivate); }


		// members
		stl::enumeration<Flag, std::uint32_t> flags;  // 10
		std::uint32_t						  pad14;  // 14
	};
	static_assert(sizeof(ExtraFlags) == 0x18);
}
