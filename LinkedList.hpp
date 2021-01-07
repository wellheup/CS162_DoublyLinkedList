/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/12/19
** Description: Specifies the LinkedList class header. LinkedList is used for 
** creating doubly linked lists
*********************************************************************/
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
class ListNode;

class LinkedList {
protected:

	ListNode *head;
	ListNode *tail;
public:
	LinkedList();
	~LinkedList();
	/*********************************************************************
** Description: adds a node to the head of the list using parameter
** and set it to the head value of the list
*********************************************************************/
	void addToHead(int number);
	/*********************************************************************
** Description: adds a node to the tail of the list using parameter
** and sets it to the tail value of the list
*********************************************************************/
	void addToTail(int number);
	/*********************************************************************
** Description: removes a node from the head of the list and sets the
** second node to the head value
*********************************************************************/
	void removeFromHead();
	/*********************************************************************
** Description: removes a node from the tail of the list and sets the
** second to last node to the tail value
*********************************************************************/
	void removeFromTail();
	/*********************************************************************
** Description: displays the current list from head to tail
*********************************************************************/
	void displayFwdList();
	/*********************************************************************
** Description: displays the current list from tail to head
*********************************************************************/
	void displayRevList();
	/*********************************************************************
** Description: displays the current value of the head node of the list
*********************************************************************/
	void displayHead();
	/*********************************************************************
** Description: displays the current value of the tail node of the list
*********************************************************************/
	void displayTail();
};


#endif