#ifndef MST_MAZE_H
#define MST_MAZE_H

#include <iostream>
#include <string>
#include <vector>

namespace MST {
    
    class Maze {

        private: /// Private data
            int count;
            size_t pSize;
            size_t mSize;
            vector<vector<int>> matrix;
            map<string, Node> graph;
        
        private: /// private Functions 
            string DFSInfo( Maze &maze);
            string listInfo( Maze &maze);
            string matrixInfo( Maze &maze);

        public: /// Creation
            Maze(size_t size);
            ~Maze();

        public: /// Mutation
            void generate(Maze & maze, int nodes, int seed, double value);
            vector< Edge > getMatrix(Maze &maze);
            vector< Edge > getList(Maze &maze);
            vector< Node > getMatrixNodes(Maze &maze);
            vector< Node > getListNodes(Maze &maze);

        public: /// Output
            friend ostream &operator<<(ostream &os, const Maze &maze);

    };
}
#endif
