#pragma once

#include "RE/BSCore/BSAtomic.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"
#include "RE/FormComponents/Enums/FormTypes.h"


namespace RE
{
	class BGSBaseAlias;


	struct BGSRefAliasInstanceData
	{
		TESQuest*					 quest;				 // 00
		const BGSBaseAlias*			 alias;				 // 08
		const BSTArray<TESPackage*>* instancedPackages;	 // 10
	};
	static_assert(sizeof(BGSRefAliasInstanceData) == 0x18);


	class ExtraAliasInstanceArray : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraAliasInstanceArray;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kAliasInstanceArray;


		ExtraAliasInstanceArray();
		virtual ~ExtraAliasInstanceArray();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kAliasInstanceArray; }


		// members
		BSTArray<BGSRefAliasInstanceData*> aliases;	 // 10
		mutable BSReadWriteLock			   lock;	 // 28
	};
	static_assert(sizeof(ExtraAliasInstanceArray) == 0x30);
}
