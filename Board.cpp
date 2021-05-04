#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"
#include <fstream>
#include <iostream>

using namespace pandemic;
using namespace std;

  
namespace pandemic{
    Board::Board(){
        ifstream cities{"cities_map.txt"};
        string name, color;
        while (cities >> name >> color){
            City city_name = city2string.find(name)->second;
            disease_level[city_name] = 0;
            station_list[city_name] = false;
            Color city_color = color2string.find(color)->second;
            colors[city_name] = city_color;
            string neighbor;
            while (cities.peek() != '\n' && cities >> neighbor){
                neighbors[city_name].insert(city2string.find(neighbor)->second);
                neighbor = "";
            }
        }
        cities.close();
    }
    bool Board::is_clean() const{
        for(auto city : disease_level){
            if(city.second != 0){
                return false;
            }
        }
        return true;
    }
    void Board::remove_cures(){
        cure_list.clear();
    }
    bool Board::is_cured(Color color) const{
        return cure_list.find(color) != cure_list.end();
    }
    bool Board::has_station(City city) const{
        return station_list.find(city)->second;
    }
    void Board::add_cure(Color color){
        cure_list.insert(color);
    }
    void Board::add_station(City city){
        station_list[city] = true;
    }
    int &Board::operator[](City city){
        return disease_level[city];
    }
    bool Board::can_drive(City src, City dst) const{
        set temp = neighbors.find(src)->second;
        return temp.find(dst) != temp.end();
    }
    Color Board::get_color(City city) const{
        return colors.find(city)->second;
    }
    ostream &operator<<(std::ostream &out, Board &board){
        return out;
    }
};