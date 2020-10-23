#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/FormComponents/Enums/FormTypes.h"


namespace RE
{
	class BSIMusicTrack;


	class BSIMusicType
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSIMusicType;


		enum class Flag	 // FNAM
		{
			kNone = 0,
			kPlaysOneSelection = 1 << 0,
			kAbruptTransition = 1 << 1,
			kCycleTracks = 1 << 2,
			kMaintainTrackOrder = 1 << 3,
			kDucksCurrentTrack = 1 << 5,
			kDoesntQueue = 1 << 6
		};


		enum class MUSIC_STATUS
		{
			kInactive = 0,
			kPlaying = 1,
			kPaused = 2,
			kFinishing = 3,
			kFinished = 4
		};


		// add
		virtual void DoUpdate() = 0;								   // 00
		virtual void DoPlay() = 0;									   // 01
		virtual void DoPause() = 0;									   // 02
		virtual void DoFinish(bool a_arg1) = 0;						   // 03
		virtual void DoApplyDuckingAttenuation(std::uint16_t a_arg1);  // 04 - { return; }
		virtual void DoClearDucking();								   // 05 - { return; }
		virtual void DoPrepare();									   // 06 - { return; }

		virtual ~BSIMusicType();  // 07


		// members
		stl::enumeration<Flag, std::uint32_t>		  flags;			  // 08 - FNAM
		std::int8_t									  priority;			  // 0C
		std::int8_t									  padding;			  // 0D
		std::uint16_t								  ducksOtherMusicBy;  // 0E - ck value * 100 as a std::uint16_t
		float										  fadeTime;			  // 10 - WNAM
		std::uint32_t								  currentTrackIndex;  // 14
		BSTArray<std::uint32_t>						  trackHistory;		  // 18
		BSTArray<BSIMusicTrack*>					  tracks;			  // 30 - TNAM
		stl::enumeration<MUSIC_STATUS, std::uint32_t> typeStatus;		  // 48
		std::uint32_t								  pad4C;			  // 4C
	};
	static_assert(sizeof(BSIMusicType) == 0x50);
}
