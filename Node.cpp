/**
 * @file Node.cpp
 * @brief Node Class representing nodes in a MST.
 * @author Michael E. Rinos
 * @version 0
 * @date 2017-08-16
 */

#include <iostream>
#include "Node.h"

using namespace std;

namespace MST{

Node::Node( string && name ): 
    rank{0},
    marked{false},
    predSet{false},
    nSize{0},
    nCapacity{0},
    name{name},
    predecessor{NULL}
    {}

Node::Node( const Node & other){
    this->rank = other.rank;
    this->marked = other.marked;
    this->predSet = other.predSet;
    this->nSize = other.nSize;
    this->nCapacity = other.nCapacity;
    this->name = other.name;
    this->predecessor = other.predecessor;
    this->weighs = other.weights;
    this->neighbors = other.neighbors;
}

Node::~Node(){
    //Shouldn't need anything here
}

Node::putNeighbor(Node & a, const Node & b, int weight){

}
    
}
