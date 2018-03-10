/*
 * LinkedLists.h
 *
 *  Created on: Mar 7, 2018
 *      Author: Saibhavya
 */

#ifndef LINKEDLISTS_H_
#define LINKEDLISTS_H_
#include <stddef.h>
#include <vector>
namespace DataStructures {

class LinkedList {
public:
	struct Node
	{
		int data;
		Node *next;
	};
	LinkedList(Node* head_ptr = NULL);
	virtual ~LinkedList();
	void insertNodeAtFront(int data);
	void insertNodeAtBack(int data);
	void deleteNodeAtFront(void);
	void deleteNodeAtBack(void);
	bool search(int data);//assuming a list of unique values
	void printList();

private:
	Node *head;
	Node *tail;
	std::vector<Node *> trash;
	void deleteNode(bool at_front);
	bool searchHelper(Node* curr, int data);
};

} /* namespace DataStructures */
#endif /* LINKEDLISTS_H_ */
