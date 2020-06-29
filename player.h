//
// Created by yuta on 6/29/2020.
//

#ifndef MINI_MONOPOLY_PLAYER_H
#define MINI_MONOPOLY_PLAYER_H

#include <string>
#include <utility>

class Player {

private:
	const int id;
	const std::string name;
	int offset = 0;
	int unitCount = 0;
	int money = defaultMoney;

	constexpr static int defaultMoney = 30000;

public:

	Player (int id, std::string name) : id(id), name(std::move(name)) {}

	[[nodiscard]] int getId() const;
	[[nodiscard]] const std::string& getName() const;
	[[nodiscard]] int getOffset() const;
	[[nodiscard]] int getMoney() const;
	[[nodiscard]] int getUnitCount() const;

	void move(int steps);
	void increaseMoney(int amount);
};

#endif //MINI_MONOPOLY_PLAYER_H