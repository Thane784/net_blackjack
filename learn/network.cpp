
#include "network.hpp"

Network::Network(double speed,double line):m_speed(speed),m_line(line){
	Network::m_coeffs = read_coeffs();
}

void Network::write_coeffs() const{

}

std::map<int,double> Network::read_coeffs() const{
	std::map<int,double> coeffs{};
	for(int i{2};i<21;++i)
		coeffs.insert(std::make_pair(i,0.5));
	return(coeffs);
}


std::ostream& operator<<(std::ostream &out, const Network& net){
	for(const auto& elem : net.m_coeffs)
		out << elem.first << " " << elem.second << "\n";
	return (out);
}

void Network::result(std::pair<int,bool> move,bool result){
	if((result && move.second) || (!result && !move.second))
		m_coeffs[move.first] += m_speed;
	else
		m_coeffs[move.first] -= m_speed;
}
