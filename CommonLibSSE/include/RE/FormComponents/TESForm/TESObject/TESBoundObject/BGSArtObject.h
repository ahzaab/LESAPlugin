#pragma once

#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundObject.h"
#include "RE/FormComponents/TESModel/TESModelTextureSwap.h"


namespace RE
{
	class BGSArtObject :
		public TESBoundObject,		// 00
		public TESModelTextureSwap	// 30
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSArtObject;
		inline static constexpr auto FORMTYPE = FormType::ArtObject;


		enum class ArtType
		{
			kMagicCastingArt = 0,
			kMagicHitEffect = 1,
			kMagicEnchantEffect = 2
		};


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	 // DNAM
		{
		public:
			// members
			stl::enumeration<ArtType, std::uint32_t> artType;  // 0
		};
		static_assert(sizeof(Data) == 0x4);


		virtual ~BGSArtObject();  // 00

		// override (TESBoundObject)
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		Data		  data;	  // 68 - DNAM
		std::uint32_t pad6C;  // 6C
	};
	static_assert(sizeof(BGSArtObject) == 0x70);
}
