#include <iostream>
#include <vector> 
using namespace std;

std::vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int player_choice; // to delete
int turn = 0;
char winner;
bool game_ended = false;
char player = 'X';


char is_winner() {
    if (board[0] == board[1] && board[0] == board[2]) {
        return board[0];
    }
    if (board[0] == board[4] && board[0] == board [8]) {
        return board[0];
    }
    if (board[0] == board[3] && board[0] == board [6]) {
        return board[0];
    } 
    if (board[3] == board[4] && board[3] == board [5]) {
        return board[4];
    }
    if (board[2] == board[4] && board[2] == board [6]) {
        return board[4];
    }
    if (board[6] == board[7] && board[6] == board [8]) {
        return board[7];
    } 
    if (board[1] == board[4] && board[1] == board [7]) {
        return board[7];
    }
    if (board[2] == board[5] && board[2] == board [8]) {
        return board[8];
    } 
    else {
        return ' ';
    }
}   

void display_board() {
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n"; // board index  0, 1, 2
    std::cout << "---|---|---\n";
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n"; // board index 3, 4, 5
    std::cout << "---|---|---\n"; 
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n"; // board index 6, 7, 8
}

void end_game() {
    std::cout << is_winner() <<" WINS!\n\n\n";
    game_ended = true;
}

bool filled_up() {
    bool filled_up = false;

    if (turn > 8) {
        filled_up == true;
        std::cout << "The board is full. Start a new game.\n";
        end_game();
    } 
    return filled_up;
}

void toggle_player() {
    if (player == 'X') {
        player = 'O';
    }
    else {
        player = 'X';
    }
}

void input() {
    // get the input from the player, and set it on the board

    int choice;
    
    std::cout << "Enter the number of the box: ";
    std::cin >> choice;

    if (choice == 1) {
        board[0] = player;
    }
    if (choice == 2) {
        board[1] = player;
    }
    if (choice == 3) {
        board[2] = player;
    }
    if (choice == 4) {
        board[3] = player;
    }
    if (choice == 5) {
        board[4] = player;
    }
    if (choice == 6) {
        board[5] = player;
    }
    if (choice == 7) {
        board[6] = player;
    }
    if (choice == 8) {
        board[7] = player;
    }
    if (choice == 9) {
        board[8] = player;
    }
}


int main() {

    while (!game_ended) {
        display_board();
        input();
        turn += 1;
        if (is_winner() != ' ') {
            break;
        } ;
        if (filled_up()) {
            game_ended = true;
            break;
        };
        toggle_player();

    }
    end_game();

}