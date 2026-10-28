#include "Graph.h"
#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;


Graph::Graph(){
}

Graph::~Graph(){
    for(const GraphEdge* horace: edges){
        delete horace;
    }
    edges.clear();
}

//both of these will throw an invalid_argument exception if invalid inputs are given
//duplicate node keys or a node key that doesn't exist in the graph

void Graph::AddNode(nodekey_t key){
    Graph::nodes.insert(key);

}

//both of these will throw an invalid_argument exception if invalid inputs are given
//duplicate node keys or a node key that doesn't exist in the graph

const GraphEdge* Graph::AddEdge(nodekey_t fromNodeKey, nodekey_t toNodeKey, unsigned int weight){
    if(!IsPresent(fromNodeKey) || !IsPresent(toNodeKey)){
        throw invalid_argument("One or both nodes do not exist in the graph");
    }
    
    GraphEdge *edge = new GraphEdge{fromNodeKey, toNodeKey, weight}; // creates new edge struct as a pointer
    edges.insert(edge);// adds the edge to the set of edges
    adj_list[fromNodeKey].push_back(edge);
    return edge; // returns the edge
}

//this method returns true if the given key is in the graph
bool Graph::IsPresent(nodekey_t key){
     if (nodes.find(key) != nodes.end()){
            return true;
     } else{ return false;}
}

//these are not actually used except for testing
string Graph::NodesToString() const {
    string str = "[";
    for(nodekey_t greg:nodes){
        str +="(" +  to_string(greg) + ")";
        if(nodes.find(greg) != nodes.end()){
            str += ", ";
        }
    }
    str += "]";
    cout << str << "\n";
    return str;
}


string Graph::EdgesToString() const {
    string str = "[ ";
    for(const GraphEdge* jon : edges){
        str += "from: " + to_string(jon ->from) + "to: " + to_string(jon ->to) + "Weight: " + to_string(jon ->weight) + ", ";
    }
    str +=" ]";
    cout << str << "\n";
    return str;
}


//These next two functions both return a set since the order doesn't matter
//get pointers to the edges that go out from a given node
set<const GraphEdge*> Graph::GetOutwardEdgesFrom(nodekey_t nodekey) const {
    auto it = adj_list.find(nodekey); // grabs the data from the hashmap
    if (it != adj_list.end()) {
        // Only loops over edges starting from 'nodekey'
        return set<const GraphEdge*>(it->second.begin(), it->second.end()); // returns the set of all the outward edges
    }
    return {};
}


 // gets all nodes in graph
set<nodekey_t> Graph::GetNodes() const{
    return nodes;
}

// num edges
size_t Graph::Size() const{
    return edges.size();
}

// num nodes
size_t Graph::Order() const{
    return nodes.size();
}
