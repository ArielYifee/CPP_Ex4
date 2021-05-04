#pragma once

#include <string>
#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"
#include <iostream>

namespace pandemic{

    class Board{

        public:
            Board();
            int &operator[](City city);
            friend std::ostream &operator<<(std::ostream &out, Board &board);
            bool is_clean() const;
            bool is_cured(Color color) const;
            bool has_station(City city) const;
            void add_cure(Color color);
            void add_station(City city);
            bool can_drive(City src, City dst) const;
            void remove_cures();
            Color get_color(City city) const;
        private:
            std::map<City, std::set<City>> neighbors;
            std::map<City, Color> colors;
            std::map<City, int> disease_level;
            std::set<Color> cure_list;
            std::map<City, bool> station_list;
    };
}