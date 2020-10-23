#pragma once

#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESForm.h"


namespace RE
{
	class BGSReferenceEffect : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSReferenceEffect;
		inline static constexpr auto FORMTYPE = FormType::ReferenceEffect;


		enum class Flag
		{
			kNone = 0,
			kFaceTarget = 1 << 0,
			kAttachToCamera = 1 << 1,
			kInheritRotation = 1 << 2
		};


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	 // DATA
		{
		public:
			// members
			BGSArtObject*						  artObject;	 // 00
			TESEffectShader*					  effectShader;	 // 08
			stl::enumeration<Flag, std::uint32_t> flags;		 // 10
			std::uint32_t						  pad14;		 // 14
		};
		static_assert(sizeof(Data) == 0x18);


		virtual ~BGSReferenceEffect();	// 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		Data data;	// 20 - DATA
	};
	static_assert(sizeof(BGSReferenceEffect) == 0x38);
}
