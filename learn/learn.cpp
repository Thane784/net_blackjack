

#include <conio.h>
#include <iostream>
#include <vector>

#include "player.hpp"
#include "deck.hpp"



const double learn_speed{0.01};
const int learn_number{1};
int main(){
	Network network{learn_speed};
	for(int i{0};i<learn_number;++i){
		std::vector<Player> nets{};
		bool net_number{0};
		Deck deck{};
		while (true){
			int card = deck.get_card();
			int key = nets[net_number].move(card);
			std::cout << card << " " << key;
			net_number = !net_number;
		}
		for(auto &net : nets)
			net.clear();
	}
	getch();
	return(0);
}
