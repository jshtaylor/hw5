all:
	g++ -Wall -g -O3 Graph.cpp GraphTests.cpp -o graph-tests
	g++ -Wall -g -O3 Graph.cpp BetterPriorityQueue.cpp BPQTests.cpp -o bpq-tests

clean:
	-rm -f graph-tests bpq-tests
test:
	g++ -Wall -g Graph.cpp GraphTestsStarter.cpp -o graph-tests
	./graph-tests
bpq:
	g++ -Wall -g BPQNode.cpp BPQTestsStarter.cpp Graph.cpp -o bpq-tests
	./bpq-tests