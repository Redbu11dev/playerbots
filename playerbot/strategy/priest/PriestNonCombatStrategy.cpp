#include "botpch.h"
#include "../../playerbot.h"
#include "PriestMultipliers.h"
#include "PriestNonCombatStrategy.h"
#include "PriestNonCombatStrategyActionNodeFactory.h"

using namespace ai;

PriestNonCombatStrategy::PriestNonCombatStrategy(PlayerbotAI* ai) : NonCombatStrategy(ai)
{
    actionNodeFactories.Add(new PriestNonCombatStrategyActionNodeFactory());
}

void PriestNonCombatStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    NonCombatStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "power word: fortitude",
        NextAction::array(0, new NextAction("power word: fortitude", 12.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "divine spirit",
        NextAction::array(0, new NextAction("divine spirit", 14.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "inner fire",
        NextAction::array(0, new NextAction("inner fire", 10.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "critical health",
        NextAction::array(0, new NextAction("greater heal", 70.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "party member critical health",
        NextAction::array(0, new NextAction("greater heal on party", 60.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "low health",
        NextAction::array(0, new NextAction("heal", 21.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "party member low health",
        NextAction::array(0, new NextAction("heal on party", 20.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "low aoe heal",
        NextAction::array(0, new NextAction("circle of healing", 26.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "medium aoe heal",
        NextAction::array(0, new NextAction("lightwell", 27.0f), NULL)));

	triggers.push_back(new TriggerNode(
		"party member dead",
		NextAction::array(0, new NextAction("remove shadowform", 20.0f), new NextAction("resurrection", 19.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "swimming",
        NextAction::array(0, new NextAction("levitate", 1.0f), NULL)));

    triggers.push_back(new TriggerNode(
       "often",
       NextAction::array(0, new NextAction("apply oil", 1.0f), NULL)));
}

void PriestBuffStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    NonCombatStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "prayer of fortitude on party",
        NextAction::array(0, new NextAction("prayer of fortitude on party", 12.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "prayer of spirit on party",
        NextAction::array(0, new NextAction("prayer of spirit on party", 14.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "power word: fortitude on party",
        NextAction::array(0, new NextAction("power word: fortitude on party", 11.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "divine spirit on party",
        NextAction::array(0, new NextAction("divine spirit on party", 13.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "fear ward",
        NextAction::array(0, new NextAction("fear ward", 10.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "touch of weakness",
        NextAction::array(0, new NextAction("touch of weakness", 10.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "shadowguard",
        NextAction::array(0, new NextAction("shadowguard", 10.0f), NULL)));
}

void PriestShadowResistanceStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    NonCombatStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "shadow protection",
        NextAction::array(0, new NextAction("shadow protection", 12.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "shadow protection on party",
        NextAction::array(0, new NextAction("shadow protection on party", 11.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "shadow protection on party",
        NextAction::array(0, new NextAction("shadow protection on party", 10.0f), NULL)));
}
