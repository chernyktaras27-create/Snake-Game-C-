#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
using namespace std;

// Game variables
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int tailLength;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

// Initialize game
void setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    tailLength = 0;
}

// Draw the game board
void draw() {
    system("cls"); // Clear screen

    // Top border
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    // Game field
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "#"; // Left border

            if (i == y && j == x)
                cout << "O"; // Snake head
            else if (i == fruitY && j == fruitX)
                cout << "F"; // Fruit
            else {
                bool print = false;
                for (int k = 0; k < tailLength; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o"; // Snake tail
                        print = true;
                    }
                }
                if (!print) cout << " "; // Empty space
            }

            if (j == width - 1) cout << "#"; // Right border
        }
        cout << endl;
    }

    // Bottom border
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score: " << score << endl; // Display score
}

// Handle player input
void input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            if (dir != RIGHT) dir = LEFT;
            break;
        case 'd':
            if (dir != LEFT) dir = RIGHT;
            break;
        case 'w':
            if (dir != DOWN) dir = UP;
            break;
        case 's':
            if (dir != UP) dir = DOWN;
            break;
        case 'x':
            gameOver = true; // Quit game
            break;
        }
    }
}

// Game logic
void logic() {
    // Save previous position of head
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    // Move tail
    for (int i = 1; i < tailLength; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Move head
    switch (dir) {
    case LEFT:  x--; break;
    case RIGHT: x++; break;
    case UP:    y--; break;
    case DOWN:  y++; break;
    default: break;
    }

    // Check for collision with fruit
    if (x == fruitX && y == fruitY) {
        score++;
        fruitX = rand() % width;
        fruitY = rand() % height;
        tailLength++;
    }

    // Check for collision with walls
    if (x < 0 || x >= width || y < 0 || y >= height)
        gameOver = true;

    // Check for collision with tail
    for (int i = 0; i < tailLength; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }
}

// Main function
int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Control speed
    }
    return 0;
}