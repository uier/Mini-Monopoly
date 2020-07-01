#include "MapUnit.h"

#include <assert.h>

bool MapUnit::isJail() const { 
	return (TYPE == 'J'); 
}
bool MapUnit::isOwner(int player) const { 
	return (owner == player); 
}
bool MapUnit::buyable() const { 
	return ( !isJail() && owner == NOBODY ); 
}
void MapUnit::setOwner(int player) { 
	owner = player; 
}
// travel fine 會被各個子類別 virtual 然後我不知道父類別要回傳啥 就傳 0 了 QQ
int MapUnit::travelFine() const { 
	return 0; 
}
bool MapUnit::upgradable() const { 
	return false; 
}
void MapUnit::release() { 
	owner = NOBODY; 
}
int MapUnit::getId() { 
	return ID; 
}
int MapUnit::getPrice() { 
	return PRICE; 
}
std::string MapUnit::getName() { 
	return NAME; 
}
int MapUnit::getOwner() { 
	return owner; 
}


int UpgradableUnit::getUpgradePrice() const { 
	return UPGRADE_PRICE; 
}
int UpgradableUnit::getLevel() const { 
	return level; 
}
int UpgradableUnit::travelFine() const {
	assert(1 <= level && level <= MAX_LEVEL);
	return FINE_OF_LEVEL[level-1];
}
bool UpgradableUnit::upgradable() const { 
	return (level+1 <= MAX_LEVEL); 
}
void UpgradableUnit::upgrade() { 
	level += 1; 
}
void UpgradableUnit::release() {
	owner = NOBODY;
	level = 1;
}


int CollectableUnit::number_of_units_of_owner[MAX_PLAYER];
void CollectableUnit::setOwner(int player) {
	owner = player;
	number_of_units_of_owner[owner] += 1;
}
int CollectableUnit::travelFine() const {
	assert(0 <= owner && owner < MAX_PLAYER);
	return number_of_units_of_owner[owner] * UNIT_FINE;
}
void CollectableUnit::release() {
	number_of_units_of_owner[owner] -= 1;
	owner = NOBODY;
}


int RandomCostUnit::travelFine() const { 
	return randint(1, 6) * UNIT_FINE; 
}


void JailUnit::addPlayer(int player) { 
	player_in_jail.insert(player); 
}
void JailUnit::removePlayer(int player) { 
	player_in_jail.erase(player); 
}