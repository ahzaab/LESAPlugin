#pragma once


namespace RE
{
	namespace BSResource
	{
		struct Info
		{
		public:
			// members
			FILETIME	  modifyTime;  // 00
			FILETIME	  createTime;  // 08
			LARGE_INTEGER fileSize;	   // 10
		};
		static_assert(sizeof(Info) == 0x18);
	}
}
