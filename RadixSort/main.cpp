#include "iostream"
#include "fstream"
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int main(int argc, char* argv[]) {
	//max amount of numbers to sort
	const int NUM_OF_INTS = 10;
	int numbers[NUM_OF_INTS];

	//read filename from cli
	string filename = argv[1];

	//open file
	ifstream inFile;
	inFile.open(filename);

	//read data into array
	for (int i = 0; i < NUM_OF_INTS; i++) {
		inFile >> numbers[i];
	}

	//create array of queues, one for each digit 0-9
	queue<int> qArray[NUM_OF_INTS];

	for (int j = 0; j < 4; j++) { //sorts up to 4 digits
		for (int i = 0; i < NUM_OF_INTS; i++) {
			int root = pow(10, j); //digit to sort by, from least to most significant
			int digit = (numbers[i]/root) % 10; //value of that digit
			qArray[digit].push(numbers[i]); //put number into appropriate digit queue
		}
		int l = 0; 
		for (int k = 0; k < NUM_OF_INTS; k++) { //move sorted numbers back to numbers array
			while (!qArray[k].empty()) { //while each queue is not empty...
				numbers[l] = qArray[k].front(); //...move front into next slot of numbers array
				qArray[k].pop();	//...pop from queues in order
				l++;	//increment index of numbers array
			}
		}
	}	//array now sorted

	std::cout << "Sorted numbers:\n";
	for (int i = 0; i < NUM_OF_INTS; i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << "\n";

	return 0;
}