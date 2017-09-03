/**
 * @file MinHeapNode.cpp
 * @brief 
 * @author Michael E. Rinos
 * @version 0
 * @date 2017-09-02
 */

#include "MinHeapNode.h"

using namespace std;

namespace MST{
    
    MinHeapNode::MinHeapNode(int key, Node node):
        key(key),
        Node(node)
    {}

    MinHeapNode::~MinHeapNode

    int MinHeapNode::getKey(){
        return key;
    }

    Node & MinHeapNode::getNode(){
        return node;
    }
    
    void MinHeapNode::setKey(int key){
        this->key = key;
    }

    void MinHeapNode::setNode(Node & node){
        this->node = node;
    }

}
