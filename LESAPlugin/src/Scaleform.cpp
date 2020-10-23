#include "PCH.h"

#include "Scaleform.h"

#include "LevelUpMenu.h"

#include "SKSE/API.h"

namespace Scaleform
{
    void RegisterCallbacks()
    {
        logger::info("Registered all scaleform callbacks");
    }


    void RegisterCreators()
    {
        LevelUpMenu::Register();
        logger::info("Registered all scaleform creators");
    }
}
