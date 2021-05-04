#include "doctest.h"
#include "Board.hpp"

#include "Dispatcher.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "OperationsExpert.hpp"
#include "Virologist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "Medic.hpp"
#include "City.hpp"
#include <math.h>
#include <stdexcept>

using namespace std;
using namespace pandemic;

TEST_CASE("OperationsExpert"){
    Board board;
    board[City::Kinshasa] = 3;      
    board[City::Kinshasa] = 2;      
    board[City::MexicoCity] = 3;    
    board[City::HoChiMinhCity] = 1; 
    board[City::Chicago] = 1; 
    OperationsExpert player {board, City::Atlanta};
    player.take_card(City::Johannesburg)
	 .take_card(City::Khartoum)
	 .take_card(City::SaoPaulo)
	 .take_card(City::BuenosAires)
	 .take_card(City::HoChiMinhCity);
    CHECK_NOTHROW(player.build());
    CHECK_NOTHROW(player.drive(City::Washington));
    CHECK_THROWS(player.drive(City::Madrid));
    CHECK_NOTHROW(player.fly_direct(City::Johannesburg));
    CHECK_THROWS(player.fly_direct(City::Taipei));
    CHECK_NOTHROW(player.drive(City::Kinshasa));
    CHECK(board[City::Kinshasa] == 2);
    CHECK_NOTHROW(player.treat(City::Kinshasa));
    CHECK(board[City::Kinshasa] == 1);
    CHECK_NOTHROW(player.treat(City::Kinshasa));
    CHECK(board[City::Kinshasa] == 0);
    CHECK_THROWS(player.treat(City::Kinshasa));
    CHECK_THROWS(player.treat(City::Washington));
    CHECK_NOTHROW(player.drive(City::Khartoum).fly_charter(City::Sydney));
    CHECK_THROWS(player.fly_charter(City::Seoul));
    CHECK_NOTHROW(player.drive(City::LosAngeles));
    CHECK_NOTHROW(player.build());
    CHECK_NOTHROW(player.fly_shuttle(City::Atlanta));
    CHECK_NOTHROW(player.fly_shuttle(City::LosAngeles));
    CHECK_THROWS(player.fly_shuttle(City::Chicago));
    CHECK_THROWS(player.discover_cure(Color::Yellow));
    CHECK_NOTHROW(player.take_card(City::Miami)
	 .take_card(City::Bogota)
	 .take_card(City::Lima));
    CHECK_NOTHROW(player.discover_cure(Color::Yellow));
    CHECK_THROWS(player.fly_direct(City::Miami));
    CHECK_NOTHROW(player.drive(City::MexicoCity));
    CHECK_NOTHROW(player.treat(City::MexicoCity));
    CHECK_NOTHROW(board.is_clean());
}