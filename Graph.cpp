#include "Graph.h"
#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>

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
    if(IsPresent(key)){
        throw invalid_argument("Duplicate key's are not allowed");
    }
    Graph::nodes.insert(key);
    Graph:: nodeOrder.push_back(key);
}

//both of these will throw an invalid_argument exception if invalid inputs are given
//duplicate node keys or a node key that doesn't exist in the graph

const GraphEdge* Graph::AddEdge(nodekey_t fromNodeKey, nodekey_t toNodeKey, unsigned int weight){
    if(!IsPresent(fromNodeKey) || !IsPresent(toNodeKey)){
        throw invalid_argument("One or both nodes do not exist in the graph");
    }
    auto it = adj_list.find(fromNodeKey); // this whole thing is to check for duplicates
    if(it != adj_list.end()){ // checks to see if the from key is in the hash map, if not returns adj_list.end()
        auto edgeIt = std::find_if(it->second.begin(), it->second.end(), // grabs the vector from the hashmap
        [&toNodeKey](const GraphEdge* edge) {
            return edge->to == toNodeKey; // Replace 'to' with your struct's destination member name
        });

    if (edgeIt != it->second.end()) {
        throw std::invalid_argument("Cannot input duplicate edges");
    }
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
    size_t count = 0;
    for(nodekey_t greg:nodeOrder){
        count ++;
        str +="(" +  to_string(greg) + ")";
        if(count != nodes.size()){
            str += ", ";
        }
    }
    str += "]";
    cout << str << "\n";
    return str;
}


string Graph::EdgesToString() const {
    string str = "[";
    size_t count = 0;
    for(const GraphEdge* jon : edges){
        count ++;
        str += "((" + to_string(jon ->from) + ")->(" + to_string(jon ->to) + ") w:" + to_string(jon ->weight) + ")";
        if(count != edges.size()){
            str += ", ";
        }
    }
    str +="]";
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
