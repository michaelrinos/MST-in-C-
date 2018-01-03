#include <iostream>
#include "Edge.h"

using namespace MST;
using namespace std;

void test1(){
    Edge a(5, 0, 1);
    Edge b(5,0,2);
    Edge c(6,0,2);
    Edge d(1,1,2);
    if (a<b)
        cout<<"true"<<endl;
    cout<<a<<endl<<b<<endl;
    if (b<c)
        cout<<"true"<<endl;
    cout<<b<<endl<<c<<endl;

    
    if (d>c)
        cout<<"d > c"<<endl;
    cout<<"D: "<<d<<endl<<c<<endl;



}

int main(){
    test1();
    return 0;
}
