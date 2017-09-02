/**
 * @file Maze.cpp
 * @brief 
 * @author Michael E. Rinos
 * @version 0
 * @date 2017-09-01
 */

#include <iostream>
#include <sstream>
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

        while(maze.count != n){
            maze.count = 0;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (i == j) continue;
                    double r = (double) rand() / RAND_MAX;
                    if ( r <= p){
                        int weight = rand % n;
                        maze.matrix[i][j] = weight;
                        maze.matrix[j][i] = weight;
                        
                        string str_i = to_string(i);
                        string str_j = to_string(j);

                        Node i = maze.graph.find(str_i).second;
                        Node j = maze.graph.find(str_j).second;

                        i.putNeighbor(j);
                        j.putNeighbor(i);
                    }
                } 
            }
            Noze zero = maze.graph.find("0");
            Node invalid("-1");
            zero.setPred(invalid);
            }
        }
    }

    vector < Edge > Maze::getMatrix(Maze & maze){
        vector < Edge > edges;
        int loc = 0;
        for (int i = 0; i < maze.count; i++){
            for (int j = 0; j < maze.count; j++){
                if (i == j) continue;
                if (maze.matrix[i][j] == 0) continue;
                else {
                    if (j > i){
                        Edge e(maze.matrix[i][j], i, j);
                        edges.push_back(e);
                    }
                }
            }
        }
        return edges;
    }

    vector < Edge > Maze::getList(Maze & maze){
        vector < Edge > edges;
        for (int i = 0; i < maze.count -1; i++){
            string str = to_string(i);
            Node n = maze.graph.find(str)->second;
            for (size_t j = 0; j < n.nSize; j++){
                Node neighbor = n.neighbors[j];
                if (stoi(neighbor.name) > i){
                    Edge e(neighbor.weights.find(str)->second , i, stoi(neighbor.name));
                }
            }
        }
        return edges;
    }

    vector < Node > Maze::getMatrixNodes(Maze & maze){
        vector< Node > nodes;
        for ( int i = 0; i < maze.count; i++){
            string str = to_string(i);
            Node n(str);
            nodes.push_back(n);
        }
        for ( int i = 0; i < maze.count; i++){
            for ( int j = 0; j < maze.count; j++){
                if (i==j) continue;
                if (maze.matrix[i][j] == 0) continue;
                else{
                    nodes[i].putNeighbor(nodes[j], maze.matrix[i][j]);
                    nodes[j].putNeighbor(nodes[i], maze.matrox[i][j]);
                }
            }
        }
        return nodes;
    }

    vector < Node > Maze::getListNodes(Maze & maze){
        vector< Node > nodes;
        for (int i = 0; i < maze.count; i++){
            string str = to_string(i);
            nodes.push_back(Node t(maze.graph.find(str)));
        }
        return nodes;
    }

    string Maze::DFSInfo(Maze & maze){
        ostringstream oss{};
        oss<<"Depth-First Search:\n";
        oss<<"Vertices:  \n";
        for ( int i = 0; i < maze.count; i ++)
            oss<<" i";
        oss<<"\nPredecessors: \n";
        for ( int i = 0; i < maze.count; i ++){
            oss<< maze.graph.find(to_string(i))->second.predecessor->name;
        }
        oss<<"\n";
        return oss.str();
    }

    string Maze::listInfo(Maze & maze){
        ostringstream oss{};
        oss<<"The graph as an adjacency list:\n";
        for (int i = 0; i < maze.count; i++){
            oss<<maze.graph.get(to_string(i))->second;
        }
        oss<<"\n";
        return oss.str();
    }

    string Maze::matrixInfo(Maze & maze){
        ostringstream oss{};
        oss<<"The graph as an adjacency matrix:\n\n";
        for (int i = 0; i < maze.count; i++){
            oss<<" ";
            for (int j = 0; j < maze.count; j++){
                if ( j == 0)
                    oss<<maze.matrix[i][j];
                else
                    oss<<"    "<<maze.matrix[i][j];
            }
            oss<<"\n\n";
        }
        return oss.str();
    }

}
