
#include <iostream>

#include "deck.hpp"
#include "random.hpp"

Deck::Deck(){
	for(int i{2};i<10;++i){
		for(int j{0};j<4;++j)
			m_deck.push_back(i);
	}
	for(int j{0};j<4*5;++j)
		m_deck.push_back(10);
	shuffle();
}

int Deck::get_card(){
	int temp{*(m_deck.end()-1)};
	m_deck.pop_back();
	return(temp);
}

void Deck::shuffle(){
	for(int i{0};i<m_deck.size();++i)
		std::swap(m_deck[i],m_deck[get_int_random_number(0,m_deck.size()-1)]);
}

std::ostream& operator<<(std::ostream &out, const Deck& deck){
	for(const auto& elem : deck.m_deck)
		out << elem << " ";
	return (out);
}