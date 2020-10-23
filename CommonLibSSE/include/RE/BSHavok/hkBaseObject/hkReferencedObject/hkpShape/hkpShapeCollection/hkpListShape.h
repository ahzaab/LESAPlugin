#pragma once

#include "RE/BSHavok/hkArray.h"
#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkpShape/hkpShapeCollection/hkpShapeCollection.h"
#include "RE/BSHavok/hkVector4.h"


namespace RE
{
	class hkpListShape : public hkpShapeCollection
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpListShape;


		enum
		{
			kMaxChildrenForSPUMidPhase = 252,
			kMaxDisabledChildren = 256
		};


		enum class ListShapeFlags
		{
			kNone = 0,
			kDisableSPUCacheForListChildInfo = 1 << 0
		};


		struct ChildInfo
		{
		public:
			// members
			alignas(0x10) const hkpShape* shape;	   // 00
			std::uint32_t		 collisionFilterInfo;  // 08
			mutable std::int32_t shapeSize;			   // 0C
			mutable std::int32_t numChildShapes;	   // 10
			std::uint32_t		 pad14;				   // 14
			std::uint64_t		 pad18;				   // 18
		};
		static_assert(sizeof(ChildInfo) == 0x20);


		virtual ~hkpListShape();  // 00

		// override (hkpShapeCollection)
		virtual void		 CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;											// 02
		virtual std::int32_t CalcSizeForSpu(const CalcSizeForSpuInput& a_input, std::int32_t a_spuBufferSizeLeft) const override;										// 06
		virtual void		 GetAabbImpl(const hkTransform& a_localToWorld, float a_tolerance, hkAabb& a_out) const override;											// 07
		virtual bool		 CastRayImpl(const hkpShapeRayCastInput& a_input, hkpShapeRayCastOutput& a_output) const override;											// 08
		virtual void		 CastRayWithCollectorImpl(const hkpShapeRayCastInput& a_input, const hkpCdBody& a_cdBody, hkpRayHitCollector& a_collector) const override;	// 09

		// override (hkpShapeContainer)
		virtual std::int32_t	GetNumChildShapes() const override;											// 01 - { return m_childInfo.getSize() - m_numDisabledChildren; }
		virtual hkpShapeKey		GetFirstKey() const override;												// 02 - { return hkpListShape::getNextKey(hkpShapeKey(-1)); }
		virtual hkpShapeKey		GetNextKey(hkpShapeKey a_oldKey) const override;							// 03
		virtual std::uint32_t	GetCollisionFilterInfo(hkpShapeKey a_key) const override;					// 04
		virtual const hkpShape* GetChildShape(hkpShapeKey a_key, hkpShapeBuffer& a_buffer) const override;	// 05


		// members
		hkArray<ChildInfo> childInfo;			 // 30
		std::uint16_t	   flags;				 // 40
		std::uint16_t	   numDisabledChildren;	 // 42
		std::uint32_t	   pad44;				 // 44
		hkVector4		   aabbHalfExtents;		 // 50
		hkVector4		   aabbCenter;			 // 60
		std::uint32_t	   enabledChildren[8];	 // 70
	};
	static_assert(sizeof(hkpListShape) == 0x90);
}
