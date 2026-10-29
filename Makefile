all:
	g++ -Wall -g -O3 Graph.cpp GraphTests.cpp -o graph-tests
	g++ -Wall -g -O3 Graph.cpp BPQNode.cpp BPQTests.cpp -o bpq-tests
	g++ -Wall -g Graph.cpp BPQNode.cpp Dijkstra.cpp DijkstraTests.cpp -o dijk-tests

clean:
	-rm -f graph-tests bpq-tests dijk-tests
test:
	g++ -Wall -g Graph.cpp GraphTests.cpp -o graph-tests
	./graph-tests
bpq:
	g++ -Wall -g BPQNode.cpp BPQTests.cpp Graph.cpp -o bpq-tests
	./bpq-tests
final:
	g++ -Wall -g Graph.cpp BPQNode.cpp Dijkstra.cpp DijkstraTests.cpp -o dijk-tests
	./dijk-tests