#pragma once

#include "RE/FormComponents/Components/IPackageData/IPackageData.h"


namespace RE
{
	template <class Parent>
	class BGSNamedPackageData : public Parent
	{
	public:
		static_assert(std::is_base_of<IPackageData, Parent>::value);


		union Data
		{
			bool		  b;
			std::uint32_t i;
			float		  f;
			void*		  p;
		};
		static_assert(sizeof(Data) == 0x8);


		// override (IPackageData)
		virtual void InitPackage() override;							// 01 - { return; }
		virtual void LoadPackage(TESFile* a_mod) override;				// 02
		virtual void Assign(IPackageData* a_other) override;			// 03 - { return; }
		virtual bool IsNotEqual(IPackageData* a_other) const override;	// 04


		// members
		Data data;	// ??
	};
}
