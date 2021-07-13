#pragma once

#include <vector>
#include "network.hpp"

class Player: public Network{
private:
	int m_sum{0};
	std::vector<int> m_stops;
public:
	Player(){};
	Player(const Network& network,int sum);
	bool move();
	void plus(int number){m_sum+=number;}
	int get_sum(){return(m_sum);};
};
