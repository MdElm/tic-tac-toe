#include <iostream>
// #include <fstream>
#include <stdlib.h>
#include <string>
#include <cstdlib>      // For rand and srand
#include <ctime>        // For the time function
#include "Matrix.h"
#include "disp.h"
#include "gameenums.h"

using namespace std;
using namespace disp;

struct Player {
    Ply p;
    Symbol sym;
};

void About();
void getUserChoice(int*, int, int);
void runGame();
bool winner(Matrix M, Symbol* win);
void playTurn(Matrix *M, Player);
void switchTurn(Player*);
void printTable(Matrix M);
char getSym(int num);
void getRowCol(int userChoice, int *row, int *col);
void printWinner(Player user, Symbol win);
// int  getRandNum(int n);

int main()
{
    // Stat stat;          // The stat of the game
    int userStatChoice;
    
    // Enter the main
    do
    {
        system("clear");
        
        Title("Tic-Tac-Toe");
        MainMenu();
        
        // Get user choice
        getUserChoice(&userStatChoice, 1, 3);
        
        switch ( userStatChoice )
        {
            case 1:
                system("clear");
                runGame();
                
                break;
            case 2:
                system("clear");
                About();
                break;
            case 3:
                cout << "Good Bye!\n";
                break;
        }
    }
    while ( userStatChoice != QUIT );
    
    return 0;
}

void About()
{
    cout << "\n\n";
    cout << "Info Are Lined here!!!\n";
    cout << "\n";
    
    cout << "Press <Enter> to back to main menu.\n";
    cin.get();
}

void getUserChoice(int* userChoice, int low, int high)
{
    bool goodChoice = false;
    
    do
    {
        cout << " > ";
        cin  >> *userChoice;
        cin.ignore();
        
        if ( (*userChoice >= low) && (*userChoice <= high) )
            goodChoice = true;
        
        if (!goodChoice)
            cout << "Please try again." << endl;
        
    } while (!goodChoice);
}

void runGame()
{
    int userChoice;
    Player player, user;
    char playAgain;
    Symbol win = NONE;
    string p_is;
    char usr_sym, com_sym;
    
    int init[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    Matrix M;                 // The Main matrix
    
    do
    {
        system("clear");
        
        PlayMenu();
        getUserChoice(&userChoice, 1, 2);
        user.p = USER;
        if (userChoice == 1)
        {
            user.sym = X;
            usr_sym = 'X';
            com_sym = 'O';
        }
        else
        {
            user.sym = O;
            usr_sym = 'O';
            com_sym = 'X';
        }
        
        // Initialize the game
        M.setMat(init);
        
        // The user will play first
        player = user;
        
        while ( !winner(M, &win) && M.getValue(0) )
        {
            system("clear");
            
            cout << "\n    User (" << usr_sym << ")  -  Computer (" << com_sym << ")" << endl; 
            
            printTable(M);
            
            if ( player.p == COMPUTER )
            {
                cout << "Thinking...\n";
                system("sleep 2");
            }
            
            playTurn(&M, player);
            switchTurn(&player);
        }
        
        system("clear");
        
        printTable(M);
        
        if ( win != NONE )
            printWinner(user, win);
        
        cout << "Do you want to play again? (y/n): ";
        cin  >> playAgain;
        cin.ignore();
        
    } while ( toupper(playAgain) == 'Y' );
    
}

bool winner(Matrix M, Symbol* win)
{
    // bool thereIsWinner = false;
    
    for(int i = 0; i < 3; i++)
    {
        if ( M.rowElementsEql(i, 1) )
        {
            *win = X;
            return true;
        }
        else if ( M.rowElementsEql(i, 2) )
        {
            *win = O;
            return true;
        }
    }
    
    for(int i = 0; i < 3; i++)
    {
        if ( M.colElementsEql(i, 1) )
        {
            *win = X;
            return true;
        }
        else if ( M.colElementsEql(i, 2) )
        {
            *win = O;
            return true;
        }
    }
    
    for(int i = 1; i <= 2; i++)
    {
        if ( M.diagElementsEql(i, 1) )
        {
            *win = X;
            return true;
        }
        else if ( M.diagElementsEql(i, 2) )
        {
            *win = O;
            return true;
        }
    }
}

void switchTurn(Player *player)
{
    if (player->p == USER)
    {
        player->p = COMPUTER;
        if (player->sym == X)
            player->sym = O;
        else
            player->sym = X;
    }
    else if (player->p == COMPUTER)
    {
        player->p = USER;
        if (player->sym == X)
            player->sym = O;
        else
            player->sym = X;
    }
}

void playTurn(Matrix *M, Player player)
{
    int arr[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    Matrix P(arr);
    int userChoice, row, col;
    bool goodChoice = false;
    
    if ( player.p == USER )                     // Here the turn of the user
    {
        do
        {
            getUserChoice(&userChoice, 1, 9);
            getRowCol(userChoice, &row, &col);
            
            if ( M->getElement(row, col) == 0 )
            {
                P.setElement(row, col, player.sym);
                goodChoice = true;
            }
            
            if (!goodChoice)
                cout << "Already fill. Try again.\n";
        
        } while (!goodChoice);
        
        (*M) = (*M) + P;
    }
    else if ( player.p == COMPUTER )            // Here the computer playing
    {
        
        do
        {
            srand( time(0) );
            
            userChoice = 1+rand()%9;
            
            getRowCol(userChoice, &row, &col);
            
            if ( M->getElement(row, col) == 0 )
            {
                // Debuging
                // cout << "OK!\n";
                P.setElement(row, col, player.sym);
                goodChoice = true;
            }
        
        } while (!goodChoice);
        
        (*M) = (*M) + P;
        
        // Debuging
        // cout << "\n\nThis Statment is for Debuging purpose\n";
        // M->print();
    }
    
}

void printTable(Matrix M)
{
    cout << "\n\n";
    cout << "\t+---+---+---+\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\t| " << getSym(M.getElement(i, 0)) << " | "
             << getSym(M.getElement(i, 1)) << " | " 
             << getSym(M.getElement(i, 2)) << " |" << endl;
        cout << "\t+---+---+---+\n";
    }
    cout << "\n";
}

char getSym(int num)
{
    char sym;
    
    switch (num)
    {
        case 0:
            sym = ' ';
            break;
        case X:
            sym = 'X';
            break;
        case O:
            sym = 'O';
            break;
        default:
            sym = ' ';
            break;
    }
    
    return sym;
}

void getRowCol(int userChoice, int *row, int *col)
{
    switch (userChoice)
    {
        case 1:
            *row = 0;
            *col = 0;
            break;
        case 2:
            *row = 0;
            *col = 1;
            break;
        case 3:
            *row = 0;
            *col = 2;
            break;
        case 4:
            *row = 1;
            *col = 0;
            break;
        case 5:
            *row = 1;
            *col = 1;
            break;
        case 6:
            *row = 1;
            *col = 2;
            break;
        case 7:
            *row = 2;
            *col = 0;
            break;
        case 8:
            *row = 2;
            *col = 1;
            break;
        case 9:
            *row = 2;
            *col = 2;
            break;
    }
}

void printWinner(Player user, Symbol win)
{
    if ( user.sym == win )
        cout << "\nYOU WIN!!\n";
    else
        cout << "\nCOMPUTER WIN! you lose\n";
}