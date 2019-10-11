#include "node.h"
#include <cstdlib>
#include <string>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;


int main() {


	char response = 'y';

	//availableList = new Node availableList[x + 1];
	//Node<int>* availableList[9] = { NULL };
	//Node<int> *allocatedList[9] = { NULL };
	Node<int>* allocatedList[9] = { NULL };
	Node<int>* freeList[9] = { NULL };
	freeList[8] = new Node<int>(256);

	int size = 256; //size of main memory
	//int x = ceil(log(size) / log(2)); //give us all powers of 2



	//THis is for deallocation, I will implement it later on
	//for (int i = 0; i < 9; i++)
	//{
 //		delete availableList[i];
	//}
	//delete[] availableList;


	/*
		// Uma version
		//------------------------------------------------------------------------------------------------------------------------------------------------------------
				//print allocated list
	Node<int>* allocatedList[9] = { NULL};
	Node<int>* freeList[9] = { NULL};

		freeList[8] = new Node<int>(256);

		cout << "allocated blocks ----> ";
		for (int i = 1; i < 9; i++)
		{
			Node<int>* temp = NULL;
			for (temp = freeList[i]; temp != NULL; temp = temp->getNext())
			{
				cout << temp->getData() << ", " << endl;
			}
		}


		cout << "What would you like for the proram to do for you today: " << endl;

		cout << endl;
		cout << "   1) Allocate Memory" << endl;
		cout << "   2) Deallocate Memory" << endl;
		cout << "   3) Exit" << endl;

		int Choice = 0;



		cin >> Choice;
		while (Choice != 3)
		{





			if (Choice == 1)
			{
				int memBlock = 0;
				cout << "Enter memory block size 1-256: ";
				cin >> memBlock;


				/////////////////////////////////////////////////////////////


			}
			else if (Choice == 2)
			{

			}

			else if (Choice == 3)
			{

			}
			else
			{
				cout << "Sorry! The value you put was invalid." << endl;
			}

		}
		system("pause");
		return 0;

	}


		///////////////////////////////////////////////////////////////////////////////////------------------------------------------------------------------ignore or delete this part
	*/


	// -- My version
	while (response == 'y')
	{

		cout << "allocated blocks ---> " << endl;;
		for (int i = 1; i < 9; i++) {
			Node<int>* temp;
			for (temp = allocatedList[i]; temp != NULL; temp = temp->getNext()) {
				cout << temp->getData() << ", " ;
				if (allocatedList[i] != NULL)
				{
					cout << allocatedList[i]->getData() << endl;
				}
			}
		}

		char input;

		cout << "1. Allocates memory" << endl;
		cout << "2. Deallocates memory" << endl;
		cout << "3. exits the program" << endl;

		cout << "What choice would you like to make: ";
		std::cin >> input;

		int fileSize = 0;
		Node<int>* ptr = NULL;

		switch (input)
		{
		case '1':

			cout << "Input size of file: ";
			std::cin >> fileSize;
			cout << endl << "You want to allocate " << fileSize << " kb" << endl;
			int i, k;

			if (fileSize > 256)
			{
				cout << "I'm sorry but the maximum file size you can store is 256 kb" << endl;
			}
			else {



				cout << endl << "I am now allocating memory " << endl;

				//cout << "x: " << x << endl;

				/*for (int i = x; i > 0; i--)
				{
					int powerOfTwo = pow(2, i);
					int dec = powerOfTwo - fileSize;
					cout << "dec variable:" << dec << endl;
					x--;
					cout << "Block: " << i << " has size " << powerOfTwo << "kb" << endl;

					availableList[i] = new Node<int>(powerOfTwo);

					cout << availableList[i]->getData() << endl;



				}*/
				if (fileSize <= 2) {
					allocatedList[1] = new Node<int>(fileSize);
					cout << "This is index 1 in allocated: " << allocatedList[1]->getData() << endl;
				}

				else if (fileSize <= 4) {
					allocatedList[2] = new Node<int>(fileSize);
					cout << "This is index 2 in allocated: " << allocatedList[2]->getData() << endl;
				}

				else if (fileSize <= 8) {
					allocatedList[3] = new Node<int>(fileSize);
					cout << "This is index 3 in allocated: " << allocatedList[3]->getData() << endl;
				}

				else if (fileSize <= 16) {
					allocatedList[4] = new Node<int>(fileSize);
					cout << "This is index 4 in allocated: " << allocatedList[4]->getData() << endl;
				}

				else if (fileSize <= 32) {
					allocatedList[5] = new Node<int>(fileSize);
					cout << "This is index 5 in allocated: " << allocatedList[5]->getData() << endl;
				}
				else if (fileSize <= 64) {
					//allocatedList[6] = new Node<int>(fileSize);
					//int i = 0, k = 0;
					k = 6;
					for (i = k; i < 9; ) {
						if (freeList[i] != NULL) {

							//if the block is too big, iteratively break into into two halves until you get a block just right
							Node<int>* temp = freeList[i];
							if (i > k) { // then break the blocks
								freeList[i] = temp->getNext();
								temp->setNext(NULL);

								while (temp->getData() > pow(2, k)) {
									Node<int>* temp2 = new Node<int>(temp->getData() / 2);
									temp->setData(temp->getData() / 2);

									//insert temp2 at end of list of corresponding section of freeList[i-1]
									Node<int>* current;
									if (freeList[i - 1] == NULL) {
										freeList[i - 1] = temp2;
									}
									else {
										for (current = freeList[i - 1]; current->getNext() != NULL; current = current->getNext());
										current->setNext(temp2);
									}
									i--;
								}
							}
							Node<int>* current;
							if (allocatedList[i] == NULL) {
								allocatedList[i] = temp;
							}
							else {
								for (current = allocatedList[i]; current->getNext() != NULL; current = current->getNext());
								current->setNext(temp);
							}
							break;
						}
						i++;
						//cout << "This is index 6 in allocated: " << allocatedList[6]->getData() << endl;
					}



					//cout << availableList[5]->getData() << endl;
				}

				else if (fileSize <= 128) {
					//allocatedList[7] = new Node<int>(fileSize);

					k = 7;
					for (i = k; i < 9; ) {
						if (freeList[i] != NULL) {

							//if the block is too big, iteratively break into into two halves until you get a block just right
							Node<int>* temp = freeList[i];
							if (i > k) { // then break the blocks
								freeList[i] = temp->getNext();
								temp->setNext(NULL);

								while (temp->getData() > pow(2, k)) {
									Node<int>* temp2 = new Node<int>(temp->getData() / 2);
									temp->setData(temp->getData() / 2);

									//insert temp2 at end of list of corresponding section of freeList[i-1]
									Node<int>* current;
									if (freeList[i - 1] == NULL) {
										freeList[i - 1] = temp2;
									}
									else {
										for (current = freeList[i - 1]; current->getNext() != NULL; current = current->getNext());
										current->setNext(temp2);
									}
									i--;
								}
							}
							Node<int>* current;
							if (allocatedList[i] == NULL) {
								allocatedList[i] = temp;
							}
							else {
								for (current = allocatedList[i]; current->getNext() != NULL; current = current->getNext());
								current->setNext(temp);
							}
							break;
						}
						i++;
						//cout << "This is index 6 in allocated: " << allocatedList[6]->getData() << endl;
					}


					cout << "This is index 7 in allocated: " << allocatedList[7]->getData() << endl;
				}

				else if (fileSize <= 256) {
					allocatedList[8] = new Node<int>(fileSize);
					cout << "This is index 8 in allocated: " << allocatedList[8]->getData() << endl;
				}



				break;

		case '2':

			for (int i = 1; i < 9; i++)
			{
				if (allocatedList[i] != NULL) {
					cout << allocatedList[i]->getData() << endl;
				}

			}


			cout << "I am now deallocating memory " << endl;

			break;

		case '3':

			cout << "Exit the program" << endl;
			std::exit(1);

			break;

		default:
			cout << "Something" << endl;


			}


			cout << "Would you like to continue? (y/n) " << endl;
			std::cin >> response;
			std::system("cls");
		}
	}

		std::system("pause");

		return 0;
	}


