#include <iostream>

const int N = 5;

bool isValid(int maze[N][N], int x, int y, int solution[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && solution[x][y] == 0);
}

bool solveMaze(int maze[N][N], int x, int y, int solution[N][N]) {
    if (x == N - 1 && y == N - 1) {
        solution[x][y] = 1;
        return true;
    }
    if (isValid(maze, x, y, solution)) {
        solution[x][y] = 1;
        if (solveMaze(maze, x + 1, y, solution)) {
            return true;
        }
        if (solveMaze(maze, x, y + 1, solution)) {
            return true;
        }
        if (solveMaze(maze, x - 1, y, solution)) {
            return true;
        }
        if (solveMaze(maze, x, y - 1, solution)) {
            return true;
        }
        solution[x][y] = 0;
        return false;
    }
    return false;
}

int main() {
    int maze[N][N] = {
        {1, 1, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 1, 1}
    };

    int solution[N][N] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    if (solveMaze(maze, 0, 0, solution)) {
        std::cout << "Solution Path Found:" << std::endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << solution[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "No solution exists." << std::endl;
    }
    return 0;
}