#include <iostream>
#include <vector>

void intro(){
    std::cout << "===============================\n";
    std::cout << "          TIC TAC TOE          \n";
    std::cout << "Player 1 is 0 and Player 2 is X\n";
    std::cout << "         Best of three!        \n";
    std::cout << "===============================\n\n";
    std::cout << "Press enter to start: \n";
    }

void gridPosition(){
    std::cout << "         Board Positions        \n";
    std::cout << "            1 | 2 | 3           \n";
    std::cout << "            ---------           \n";
    std::cout << "            4 | 5 | 6           \n";
    std::cout << "            ---------           \n";
    std::cout << "            7 | 8 | 9           \n";
}

int check_for_win(std::vector<int> grid){
    // Check for horizontal lines

    // Check for vertical lines

    // Check for diagonal lines
        for (int i = 0; i < 2; i++){
            
        }

}


void endgame(int wins_play1,int wins_play2){
    if (wins_play1 > wins_play2){
        std::cout << "Player 1 wins!!";
    }
    else if (wins_play1 < wins_play2){
        std::cout << "Player 2 wins!!";
    }
    else{
        std::cout << "It is a draw!";
    }
}

