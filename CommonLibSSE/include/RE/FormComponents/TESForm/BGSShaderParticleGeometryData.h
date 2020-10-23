#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESForm.h"
#include "RE/FormComponents/TESTexture/TESTexture.h"


namespace RE
{
	union SETTING_VALUE
	{
		float		  f;
		std::uint32_t i;
	};
	static_assert(sizeof(SETTING_VALUE) == 0x4);


	class BGSShaderParticleGeometryData : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSShaderParticleGeometryData;
		inline static constexpr auto FORMTYPE = FormType::ShaderParticleGeometryData;


		enum class DataID
		{
			kGravityVelocity = 0,
			kRotationVelocity,
			kParticleSizeX,
			kParticleSizeY,
			kCenterOffsetMin,
			kCenterOffsetMax,
			kStartRotationRange,
			kNumSubtexturesX,
			kNumSubtexturesY,
			kParticleType,
			kBoxSize,
			kParticleDensity,

			kTotal
		};


		enum class ParticleType
		{
			kRain = 0,
			kSnow = 1
		};


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSShaderParticleGeometryData();  // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		BSTArray<SETTING_VALUE> data;			  // 20 - DATA - size == DataID::kTotal
		TESTexture				particleTexture;  // 38 - ICON
	};
	static_assert(sizeof(BGSShaderParticleGeometryData) == 0x48);
}
