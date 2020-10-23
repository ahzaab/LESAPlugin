#pragma once

#include "RE/BSCore/BSAtomic.h"
#include "RE/Memory/IMemoryStoreBase/IMemoryStoreBase.h"


namespace RE
{
	namespace CompactingStore
	{
		class BlockHeader;
		class FreeBlock;
		class StoreBlock;


		class Store : public IMemoryStoreBase
		{
		public:
			inline static constexpr auto RTTI = RTTI_CompactingStore__Store;


			virtual ~Store();  // 00

			// override (IMemoryStoreBase)
			virtual std::size_t Size(const void* a_block) const override;				// 01
			virtual void		GetMemoryStats(MemoryStats* a_stats) override;			// 02
			virtual bool		ContainsBlockImpl(const void* a_block) const override;	// 03


			// members
			BSNonReentrantSpinLock lock;
			void*				   allocBase;
			void*				   allocEndMin;
			void*				   allocEnd;
			void*				   storeEnd;
			BlockHeader*		   lastBlock;
			FreeBlock*			   smallFree[66];
			FreeBlock*			   currentFree;
			FreeBlock*			   nextMerge;
			StoreBlock*			   storeBlockMin;
			StoreBlock*			   nextStoreBlock;
			StoreBlock*			   freeStoreBlockList;
			std::uint32_t		   currentThread;
			std::size_t			   allocated;
			std::uint32_t		   numAllocatedBlocks;
			std::size_t			   free;
			std::uint32_t		   numFreeBlocks;
			std::uint32_t		   compacted;
			std::uint32_t		   batchDeallocateTlsSlot;
		};
		static_assert(sizeof(Store) == 0x2A0);
	}
}
