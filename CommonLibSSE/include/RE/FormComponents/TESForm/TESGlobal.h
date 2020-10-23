#pragma once

#include "RE/BSCore/BSString.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESForm.h"


namespace RE
{
	class TESGlobal : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESGlobal;
		inline static constexpr auto FORMTYPE = FormType::Global;


		enum class Type
		{
			kFloat = 'f',
			kLong = 'l',
			kShort = 's'
		};


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kConstant = 1 << 6,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESGlobal();  // 00

		// override (TESform)
		virtual bool		Load(TESFile* a_mod) override;				  // 06
		virtual const char* GetFormEditorID() const override;			  // 32 - { return formEditorID.c_str(); }
		virtual bool		SetFormEditorID(const char* a_str) override;  // 33 - { formEditorID = a_str; return true; }


		// members
		BSString							 formEditorID;	// 20 - EDID
		stl::enumeration<Type, std::uint8_t> type;			// 30 - ENAM
		std::uint8_t						 pad31;			// 31
		std::uint16_t						 pad32;			// 32
		float								 value;			// 34 - FLTV
	};
	static_assert(sizeof(TESGlobal) == 0x38);
}
