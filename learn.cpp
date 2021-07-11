
#include <list>
#include <iostream>


class Deck{
private:
	std::list<int> m_deck{};
public:
	Deck(){	
		for(int i{2};i<10;++i){
			for(int j{0};j<4;++j)
				m_deck.push_back(i);
		}
		for(int j{0};j<4*5;++j)
				m_deck.push_back(10);
	}
	friend std::ostream& operator<<( std::ostream& out,const Deck& deck);
	void shuffle(){
	}
};

std::ostream& operator<<(std::ostream &out, const Deck& deck){
	for(const auto& elem : deck.m_deck)
		out << elem << " ";
	return (out);
}

class network{
	
};

int main(){
	Deck deck{};
	std::cout << deck;
	return(0);
}
