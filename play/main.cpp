#include "learn\deck.hpp"
#include "learn\player.hpp"
#include <iostream>
#include <vector>

void print_cards(std::vector<int> cards){
    std::cout << "Your cards are ";
    for (auto &card : cards)
        std::cout << card;
    std::cout << "\n";
}

bool get_player_resolution(){
    std::string player_resolution;
    do{
    std::cout << "would you like to take a one more card?(y,n) ";
    std::cin >> player_resolution;
    }
    while(player_resolution!="y" || player_resolution!="n");
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
    print_cards(net_cards);
}

const double learn_line{0.5};
const double learn_speed{0.000};
int main(){
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
            int card = deck.get_card();
            player_cards.push_back(card);
            std::cout << "Your new card is " << card << "\n";
            print_cards(player_cards);
            if(get_player_sum(player_cards)+card>21){
                game_result(false,net.get_cards());
                break;
            }
        }
        else{
            ++pause;
            if(pause>2){
                //TODO
                std::cout << "";
                break;
            }
            //TODO
        }
    }
    return(0);
}