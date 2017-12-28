#include <iostream>
#include "Node.h"

using namespace MST;
using namespace std;

void test1(){
    Node a("0");
    Node b(a);
    Node c("5");
    cout<<a;
    cout<<b;
    a.putNeighbor(&c, 9);
    cout<<a;
    vector<Node*> v = a.getNeighbors();
    cout<<v.size()<<endl;
    for (auto a : v){
        cout<<a<<endl;
    }

}

int main(){
    test1();
    return 0;
}
