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
        cout<<*a<<endl;
    }

    Node d("6");
    d.setPred(a);
    cout<<*d.getPredecessor()<<endl;

    Node e(d);
    cout<<"Original:"<<endl;
    cout<<d;
    cout<<"Pred: " << *d.getPredecessor()<<endl;
    cout<<"Pred name: " << d.getPredecessor()->getName()<<endl;

    cout<<"This is the copy: "<<endl;
    cout<<e;
    cout<<"Pred: " << *e.getPredecessor()<<endl;
    cout<<"Pred name: " << e.getPredecessor()->getName()<<endl;
}

int main(){
    test1();
    return 0;
}
