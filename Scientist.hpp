#include "Player.hpp"
#pragma once
namespace pandemic{
    class Scientist : public Player{
        public:
            Scientist(Board& board, City city, int n): Player(board, city), MIN_CARDS(n){}
            std::string role() const{
                return "Scientist";
            }
            Player &discover_cure(Color color){
                if(!(board.has_station(current_city))){
                    throw std::invalid_argument("there is no research station in the current city!");
                }
                int counter = 0;
                std::set<City> cards;
                for(auto city_card : Player_cards){
                    if(board.get_color(city_card) == color){
                        counter ++;
                        cards.insert(city_card);
                        if(counter == MIN_CARDS){
                            break;
                        }
                    }
                }
                if(counter == MIN_CARDS){
                    board.add_cure(color);
                    for(auto city : cards){
                        Player_cards.erase(city);
                    }
                }
                return *this;
                }
            private:
                int MIN_CARDS;
    };
}