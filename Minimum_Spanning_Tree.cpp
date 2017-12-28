#include <iostream>
#include <queue>
#include <limits.h>
#include "Edge.h"
#include "Maze.h"
#include "Node.h"
#include "MinHeapNode.h"

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

vector< Edge > prim (vector< Node> a){
    vector< Node > parent;
    vector< int > key;
    vector< Edge > MST;
    priority_queue< MinHeapNode > minHeap;
    Node n("-1");
    for (int i = 0; i < a.size(); i++){
        parent[i] = n;
        key[i] = INT_MAX;
        MinHeapNode m(key[i], a[i]);
        // Add to MinHeap
    }
    key[0] = 0;
    MinHeapNode m(0, a[0]);
    // Add to MinHeap
    
    while (minHeap.empty() == false){
        MinHeapNode u = minHeap.top();
        minHeap.pop();
        for ( auto n : (u.getNode().getNeighbors()) ){
            int name = stoi(n->getName());
            int weight = n->getWeight(u.getNode().getName());
            MinHeapNode neighbor(key[name], *n);
            if ( weight < key[name]){
                key[name] = weight;
                parent[name] = u.getNode();
                MinHeapNode t(weight, *n);
                //drease the key of the MinHeapNode with the same node
            }
        }
    }
    for (int i = 0; i < a.size(); i++){
        string str = to_string(i);
        Edge e( parent[i].getWeight(str), stoi(parent[i].getName()), i);
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
    Node * pp = p.getPredecessor();
    if ( p != *pp ){
        Node * daPred = find(*pp);
        p.setPred(*daPred);
    }
    return p.getPredecessor();
}

void Union(Node & u, Node & v){
    Node * i = find(u);
    Node * j = find(v);

    if (i->getRank() > j->getRank()){
        j->setPred(*i);
    } else {
        i->setPred(*j);
        if (i->getRank() == j->getRank()){
            j->setRank(j->getRank()+1);
        }
    }
}

vector< Edge> kruskal( vector< Edge > a){
    vector< Node > b;
    for (int i = 0; i < a.size(); i ++){
        Node n(to_string(i));
        b[i] = n;
    }
    
    int includedCount = 0;
    int edges = 0;

    vector< Edge > MST;
    int size = 0;

    while ( includedCount < a.size()-1){
        Node root1 = b[ a[edges].getRow() ];
        Node root2 = b[ a[edges].getCol() ];

        if (!root1.predSet()){
            root1.setPred(root1);
        }
        
        if (!root2.predSet()){
            root2.setPred(root2);
        }

        root1 = (*find(root1));
        root2 = (*find(root2));
       
        if (root1 != root2){
            MST[size++] = a[edges];
            includedCount++;
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
    if (low < j) quickSort(arr, low, j);
    if (high > i) quickSort(arr, i, high);

}

void countSort(vector< Edge> a, int k){
    vector < Edge > copy;
    vector< int > c;
    int i;

    for (i = 0; i < k; i++){
        ++c[ a[i].getWeight() ];
    }

    for ( i = 1; i < k; i++){
        c[i] += c[i-1];
    }
    
    for ( i = 0; i < k; i++){
        copy[c[a[i].getWeight()]-1] = a[i];
        --(c[a[i].getWeight()]);
    }

    for ( i = 0; i < k; i++){
        a[i] = copy[i];
    }

}

void insertionSort(vector< Edge> arr, int length){
   int i, j;
   Edge newValue(0,0,0);
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

void printSorts(vector<Edge> arr,int korp, int morl, int sort, long runTime, int printEdges) {
    printf("===================================\n");
    switch (korp){
        case 1:
            printf("KRUSKAL WITH ");
            switch (morl){
                case 1:
                    printf("MATRIX USING ");
                    break;
                case 2:
                    printf("LIST USING ");
                    break;
            }
            switch (sort) {
                case 1:
                    printf("INSERTION SORT\n");
                    break;
                case 2:
                    printf("COUNT SORT\n");
                    break;
                case 3:
                    printf("QUICKSORT\n");
                    break;
            }
            break;
        case 2:
            printf("PRIM WITH ADJACENCY ");
            switch (morl){
                case 1:
                    printf("MATRIX\n");
                    break;
                case 2:
                    printf("LIST\n");
                    break;
            }
            break;
    }
    int tWeight = 0;
    for (int i = 0; i < arr.size()-1; i++){
        if (&arr[i]){
            Edge temp = arr[i];

            if (printEdges){
                cout<<temp<<endl;
            }
            tWeight+=temp.getWeight();
        }
    }
    if (!printEdges)
        printf("\n");

    switch (korp){
        case 1:
            printf( "\nTotal weight of MST using Kruskal:  %d\n", tWeight);
            printf( "Runtime: %lu milliseconds\n\n", runTime);
            break;
        case 2:
            printf( "\nTotal weight of MST using Prim: %d\n", tWeight);
            printf( "Runtime: %lu milliseconds\n\n", runTime);
            break;
	}
}

void sorter(Maze maze, int korp, int lorm, int sort, int printEdges){
    time_t startTime;
    time_t endTime;
    //Edge lst[numbers];
    vector<Edge> lst;
    vector<Edge> MST;
    vector<Node> temp;


    switch (korp) {
        case 1:
            switch (lorm) {
                case 1:
                    startTime = time(0);
                    lst = maze.getMatrix();
                    break;
                case 2:
                    startTime = time(0);
                    lst = maze.getList();
                    break;
                default:
                    lst = maze.getMatrix();
                    break;
            }

            switch (sort) {
                case 1:
                    insertionSort(lst, lst.size());
                    break;
                case 2:
                    countSort(lst, lst.size());
                    break;
                case 3:
                    quickSort(lst, 0, lst.size());
                    break;
            }
            MST = kruskal(lst);
            endTime = time(0);
            break;
        case 2:
            switch (lorm){
                case 1:
                    startTime = time(0);
                    temp = maze.getMatrixNodes();
                    MST = prim(temp);
                    break;
                case 2:
                    startTime = time(0);
                    temp = maze.getListNodes();
                    MST = prim(temp);
					break;
			}
        endTime = time(0);
        break;
    }

    printSorts(MST, korp, lorm, sort, (endTime-startTime), printEdges);
}

} // namespace 

int main(int argc, const char* argv[]){
    if( argc !=2){
        printf("Input file not found \n");
        exit(EXIT_FAILURE);
    }
    const char * filename = argv[1];

    FILE * fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Failed to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    int n, seed;
    double p;

    fscanf(fp, "%d", &n);                                   //Get n value
    if (n < 2){                                             //Check n value is valid
        printf("n must be greater than 1\n");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d", &seed);                                //Get seed value
    if (!seed){
        printf("failed to retrieve seed value\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%lf", &p);                                  //Get p value
    if (p < 0 || p > 1){                                    //Check n value is valid
        printf("p must be between 0 and 1\n");
        exit(EXIT_FAILURE);
    }

    fclose(fp); //be kind rewind


    int print=0;
    if (n < 10)
        print = 1;

    const time_t startTime = time(0);
    //Init maze
    MST::Maze maze(n);
    maze.generate(maze, n, seed, p);
    const time_t endTime = time(0);

    if ( print ) {
        printf("TEST: n= %d, seed=%d, p=%f\n", n, seed, p);
        printf("Time to generate the graph: %lu milliseconds\n\n", (endTime - startTime));
        cout<<maze<<endl;
        //maze.printMatrix();
        //maze.printList();
        //maze.DFSInfo(maze);

        sorter(maze, 1, 1, 1, print);
        //sorter(maze, 1, 1, 2, print);
        //sorter(maze, 1, 1, 3, print);
        //sorter(maze, 1, 2, 1, print);
        //sorter(maze, 1, 2, 2, print);
        //sorter(maze, 1, 2, 3, print);


        //sorter(maze, 2, 1, 1, print);
        //sorter(maze, 2, 2, 1, print);

    } else {
        printf("\nTEST: n= %d, seed=%d, p=%f\n", n, seed, p);
        printf("Time to generate the graph: %lu milliseconds\n\n", (endTime - startTime));

        sorter(maze, 1, 1, 1, print);
        sorter(maze, 1, 1, 2, print);
        sorter(maze, 1, 1, 3, print);
        sorter(maze, 1, 2, 1, print);
        sorter(maze, 1, 2, 2, print);
        sorter(maze, 1, 2, 3, print);

        sorter(maze, 2, 1, 1, print);
        sorter(maze, 2, 2, 1, print);
    }
    return 0;
}
