#include <iostream>
#include <vector>
#include "tic_tac_toe.hpp"

int main(){
   start:
   char player1 = '0';
   char player2 = 'X';
   int wins_play1 = 0;
   int wins_play2 = 0;
   int games_played = 0;


   intro();
   
   char temp;
   temp = std::cin.get();

   gridPosition();

   std::cout << "Player 1 choose position: ";

   std::cout << "Player 2 choose position: ";
   int position;
   std::cin >> position;


   

   endgame(wins_play1,wins_play2);
   std::cout << "Play again: (y or n)\n";
   char temp;
   std::cin >> temp;
   if (temp == 'y'){
      goto start;
   }
   else {
      std::cout << "Programme ending";
      return 0;
   }

}