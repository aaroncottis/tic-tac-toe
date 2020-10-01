#include <iostream>
#include <vector>

void intro(){
    std::cout << "===============================\n";
    std::cout << "          TIC TAC TOE          \n";
    std::cout << "Player 1 is 0 and Player 2 is X\n";
    std::cout << "         Best of three!        \n";
    std::cout << " Press Ctrl+C to exit the game \n";
    std::cout << "===============================\n\n";
    std::cout << "Press enter to start: \n";
    }

void show_grid_positions(){
    std::cout << "         Board Positions        \n";
    std::cout << "            1 | 2 | 3           \n";
    std::cout << "            ---------           \n";
    std::cout << "            4 | 5 | 6           \n";
    std::cout << "            ---------           \n";
    std::cout << "            7 | 8 | 9           \n\n";
}

std::vector<char> show_grid(std::vector<int> p1_positions, std::vector<int> p2_positions){
    
    std::vector<char> grid = {'-','-','-','-','-','-','-','-','-'};

    for (int i = 0; i < p1_positions.size(); i++){
        grid[p1_positions[i]-1] = '0';
    }
    for (int i = 0; i < p2_positions.size(); i++){
        grid[p2_positions[i]-1] = 'X';
    }

    for (int i = 0; i < 9; i++){
        if ((i+1)%3 != 0){
            std::cout << grid[i] << " ";
        }
        else{
            std::cout << grid[i] << "\n";
        }
            
    }
    return grid;
}

int select_player(int player){
    if (player == 1 || player == 2){
        return player;
    }
    else{
        std::cout << "Error: Select player input must be 1 or 2. Defaulted to player 1 first.\n";
        return 1;
    }
}

int change_player(int player){
    if (player == 1){
        return 2;
    }
    else{
        return 1;
    }
}

bool check_move_valid(int position, std::vector<int> p1_positions, std::vector<int> p2_positions){

    bool valid = true;

    if (position > 9 || position < 1){
        valid = false;
    }

    for (int i = 0; i < p1_positions.size(); i++){
        if (valid == false){
            break;
        }
        if (position == p1_positions[i]){
            valid = false;
            break;
        }
    }
    for (int i = 0; i < p2_positions.size(); i++){
        if (valid == false){
            break;
        }
        if (position == p2_positions[i]){
            valid = false;
            break;
        }
    }
    return valid;
}

int check_win(std::vector<char> grid){

    int winner = 0;
    std::vector<int> check_positions;
    // Check diagonals
    if (grid[0] == grid[4] && grid[4] == grid[8] && grid[8] != '-'){
        if (grid[0] == '0'){
            winner = 1;
        }
        else{
            winner = 2;
        }
        goto winner_found;
        }

    if (grid[2] == grid[4] && grid[4] == grid[6] && grid[6] != '-'){
        if (grid[0] == '0'){
            winner = 1;
        }
        else{
            winner = 2;
        }
        goto winner_found;
        }
    
    // Check horizontal lines
    for (int i = 0; i < 3; i++){
        if (grid[0+i*3] == grid[1+i*3] && grid[1+i*3] == grid[2+i*3] && grid[2+i*3] != '-'){
            if (grid[0+i*3] == '0'){
            winner = 1;
        }
        else{
            winner = 2;
        }
        }
    }
    // Check vertical lines
    for (int i = 0; i < 3; i++){
        if (grid[0+i] == grid[3+i] && grid[3+i] == grid[6+i] && grid[6+i] != '-'){
            if (grid[0+i] == '0'){
            winner = 1;
        }
        else{
            winner = 2;
        }
        }
    }   

    winner_found:
    return winner;
}

void endgame(int wins_play1,int wins_play2){
    if (wins_play1 > wins_play2){
        std::cout << "\nPlayer 1 wins!!\n\n";
    }
    else if (wins_play1 < wins_play2){
        std::cout << "\nPlayer 2 wins!!\n\n";
    }
    else{
        std::cout << "\nMatch was a draw!\n\n";
    }
}

