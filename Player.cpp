#include "Player.hpp"

using namespace pandemic;
using namespace std;

const int MIN_CARDS = 5;

Player& Player::drive(City dst){
    if(!(board.can_drive(current_city,dst))){
        throw invalid_argument("the cities are'nt neighbors");
    }
    current_city = dst;
    return *this;
}
Player& Player::fly_direct(City dst){
    auto temp = Player_cards.find(dst);
    if(temp == Player_cards.end()){
        throw invalid_argument("the player doesn't have the card!");
    }
    current_city = dst;
    Player_cards.erase(temp);
    return *this;
}
Player& Player::fly_charter(City dst){
    auto temp = Player_cards.find(current_city);
    if(temp == Player_cards.end()){
        throw invalid_argument("the player doesn't have the card!");
    }
    current_city = dst;
    Player_cards.erase(temp);
    return *this;
}
Player& Player::fly_shuttle(City dst){
    if(board.has_station(current_city) && board.has_station(dst)){
        current_city = dst;
    }else{
        throw invalid_argument("fly_shuttle - there is not research station in the cities!");
    }
    return *this;
}
Player& Player::build(){
    if(!(board.has_station(current_city))){
        if(Player_cards.find(current_city) != Player_cards.end()){
            board.add_station(current_city);
            Player_cards.erase(current_city);
        }else{
            throw invalid_argument("the player doesn't have the card!");
        }
    }else{
        throw invalid_argument("there is already research station in this city");
    }
    return *this;
}
Player& Player::discover_cure(Color color){
    if(!(board.has_station(current_city))){
        throw invalid_argument("there is no research station in the current city!");
    }
    int counter = 0;
    set<City> cards;
    for(auto city_card : Player_cards){
        if(board.get_color(city_card) == color){
            counter ++;
            cards.insert(city_card);
            if(counter == MIN_CARDS){
                break;
            }
        }
    }
    if(counter == MIN_CARDS){
        board.add_cure(color);
        for(auto city : cards){
            Player_cards.erase(city);
        }
    }else{
        throw invalid_argument("not enough cards");
    }
    return *this;
}
Player& Player::treat(City city){
    if(city == current_city){
        if(board[city] > 0){
            if(board.is_cured(board.get_color(city))){
                board[city] = 0;
            }else{
                board[city] -= 1;
            }
        }else{
            throw invalid_argument("the disease level of this city is 0!");
        }
    }else{
        throw invalid_argument("you are not in this city!");
    }
    return *this;
}
Player& Player::take_card(City city){
    Player_cards.insert(city);
    return *this;
}
string Player::role() const{
    return "";
}