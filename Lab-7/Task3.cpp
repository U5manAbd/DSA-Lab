#include <iostream>
using namespace std;

#define N 4

int maze[N][N] = {
    {1, 1, 1, 1},
    {0, 0, 0, 1},
    {1, 1, 0, 1},
    {1, 1, 1, 1}
};

int sol[N][N];

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N &&
            maze[x][y] == 1 && sol[x][y] == 0);
}

bool solveMazeUtil(int x, int y, int targetX, int targetY) {
    if (x == targetX && y == targetY) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(x, y)) {
        sol[x][y] = 1;

        if (solveMazeUtil(x + 1, y, targetX, targetY)) return true; // Down
        if (solveMazeUtil(x, y + 1, targetX, targetY)) return true; // Right
        if (solveMazeUtil(x, y - 1, targetX, targetY)) return true; // Left
        if (solveMazeUtil(x - 1, y, targetX, targetY)) return true; // Up

        sol[x][y] = 0;
    }
    return false;
}

bool solveMaze(int targetX, int targetY) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sol[i][j] = 0;

    if (!solveMazeUtil(0, 0, targetX, targetY)) {
        cout << "No solution exists" << endl;
        return false;
    }

    cout << "Path found:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
    return true;
}

int main() {
    solveMaze(2, 0);
}
