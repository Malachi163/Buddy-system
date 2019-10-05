#pragma once
#ifndef UNORDERED_H
#define UNORDERED_H
#include "node.h"
#include <iostream>


//template <class Object>
//class UnorderedList {
//
//public:
//	
//	Node<Object> * head; //create a node from class Node in node.h
//	friend ostream& operator<<(ostream& os, const UnorderedList& ol); //used to output elements in the list
//	//UnorderedList<UnorderedList> arr[9];
//	Node<int> *availableList[9];
//	Object size = 0; // input size for list = 256
//
//	//-----------------------------------------------------------------------------
//	//UnorderedList() // orginal default constructor
//	//{
//	//	head = NULL; //set head to null if nothing is added to the link list
//	//}
//	//--------------------------------------------------------------------------------
//
//	//create this for buddy system
//	template <class Object>
//	UnorderedList(Object s)
//	{
//		size = s; //size of main memory
//		head = NULL; //set head to null if nothing is added to the link list
//		int x = ceil(log(s) / log(2)); //give us all powers of 2
//
//		availableList = new Node[x + 1];
//
//
//	}
//
//	bool isEmpty() { return head == NULL; }
//
//	bool search(Object item);
//	void add(Object item);
//	int size();
//
//};
//
///*
//ostream& operator<<(ostream& os, const UnorderedList& ol) {
//	Node<Object> *current = ol.head;
//	while (current != NULL) {
//		os << current->getData() << endl; //get the node at that point
//		current = current->getNext(); //pushes to the next node
//	}
//	return os; //return that element
//}
//*/
//
//template <class Object>
//void UnorderedList<Object>::add(Object item)
//{
//	Node<Object> *temp = new Node(item); //create new node and set to what the item is
//	temp->setNext(head); // set temp from the class in node.h
//	head = temp;
//}
//
//template <class Object>
//int UnorderedList<Object>::size()
//{
//	Node<Object> *current = head; // create a new node and set it to head
//	int count = 0; //count to count the size of the list
//	while (current != NULL)  //current points to the first number in the list
//	{
//		count++; //this just counts each number in the list
//		current = current->getNext(); //Like the i iterator in a for loop, it intilaize the constructor from node.h
//	}
//	return count;
//}
//
//template <class Object>
//bool UnorderedList<Object>::search(Object item)
//{
//	Node<Object> *current = head; //create another node (it doesn't have to be named current It's just done for consistency) set it to head
//	while (current != NULL)  //current points to the first number in the list
//	{
//		if (current->getData() == item) { return true; } //If the number at this point in the list is equivalent to item then return true
//		else { current = current->getNext(); } // If not move to the next node
//	}
//	return false; // If nothing is found return false
//}


#endif 