#include "Player.hpp"
#pragma once

namespace pandemic{
    class FieldDoctor : public Player{
        public:
            FieldDoctor(Board& board, City city): Player(board, city){}
            std::string role() const{
                return "FieldDoctor";
            }
        Player& treat(City city){
            if(city == current_city || board.can_drive(current_city, city)){
                if(board[city] > 0){
                    if(board.is_cured(board.get_color(city))){
                        board[city] = 0;
                    }else{
                        board[city] -= 1;
                    }
                }else{
                    throw std::invalid_argument("the disease level of this city is 0!");
                }
            }else{
                throw std::invalid_argument("you are not in this city or its neighber!");
            }
            return *this;
        }
    };
}