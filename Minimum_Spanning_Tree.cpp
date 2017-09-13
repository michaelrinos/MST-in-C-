#include <iostream>
#include "Edge.h"
#include "Maze.h"
#include "Node.h"

using namespace std;

namespace MST {

///////////////////////////////////////////////////////////////////////////////
//    _____      _           _        _____ _          __  __
//   |  __ \    (_)         ( )      / ____| |        / _|/ _|
//   | |__) | __ _ _ __ ___ |/ ___  | (___ | |_ _   _| |_| |_
//   |  ___/ '__| | '_ ` _ \  / __|  \___ \| __| | | |  _|  _|
//   | |   | |  | | | | | | | \__ \  ____) | |_| |_| | | | |
//   |_|   |_|  |_|_| |_| |_| |___/ |_____/ \__|\__,_|_| |_|
//
///////////////////////////////////////////////////////////////////////////////

vector< Edge > prim (vector< vector< Node> a){
    vector< Node > parent;
    vector< int > key;
    vector< Edge > MST;
    priority_queue< MinHeapNode > minHeap;
    Node n("-1");
    for (int i = 0; i < numbers; i++){
        parent[i] = n;
        key[i] = INT_MAX;
        MinHeapNode m(key[i], a[i]);
        // Add to MinHeap
    }
    key[0] = 0;
    MinHeapNode m(0, a[0]);
    // Add to MinHeap
    
    while (minHeap.empty() == false){
        MinHeapNode u = pq.pop();
        for ( auto n : u.getNode.neighbors){
            int name = stoi(n.name);
            int weight = n.weights.find(u.getNode.name);
            MinHeapNode neighbor(n, key[name]);
            if ( minHeap.contains(neighbor) && weight < key[name]){
                key[name] = weight;
                parent[name] = u.getNode();
                MinHeapNode t(weight, n);
                //drease the key of the MinHeapNode with the same node
            }
        }
    }
    for (int i = 0; i < numbers; i++){
        string str = stoi(i);
        Edge e( parent[i].weights.find(str), stor(parent[i].name), i);
        MST.push_back(e);
    }
    return MST;

}

///////////////////////////////////////////////////////////////////////////////
//    _                   _     _         _    _____ _          __  __
//   | |                 | |   | |       | |  / ____| |        / _|/ _|
//   | | ___ __ _   _ ___| |__ | | ____ _| | | (___ | |_ _   _| |_| |_
//   | |/ / '__| | | / __| '_ \| |/ / _` | |  \___ \| __| | | |  _|  _|
//   |   <| |  | |_| \__ \ | | |   < (_| | |  ____) | |_| |_| | | | |
//   |_|\_\_|   \__,_|___/_| |_|_|\_\__,_|_| |_____/ \__|\__,_|_| |_|
//
///////////////////////////////////////////////////////////////////////////////

Node * find(Node p){
    Node * pp = p.predecessor;
    if ( p != &pp ){
        Node * daPred = find(pp);
        p.setPredecessor(daPred);
    }
    return p.predecessor;
}

void Union(Node & u, Node & v){
    Node * i = find(u);
    Node * j = find(v);

    if (i->rank > j->rank){
        j.setPredecessor(i);
    } else {
        i.setPredecessor(j);
        if (i->rank == j->rank){
            j->rank = j->rank+1;
        }
    }
}

vector< Edge> kruskal( vector< Edge >){
    vector< Node > b;
    for (int i = 0; i < numbers; i ++){
        Node n(to_string(i));
        b[i] = n;
    }
    
    int includedCount = 0;
    int edge = 0;

    vector< Edge > MST;
    int size = 0;

    while ( includedCount < numbers-1){
        Node root1 = b[ a[edges].row ];
        Node root2 = b[ a[edges].col ];

        if (!root1.predSet){
            root1.setPred(root1);
        }
        
        if (!root2.predSet){
            root2.setPred(root2);
        }

        root1 = find(root1);
        root2 = find(root2);
       
        if (root1 != root2){
            MST[size++] = a[edges];
            includeCount++;
            Union(root1,root2);
        }
        edges++;

    }
    return MST;

}

//////////////////////////////////////////////////////////////////////////////
//
//     _____            _   _                _____ _          __  __
//    / ____|          | | (_)              / ____| |        / _|/ _|
//   | (___   ___  _ __| |_ _ _ __   __ _  | (___ | |_ _   _| |_| |_
//    \___ \ / _ \| '__| __| | '_ \ / _` |  \___ \| __| | | |  _|  _|
//    ____) | (_) | |  | |_| | | | | (_| |  ____) | |_| |_| | | | |
//   |_____/ \___/|_|   \__|_|_| |_|\__, | |_____/ \__|\__,_|_| |_|
//                                   __/ |
//                                  |___/
///////////////////////////////////////////////////////////////////////////////

void quickSort(vector< Edge> arr, int low, int high){
    if (low >= high) return;
    int middle = low + (high - low) / 2;
    Edge pivot = arr[middle];
    int i = low;
    int j = high;
    while ( i <= j){
        while (arr[i] < pivot) i++; 
        while (arr[j] > pivot) j--; 
        
        if ( i <= j ) {
            Edge temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (low < j) quicksort(arr, low, j);
    if (high > i) quicksort(arr, i, high);

}

void countSort(vector< Edge> a, int k){
    vector < Edge > copy;
    vector< int > c;
    int i;

    for (i = 0; i < k; i++){
        ++c[ a[i].weight ];
    }

    for ( i = 1; i < k; i++){
        c[i] += c[i-1];
    }
    
    for ( i = 0; i < k; i++){
        copy[c[a[i].weight]-1] = a[i];
        --(c[a[i].weight]);
    }

    for ( i = 0; i < k; i++){
        a[i] = copy[i];
    }

}

void insertionSort(vector< Edge> arr, int length){
   int i, j;
   Edge newValue;
   for (i = 1; i < length; i++){
        newValue = arr[i];
        j = i;
        while ( j > 0 && newValue < arr[j-1] ){
            arr[j] = arr[j-1];
            j--;
        }
   arr[j] = newValue;
   }
}


} // namespace 
