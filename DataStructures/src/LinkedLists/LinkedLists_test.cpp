/*
 * LinkedLists_test.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: Saibhavya
 */

#include "SinglyLinkedList.h"
#include <iostream>
int main()
{
	using namespace DataStructures;
	std::cout << " In main "<< std::endl;
//	Node *firstNode = new Node();
	SinglyLinkedList::Node *firstNode = new SinglyLinkedList::Node();
	firstNode->data = 100;
	firstNode->next = NULL;
	SinglyLinkedList list(firstNode);
	list.printList();
	std::cout<<"Deleting a node from the front"<<std::endl;
	list.deleteNodeAtFront();
	list.printList();
	list.insertNodeAtBack(15);
	list.printList();
	list.insertNodeAtFront(10);
	list.insertNodeAtFront(20);
	std::cout<<" Is there a value 20 in the list ? - "<< list.search(20)<<std::endl;
	list.insertNodeAtFront(-3);
	list.insertNodeAtBack(5);
	list.insertNodeAtFront(40);
	std::cout<<" Is there a value 50 in the list ? - "<< list.search(50)<<std::endl;
	list.printList();
	std::cout<<"Deleting a node from the back"<<std::endl;
	list.deleteNodeAtBack();
	list.printList();

	return 0;

} /* namespace DataStructures */
