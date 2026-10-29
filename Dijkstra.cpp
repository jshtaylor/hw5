#include "Dijkstra.h"
#include "Graph.h"
#include "BetterPriorityQueue.h"



int dijkstra(nodekey_t start, nodekey_t end, const Graph *g){

    //map and prior Q
    unordered_map<nodekey_t, int> distances;
    BetterPriorityQueue pq = BetterPriorityQueue();
    set<nodekey_t> nodes = g->GetNodes();

    //populate distances map as infinity
    for (const auto& pair : nodes) {
        distances[pair] = INT_MAX;
    }
    //set start distance to 0
    distances[start] = 0;

    //adds all nodes to the BP
    for (const auto& pair : distances) {
        BPQNode node;
        node.gnode = pair.first;
        node.pri = pair.second;
        pq.push(node);
    }

    while (!pq.empty()) {
        BPQNode current = pq.top();
        pq.pop();

        // Target reached: return shortest distance immediately
        if (current.gnode == end) {
            return current.pri;
        }

        // Remaining nodes are unreachable
        if (current.pri == INT_MAX) {
            break;
        }

        //Retrieve the outward edge pointers set from the Graph class
        set<const GraphEdge*> outwardEdges = g->GetOutwardEdgesFrom(current.gnode);

        //Iterate through edge pointers
        for (const GraphEdge* edge : outwardEdges) {
            if (!edge) continue; // Safety check for null pointers

            // Calculate updated path weight
            unsigned long long int newDist = current.pri + edge->weight;

            // Relaxation step
            if (newDist < distances[edge->to]) {
                distances[edge->to] = newDist;

                // Prepare dummy node and update priority queue
                BPQNode dummy;
                dummy.gnode = edge->to;
                dummy.pri = newDist;

                pq.Update(dummy);
            }
        }
    }

    // Return distance to end node (INT_MAX if unreachable)
    return distances[end];
}
