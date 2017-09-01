/**
 * @file Maze.cpp
 * @brief 
 * @author Michael E. Rinos
 * @version 0
 * @date 2017-09-01
 */

#include <iostream>
#include <string>
#include <stdlib>
#include "Maze.h"

using namespace std;
namespace MST{

    Maze::Maze():
    count(0),
    pSize(),
    mSize()
    {}

    Maze::~Maze(){
    //Shouldn't need anything else here
    }

    void Maze::generate(Maze & maze, int n, int seed, double value){
        maze.pSize = n;
        for ( int i = 0; i < n; i++){
            string str = to_string(i);
            Node n(str);
            maze.graph.insert(pair<string, Node> (str, n));
        }
        
        srand(seed);

        while

    }

    vector < Edge > Maze::getMatrix(Maze & maze){

    }

    vector < Edge > Maze::getList(Maze & maze){

    }

    vector < Node > Maze::getMatrixNodes(Maze & maze){

    }

    vector < Node > Maze::getListNodes(Maze & maze){

    }

    string Maze::DFSInfo(Maze & maze){

    }

    string Maze::listInfo(Maze & maze){

    }

    string Maze::matrixInfo(Maze & maze){

    }

}
