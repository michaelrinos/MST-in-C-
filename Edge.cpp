#include "Edge.h"

namespace MST {
Edge::Edge(int weight, int row, int col):
    weight{weight},
    row{row},
    col{col}
{}

int Edge::getRow(){
    return row;
}

int Edge::getCol(){
    return col;
}

int Edge::getWeight(){
    return weight;
}

ostream & operator<<(ostream &os, const Edge & e){
    return os << e.row << " " << e.col << " weight = " << e.weight << endl;
}
        

}
