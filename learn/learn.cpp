

#include <conio.h>
#include <iostream>
#include <vector>

#include "player.hpp"
#include "deck.hpp"

void result(Network& network,std::array<Player,2> nets,bool winner){
	for(int i{0};i<2;++i){
		auto stops = nets[i].get_stops();
		for(auto& stop:stops)
			network.result(std::make_pair(stop,false),(i==winner));
	}
}

bool compare(std::array<Player,2> nets){
	return(!(nets[0].get_sum()>nets[1].get_sum()));
}

void game_end(Network& network,std::array<Player,2> nets,int game_result=-1){
	if(game_result == 0 || game_result == 1)
		 result(network,nets,game_result);
	else{
		bool winner = compare(nets);
		result(network,nets,winner);
	}
}


const double learn_line{0.5};
const double learn_speed{0.01};
const int learn_number{1};
int main(){
	Network network{learn_speed,learn_line};
	for(int i{0};i<learn_number;++i){
		Deck deck;
		std::array<Player,2> nets{
			Player{network,(deck.get_card()+deck.get_card())},
			Player{network,(deck.get_card()+deck.get_card())}
		};
		bool net_number{0};
		while (true){
			auto net = nets[net_number];
			bool resolution = net.move();
			if(resolution){
				int card = deck.get_card();
				if(net.get_sum()+card>21){
					network.result(std::make_pair(net.get_sum(),true),false);
					game_end(network,nets,!net_number);
				}
				else{
					net.plus(card);
					network.result(std::make_pair(net.get_sum(),true),true);
				}
			}
			else{
				//TODO
			}
			//std::cout << card << " " << key;
			net_number = !net_number;
		}
	}
	getch();
	return(0);
}
