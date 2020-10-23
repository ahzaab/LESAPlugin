#pragma once

#include "RE/BSResource/FileID/ID.h"
#include "RE/FormComponents/Components/Color.h"
#include "RE/FormComponents/Components/DecalData.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundObject.h"
#include "RE/FormComponents/TESTexture/TESTexture.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSTextureSet.h"


namespace RE
{
	class BGSTextureSet :
		public TESBoundObject,	// 00
		public BSTextureSet		// 30
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSTextureSet;
		inline static constexpr auto FORMTYPE = FormType::TextureSet;


		enum class Flag
		{
			kNone = 0,
			kNoSpecularMap = 1 << 0,
			kFacegenTextures = 1 << 1,
			kHasModelSpaceNormalMap = 1 << 2
		};


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSTextureSet();  // 00

		// override (TESBoundObject)
		virtual void		InitializeData() override;							  // 04
		virtual void		ClearData() override;								  // 05
		virtual bool		Load(TESFile* a_mod) override;						  // 06
		virtual NiAVObject* Clone3D(TESObjectREFR* a_ref, bool a_arg3) override;  // 40
		virtual void		UnClone3D(TESObjectREFR* a_ref) override;			  // 41


		// members
		TESTexture							  textures[Textures::kTotal];		 // 040 - TX00 - TX07
		DecalData*							  decalData;						 // 0C0 - DODT
		stl::enumeration<Flag, std::uint16_t> flags;							 // 0C8 - DNAM
		std::uint16_t						  pad0CA;							 // 0CA
		BSResource::ID						  textureFileIDs[Textures::kTotal];	 // 0CC
		std::uint32_t						  pad12C;							 // 12C
	};
	static_assert(sizeof(BGSTextureSet) == 0x130);
}
