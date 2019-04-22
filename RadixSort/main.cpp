#include "iostream"
#include "fstream"
#include <string>
#include <queue>

using namespace std;

void main() {
	ifstream inFile;
	inFile.open("data.txt");
	const int NUM_OF_INTS = 10;
	string numbers[NUM_OF_INTS];

	//read data into array
	for (int i = 0; i < NUM_OF_INTS; i++) {
		inFile >> numbers[i];
	}

	//create array of queues, one for each digit 0-9
	queue<string> qArray[NUM_OF_INTS];

	for (int j = 4; j > 0; j--) {
		for (int i = 0; i < NUM_OF_INTS; i++) {
			//read each digit into appropriate array
			int value = (numbers[i][j-1] - 48);	//convert ASCII value to numeric value
			qArray[value].push(numbers[i]);
		}
		int l = 0;
		for (int k = 0; k < NUM_OF_INTS; k++) {
			//moving each element from queue back to array in sorted order
			while (!qArray[k].empty()) {
				numbers[l] = qArray[k].front(); //grab from front of queue
				qArray[k].pop(); //remove from queue
				l++; //increment array index
			}
			//repeat for each digit (NUM_OF_INTS)
		}
	} //array is now sorted 

	return;
}