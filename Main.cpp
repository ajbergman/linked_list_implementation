#include <functional>
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "LinkedList.h"

int main(int argc, char* argv[]) {
	using namespace std;
	
	if(argc != 3) {
		cerr << "Incorrect number of command line arguments." << endl;
		cerr << "Usage: " << argv[0] << " <filename> <K>" << endl;
		exit(EXIT_FAILURE);
	}
	
	ifstream infile(argv[1]);
    // check to see if file opening succeeded
    if ( !infile.is_open() ) {
        cout<<"Could not open file\n";
        exit(EXIT_FAILURE);
	}

	
    //read input
	LinkedList<int> ll;
	int input;
	while( infile >> input) {
		ll.PushBack(input);
	}
	LinkedList<int> ll2 = ll;

	int k = atoi(argv[2]);        // k, divisor function
	

	ll.Display();
	cout << ll.Size() << endl;


	// Only keep the elements that are divisible by k
	auto isDivisibleByK = [k](int x){ return x % k == 0; };
	auto notDivisibleByK = [k](int x){ return x % k != 0; };
	ll.Filter(isDivisibleByK);
	ll.Display();
	cout << ll.Size() << endl;
	// And this time the ones not visible by k
	ll2.Filter(notDivisibleByK);
	ll2.Display();
	cout << ll2.Size() << endl;
	
	return 0;
}
