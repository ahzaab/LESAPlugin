#pragma once

#include "RE/BSCore/BSString.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESObject/TESObject.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class NiAVObject;
	class TESObjectREFR;


	class NiNPShortPoint3
	{
	public:
		// members
		std::int16_t x;	 // 0
		std::int16_t y;	 // 2
		std::int16_t z;	 // 4
	};
	static_assert(sizeof(NiNPShortPoint3) == 0x6);


	class TESBoundObject : public TESObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESBoundObject;


		struct BOUND_DATA  // OBND
		{
		public:
			// members
			NiNPShortPoint3 boundMin;  // 0
			NiNPShortPoint3 boundMax;  // 6
		};
		static_assert(sizeof(BOUND_DATA) == 0xC);


		virtual ~TESBoundObject();	// 00

		// override (TESObject)
		virtual void		LoadObjectBound(TESFile* a_mod) override;																												  // 26
		virtual bool		IsBoundObject() const override;																															  // 27 - { return true; }
		virtual bool		Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 37
		virtual NiAVObject* Clone3D(TESObjectREFR* a_ref, bool a_arg3) override;																									  // 40
		virtual bool		ReplaceModel() override;																																  // 44

		// add
		virtual void		  SetObjectVoiceType(BGSVoiceType* a_voiceType);												 // 48 - { return; }
		virtual BGSVoiceType* GetObjectVoiceType() const;																	 // 49 - { return 0; }
		virtual NiAVObject*	  Clone3D(TESObjectREFR* a_ref);																 // 4A - { Clone3D(a_ref, false); }
		virtual bool		  ReplaceModel(const char* a_str);																 // 4B
		virtual bool		  GetActivateText(TESObjectREFR* a_activator, BSString& a_dst);									 // 4C
		virtual bool		  CalculateDoFavor(Actor* a_activator, bool a_arg2, TESObjectREFR* a_toActivate, float a_arg3);	 // 4D
		virtual void		  HandleRemoveItemFromContainer(TESObjectREFR* a_container);									 // 4E - { return; }
		virtual void		  OnRemove3D(NiAVObject* a_obj3D);																 // 4F - { return; }
		virtual void		  OnCheckModels();																				 // 50 - { return; }
		virtual void		  OnCopyReference();																			 // 51 - { return; }
		virtual void		  OnFinishScale();																				 // 52 - { return; }


		// members
		BOUND_DATA	  boundData;  // 20 - OBND
		std::uint32_t pad2C;	  // 2C
	};
	static_assert(sizeof(TESBoundObject) == 0x30);
}
