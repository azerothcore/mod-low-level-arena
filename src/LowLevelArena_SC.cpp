/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 * Copyright (C) 2021+ WarheadCore <https://github.com/WarheadCore>
 */

#include "LowLevelArena.h"
#include "Log.h"
#include "ScriptMgr.h"
#include "Config.h"
#include "Chat.h"
#include "Player.h"
#include "ScriptedGossip.h"

#ifndef STRING_VIEW_FMT
#define STRING_VIEW_FMT "%.*s"
#define STRING_VIEW_FMT_ARG(str) static_cast<int>((str).length()), (str).data()
#endif

//class LowLevelArena_BG : public BGScript
//{
//public:
//    LowLevelArena_BG() : BGScript("LowLevelArena_BG") { }
//
//    void OnBattlegroundEnd(Battleground* bg, TeamId winnerTeamId) override
//    {
//        if (!sConfigMgr->GetOption<bool>("LLA.Enable", false))
//            return;
//
//        // Not reward for bg or rated arena
//        if (bg->isBattleground() || bg->isRated())
//        {
//            return;
//        }
//
//        sLLA->Reward(bg, winnerTeamId);
//    }
//};

class LowLevelArena_Command : public CommandScript
{
public:
    LowLevelArena_Command() : CommandScript("LowLevelArena_Command") {}

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> llaCommandTable =
        {
            { "queue",  SEC_PLAYER, false,  &HandleLLAQueue, "" },
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "lla",    SEC_PLAYER, false, nullptr, "", llaCommandTable }
        };

        return commandTable;
    }

    static bool AddQueue(Player* player)
    {
        ChatHandler handler(player->GetSession());

        if (!sConfigMgr->GetOption<bool>("LLA.Enable", false))
        {
            handler.PSendSysMessage("> Module disable!");
            return true;
        }

        // Join arena queue
        sLLA->AddQueue(player);

        return true;
    }

    static bool HandleLLAQueue(ChatHandler* handler, const char* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();
        if (!player)
            return false;

        if (!AddQueue(player))
        {
            handler->SetSentErrorMessage(true);
            return false;
        }

        return true;
    }
};

class LowLevelArena_World : public WorldScript
{
public:
    LowLevelArena_World() : WorldScript("LowLevelArena_World") { }

    void OnAfterConfigLoad(bool /*reload*/) override
    {
        // Add conigs options configiration
    }
};

// Group all custom scripts
void AddSC_LowLevelArena()
{
    //new LowLevelArena_BG();
    new LowLevelArena_Command();
    //new LowLevelArena_World();
}
