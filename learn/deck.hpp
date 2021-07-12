#pragma once

#include <vector>
#include <iostream>
#include <random>

class Deck{
private:
	std::vector<int> m_deck{};
public:
	Deck();
	void shuffle();
	int get_card();
	friend std::ostream& operator<<( std::ostream& out,const Deck& deck);
};

