#pragma once

#include "RE/NetImmerse/NiTMapBase/NiTMap/NiTStringMap.h"


namespace RE
{
	// 28
	template <class T>
	class BSTCaseInsensitiveStringMap : public NiTStringMap<T>
	{
	private:
		using base = NiTStringMap<T>;

	public:
		using key_type = base::key_type;


		virtual ~BSTCaseInsensitiveStringMap();	 // 00

		// override (NiTStringMap<T>)
		virtual std::uint32_t hash_function(key_type a_key) const override;			  // 01
		virtual bool		  key_eq(key_type a_lhs, key_type a_rhs) const override;  // 02
	};
}
