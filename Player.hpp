#include "Board.hpp"
#include "City.hpp"
#include <set>

#pragma once

namespace pandemic{
    class Player{
        public:
            Player(Board& board, City city): board(board), current_city(city){}
            virtual Player& drive(City city);
            virtual Player& fly_direct(City city);
            virtual Player& fly_charter(City city);
            virtual Player& fly_shuttle(City city);
            virtual Player& build();
            virtual Player& discover_cure(Color color);
            virtual Player& treat(City city);
            Player& take_card(City city);
            virtual std::string role() const;

        protected:
            Board& board;
            std::set<City> Player_cards;
            City current_city;
    };
}