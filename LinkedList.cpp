/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/12/19
** Description: Implements source code for LinkedList class. 
** LinkedList is used for creating doubly linked lists
*********************************************************************/
#include <iostream>
#include "LinkedList.hpp"
#include "ListNode.hpp"

LinkedList::LinkedList() { 
	head = nullptr;
	tail = nullptr;
}

LinkedList::~LinkedList() {
	ListNode *nodePtr = head;
	while (nodePtr != nullptr) {
		ListNode *garbage = nodePtr;
		nodePtr = nodePtr->getNext(); 
		delete garbage; 
	}
}

/*********************************************************************
** Description: adds a node to the head of the list using parameter 
** and set it to the head value of the list
*********************************************************************/
void LinkedList::addToHead(int number) {
	if (head == nullptr) {
		head = new ListNode(number);
		tail = head; 
	}
	else {
		ListNode *nodePtr = head;
		nodePtr->setPrev(new ListNode(number, nodePtr, nullptr));
		head = nodePtr->getPrev();	
	}
}

/*********************************************************************
** Description: adds a node to the tail of the list using parameter 
** and sets it to the tail value of the list
*********************************************************************/
void LinkedList::addToTail(int number) {
	if (tail == nullptr) {
		tail = new ListNode(number);
		head = tail;
	}
	else {
		ListNode *nodePtr = tail;
		nodePtr->setNext(new ListNode(number, nullptr, nodePtr));
		tail = nodePtr->getNext();
	}
}

/*********************************************************************
** Description: removes a node from the head of the list and sets the 
** second node to the head value
*********************************************************************/
void LinkedList::removeFromHead() {
	ListNode *nodePtr;
	if (!head) {
		std::cout << "There are no values in this list." << std::endl;
		return;
	}
	else {
		nodePtr = head;
		if (head->getNext() != nullptr) {
			head = head->getNext();
			head->setPrev(nullptr);
		}
		else if (nodePtr->getNext() == nullptr) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			std::cout << "unexpected occured in removeFromHead()" << std::endl;
		}
		delete nodePtr;
	}
}

/*********************************************************************
** Description: removes a node from the tail of the list and sets the
** second to last node to the tail value
*********************************************************************/
void LinkedList::removeFromTail() {
	ListNode *nodePtr;
	if (!tail) {
		std::cout << "There are no values in this list." << std::endl;
		return;
	}
	else {
		nodePtr = tail;
		if (tail->getPrev() != nullptr) {
			tail = tail->getPrev();
			tail->setNext(nullptr);
		}
		else if (nodePtr->getPrev()==nullptr) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			std::cout << "unexpected occured in removeFromTail()" << std::endl;
		}
		delete nodePtr;
	}
}

/*********************************************************************
** Description: displays the current list from head to tail
*********************************************************************/
void LinkedList::displayFwdList() {
	
	if (!head) {
		std::cout << "empty";
	}
	else {
		ListNode *nodePtr = head;
		while (nodePtr) {
			std::cout << nodePtr->getVal() << "   ";
			nodePtr = nodePtr->getNext();
		}
	}
}

/*********************************************************************
** Description: displays the current list from tail to head
*********************************************************************/
void LinkedList::displayRevList() {
	if (!tail) {
		std::cout << "empty";
	}
	else {
		ListNode *nodePtr = tail;
		while (nodePtr) {
			std::cout << nodePtr->getVal() << "   ";
			nodePtr = nodePtr->getPrev();
		}
	}
}

/*********************************************************************
** Description: displays the current value of the head node of the list
*********************************************************************/
void LinkedList::displayHead() {
	if (head == nullptr) {
		std::cout << "There are no values in this list." << std::endl;
	}
	else {
		std::cout << head->getVal();
	}
}

/*********************************************************************
** Description: displays the current value of the tail node of the list
*********************************************************************/
void LinkedList::displayTail() {
	if (tail == nullptr) {
		std::cout << "There are no values in this list." << std::endl;
	}
	else {
		std::cout << tail->getVal();
	}
}
