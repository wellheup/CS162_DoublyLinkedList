/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/12/19
** Description: Specifies the ListNode class header. 
** ListNode is used for creating single value nodes for linked lists
*********************************************************************/
#ifndef LISTNODE_HPP
#define LISTNODE_HPP

class ListNode {
protected:
	int val;
	ListNode *next, *prev;
public:
	ListNode(int val1, ListNode *next1 = nullptr, ListNode *prev1 = nullptr);
	int getVal();
	void setVal(int val);
	ListNode* getNext();
	void setNext(ListNode* next);
	ListNode* getPrev();
	void setPrev(ListNode* prev);
};
#endif