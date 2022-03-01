//
//  main.cpp
//  Tic Tac Toe
//
//  Created by Stanley Chong on 9/22/20.
//  Copyright © 2020 Stanley Chong. All rights reserved.

//  Stanley Chong
//  10/3/20
//  Assignment 1 - tic-tac-toe
//  CPSC 121 - 07
//  Program that simulates tic-tac-toe game

#include <iostream>
using namespace std;

void showGame(char game[3][3], int currentPlayer, char currentPlayerSymbol);
void showGameEnd(char game[3][3]);
bool win(char game[3][3], bool &run);

int main(int argc, const char * argv[]) {
    char game[3][3] =   {{' ',' ',' '}, // main 2D game array
                        {' ',' ',' '},
                        {' ',' ',' '}};
    int currentPlayer = 1;
    char currentPlayerSymbol = 'X';
    int row;
    int column;
    bool legalMove = true;
    bool run = true;
    int gameCounter = 0;
    bool gameWon = false;
    
    cout << "Welcome to Tic-Tac-Toe" << endl;
    cout << "======================" << endl;
    
    do{
    if ( legalMove == true ){ // display game only if move is legal
    showGame(game, currentPlayer, currentPlayerSymbol);
        }
    cout << "Which Row would you like?" << endl;
    cin >> row;
    cout << "Which Col would you like?" << endl;
    cin >> column;
        // if user input spot is already taken, ask for user input until move is legal
        if (game[row][column] != ' ' ){
            cout << "Illegal move" << endl;
            legalMove = false;
            continue;
        }
        //if user input spot is empty, continue program
        else if (game[row][column] == ' '){
            legalMove = true;
        }
        game[row][column] = currentPlayerSymbol; // set user input to correct symbol
        gameCounter = gameCounter + 1; // counts number of turns made
        
        win(game, run);
        if (run == false){ // if win, display game and end program
            gameWon = true;
            showGameEnd(game);
        }
        //if all spaces are filled and no player has won, end program on a draw
        if (gameCounter == 9 && gameWon != true){
            cout << "Cat's Game!" << endl;
            showGameEnd(game);
            run = false;
        }
        
        if (currentPlayer == 2){ // After player 2 turn, change to player 1 turn
            currentPlayer = 1;
            currentPlayerSymbol = 'X';
        }

        else if (currentPlayer == 1){ // After player 1 turn, change to player 2 turn
            currentPlayer = 2;
            currentPlayerSymbol = 'O';
        }
        
    } while (run == true);
    
    return 0;
}
// function to display player turn and game
void showGame(char game[3][3], int currentPlayer, char currentPlayerSymbol)
{
    cout << "Player "<< currentPlayer <<" turn "<< "'" << currentPlayerSymbol << "'" << endl;
    cout << ""<<game[0][0]<<"|"<<game[0][1]<<"|"<<game[0][2]<<"" << endl;
    cout << "-----" << endl;
    cout << ""<<game[1][0]<<"|"<<game[1][1]<<"|"<<game[1][2]<<"" << endl;
    cout << "-----" << endl;
    cout << ""<<game[2][0]<<"|"<<game[2][1]<<"|"<<game[2][2]<<"" << endl;
}
// function to display game when game is over
void showGameEnd(char game[3][3]){
    cout << ""<<game[0][0]<<"|"<<game[0][1]<<"|"<<game[0][2]<<"" << endl;
    cout << "-----" << endl;
    cout << ""<<game[1][0]<<"|"<<game[1][1]<<"|"<<game[1][2]<<"" << endl;
    cout << "-----" << endl;
    cout << ""<<game[2][0]<<"|"<<game[2][1]<<"|"<<game[2][2]<<"" << endl;
}
// function that determines win
bool win(char game[3][3], bool &run){
    for (int i = 0; i <3; i++){
    if ((game[i][0] != ' ') && (game[i][0] == game[i][1]) && (game[i][1] == game[i][2])){
        cout << game[i][0] << " Player Wins!" << endl;
        run = false;
    }
    if ((game[0][i] != ' ') && (game[0][i] == game[1][i]) && (game[1][i] == game[2][i])){
        cout << game[0][i] << " Player Wins!" << endl;
        run = false;
    }}
    if ((game[0][0] != ' ') && (game[0][0] == game[1][1]) && (game[1][1] == game[2][2])){
        cout << game[0][0] << " Player Wins!" << endl;
        run = false;
    }
    if ((game[2][0] != ' ') && (game[2][0] == game[1][1]) && (game[1][1] == game[0][2])){
        cout << game[2][0] << " Player Wins!" << endl;
        run = false;
    }
    return run;
}


