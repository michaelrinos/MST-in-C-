#ifndef MST_EDGE_H
#define MST_EDGE_H

namespace MST {
    
    class Edge{
        private:
            int weight;
            int row;
            int col;
        public:
            Edge(int weight, int row, int col);
            int getRow();
            int getCol();
            int getWeight();
            friend std::ostream& operator<< (std::ostream& stream, const Edge &e);
    };
    

}

#endif 
