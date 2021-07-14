#pragma once

#include <vector>
#include <iostream>
#include "network.hpp"

class Player: public Network{
private:
	int m_sum;
	std::vector<int> m_stops;
public:
	Player(){};
	Player(const Network& network,int sum);
	bool move();
	void plus(int number){m_sum+=number;std::cout << "plus" << m_sum << "\n";}
	int get_sum() const{return(m_sum);}
	std::vector<int> get_stops() const{return(m_stops);}
	void append_stop(){m_stops.push_back(m_sum);}
};
