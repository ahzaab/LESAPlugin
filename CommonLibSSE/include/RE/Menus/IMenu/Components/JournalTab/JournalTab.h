#pragma once

#include "RE/Scaleform/FxGameDelegate/FxDelegateHandler.h"
#include "RE/Scaleform/GRefCount/GPtr.h"


namespace RE
{
	class GFxMovieView;


	class JournalTab : public FxDelegateHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_JournalTab;


		virtual ~JournalTab();	// 00

		// add
		virtual void Unk_02(void);	// 02 - { return; }
		virtual void Unk_03(void);	// 03 - { return; }


		// members
		GPtr<GFxMovieView> view;  // 10
	};
	static_assert(sizeof(JournalTab) == 0x18);
}
