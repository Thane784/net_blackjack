#pragma once

#include "network.hpp"

class Player: public Network{
private:
	int sum{0};
	std::map<int,bool> moves;
public:
	int move(int card);
	void result(bool result);
	void clear();
};