#pragma once
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
template <class Object>
class Node {
public:
	Node<int>* availableList[9];
	Node(Object initdata,Object b ) {
		data = initdata; //the initialized data is set as the head
		next = NULL; //the next node is set as NULL, as there is no next node yet.
	}

	Object getData() { //function that return data of a given node.
		return data;
	}

	Node *getNext() {
		return next;
	}

	void setData(Object newData) {
		data = newData;
	}

	void setNext(Node *newnext) {
		next = newnext;
	}

	Node(Object s) {
		int size = s;
		int x = ceil(log(s) / log(2)); //give us all powers of 2
		

		availableList = new Node[x + 1];

		for (int i = 0; i <= x; i++)
		{
			availableList[i] = new Node<>();
		}

		//availableList[x].push_back(new getNext(0, size - 1));
	}

	void allocate(Object s)
	{
		Node<int> *allocatedList[9];
		int x = ceil(log(s) / log(2)); //give us all powers of 2
		int i = 0;
		Node temp = NULL;

		if (availableList[x].size() > 0)
		{
			temp = 
		}
	}
private:
	Object data; //data in the beginning node
	Node *next; //pointer to the next node
};

#endif // !