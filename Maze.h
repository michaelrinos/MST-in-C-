#ifndef MST_MAZE_H
#define MST_MAZE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Node.h"
#include "Edge.h"

using namespace std;

namespace MST {
    
    class Maze {

        private: /// Private data
            int count;
            size_t pSize;
            size_t mSize;
            vector<vector<int> > matrix;
            map<string, Node *> graph;
        
        private: /// private Functions 
            string DFSInfo() const;
            string listInfo() const;
            string matrixInfo() const;
            void canReachDFS(string startNode);

        public: /// Creation
            Maze(size_t size);
            ~Maze();

        public: /// Mutation
            void generate(Maze & maze, int nodes, int seed, double value);
            vector< Edge > getMatrix();
            vector< Edge > getList();
            vector< Node > getMatrixNodes();
            vector< Node > getListNodes();

        public: /// Output
            friend ostream &operator<<(ostream &os, const Maze &maze);
            void displayGraph();

    };
}
#endif
