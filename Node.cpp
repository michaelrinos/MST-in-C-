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

    Node::Node( string name ): 
        rank(0),
        marked(false),
        predSet(false),
        nSize(0),
        nCapacity(0),
        name(name),
        predecessor(NULL)
        {}

    Node::Node( const Node & other){
        this->rank = other.rank;
        this->marked = other.marked;
        this->predSet = other.predSet;
        this->nSize = other.nSize;
        this->nCapacity = other.nCapacity;
        this->name = other.name;
        this->predecessor = other.predecessor;
        this->weights = other.weights;
        this->neighbors = other.neighbors;
    }

    Node::~Node(){
        //Shouldn't need anything here
    }

void Node::putNeighbor(const Node & b, int weight){
    this->neighbors.push_back(b);
    this->weights.insert(pair<string, int>(b.name, weight));
}

void Node::setPred(Node & pred){
    this->predecessor=&pred;
}

ostream & operator<<(ostream &os, const Node & n){
    os << n.name;
    os << "-> ";
    for ( auto const & val : n.neighbors){
        os << val.name;
        os << "(" << n.weights.find(val.name)->second << ")";
    }
    return os<<endl;
}

bool Node::operator==( const Node & other){
    return stoi(this->name) == stoi(other.name);
}
    
}
