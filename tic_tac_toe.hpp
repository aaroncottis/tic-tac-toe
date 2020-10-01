// Header file for tic-tac-toe game

void intro();
void show_grid_positions();
void endgame(int wins_player1, int wins_player2);

int select_player(int player);
int change_player(int player);

bool check_move_valid(int position, std::vector<int> p1_positions, std::vector<int> p2_positions);
int check_win(std::vector<char> grid);

std::vector<char> show_grid(std::vector<int> p1_positions, std::vector<int> p2_positions);