#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void guessNumber(int target, int curr, int totalPlayers) {
    int guess;
    cout << "Player " << curr << ", enter your guess (1-100): ";
    cin >> guess;

    if (guess == target) {
        cout << "congratulations Player " << curr << " wins!\n";
        return;
    } else if (guess < target) {
        cout << "Too low!\n";
    } else {
        cout << "Too high!\n";
    }

    int nextPlayer = (curr % totalPlayers) + 1;
    guessNumber(target, nextPlayer, totalPlayers);
}

int main() {
    srand(time(0));

    int totalPlayers;
    cout << "Enter the number of players: ";
    cin >> totalPlayers;

    int target = rand() % 100 + 1;

    cout << "Guess the number between 1 and 100.\n";

    guessNumber(target, 1, totalPlayers);

    return 0;
}
