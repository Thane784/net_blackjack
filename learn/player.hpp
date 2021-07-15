#pragma once

#include <vector>
#include <iostream>
#include "network.hpp"

class Player: public Network{
private:
	int m_sum;
	std::vector<int> m_stops;
	std::vector<int> m_cards;
public:
	Player(){};
	Player(const Network& network,int first_card, int second_card);
	bool move();
	void plus(int number);
	int get_sum() const{return(m_sum);}
	std::vector<int> get_cards(){return(m_cards);};
	std::vector<int> get_stops() const{return(m_stops);}
	void append_stop(){m_stops.push_back(m_sum);}
};
