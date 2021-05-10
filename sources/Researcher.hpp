#include "Player.hpp"
#pragma once
namespace pandemic{
    class Researcher : public Player{
        public:
            Researcher(Board& board, City city): Player(board, city){}
            std::string role() const{
                return "Researcher";
            }
            Player &discover_cure(Color color){
                if(board.is_cured(color)){
                    return *this;
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
                }else{
                    throw std::invalid_argument("not enough cards");
                }
                return *this;
                }
        private:
            const int MIN_CARDS = 5;
    };
}