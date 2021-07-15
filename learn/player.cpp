
#include "player.hpp"

bool Player::move(){
	if(m_coeffs[m_sum]>=m_line)
		return(1);
	m_stops.push_back(m_sum);
	return(0);
}

void Player::plus(int number){
	m_sum+=number;
	m_cards.push_back(number);
}


Player::Player(const Network& network, int first_card, int second_card):m_sum(first_card+second_card){
	m_speed = network.get_speed();
	m_coeffs = network.get_coeffs();
	m_cards.push_back(first_card);
	m_cards.push_back(second_card);
}