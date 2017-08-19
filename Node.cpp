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

    Node::Node( string && name ): 
        rank{0},
        marked{false},
        predSet{false},
        nSize{0},
        nCapacity{0},
        name{name},
        predecessor{NULL},
        Table{/*to:do gen table*/}
        {}


}


    



}
