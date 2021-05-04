#include "Player.hpp"
#pragma once

namespace pandemic{
    class GeneSplicer : public Player{
        public:
            GeneSplicer(Board& board, City city): Player(board, city){}
            std::string role() const{
                return "GeneSplicer";
            }
        Player& discover_cure(Color color){
            if(!(board.has_station(current_city))){
                throw std::invalid_argument("there is no research station in the current city!");
            }
            int counter = 0;
            std::set<City> cards;
            if(Player_cards.size() <= 5){
                for(City city_card : Player_cards){
                    counter ++;
                    cards.insert(city_card);
                    if(counter == MIN_CARDS){
                        break;
                    }
                }
                for(City city_cards : cards){
                    Player_cards.erase(city_cards);
                }
                board.add_cure(color);
            }
            return *this;
        }
        private:
        const int MIN_CARDS = 5;
    };
}