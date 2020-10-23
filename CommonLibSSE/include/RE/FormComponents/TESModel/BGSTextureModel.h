#pragma once

#include "RE/FormComponents/TESModel/TESModel.h"


namespace RE
{
	class BGSTextureModel : public TESModel
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSTextureModel;


		virtual ~BGSTextureModel();	 // 00

		// override (TESModel)
		virtual void SetModel(const char* a_model) override;  // 05
	};
	static_assert(sizeof(BGSTextureModel) == 0x28);
}
