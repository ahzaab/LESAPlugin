#pragma once

#include "RE/Animation/BSAnimNoteListener.h"
#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSTHashMap.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiTimeController/NiTimeController.h"
#include "RE/NetImmerse/NiSmartPointer.h"
#include "RE/NetImmerse/NiTArray.h"
#include "RE/NetImmerse/NiTSet.h"


namespace RE
{
	class NiAVObjectPalette;
	class NiControllerSequence;


	class NiControllerManager : public NiTimeController
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiControllerManager;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiControllerManager;


		virtual ~NiControllerManager();	 // 00

		// override (NiTimeController)
		virtual const NiRTTI*		 GetRTTI() const override;							  // 02
		virtual NiObject*			 CreateClone(NiCloningProcess& a_cloning) override;	  // 17
		virtual void				 LoadBinary(NiStream& a_stream) override;			  // 18
		virtual void				 LinkObject(NiStream& a_stream) override;			  // 19
		virtual bool				 RegisterStreamables(NiStream& a_stream) override;	  // 1A
		virtual void				 SaveBinary(NiStream& a_stream) override;			  // 1B
		virtual bool				 IsEqual(NiObject* a_object) override;				  // 1C
		virtual void				 ProcessClone(NiCloningProcess& a_cloning) override;  // 1D
		virtual void				 PostLinkObject(NiStream& a_stream) override;		  // 1E
		virtual NiControllerManager* AsNiControllerManager() override;					  // 24 - { return this; }
		virtual void				 Start(float a_time) override;						  // 25
		virtual void				 Stop() override;									  // 26
		virtual void				 Update(float a_time) override;						  // 27
		virtual void				 SetTarget(NiObjectNET* a_target) override;			  // 28
		virtual bool				 TargetIsRequiredType() const override;				  // 2E

		// add
		virtual void Start();  // 2F - { return; }

		NiControllerSequence* GetSequenceByName(std::string_view a_name);


		// members
		NiTObjectArray<NiPointer<NiControllerSequence>>	 sequenceArray;	   // 48
		NiTPrimitiveSet<NiControllerSequence*>			 activeSequences;  // 60
		BSTHashMap<BSFixedString, NiControllerSequence*> stringMap;		   // 70
		BSAnimNoteListener*								 listener;		   // A0
		bool											 cumulative;	   // A8
		std::uint8_t									 padA9;			   // A9
		std::uint16_t									 padAA;			   // AA
		std::uint32_t									 padAC;			   // AC
		NiTObjectSet<NiPointer<NiControllerSequence>>	 tempBlendSeqs;	   // B0
		NiPointer<NiAVObjectPalette>					 objectPalette;	   // C0
	};
	static_assert(sizeof(NiControllerManager) == 0xC8);
}
