#include "node.h"

#include <string>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;


int main() {
	
	
	char response = 'y';
	//int *availableList[9];
	//int *allocatedList[9];
	

	Node<int>* availableList[9];
	Node<int> *allocatedList[9];
	//void * freeList[9];
	int size, s = 256;
	size = s; //size of main memory
	int x = ceil(log(s) / log(2)); //give us all powers of 2

	//for (int i = 1; i < 9; i++)
	//{
	//	availableList[i] = new Node<int>(x + 1);
	//		cout << availableList[i] << endl;
	//}
	//
	//availableList = new Node availableList[x + 1];
	for (int i = 1; i < 9; i++)
{
	//availableList[i] = new Node<int>[x + 1];
		cout << availableList[i] << endl;
		//cout << freeList[i] << endl;
}
	

	//availableList = new Node[x + 1];

	//THis is for deallocation, I will implement it later on
	/*for (int i = 0; i < some_num; i++)
	{
		delete array[i];
	}
	delete[] array;*/
	

	while (response == 'y')
	{
		char input;

		std::cout << "1. Allocates memory" << endl;
		cout << "2. Deallocates memory" << endl;
		cout << "3. exits the program" << endl;

		cout << "What choice would you like to make: ";
		cin >> input;
	
		int fileSize = 0;

		switch (input)
		{
		case '1':

			cout << "Input size of file: ";
			cin >> fileSize;
			cout << endl << "You want to allocate " << fileSize << " kb" << endl;

			if (fileSize > 256)
			{
				cout << "I'm sorry but the maximum file size you can store is 256 kb" << endl;
			}
			else {
			cout << endl << "I am now allocating memory " << endl;
		}
			


			break;

		case '2':
			cout << "I am now deallocating memory " << endl;

			break;

		case '3':

			cout << "Exit the program" << endl;
			exit(1);

			break;

		default:
			cout << "Something" << endl;


		}

		
		cout << "Would you like to continue? (y/n) " << endl;
		cin >> response;
		system("cls");
	}

	system("pause");

	return 0;
}