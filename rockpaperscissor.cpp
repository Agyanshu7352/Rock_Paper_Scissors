// Rock‑Paper‑Scissors in C++
// -----------------------------------------
// 0 = Rock   | 1 = Paper | 2 = Scissors | 9 = Quit


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>

using namespace std;

enum class Move { ROCK = 0, PAPER = 1, SCISSORS = 2 };

string to_string(Move m) {
    switch (m) {
        case Move::ROCK:      return "Rock";
        case Move::PAPER:     return "Paper";
        case Move::SCISSORS:  return "Scissors";
    }
    return ""; 
}


int getWinner(Move player, Move cpu) {
    if (player == cpu) return 0;

    if ((player == Move::ROCK     && cpu == Move::SCISSORS) ||
        (player == Move::PAPER    && cpu == Move::ROCK)     ||
        (player == Move::SCISSORS && cpu == Move::PAPER))
        return 1;

    return -1;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int playerScore = 0, cpuScore = 0;

    cout << "\n=== Rock Paper Scissors ===\n";
    cout << "(Enter 0 for Rock, 1 for Paper, 2 for Scissors, 9 to quit)\n\n";

    while (true) {
        cout << "Your move: ";
        int choice;
        if (!(cin >> choice)) {
            
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter 0, 1, 2, or 9.\n";
            continue;
        }

        if (choice == 9) {
            cout << "\nFinal Score — You: " << playerScore << " | CPU: " << cpuScore << '\n';
            cout << "Thanks for playing!\n";
            break;
        }

        if (choice < 0 || choice > 2) {
            cout << "Invalid move! Please enter 0, 1, 2, or 9.\n";
            continue;
        }

        Move playerMove = static_cast<Move>(choice);
        Move cpuMove    = static_cast<Move>(std::rand() % 3);

        cout << "You played " << to_string(playerMove)
                  << ", CPU played " << to_string(cpuMove) << ".\n";

        int result = getWinner(playerMove, cpuMove);
        if (result == 0) {
            cout << "It's a draw!\n";
        } else if (result == 1) {
            cout << "You win this round!\n";
            ++playerScore;
        } else {
            cout << "CPU wins this round!\n";
            ++cpuScore;

        }
    cout << "Score — You: " << playerScore << " | CPU: " << cpuScore << "\n\n";
    }

    return 0;
}
