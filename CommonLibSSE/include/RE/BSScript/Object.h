#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/BSScript/Variable.h"
#include "RE/Memory/MemoryManager.h"


namespace RE
{
	namespace BSScript
	{
		class ObjectTypeInfo;


		class Object
		{
		public:
			~Object();

			VMHandle					 GetHandle() const;
			ObjectTypeInfo*				 GetTypeInfo();
			const ObjectTypeInfo*		 GetTypeInfo() const;
			[[nodiscard]] constexpr bool IsConstructed() const noexcept { return constructed; }
			[[nodiscard]] constexpr bool IsInitialized() const noexcept { return initialized; }
			[[nodiscard]] constexpr bool IsValid() const noexcept { return valid; }

			void* Resolve(VMTypeID a_typeID) const;

			void		  IncRef();
			std::uint32_t DecRef();

			Variable*		GetProperty(const BSFixedString& a_name);
			const Variable* GetProperty(const BSFixedString& a_name) const;

			TES_HEAP_REDEFINE_NEW();


			// members
			std::uint32_t					constructed : 1;			// 00 - 0
			std::uint32_t					initialized : 1;			// 00 - 1
			std::uint32_t					valid : 1;					// 00 - 2
			std::uint32_t					remainingPropsToInit : 29;	// 00 - 3
			BSTSmartPointer<ObjectTypeInfo> type;						// 08
			BSFixedString					currentState;				// 10
			void*							lockStructure;				// 18 - first bit used as flag
			volatile VMHandle				handle;						// 20
			volatile std::int32_t			refCountAndHandleLock;		// 28
			std::uint32_t					pad2C;						// 2C
			Variable						variables[0];				// 30 - size == classPtr->GetTotalNumVariables() + 3

		private:
			void Dtor();
		};
		static_assert(sizeof(Object) == 0x30);
	}
}
