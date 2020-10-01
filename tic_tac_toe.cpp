#include <iostream>
#include <vector>
#include "tic_tac_toe.hpp"
#include <limits>

int main(){
   start:
   char player1 = '0';
   char player2 = 'X';
   int wins_play1 = 0;
   int wins_play2 = 0;
   int num_turns = 0;
   int games_played = 0;
   int position = 0;
   int player = 0;
   int winner = 0;
   int num_rounds;
   std::vector<int> p1_positions;
   std::vector<int> p2_positions;
   std::vector<char> grid;

   intro();
   char temp;
   temp = std::cin.get();
   show_grid_positions();

   while ((std::cout << "Select number of rounds to play: ")
            && (!(std::cin >> num_rounds))) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
   while (games_played < num_rounds && wins_play1 < 2 && wins_play2 < 2){
      // Set which player goes first
      if (games_played == 0){
         while ((std::cout << "\nSelect which player goes first (1 or 2): ")
            && (!(std::cin >> player))) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
         player = select_player(player);
      }
      std::cout << "Round " << games_played +  1 << "\n";
      for (int i = 0; i < 9; i++){
         invalid_move:

         while ((std::cout << "Player " << player << " choose a position: ")
            && (!(std::cin >> position))) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
         if (check_move_valid(position, p1_positions, p2_positions)){
            if (player == 1){
               p1_positions.push_back(position);
            }
            else{
               p2_positions.push_back(position);
            }
            grid = show_grid(p1_positions, p2_positions);
         }
         else{
            std::cout << "Error: Invalid move or input already taken\n";
            goto invalid_move;
         }
         winner = check_win(grid);
         if (winner > 0){
            std::cout << "Player " << player << " wins the round!!";
            if (player == 1){
               wins_play1++;
            }
            else{
               wins_play2++;
            }
            break;
         }
         player = change_player(player);
      }
      games_played++;
      p1_positions.clear();
      p2_positions.clear();
   }

   endgame(wins_play1,wins_play2);

   // Allow to restart programme without re-running the exe
   std::cout << "Play again: (y or n)\n";
   std::cin >> temp;
   if (temp == 'y'){
      goto start;
   }
   else {
      std::cout << "Programme ending... goodbye!";
      return 0;
   }

}