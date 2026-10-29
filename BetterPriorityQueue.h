#ifndef BETTER_PRIORITY_QUEUE_H
#define BETTER_PRIORITY_QUEUE_H

#include "Graph.h"
#include <queue>
#include <vector>
#include <algorithm> // For std::find_if and std::make_heap
#include <string>
#include <climits>

// This is used for the items in the BetterPriorityQueue
struct BPQNode {
	int pri = INT_MAX;
	bool visited = false;
	nodekey_t gnode = INVALID_NODE_KEY;
	
	bool operator<(const BPQNode &other) const {
		return pri < other.pri;
	}

	bool operator>(const BPQNode &other) const {
		return pri > other.pri;
	}
	
	bool operator==(const BPQNode &other) const {
		return this->gnode == other.gnode;
	}
};


// ---------------------------------------------------------------------------
// 2. Derived Priority Queue Class
// ---------------------------------------------------------------------------
class BetterPriorityQueue : public std::priority_queue<BPQNode, std::vector<BPQNode>, std::greater<BPQNode>> {
public:
    // Function declarations
    bool Contains(BPQNode& node) const;
    bool Update(BPQNode& dummy);
	string ToString();
	static string BPQNodeToString(BPQNode& node);

};

#endif // BETTER_PRIORITY_QUEUE_HPP