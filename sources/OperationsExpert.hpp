#include "Player.hpp"

#pragma once

namespace pandemic{
    class OperationsExpert : public Player{
        public:
            OperationsExpert(Board& board, City city): Player(board, city){}
            std::string role() const{
                return "OperationsExpert";
            }
            Player& build(){
                board.add_station(current_city);
                return *this;
            }
    };
}
