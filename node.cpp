#include "node.h"





int main() {


	char response = 'y';

	
	Node<int>* allocatedList[9] = { NULL };
	Node<int>* freeList[9] = { NULL };
	freeList[8] = new Node<int>(256);
	//allocatedList[8] = new Node<int>(NULL);
	int fileSize = 0;
	
	


	

	
	while (response == 'y')
	{

		cout << "allocated blocks ---> " << endl;;
		for (int i = 1; i < 9; i++) {
			Node<int>* temp;
			for (temp = allocatedList[i]; temp != NULL; temp = temp->getNext()) {
				
				cout << temp->getData() << " at index " << i  << endl;
				
			}
		}

		
		/*for (int i = 1; i < 9; i++) {
			if (freeList[i] != NULL) {
				Node<int>* temp;
				for (temp = freeList[i]; temp != NULL; temp = temp->getNext()) {
					cout << "Free List: " << temp->getData() << " at index: " << i << endl;

				}
			}
		}*/

		

		char input;

		cout << "1. Allocates memory" << endl;
		cout << "2. Deallocates memory" << endl;
		cout << "3. exits the program" << endl;

		cout << "What choice would you like to make: ";
		std::cin >> input;

		
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


				if (fileSize <= 2) {
					k = 1;

				}

				else if (fileSize <= 4) {
					k = 2;

				}

				else if (fileSize <= 8) {
					k = 3;

				}

				else if (fileSize <= 16) {
					k = 4;

				}

				else if (fileSize <= 32) {
					k = 5;

				}
				else if (fileSize <= 64) {

					k = 6;
				}

				else if (fileSize <= 128) {


					k = 7;

				}



				else if (fileSize <= 256) {
					k = 8;

				}

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

				}



				break;

		case '2':
			int d;
				

			for (int i = 1; i < 9; i++)
			{
				if (allocatedList[i] != NULL)
				{
					cout << endl << "At index " << i << ": " << allocatedList[i]->getData() << endl;
					
				}

				else {
					cout << endl << "Nothing at " << i << endl;
				}
			}

			
			cout << "What block would you like to delete? (choose index) " << endl;

			cin >> d;
			
			for (int i = 1; i < 9; i++)
			{
				if (allocatedList[i] != NULL)
				{
					
					delete allocatedList[d];
					allocatedList[d] = NULL;
					
				}

			}

			cout << "I am now deallocating memory " << endl;
			//std::system("cls");

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
			
		}
	}

		std::system("pause");

		return 0;
	}


