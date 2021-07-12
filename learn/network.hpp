#pragma once

#include <map>
#include <iostream>

class Network{
private:
	double m_speed;
	static inline std::map<int,double> m_coeffs;
	int sum{0};
	std::map<int,bool> moves;
	std::map<int,double> read_coeffs();
	void write_coeffs();
public:
	Network(double speed);
	virtual ~Network(){write_coeffs();};
	int move(int card);
	void result(bool result);
	void clear();
	friend std::ostream& operator<<( std::ostream& out,const Network& net);
};
