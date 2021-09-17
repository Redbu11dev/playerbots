#include "botpch.h"
#include "../../playerbot.h"
#include "ChatCommandHandlerStrategy.h"

using namespace ai;

class ChatCommandActionNodeFactoryInternal : public NamedObjectFactory<ActionNode>
{
public:
    ChatCommandActionNodeFactoryInternal()
    {
        creators["tank attack chat shortcut"] = &tank_attack_chat_shortcut;
    }

private:
    static ActionNode* tank_attack_chat_shortcut(PlayerbotAI* ai)
    {
        return new ActionNode ("tank attack chat shortcut",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NextAction::array(0, new NextAction("attack my target", 100.0f), NULL));
    }
};

void ChatCommandHandlerStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    PassTroughStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "rep",
        NextAction::array(0, new NextAction("reputation", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "q",
        NextAction::array(0,
            new NextAction("query quest", relevance),
            new NextAction("query item usage", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "add all loot",
        NextAction::array(0, new NextAction("add all loot", relevance), new NextAction("loot", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "u",
        NextAction::array(0, new NextAction("use", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "c",
        NextAction::array(0, new NextAction("item count", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "items",
        NextAction::array(0, new NextAction("item count", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "inv",
        NextAction::array(0, new NextAction("item count", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "e",
        NextAction::array(0, new NextAction("equip", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "ue",
        NextAction::array(0, new NextAction("unequip", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "t",
        NextAction::array(0, new NextAction("trade", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "nt",
        NextAction::array(0, new NextAction("trade", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "s",
        NextAction::array(0, new NextAction("sell", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "b",
        NextAction::array(0, new NextAction("buy", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "r",
        NextAction::array(0, new NextAction("reward", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "attack",
        NextAction::array(0, new NextAction("attack my target", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "accept",
        NextAction::array(0, new NextAction("accept quest", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "follow",
        NextAction::array(0, new NextAction("follow chat shortcut", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "stay",
        NextAction::array(0, new NextAction("stay chat shortcut", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "flee",
        NextAction::array(0, new NextAction("flee chat shortcut", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "tank attack",
        NextAction::array(0, new NextAction("tank attack chat shortcut", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "grind",
        NextAction::array(0, new NextAction("grind chat shortcut", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "talk",
        NextAction::array(0, new NextAction("gossip hello", relevance), new NextAction("talk to quest giver", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "cast",
        NextAction::array(0, new NextAction("cast custom spell", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "castnc",
        NextAction::array(0, new NextAction("cast custom nc spell", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "revive",
        NextAction::array(0, new NextAction("spirit healer", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "runaway",
        NextAction::array(0, new NextAction("runaway chat shortcut", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "warning",
        NextAction::array(0, new NextAction("runaway chat shortcut", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "max dps",
        NextAction::array(0, new NextAction("max dps chat shortcut", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "attackers",
        NextAction::array(0, new NextAction("tell attackers", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "ready",
        NextAction::array(0, new NextAction("ready check", relevance), NULL)));
}



ChatCommandHandlerStrategy::ChatCommandHandlerStrategy(PlayerbotAI* ai) : PassTroughStrategy(ai)
{
    actionNodeFactories.Add(new ChatCommandActionNodeFactoryInternal());

    supported.push_back("quests");
    supported.push_back("stats");
    supported.push_back("leave");
    supported.push_back("reputation");
    supported.push_back("log");
    supported.push_back("los");
    supported.push_back("drop");
    supported.push_back("share");
    supported.push_back("ll");
    supported.push_back("ss");
    supported.push_back("release");
    supported.push_back("teleport");
    supported.push_back("taxi");
    supported.push_back("repair");
    supported.push_back("talents");
    supported.push_back("spells");
    supported.push_back("co");
    supported.push_back("nc");
    supported.push_back("de");
    supported.push_back("trainer");
    supported.push_back("chat");
    supported.push_back("home");
    supported.push_back("destroy");
    supported.push_back("reset ai");
    supported.push_back("emote");
    supported.push_back("buff");
    supported.push_back("help");
    supported.push_back("gb");
    supported.push_back("bank");
    supported.push_back("invite");
    supported.push_back("spell");
    supported.push_back("rti");
    supported.push_back("position");
    supported.push_back("summon");
    supported.push_back("who");
    supported.push_back("save mana");
    supported.push_back("formation");
    supported.push_back("stance");
    supported.push_back("sendmail");
    supported.push_back("mail");
    supported.push_back("outfit");
    supported.push_back("go");
    supported.push_back("debug");
    supported.push_back("cdebug");
    supported.push_back("cs");
    supported.push_back("wts");
    supported.push_back("hire");
    supported.push_back("craft");
    supported.push_back("flag");
    supported.push_back("range");
    supported.push_back("ra");
    supported.push_back("give leader");
    supported.push_back("cheat");
    supported.push_back("ginvite");
    supported.push_back("guild promote");
    supported.push_back("guild demote");
    supported.push_back("guild remove");
    supported.push_back("guild leave");
}
