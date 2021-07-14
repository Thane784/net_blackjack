

#include <conio.h>
#include <iostream>
#include <vector>
#include <ctime>

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
const double learn_speed{0.001};
const int learn_number{1000};
int main(){
	Network network{learn_speed,learn_line};
	const unsigned int start_time =  std::clock();
	for(int i{0};i<learn_number;++i){
		std::cout << "\n\n\n";
		Deck deck;
		std::array<Player,2> nets{
			Player{network,(deck.get_card()+deck.get_card())},
			Player{network,(deck.get_card()+deck.get_card())}
		};
		bool net_number{0};
		while (true){
			bool resolution =nets[net_number].move();
			int pause{0};
			if(resolution){
				pause = 0;
				int card = deck.get_card();
				if(nets[net_number].get_sum()+card>21){
					network.result(std::make_pair(nets[net_number].get_sum(),true),false);
					game_end(network,nets,!net_number);
					break;
				}
				else{
					network.result(std::make_pair(nets[net_number].get_sum(),true),true);
					nets[net_number].plus(card);
				}
			}
			else{
				if(pause>1){
					game_end(network,nets);
					break;
				}
				else{
					nets[net_number].append_stop();
				}
				++pause;
			}
			net_number = !net_number;
		}
	}
	const unsigned int end_time =  std::clock();
	std::cout << "learn_number = " << learn_number << "\n";
	std::cout << "runtime = " << (end_time-start_time)/1000.0 << " seconds\n";
	std::cout << network;
	getch();
	return(0);
}
