//
//  Berneese.cpp
//  DogProject
//
//  Created by Owner on 4/27/24.
//

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

void PythagoreanTriples(int a, int b, int c){
    
    if(pow(a,2)+ pow(b,2)==pow(c,2)){
        cout<<"The numbers: "<<a<<" , "<<b<<" , and "<<c<<" are Pythagorean Triples. "<<endl;
    }
    else{
        cout<<"The numbers: "<<a<<" , "<<b<<" , and "<<c<<" are not Pythagorean Triples. "<<endl;

    }
}

void PlayOrderOfOperations(char cards[], int length){
    srand(time(NULL));
    char operatiors[4]={'+','-','x','/'};
    char result[7];
    int count=0;
    
    while(count<sizeof(result)){
        
        result[2*count]=cards[count];
        result[(2*count)+1]=operatiors[rand()%4];
        
        count++;
        
    }
    
    for(int i=0; i<7;i++){
        cout<<result[i]<<"\t";
    }
    
    
    cout<<endl;
}

void GetTheCards(char cards[]){
    srand(time(NULL));
    char numbers[9]={'1','2','3','4','5','6','7','8','9'};
    int count=0, length=4;
    
    while(count<length){
        cards[count]=numbers[rand()%9];
        cout<<cards[count]<<"\t";
        count++;
    }
  
    cout<<endl;
    PlayOrderOfOperations(cards,length);
}
bool TicTacToe::IsMatchVerticalOnBoard(char board[3][3], int column, char character){
    
    int row=0;
    
        if(board[row][column]==character&&board[row][column+1]==character&&board[row][column+2]==character)
        {
            return true;
        }
    return false;
}
    



bool TicTacToe:: IsMatchHorizontalOnBoard(char board[3][3],int row, char character){
    
    int column=0;
    
        if(board[row][column]==character&&board[row+1][column]==character&&board[row+2][column]==character)
        {
            return true;
    }
    return false;
}


bool TicTacToe:: IsMatchDiagonalOnBoard(char board[3][3], char character){
    
    int index=0, index2=2;
    
    if(board[index][index]==character&&board[index+1][index+1]==character&&board[index+2][index+2]==character)
        return true;
    else if((board[index2][index2]==character&&board[index2-1][index2-1]==character&&board[index2-2][index2-2])==character)
        return true;
    return false;
}


void TicTacToe::PlayGame(char board[3][3], bool IsMatchVertical, bool IsMatchHorizontal, bool IsMatchDiagonal){
    
    char PlayerOne='X', PlayerTwo='O';
    int i, j;
    int RowCount, ColumnCount;
    
    
    while(IsMatchDiagonal==false&&IsMatchVertical==false&&IsMatchDiagonal==false){
        RowCount=0; ColumnCount=0;
        cout<<"Player One Turn. Choose Where To Mark On Board "<<endl;
        cin>>i; cin>>j;
        board[i][j]=PlayerOne;
        
        PrintTheBoard(board);
        cout<<endl;
        
        
        while(ColumnCount<3){
            IsMatchVertical=IsMatchVerticalOnBoard(board, ColumnCount,PlayerOne);
            if(IsMatchVertical==true)
                break;
            ColumnCount++;
        }
     
        while(RowCount<3){
            IsMatchHorizontal=IsMatchHorizontalOnBoard(board, RowCount,PlayerOne);
            if(IsMatchHorizontal==true)
                break;
            RowCount++;
        }
        
        IsMatchDiagonal=IsMatchDiagonalOnBoard(board, PlayerOne);
        
        
        if(IsMatchVertical==true||IsMatchHorizontal==true||IsMatchDiagonal==true){
            cout<<"Player One Wins! "<<endl;
            break;
        }
        
        cout<<"Computer Turn. "<<endl;
        RowCount=0; ColumnCount=0;

        
        srand(time(NULL));
        i = rand()%3; j=rand()%3;
        while(board[i][j]=='+'){
            board[i][j]=PlayerTwo;
            break;
        }
        
        //IsMatchVertical, bool IsMatchHorizontal, bool IsMatchDiagonal
        PrintTheBoard(board);
        
        while(ColumnCount<3){
            IsMatchVertical=IsMatchVerticalOnBoard(board, ColumnCount, PlayerTwo);
            if(IsMatchVertical==true)
                break;
            ColumnCount++;
        }
     
        while(RowCount<3){
            IsMatchHorizontal=IsMatchHorizontalOnBoard(board, RowCount, PlayerTwo);
            if(IsMatchHorizontal==true)
                break;
            RowCount++;
        }
        
        IsMatchDiagonal=IsMatchDiagonalOnBoard(board, PlayerTwo);
        
        if(IsMatchVertical==true||IsMatchHorizontal==true||IsMatchDiagonal==true){
            cout<<"Player Two Wins! "<<endl;
            break;
        }
    }
    
   
        
}
void TicTacToe::SetUpBoard(char board[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j]='+';
        }
        cout<<endl;
    }
    
    PrintTheBoard(board);
}
void TicTacToe::PrintTheBoard(char board[3][3]){
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<board[i][j]<<"\t";
        }
        cout<<endl; 
    }
}





























/*
 
 
 This is code for Mathematical Gunfight:
 bool PlayerOneShoots(bool IsPlayerThreeAlive){
     int shot=rand()%100;

     
     if(shot>=0&&shot<=33){
         IsPlayerThreeAlive=false;
     }
     return IsPlayerThreeAlive;
 }

 bool PlayerTwoShoots(bool IsPlayerThreeAlive){
     int shot=rand()%100;
     
     if(shot>=0&&shot<=50){
         IsPlayerThreeAlive=false;
     }
     return IsPlayerThreeAlive;
 }
 bool PlayerThreeShoots(bool IsPlayerTwoAlive){
  
     IsPlayerTwoAlive=false;
     return IsPlayerTwoAlive;
 }

 int StartTheGame(bool IsPlayerOneAlive, bool IsPlayerTwoAlive,bool IsPlayerThreeAlive){
     
     
     while((IsPlayerOneAlive&&IsPlayerTwoAlive)||(IsPlayerTwoAlive&&IsPlayerThreeAlive)||(IsPlayerOneAlive&& IsPlayerThreeAlive)){
         
         if(IsPlayerOneAlive){
             if(IsPlayerThreeAlive){
                 IsPlayerTwoAlive=PlayerOneShoots(IsPlayerThreeAlive);
             }
             else if(IsPlayerTwoAlive){
                 IsPlayerTwoAlive=PlayerOneShoots(IsPlayerTwoAlive);
             }
         }
         if(IsPlayerTwoAlive){
             if(IsPlayerThreeAlive){
                 IsPlayerThreeAlive=PlayerTwoShoots(IsPlayerThreeAlive);
             }
             else if(IsPlayerOneAlive){
                 IsPlayerOneAlive=PlayerTwoShoots(IsPlayerOneAlive);
             }
             
         }
         if(IsPlayerThreeAlive){
             if(IsPlayerTwoAlive){
                 IsPlayerTwoAlive=PlayerThreeShoots(IsPlayerTwoAlive);
             }
             else if(IsPlayerOneAlive){
                 IsPlayerOneAlive=PlayerThreeShoots(IsPlayerOneAlive);
             }
             
         }
         
     }
     
     if(IsPlayerOneAlive){
         return 1;
     }
     else if(IsPlayerTwoAlive){
         return 2;
     }
     else if(IsPlayerThreeAlive){
         return 3;
     }
     
     return 404;
 }

 int main(){
     
     
     bool IsPlayerOneAlive=true, IsPlayerTwoAlive=true,IsPlayerThreeAlive=true;
     int PlayerOneStands=0,PlayerTwoStands=0, PlayerThreeStands=0;
     double GamesPlayed=1; int result;
     
     
     
     while(GamesPlayed<=100){
         result = StartTheGame(IsPlayerOneAlive, IsPlayerTwoAlive, IsPlayerThreeAlive);
         
         if(result==1){
             PlayerOneStands++;}
         else if(result==2){
             PlayerTwoStands++;}
         else if(result==3){
             PlayerThreeStands++; }
         
         GamesPlayed+=1;
       
     }
     cout<<"Player 1 Probability: "<<(PlayerOneStands/GamesPlayed)<<endl;
     cout<<"Player 2 Probability: "<<(PlayerTwoStands/GamesPlayed)<<endl;
     cout<<"Player 3 Probability: "<<(PlayerThreeStands/GamesPlayed)<<endl;
     
     
     return 0;
 }
 */
