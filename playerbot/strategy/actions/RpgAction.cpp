#include "botpch.h"
#include "../../playerbot.h"
#include "RpgAction.h"
#include "../../ServerFacade.h"
#include "../values/Formations.h"
#include "EmoteAction.h"

using namespace ai;

bool RpgAction::Execute(Event event)
{    
    GuidPosition guidP = AI_VALUE(GuidPosition, "rpg target");

    if (!guidP && ai->GetMaster())
    {
        guidP = ai->GetMaster()->GetSelectionGuid();
        if (guidP)
        {
            RemIgnore(guidP);
            SET_AI_VALUE(GuidPosition,"rpg target",guidP);
        }
    }

    if (bot->GetShapeshiftForm() > 0)
        bot->SetShapeshiftForm(FORM_NONE);

    if(!SetNextRpgAction())
        RESET_AI_VALUE(GuidPosition, "rpg target");

    return true;
}

bool RpgAction::isUseful()
{
    return AI_VALUE(GuidPosition, "rpg target");
}

bool RpgAction::SetNextRpgAction()
{
    Strategy* rpgStrategy = ai->GetAiObjectContext()->GetStrategy("rpg");

    vector<Action*> actions;
    vector<uint32> relevances;
    list<TriggerNode*> triggerNodes;
    rpgStrategy->InitTriggers(triggerNodes);

    for (auto& triggerNode : triggerNodes)
    {
        Trigger* trigger = context->GetTrigger(triggerNode->getName());

        if (trigger)
        {

            triggerNode->setTrigger(trigger);

            NextAction** nextActions = triggerNode->getHandlers();

            Trigger* trigger = triggerNode->getTrigger();

            bool isChecked = false;

            for (int32 i = 0; i < NextAction::size(nextActions); i++)
            {
                NextAction* nextAction = nextActions[i];

                if (nextAction->getRelevance() > 2.0f)
                    continue;

                if (!isChecked && !trigger->IsActive())
                    break;

                isChecked = true;

                Action* action = ai->GetAiObjectContext()->GetAction(nextAction->getName());

                if (!action->isPossible() || !action->isUseful())
                    continue;

                actions.push_back(action);
                relevances.push_back((nextAction->getRelevance() - 1) * 1000);
            }
        }
    }

    if (actions.empty())
        return false;

    std::mt19937 gen(time(0));

    sTravelMgr.weighted_shuffle(actions.begin(), actions.end(), relevances.begin(), relevances.end(), gen);

    Action* action = actions.front();

    SET_AI_VALUE(string, "next rpg action", action->getName());

    return true;
}

bool RpgAction::AddIgnore(ObjectGuid guid)
{
    if (HasIgnore(guid))
        return false;

    set<ObjectGuid>& ignoreList = context->GetValue<set<ObjectGuid>&>("ignore rpg target")->Get();

    ignoreList.insert(guid);

    if (ignoreList.size() > 50)
        ignoreList.erase(ignoreList.begin());

    context->GetValue<set<ObjectGuid>&>("ignore rpg target")->Set(ignoreList);

    return true;
}

bool RpgAction::RemIgnore(ObjectGuid guid)
{
    if (!HasIgnore(guid))
        return false;

    set<ObjectGuid>& ignoreList = context->GetValue<set<ObjectGuid>&>("ignore rpg target")->Get();

    ignoreList.erase(ignoreList.find(guid));

    context->GetValue<set<ObjectGuid>&>("ignore rpg target")->Set(ignoreList);

    return true;
}

bool RpgAction::HasIgnore(ObjectGuid guid)
{
    set<ObjectGuid>& ignoreList = context->GetValue<set<ObjectGuid>&>("ignore rpg target")->Get();
    if (ignoreList.empty())
        return false;

    if (ignoreList.find(guid) == ignoreList.end())
        return false;

    return true;
}