#include "doctest.h"
#include "Board.hpp"
#include <string>

namespace ariel
{
    
    TEST_CASE("read rest")
    {
        Board board{};
        CHECK_THROWS(board.read(-1,2,Direction::Horizontal,3));
        CHECK_THROWS(board.read(-1,-2,Direction::Horizontal,3));
        CHECK_THROWS(board.read(1,-2,Direction::Horizontal,1));
        CHECK_THROWS(board.read(1,12,Direction::Horizontal,0));
        CHECK_THROWS(board.read(1,12,Direction::Horizontal,-1));
        
        std::string val;
        val=board.read(1,12,Direction::Horizontal,3);
        CHECK(val.length() == 3);
        CHECK(val != "");
    }

    TEST_CASE("post test")
    {
        Board board{};
        CHECK_THROWS(board.post(-1,0,Direction::Horizontal,"ahmad"));
        CHECK_THROWS(board.post(-1,-2,Direction::Horizontal,"ahmad"));
        CHECK_THROWS(board.post(1,2,Direction::Horizontal,""));
        CHECK_THROWS(board.post(1,-2,Direction::Horizontal,"ahmad"));
    }

    TEST_CASE("read post test")
    {
        Board board{};
        board.post(0,0,Direction::Horizontal,"ahmad");
        std::string val;
        val=board.read(0,0,Direction::Horizontal,3);
        CHECK(val == "ahm");
        board.post(0,0,Direction::Vertical,"abed");
        val=board.read(0,0,Direction::Vertical,3);
        CHECK(val == "abe");
        val=board.read(0,0,Direction::Horizontal,3);
        CHECK(val == "aba");
        val=board.read(0,5,Direction::Vertical,3);
        CHECK(val == "f__");
        board.post(0,2,Direction::Vertical,"hello");
        val=board.read(1,0,Direction::Horizontal,3);
        CHECK(val == "i_e");
        val=board.read(3,0,Direction::Horizontal,3);
        CHECK(val == "a_l");
        board.post(2,2,Direction::Horizontal,"foo");
        val=board.read(2,2,Direction::Horizontal,3);
        CHECK(val == "foo");
        val=board.read(0,2,Direction::Vertical,5);
        CHECK(val == "hello");
        val=board.read(1,4,Direction::Vertical,3);
        CHECK(val == "_a_");
    }

    TEST_CASE ("empty borad") {
    Board board;
    CHECK(board.read(20,30,Direction::Horizontal, 1) == "_");
    CHECK(board.read(20,30,Direction::Horizontal, 2) == "__");
    CHECK(board.read(20,30,Direction::Horizontal, 8) == "________");
    CHECK(board.read(80,180,Direction::Vertical, 6) == "______");


}


}