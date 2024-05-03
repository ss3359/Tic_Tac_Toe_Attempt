//
//  Berneese.hpp
//  DogProject
//
//  Created by Owner on 4/27/24.
//

#ifndef Berneese_hpp
#define Berneese_hpp

#include <stdio.h>
#include <iostream>
#include <thread>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include "Maltese.hpp"
#include "Bloodhound.hpp"
#include "CockerSpaniel.hpp"
#include "Berneese.hpp"
using namespace std;


void PythagoreanTriples(int a, int b, int c);

void PlayOrderOfOperations(char cards[4],int length);
void GetTheCards(char cards[4]);

class TicTacToe{
    
public:
    char board[3][3];
    char PlayerOne, PlayerTwo;
    bool IsMatchVertical, IsMatchHorizontal, IsMatchDiagonal; 
    
    void PlayGame(char board[3][3], bool IsMatchVertical, bool IsMatchHorizontal, bool IsMatchDiagonal); 
    void PrintTheBoard(char board[3][3]); 
    void SetUpBoard(char board[3][3]); 
    bool IsMatchVerticalOnBoard(char board[3][3], int column, char character);
    bool IsMatchHorizontalOnBoard(char board[3][3],int row, char character);
    bool IsMatchDiagonalOnBoard(char board[3][3], char charcter);

    
};



#endif /* Berneese_hpp */
