#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class NavMesh;


	struct NAVMESH_PORTAL
	{
		union Nav
		{
			FormID	 navMeshID;
			NavMesh* navMesh;
		};
		static_assert(sizeof(Nav) == 0x8);


		Nav			  nav;		 // 00
		std::uint16_t triIndex;	 // 08
		std::uint16_t pad0A;	 // 0A
		std::uint32_t pad0C;	 // 0C
	};
	static_assert(sizeof(NAVMESH_PORTAL) == 0x10);


	class ExtraNavMeshPortal : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraNavMeshPortal;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kNavMeshPortal;


		virtual ~ExtraNavMeshPortal();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kNavMeshPortal; }


		// members
		NAVMESH_PORTAL portal;	// 10
	};
	static_assert(sizeof(ExtraNavMeshPortal) == 0x20);
}
