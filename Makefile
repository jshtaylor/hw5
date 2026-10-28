all:
	g++ -Wall -g Graph.cpp GraphTestsStarter.cpp -o graph-tests

clean:
	-rm -f graph-tests
test:
	g++ -Wall -g Graph.cpp GraphTestsStarter.cpp -o graph-tests
	./graph-tests