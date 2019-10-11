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
	//Node<int>* availableList[9];
	Node(){}
	Node(Object initdata) {
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

	

	
private:
	Object data; //data in the beginning node
	Node *next; //pointer to the next node
};



#endif // 