/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/12/19
** Description: Implements source code for ListNode class header. 
** ListNode is used for creating single value nodes for linked lists
*********************************************************************/
#include <iostream>
#include "ListNode.hpp"

ListNode::ListNode(int val1, ListNode * next1, ListNode * prev1) {
	val = val1;
	next = next1;
	prev = prev1;
}

int ListNode::getVal() {
	return this->val;
}

void ListNode::setVal(int val) {
	this->val = val;
}

ListNode * ListNode::getNext() {
	return this->next;
}

void ListNode::setNext(ListNode * next) {
	this->next = next;
}

ListNode * ListNode::getPrev() {
	return this->prev;
}

void ListNode::setPrev(ListNode * prev) {
	this->prev = prev;
}
