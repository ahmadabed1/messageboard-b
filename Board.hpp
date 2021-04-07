#pragma once

#include "Direction.hpp"
#include <string>
#include <vector>
using namespace std;

namespace ariel {

    class Board {

        private:
        unsigned int maxR, maxC, minR, minC;
        vector<vector<char>> board;
        void resizeBoard(unsigned int row, unsigned int col);
        void update(unsigned int row, unsigned int col, bool flag, unsigned int num);

        public:
            Board(): maxR(0), maxC(0),minR(INT32_MAX), minC(INT32_MAX){
                board=vector<vector<char>>(0, vector<char>(0,'_'));
             };
            
            void post(unsigned int row, unsigned int col, Direction d, string const &message);
            string read(unsigned int row, unsigned int col,Direction d, unsigned int num);
            void show();
    };
}