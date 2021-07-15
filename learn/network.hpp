#pragma once

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class Network{
protected:
	double m_line;
	double m_speed;
	std::map<int,double> m_coeffs;
private:
	std::map<int,double> read_coeffs() const;
public:
    Network(){};
	Network(double speed,double line);
	void write_coeffs() const;
	double get_speed() const {return(m_speed);}
	std::map<int,double> get_coeffs() const {return(m_coeffs);}
	void result(std::pair<int,bool> move,bool result);
	friend std::ostream& operator<<( std::ostream& out,const Network& net);
};
