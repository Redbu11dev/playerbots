#pragma once

#include "../Action.h"

namespace ai
{
    class GuildAcceptAction : public Action {
    public:
        GuildAcceptAction(PlayerbotAI* ai) : Action(ai, "guild accept") {}
        virtual bool Execute(Event event);
    };
}
