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
        mark(Unknown),
        pSet(false),
        nSize(0),
        nCapacity(0),
        name(name),
        predecessor(0)
        {}

    Node::Node( const Node & other){
        this->rank = other.rank;
        this->mark = other.mark;
        this->pSet = other.pSet;
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


const string & Node::getName(){
    const string t = name;
    return name;
}

Node::Marked Node::getMarked(){
    return mark;
}

void Node::putNeighbor(Node * b, int weight){
    this->neighbors.push_back(b);
    this->weights.insert(pair<string, int>(b->name, weight));
}

Node* Node::getNeighbor(int loc){
    return this->neighbors[loc];
}

void Node::setPred(Node & pred){
    this->predecessor=&pred;
}
void Node::setMarked(Marked val){
    mark = val;
}

ostream & operator<<(ostream &os, const Node & n){
    os << n.name;
    os << "-> ";
    for ( auto const & val : n.neighbors){
        os << val->name;
        os << "(" << n.weights.find(val->name)->second << ") ";
    }
    return os<<endl;
}

bool Node::operator==( const Node & other){
    return stoi(this->name) == stoi(other.name);
}
    
bool Node::operator!=( const Node & other){
    return stoi(this->name) != stoi(other.name);
}

Node * Node::getPredecessor() const{
    return this->predecessor;
}

void Node::setRank(int rank){
    this->rank = rank;
}

vector<Node* > & Node::getNeighbors(){
    return this->neighbors;
}

int Node::getRank(){
    return rank;
}

size_t Node::getSize(){
    return this->nSize;
}

int Node::getWeight(string who){
    return weights.find(who)->second;
}

bool Node::predSet(){
    return this->pSet;
}



} /// Namespace MST
