#include <iostream>
#include "Maze.h"

#define TEST_AMOUNT 2

int main(int argc, char * argv[]){
    MST::Maze maze(TEST_AMOUNT);
    double p = .5;
    int seed = 100000;
    maze.generate(maze, TEST_AMOUNT, seed, p);
    cout<<maze;
}
