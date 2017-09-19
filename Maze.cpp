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
#include <cstdlib>
#include "Maze.h"
#include "Edge.h"

using namespace std;

namespace MST{

    Maze::Maze(size_t size):
    count(0),
    pSize(),
    mSize()
    {}

    Maze::~Maze(){
    //Shouldn't need anything else here
    }

    void Maze::generate(Maze & maze, int n, int seed, double p){
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
                        int weight = rand() % n;
                        maze.matrix[i][j] = weight;
                        maze.matrix[j][i] = weight;
                        
                        string str_i = to_string(i);
                        string str_j = to_string(j);

                        Node i = maze.graph.find(str_i)->second;
                        Node j = maze.graph.find(str_j)->second;

                        i.putNeighbor(j, weight);
                        j.putNeighbor(i, weight);
                    }
                } 
            }
            Node zero = maze.graph.find("0")->second;
            Node invalid("-1");
            zero.setPred(invalid);
        }
    }

    vector < Edge > Maze::getMatrix(){
        vector < Edge > edges;
        int loc = 0;
        for (int i = 0; i < count; i++){
            for (int j = 0; j < count; j++){
                if (i == j) continue;
                if (matrix[i][j] == 0) continue;
                else {
                    if (j > i){
                        Edge e(matrix[i][j], i, j);
                        edges.push_back(e);
                    }
                }
            }
        }
        return edges;
    }

    vector < Edge > Maze::getList(){
        vector < Edge > edges;
        for (int i = 0; i < count -1; i++){
            string str = to_string(i);
            Node n = graph.find(str)->second;
            for (size_t j = 0; j < n.getSize(); j++){
                Node neighbor = n.getNeighbor(j);
                if (stoi(neighbor.getName()) > i){
                    Edge e(neighbor.getWeight(str), i , stoi(neighbor.getName()) );
                }
            }
        }
        return edges;
    }

    vector < Node > Maze::getMatrixNodes(){
        vector< Node > nodes;
        for ( int i = 0; i < count; i++){
            string str = to_string(i);
            Node n(str);
            nodes.push_back(n);
        }
        for ( int i = 0; i < count; i++){
            for ( int j = 0; j < count; j++){
                if (i==j) continue;
                if (matrix[i][j] == 0) continue;
                else{
                    nodes[i].putNeighbor(nodes[j], matrix[i][j]);
                    nodes[j].putNeighbor(nodes[i], matrix[i][j]);
                }
            }
        }
        return nodes;
    }

    vector < Node > Maze::getListNodes(){
        vector< Node > nodes;
        for (int i = 0; i < count; i++){
            string str = to_string(i);

            nodes.push_back(graph.find(str)->second);
        }
        return nodes;
    }

    string Maze::DFSInfo(){
        ostringstream oss{};
        oss<<"Depth-First Search:\n";
        oss<<"Vertices:  \n";
        for ( int i = 0; i < count; i ++)
            oss<<" i";
        oss<<"\nPredecessors: \n";
        for ( int i = 0; i < count; i ++){
            oss<< graph.find(to_string(i))->second.getPredecessor()->getName();
        }
        oss<<"\n";
        return oss.str();
    }

    string Maze::listInfo(){
        ostringstream oss{};
        oss<<"The graph as an adjacency list:\n";
        for (int i = 0; i < count; i++){
            oss<<graph.find(to_string(i))->second;
        }
        oss<<"\n";
        return oss.str();
    }

    string Maze::matrixInfo(){
        ostringstream oss{};
        oss<<"The graph as an adjacency matrix:\n\n";
        for (int i = 0; i < count; i++){
            oss<<" ";
            for (int j = 0; j < count; j++){
                if ( j == 0)
                    oss<<matrix[i][j];
                else
                    oss<<"    "<<matrix[i][j];
            }
            oss<<"\n\n";
        }
        return oss.str();
    }

}
