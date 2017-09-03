#ifndef MST_MIN_HEAP_NODE_H
#define MST_MIN_HEAP_NODE_H

#include <iostream>

namespace MST {
    class MinHeapNode{
        private:
            int key;
            Node node;
        public:
            MinHeapNode(int key, Node node);
            ~MinHeapNode();

        public: /// getters
            int getKey();
            Node & getNode();
        public: /// setters
            void setKey(int key);
            void setNode(Node & node);



    };
}

#endif
