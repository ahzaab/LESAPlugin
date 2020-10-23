#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSCore/BSString.h"
#include "RE/Menus/IUIMessageData/IUIMessageData.h"


namespace RE
{
	class NiBinaryStream;


	class ConsoleData : public IUIMessageData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ConsoleData;


		enum class DataType
		{
		};


		virtual ~ConsoleData();	 // 00


		// members
		BSString*								  str;		// 10
		ObjectRefHandle							  pickRef;	// 18
		std::uint32_t							  pad1C;	// 1C
		NiBinaryStream*							  file;		// 20
		stl::enumeration<DataType, std::uint32_t> type;		// 28
		std::uint32_t							  pad2C;	// 2C
	};
	static_assert(sizeof(ConsoleData) == 0x30);
}
