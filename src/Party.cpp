#include "Party.h"
#include "Coalition.h"
#include <vector>

using std::vector;

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    cooldown = -1;
    offers = vector<Coalition&>{};
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

int Party::getId() const
{
    return mId;
}

int Party::getCooldown() const
{
    return cooldown;
}

void Party::changeCooldown(){
    if (cooldown < 0)
        cooldown = 2;
    else if (cooldown > 0)
        cooldown--;
}

void Party::step(Simulation &s)
{
    if (!getState() == CollectingOffers){
        return;
    }
    if (cooldown > 0){
        changeCooldown();
        return;
    }
    mJoinPolicy->join();
    setState(Joined);

    // TODO
    // check if status is collectionOffers
    // update timer
    // join to coalition according to policy & clone agent & add neighbors to availableParties
    // update status
}

void Party::addOffer(Coalition &coalition)
{
    offers.push_back(coalition);
}
