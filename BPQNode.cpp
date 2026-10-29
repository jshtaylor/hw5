#include "BetterPriorityQueue.h"
#include <queue>
#include <vector>
#include <algorithm> // For std::find_if and std::make_heap
#include <string>
#include <climits>

using namespace std;

bool BetterPriorityQueue::Contains(BPQNode& node) const{ 
    // returns true if contains
    for(BPQNode Lauren: this->c){
        if(Lauren.gnode == node.gnode && Lauren.pri == node.pri){
            return true;
        }
    }
    return false;
}

bool BetterPriorityQueue::Update(BPQNode& dummy){
    //returns true if something was updated
    //checks for validity
    if( dummy.pri == INT_MAX || dummy.gnode == INVALID_NODE_KEY){
        return false;
    }
    //interate through, pass by reference means it can modify queue
    for(BPQNode& Fred: this->c){
        if(Fred.gnode == dummy.gnode){
            if(dummy.pri > Fred.pri){return false;}
            Fred.pri = dummy.pri;
            //Re-heapify the container to restore Min-Heap ordering
            make_heap(this->c.begin(), this->c.end(), greater<BPQNode>());
            return true;
        }
    }
    return false;
}

string BetterPriorityQueue::ToString(){
    //returns a string of the entire queue in format 
    //"[(6, pri: 0), (1, pri: 0), (2, pri: 1), (3, pri: 2), (4, pri: 3), (5, pri: 4)]";
    //i.e. [(key, pri: priority)]
    string str ="[";
    size_t count = 0;
    for(BPQNode Lamar: this->c){
        count ++;
        str += BPQNodeToString(Lamar);//we using the print function, its maybe faster who knows
        if(count != this->c.size()){
            str += ", ";
        }
    }
    return str +="]";
}

string BetterPriorityQueue::BPQNodeToString(BPQNode& node){
    //prints in the format wanted
    return "(" + to_string(node.gnode) + ", pri: " + to_string(node.pri) + ")";
}
