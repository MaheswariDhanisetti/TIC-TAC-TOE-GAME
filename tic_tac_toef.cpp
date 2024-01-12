#include <bits/stdc++.h>
using namespace std;

class TicTacToe {
private:
    string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
    string player1;
    string player2;

    void getboard() {
        cout << "   " << " |" << "   " << " |" << "   " << endl;
        cout << " " << board[0] << " " << " |" << " " << board[1] << " " << " |" << " " << board[2] << " " << endl;
        cout << "   " << " |" << "   " << " |" << "   " << endl;
        cout << "---------------" << endl;
        cout << "   " << " |" << "   " << " |" << "   " << endl;
        cout << " " << board[3] << " " << " |" << " " << board[4] << " " << " |" << " " << board[5] << " " << endl;
        cout << "   " << " |" << "   " << " |" << "   " << endl;
        cout << "---------------" << endl;
        cout << "   " << " |" << "   " << " |" << "   " << endl;
        cout << " " << board[6] << " " << " |" << " " << board[7] << " " << " |" << " " << board[8] << " " << endl;
        cout << "   " << " |" << "   " << " |" << "   " << endl;
    }

    int count(string s) {
        int t = 0;
        for (int i = 0; i < 9; i++) {
            if (board[i] == s) {
                t = t + 1;
            }
        }
        return t;
    }

    string getwinner() {
        // Checking horizontally row-wise
        for (int i = 0; i < 3; i++) {
            if (board[i * 3] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2] && board[i * 3] != " ") {
                return board[i * 3];
            }
        }

        // Checking winner vertically column-wise
        for (int i = 0; i < 3; i++) {
            if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != " ") {
                return board[i];
            }
        }

        // Checking diagonally
        if (board[0] == board[4] && board[4] == board[8] && board[0] != " ") {
            return board[0];
        }
        if (board[2] == board[4] && board[4] == board[6] && board[2] != " ") {
            return board[2];
        }

        if (count("X") + count("O") < 9) {
            return "cont";
        } else {
            return "draw";
        }
    }

    void get_Player_choice(string playerName, string symbol) {
        while (true) {
            cout << playerName << ", select your position (1-9): ";
            int choice;
            cin >> choice;
            choice--; // Because 0-based indexing
            if (choice < 0 || choice > 8) {
                cout << "Invalid choice, please try again!" << endl;
            } else if (board[choice] != " ") {
                cout << "Invalid choice, please select an empty position!" << endl;
            } else {
                board[choice] = symbol;
                break;
            }
        }
    }

public:
    void playGame() {
        cout << "Enter X player name: ";
        cin >> player1;
        cout << "Enter O player name: ";
        cin >> player2;

        while (true) {
            system("cls");
            getboard();
            if (count("X") == count("O")) {
                cout << player1 << "'s Turn." << endl;
                get_Player_choice(player1, "X");
            } else {
                cout << player2 << "'s Turn." << endl;
                get_Player_choice(player2, "O");
            }
            string winner = getwinner();
            if (winner == "X" || winner == "O") {
                getboard();
                cout << (winner == "X" ? player1 : player2) << " won the game." << endl;
                break;
            } else if (winner == "draw") {
                cout << "Game is Draw." << endl;
                break;
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}

