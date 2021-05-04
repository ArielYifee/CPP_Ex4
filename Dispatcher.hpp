#include "Player.hpp"
#pragma once
namespace pandemic{
    class Dispatcher : public Player{
        public:
            Dispatcher(Board& board, City city): Player(board, city){}
            std::string role() const{
                return "Dispatcher";
            }
            Player& fly_direct(City dst){
                if(board.has_station(current_city)){
                    current_city = dst;
                }else{
                    return Player::fly_direct(dst);
                }
                return *this;
            }
    };
}