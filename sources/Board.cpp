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
        string name;
        string color;
        while (cities >> name >> color){
            City city_name = string2city.find(name)->second;
            disease_level[city_name] = 0;
            Color city_color = string2color.find(color)->second;
            colors[city_name] = city_color;
            string neighbor;
            while (cities.peek() != '\n' && cities >> neighbor){
                neighbors[city_name].insert(string2city.find(neighbor)->second);
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
    void Board::remove_stations(){
        station_list.clear();
    }
    bool Board::is_cured(Color color) const{
        return cure_list.find(color) != cure_list.end();
    }
    bool Board::has_station(City city) const{
        return station_list.find(city) != station_list.end();
    }
    void Board::add_cure(Color color){
        cure_list.insert(color);
    }
    void Board::add_station(City city){
        station_list.insert(city);
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
        cout << "***********************PANDEMIC GAME!***********************\n" << endl;
        for(auto city : board.disease_level){
            string name = city2string.find(city.first)->second;
            int level = board[city.first];
            cout << "City: " << name << ", Disease Level :" << level <<endl;
        }
        cout << "----------------------CURE LIST:----------------------\n" << endl;
        for(auto color : board.cure_list){
            string color_name = color2string.find(color)->second;
            cout << color_name << endl;
        }
        cout << "\n\n----------------------STATION LIST:----------------------\n" << endl;
        for(auto station : board.station_list){
            string station_name = city2string.find(station)->second;
            cout << station_name <<endl;
        }
        cout << "\n\n\n*********************GAME OVER*********************" << endl;
        return out;
    }
};