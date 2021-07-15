#include "learn\deck.hpp"
#include "learn\player.hpp"
#include <iostream>
#include <vector>
#include <conio.h>
#include <thread>

void print_cards(std::vector<int> cards){
    std::cout << "Your cards are ";
    for (auto &card : cards)
        std::cout << card << " ";
    std::cout << "\n";
}

bool get_player_resolution(){
    std::string player_resolution;
    do{
    std::cout << "would you like to take a one more card?(y,n) ";
    std::cin >> player_resolution;
    }
    while(player_resolution!="y" && player_resolution!="n");
    if(player_resolution=="y")
        return(true);
    else
        return(false);
}

int get_player_sum(std::vector<int> cards){
    int sum{0};
    for (auto &card : cards)
        sum += card;
    return(sum);
}

void game_result(bool winner,std::vector<int> net_cards){
    if(winner)
        std::cout << "You are WIN!\n";
    else
        std::cout << "You are LOSE!\n";
    std::cout << "Network cards was ";
        for (auto &card : net_cards)
        std::cout << card << " ";
    std::cout << "\n";
}

bool compare(std::vector<int> player_cards,Player net){
	return(!(net.get_sum()>get_player_sum(player_cards)));
}

const double learn_line{0.5};
const double learn_speed{0.000};
int main(){
    using namespace std::chrono_literals;
    Network network{learn_speed,learn_line};
    Deck deck;
    Player net(network,deck.get_card(),deck.get_card());
	std::cout << network << "\n\n\n";
    std::vector<int> player_cards{deck.get_card(),deck.get_card()};
    int pause{0};
    while (true){
        print_cards(player_cards);
        bool player_resolution = get_player_resolution();
        if(player_resolution){
            pause = 0;
            int card = deck.get_card();
            player_cards.push_back(card);
            std::cout << "Your new card is " << card << "\n";
            print_cards(player_cards);
            if(get_player_sum(player_cards)>21){
                game_result(false,net.get_cards());
                break;
            }
        }
        else{
            ++pause;
        }
        bool resolution = net.move();
        std::this_thread::sleep_for(400ms);
        if(resolution){
            std::cout << "The network took a one more card\n";
			pause = 0;
			int card = deck.get_card();
            if(net.get_sum()+card>21){
				game_result(true,net.get_cards());
				break;
			}
			else{
				net.plus(card);
			}
		}
		else{
            ++pause;
            if(pause>1){
                std::this_thread::sleep_for(400ms);
                std::cout << "The network won't take a card too\n";
                std::this_thread::sleep_for(400ms);
                std::cout << "Let's compare the sums\n";
                std::this_thread::sleep_for(400ms);
                std::cout << "You have " << get_player_sum(player_cards) << " and network has " << net.get_sum() << "\n";
                std::this_thread::sleep_for(400ms);
                game_result(compare(player_cards,net),net.get_cards());
                break;
            }
            std::cout << "The network didn't decide to take a card\n";
		}
        std::cout << "The network has " << net.get_cards().size() << " cards\n";
    }
    getch();
    return(0);
}