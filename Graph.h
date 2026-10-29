#ifndef GRAPH_H
#define GRAPH_H

using namespace std;

#define nodekey_t unsigned long long int // nodekey is an unsigned long ling int
#define INVALID_NODE_KEY ULLONG_MAX // invalid node key to mean UULONG_MAX which is 18446744073709551615
#include <unordered_map>
#include <string>
#include <set>
#include <vector>
//every graph edge instance should be created on the heap
struct GraphEdge{
    nodekey_t from;
    nodekey_t to;
    unsigned int weight;
};

class Graph{

    public:
    Graph(); // constructor and pass by reference
    Graph(const Graph&);
    ~Graph(); //destructor
    
    //both of these will throw an invalid_argument exception if invalid inputs are given
    //duplicate node keys or a node key that doesn't exist in the graph
    void AddNode(nodekey_t key = 0);
    const GraphEdge* AddEdge(nodekey_t fromNodeKey, nodekey_t toNodeKey, unsigned int weight = 0);

    //this method returns true if the given key is in use in the graph
    bool IsPresent(nodekey_t);

    //these are not actually used except for testing
    string NodesToString() const;
    string EdgesToString() const;


    //These next two functions both return a set since the order doesn't matter
    //get pointers to the edges that go out from a given node
   set<const GraphEdge*> GetOutwardEdgesFrom(nodekey_t nodekey) const;
   set<nodekey_t> GetNodes() const; // gets all nodes in graph
   
   size_t Size() const; // num edges
   size_t Order() const; // num nodes

   private:
   set<nodekey_t> nodes;
   vector<nodekey_t> nodeOrder;
   set<const GraphEdge*> edges;
   unordered_map<nodekey_t, vector<const GraphEdge*>> adj_list;

};

    
#endif
