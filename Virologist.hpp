#include "Player.hpp"
#pragma once
namespace pandemic{
    class Virologist : public Player{
        public:
            Virologist(Board& board, City city): Player(board, city){}
            std::string role() const{
                return "Virologist";
            }
            Player& treat(City city){
                if(city == current_city){
                    Player::treat(city);
                }else{
                    if(Player_cards.find(city) != Player_cards.end()){
                        if(board[city] > 0){
                            if(board.is_cured(board.get_color(city))){
                                board[city] = 0;
                            }else{
                                board[city] -= 1;
                            }
                            Player_cards.erase(city);
                        }else{
                            throw std::invalid_argument("the disease level of this city is 0!");
                        }
                    }else{
                        throw std::invalid_argument("you dont have this city card!");
                    }
                }
                return *this;
            }
    };
}