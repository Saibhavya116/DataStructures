/*
 * LinkedLists_test.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: Saibhavya
 */

#include "SinglyLinkedList.h"
#include <iostream>
namespace DataStructures
{
	//Input - Given a linked list of form a1->a2->a3..->b1->b2->b3...
	//Output - Rearranged linked list as a1->b1->a2->b2->a3->b3...

	void rearrangeSinglyLinkedListTest()
	{
		SinglyLinkedList::Node *n1 = new SinglyLinkedList::Node();
		n1->data = 10;
		n1->next = NULL;
		SinglyLinkedList odd_list(n1);
		odd_list.insertNodeAtBack(20);
		odd_list.insertNodeAtBack(30);
		odd_list.insertNodeAtBack(40);
		odd_list.insertNodeAtBack(50);
		odd_list.insertNodeAtBack(-10);
		odd_list.insertNodeAtBack(-20);
		odd_list.insertNodeAtBack(-30);
		odd_list.insertNodeAtBack(-40);
		std::cout<< "Odd numbered linked list rearrangement "<< std::endl;
		odd_list.printList();
		odd_list.rearranage();
		odd_list.printList();

		SinglyLinkedList even_list(n1);
		even_list.insertNodeAtBack(20);
		even_list.insertNodeAtBack(30);
		even_list.insertNodeAtBack(-10);
		even_list.insertNodeAtBack(-20);
		even_list.insertNodeAtBack(-30);
		std::cout<< "Even numbered linked list rearrangement "<< std::endl;

		even_list.printList();
		even_list.rearranage();
		even_list.printList();

	}
	void basicSinglyLinkedListOperationsTest()
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

	}
	void deleteDupsWithHashSetTest()
	{
		SinglyLinkedList ll;
		ll.insertNodeAtFront(-1);
		ll.insertNodeAtFront(1);
		ll.insertNodeAtFront(10);
		ll.insertNodeAtFront(1);
		ll.insertNodeAtBack(2);
		ll.insertNodeAtFront(13);
		ll.insertNodeAtFront(2);
		ll.insertNodeAtFront(3);
		ll.deleteDupsWithHashSet();
		ll.printList();
	}
} // end of the workspace

int main()
{
	using namespace DataStructures;
	deleteDupsWithHashSetTest();
	//rearrangeSinglyLinkedListTest();
	return 0;

} /* namespace DataStructures */
