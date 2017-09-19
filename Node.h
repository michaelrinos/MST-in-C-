#ifndef MST_NODE_H
#define MST_NODE_H

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

namespace MST {

class Node{

    private: 
        int rank;
        bool marked;
        bool pSet;
        size_t nSize;
        size_t nCapacity;
        string name;
        Node * predecessor;
        map<string, int> weights;
        vector<Node> neighbors;

    public: // Creation

        /// Makes a node with a given name
        Node(string name);

        /// Copy Constructor
        Node(const Node & other);

        /// Destructor
        ~Node();

    public: /// getters

        int getRank();

        bool getMarked();

        bool predSet();

        size_t getSize();

        string & getName();

        Node * getPredecessor();

        int getWeight(string who);
        
        Node & getNeighbor(int loc);

        vector<Node> getNeighbors();

    public:  /// Mutation

        /// Set a nodes neightbor
        void putNeighbor(const Node & b, int weight);

        /// Set a nodes parent
        void setPred(Node & pred);

        /// Set rank
        void setRank(int rank);
    
    public: /// operators
        bool operator==(const Node & other);
        bool operator!=(const Node & other);
        bool operator<(const Node & l);
        /// Prints node and neighbors with weights to get to each neighbor
        friend ostream &operator<<(ostream &os, const Node &n);

};
}

#endif
