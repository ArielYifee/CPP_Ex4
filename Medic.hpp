#include "Player.hpp"
#pragma once
namespace pandemic{
    class Medic : public Player{
        public:
            Medic(Board& board, City city): Player(board, city){}
            std::string role() const{
                return "Medic";
            }
            Player& drive(City city);
            Player& fly_direct(City city);
            Player& fly_charter(City city);
            Player& fly_shuttle(City city);
            Player& discover_cure(Color color);
            Player& treat(City city);
    };
}