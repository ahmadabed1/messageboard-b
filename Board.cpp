#include <iostream>
#include "Board.hpp"
using namespace std;
using namespace ariel;

const char defaultChar = '_';
namespace ariel {
 

    void Board::update(unsigned int row, unsigned int col, bool flag, unsigned int num){


        if(this->maxR!=0 || this->minR!=INT32_MAX || this->maxC!=0 || this->minC!=INT32_MAX){
              this->minC=min(this->minC, col);
            this->minR=min(this->minR, row);

            if(!flag){
                 this->maxC=max(this->maxC, col+1);
                this->maxR=max(this->maxR, row+num+1);
            }
            else{
                this->maxC= max(this->maxC, col+num+1);
                this->maxR=max(this->maxR, row+1);
               
            }
           
            resizeBoard(this->maxR, this->maxC);
        }
        
        else{
             if (!flag){
                this->maxR=row+num;
                this->maxC=col+1;
                this->minR=row;
                this->minC=col;
             }
             else{
                this->maxR=row+1;
                this->maxC=col+num;
                this->minR=row;
                this->minC=col;
             }
             resizeBoard(this->maxR, this->maxC);
        }
        
    }

    
    /*
    resize boeard
    */
    void Board::resizeBoard(unsigned int row, unsigned int col){

        this-> board.resize(row);

        for(unsigned int i=0; i < row; i++){
            board.at(i).resize(col,defaultChar);
        }

    }



    /*
    write message to the board 
    */
    void Board::post(unsigned int row, unsigned int col, Direction d, string const &message){
        unsigned int messageSize = message.length();
        bool flag = (d == Direction::Horizontal);
        
        update(row,col,flag,messageSize);

        for (char ch: message){
            board.at(row).at(col) = ch;
            flag? col++ : row++;
        }
    
    }

    /*
    read messages from board
    */
    string Board::read(unsigned int row, unsigned int col, Direction d, unsigned int num){
        string s;
        bool flag = (d == Direction::Horizontal);


        for(int i=0; i<num; i++){
            try
            {
                s+=board.at(row).at(col);
            }
            catch(const std::exception& e)
            {
                s+="_";
            }
            flag? col++ : row++;
        }
        
        return s;
    }

/*
print the board
*/
    void Board::show(){

        for (unsigned int i = this->minR; i < this->maxR; i++) {
            cout << i << ": ";
           
            for (unsigned int j = this->minC; j < this->maxC; j++) {
                    cout << this->board[i][j];
            }
            cout<< "\n";
        }
        cout << "\n" << endl;
    }
}
