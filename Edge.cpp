#include <iostream>
#include "Edge.h"

using namespace std;

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

bool Edge::operator>(const Edge & b){
    int result = this->weight - b.weight;
    if ( result == 0){
        if (this->row - b.row == 0)
            return (this->col - b.col) > 0;
        else 
            return (this->row - b.row) > 0;
    }
    return result > 0;
}

bool Edge::operator<(const Edge & b){
    int result = this->weight - b.weight;
    if ( result == 0){
        if (this->row - b.row == 0)
            return (this->col - b.col) < 0;
        else 
            return (this->row - b.row) < 0;
    }
    return result < 0;
}
        

}
