
#include "player.hpp"

bool Player::move(){
	if(m_coeffs[m_sum]>=m_line)
		return(1);
	m_stops.push_back(m_sum);
	return(0);
}


Player::Player(const Network& network, int sum):m_sum(sum){
	m_speed = network.get_speed();
	m_coeffs = network.get_coeffs();
}