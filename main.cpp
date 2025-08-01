#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
 using namespace std;


bool   gameOver;
const int width = 20;
const int height = 20;
int x,y, fruitX, fruitY,score;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;
 void setup(){
    
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;

}

void draw(){

     system("cls"); // screen cleaning

    // Upper limit
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    // Field
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "#"; // left border

            if (i == y && j == x)
                cout << "O"; // snake
            else if (i == fruitY && j == fruitX)
                cout << "F"; // food
            else
                cout << " "; // empty space

            if (j == width - 1) cout << "#"; // right border
        }
        cout << endl;
    }

    // Lower limit
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

  
    cout << "Score: " << score << endl;


}

void  input(){

if (_kbhit()) {
        char key = _getch(); 

        switch (key) {
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
        }
    }
}




void logic(){
    if (dir == LEFT)
    x--;
if (dir == RIGHT)
    x++;
if (dir == UP)
    y--;
if (dir == DOWN)
    y++;

   if (x ==fruitX && y==fruitY)
   score++;
   
   if (x<0||x>=width||y<0||y>= height)
   gameOver = true;
   
   

    
   
    
    


}





int main(){

    setup();
   
   while (!gameOver)
    {
    
    draw();
    input();
    logic();
    }
    





    return 0;

}