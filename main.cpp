#include <iostream>
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


}

void  input(){


}

void logic(){


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