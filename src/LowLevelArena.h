/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 * Copyright (C) 2021+ WarheadCore <https://github.com/WarheadCore>
 */

#ifndef _LOW_LEVEL_ARENA_H_
#define _LOW_LEVEL_ARENA_H_

#include "Common.h"
#include "SharedDefines.h"

class Battleground;
class Player;

class LLA
{
    LLA() = default;
    ~LLA() = default;

    LLA(LLA const&) = delete;
    LLA(LLA&&) = delete;
    LLA& operator= (LLA const&) = delete;
    LLA& operator= (LLA&&) = delete;

public:
    static LLA* instance();

    void Reward(Battleground* bg, TeamId winnerTeamId);
    void LoadConfig();
    void AddQueue(Player* leader, uint8 arenaType, bool joinAsGroup);
};

#define sLLA LLA::instance()

#endif /* _LOW_LEVEL_ARENA_H_ */
