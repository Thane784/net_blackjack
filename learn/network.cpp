
#include "network.hpp"

Network::Network(double speed,double line):m_speed(speed),m_line(line){
	Network::m_coeffs = read_coeffs();
}

void Network::write_coeffs() const{
	std::ofstream outfile("coeffs.txt", std::ios::trunc);
	if (!outfile){
		std::ofstream outfile("learn\\coeffs.txt");
		if (!outfile){
			std::cerr << "coeffs.txt could not be opened!" << std::endl;
			std::exit(1);
		}
	}
	for (auto pair : m_coeffs){
		outfile << pair.first << std::endl;
		outfile << pair.second << std::endl;
	}
}

std::map<int,double> Network::read_coeffs() const{
	std::map<int,double> coeffs{};
	std::ifstream infile("coeffs.txt");
	if (!infile){
		std::ifstream infile("learn\\coeffs.txt");
		if (!infile){
			std::cerr << "coeffs.txt could not be opened!" << std::endl;
			std::exit(1);
		}
	}
	while (infile){
		std::string first_str, second_str;
		std::getline(infile, first_str);
		std::getline(infile, second_str);
		if(first_str.length() != 0 && second_str.length() != 0)
			coeffs.insert(std::make_pair(std::stoi(first_str),std::stod(second_str)));
	}
	return(coeffs);
}


std::ostream& operator<<(std::ostream &out, const Network& net){
	for(const auto& elem : net.m_coeffs)
		out << elem.first << " " << elem.second << "\n";
	return (out);
}

void Network::result(std::pair<int,bool> move,bool result){
	if((result && move.second) || (!result && !move.second)){
		m_coeffs[move.first] += m_speed;
		if(m_coeffs[move.first]>1)
			m_coeffs[move.first] = 1;
	}
	else{
		m_coeffs[move.first] -= m_speed;
		if(m_coeffs[move.first]<0)
			m_coeffs[move.first] = 0;
	}
}
