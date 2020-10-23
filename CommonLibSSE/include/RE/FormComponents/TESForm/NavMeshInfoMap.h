#pragma once

#include "RE/BSCore/BSAtomic.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/BSCore/BSTHashMap.h"
#include "RE/BSPathFinding/BSNavmeshInfoMap.h"
#include "RE/BSPathFinding/BSPrecomputedNavmeshInfoPathMap/PrecomputedNavmeshInfoPathMap.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESForm.h"


namespace RE
{
	struct NavMeshInfo;


	class NavMeshInfoMap :
		public TESForm,						  // 00
		public BSNavmeshInfoMap,			  // 20
		public PrecomputedNavmeshInfoPathMap  // 30
	{
	public:
		inline static constexpr auto RTTI = RTTI_NavMeshInfoMap;
		inline static constexpr auto FORMTYPE = FormType::Navigation;


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};


		virtual ~NavMeshInfoMap();	// 00

		// override (TESForm)
		virtual bool Load(TESFile* a_mod) override;	   // 06
		virtual void InitItemImpl() override;		   // 13
		virtual void SetAltered(bool a_set) override;  // 24

		// override (BSNavmeshInfoMap)

		virtual BSNavmeshInfo* GetNavMeshInfoFixID(std::uint32_t a_id) override;													  // 01
		virtual BSNavmeshInfo* GetNavmeshInfo(std::uint32_t a_id) override;															  // 02
		virtual void		   GetAllNavMeshInfo(BSTArray<BSNavmeshInfo*>& a_results) override;										  // 03
		virtual void		   BuildListOfConnectedInfos(const BSNavmeshInfo* a_info, BSTArray<BSNavmeshInfo*>& a_results) override;  // 04
		virtual void		   ForEach(IVisitor* a_visitor) override;																  // 05


		// members
		bool												 updateAll;			// 78
		std::uint8_t										 pad79;				// 79
		std::uint16_t										 pad7A;				// 7A
		std::uint32_t										 pad7C;				// 7C
		BSTHashMap<std::uint32_t, NavMeshInfo*>				 infoMap;			// 80
		BSTHashMap<std::uint64_t, BSTArray<BSNavmeshInfo*>*> ckNavMeshInfoMap;	// B0
		mutable BSReadWriteLock								 mapLock;			// E0
		bool												 init;				// E8
		std::uint8_t										 padE9;				// E9
		std::uint16_t										 padEA;				// EA
		std::uint32_t										 padEC;				// EC
	};
	static_assert(sizeof(NavMeshInfoMap) == 0xF0);
}
