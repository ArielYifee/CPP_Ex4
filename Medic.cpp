#include "Medic.hpp"

using namespace pandemic;
using namespace std;

Player& Medic::drive(City city){
    if(board.is_cured(board.get_color(city))){
        board[city] = 0;
    }
    Player::drive(city);
    return *this;
}
Player& Medic::fly_direct(City city){
    if(board.is_cured(board.get_color(city))){
        board[city] = 0;
    }
    Player::fly_direct(city);
    return *this;
}
Player& Medic::fly_charter(City city){
    if(board.is_cured(board.get_color(city))){
        board[city] = 0;
    }
    Player::fly_charter(city);
    return *this;
}
Player& Medic::fly_shuttle(City city){
    if(board.is_cured(board.get_color(city))){
        board[city] = 0;
    }
    Player::fly_shuttle(city);
    return *this;
}
Player& Medic::discover_cure(Color color){
    Player::discover_cure(color);
    board[current_city] = 0;
    return *this;
}
Player& Medic::treat(City city){
    if(city == current_city){
        if(board[city] > 0){
            board[city] = 0;
        }else{
            throw invalid_argument("the disease level of this city is 0!");
        }
    }else{
        throw invalid_argument("you are not in this city!");
    }
    return *this;
}