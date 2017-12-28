#ifndef MST_NODE_H
#define MST_NODE_H

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

namespace MST {

class Node{
    public: 
        enum Marked { Unknown, Discovered, Visited};

    private: 
        int rank;
        Marked mark;
        bool pSet;
        size_t nSize;
        size_t nCapacity;
        string name;
        Node * predecessor;
        map<string, int> weights;
        vector<Node *> neighbors;

    public: // Creation

        /// Makes a node with a given name
        Node(string name);

        /// Copy Constructor
        Node(const Node & other);

        /// Destructor
        ~Node();

    public: /// getters

        int getRank();

        bool predSet();

        size_t getSize();

        const string & getName();

        Node * getPredecessor() const;

        int getWeight(string who);

        Node::Marked getMarked();
        
        Node * getNeighbor(int loc);

        vector<Node*> & getNeighbors();

    public:  /// Mutation

        /// Set a nodes neightbor
        void putNeighbor(Node * b, int weight);

        /// Set a nodes parent
        void setPred(Node & pred);

        ///
        void setMarked(Marked value);

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
