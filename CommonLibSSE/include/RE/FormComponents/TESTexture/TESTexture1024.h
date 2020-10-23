#pragma once

#include "RE/FormComponents/TESTexture/TESTexture.h"


namespace RE
{
	class TESTexture1024 : public TESTexture
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESTexture1024;


		virtual ~TESTexture1024();	// 00

		// override (TESTexture)
		virtual std::uint32_t GetMaxAllowedSize() override;	 // 04 - { return 1024; }
	};
	static_assert(sizeof(TESTexture1024) == 0x10);
}
