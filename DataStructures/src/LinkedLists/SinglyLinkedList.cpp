/*
 * SinglyLinkedLists.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: Saibhavya
 */

#include "SinglyLinkedList.h"
#include <stdio.h>
#include <iostream>
#include <unordered_set>
namespace DataStructures {
SinglyLinkedList::SinglyLinkedList(Node *head_ptr)
{
	if(head_ptr)
	{
		head = head_ptr;
		head->next = NULL;
		tail = head_ptr;
		tail->next = NULL;
		trash.push_back(head_ptr);
	}
	else
	{
		head = NULL;
		tail = NULL;
	}
}

SinglyLinkedList::~SinglyLinkedList()
{
	//address memory leaks
	std::vector<Node *>::iterator itr = trash.begin();
	while(itr != trash.end())
	{
		(*itr) = NULL;
		delete (*itr);
		++itr;
	}
	trash.clear();
	//clear the list itself
	while(head != NULL)
	{
		Node *curr = head;
		head = head->next;
		curr = NULL;
		delete curr;
	}
	delete head;
	delete tail;
	std::cout << "Done!"<<std::endl;
}

void SinglyLinkedList::insertNodeAtFront(int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->next = head;
	if(head == NULL)
	{
		tail = temp; // empty list
	}
	head = temp;
	trash.push_back(temp);
}

void SinglyLinkedList::insertNodeAtBack(int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(tail == NULL) // tail should be null only when head is null
	{
		tail = temp;
		head = temp;
		trash.push_back(temp);
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	tail->next = NULL;
}

void SinglyLinkedList::deleteNodeAtFront(void)
{

	deleteNode(true);
}

void SinglyLinkedList::deleteNodeAtBack(void)
{
	deleteNode(false);
}
bool SinglyLinkedList::searchHelper(Node *curr, int data)
{
	if(curr == NULL)
	{
		return false;
	}
	if(curr->data == data)
	{
		return true;
	}
	return searchHelper(curr->next,data);
}
bool SinglyLinkedList::search(int data)
{
	//using recursion
	Node *curr = head;
	bool found = searchHelper(curr,data);
	trash.push_back(curr);
	return found;
}
void SinglyLinkedList::printList()
{
	Node *temp = head;
	std::cout<<"Current list is : ";
	while(temp != NULL)
	{
		std::cout<< temp->data;
		temp = temp->next;
		if(temp)
		{
			std::cout<<" => ";
		}
	}
	trash.push_back(temp);
	std::cout<<std::endl;
}
void SinglyLinkedList::deleteNode(bool at_front)
{
	if(head == NULL)
	{
		std::cout<<"The list is empty !"<<std::endl;
		return;
	}
	else if(head == tail) // single element list
	{
		head = tail = NULL;
		delete head;
		delete tail;
	}
	else
	{
		Node *temp = head;
		if(at_front)
		{
			head = head->next;
		}
		else
		{
			while(temp->next != tail)
			{
				temp = temp->next;
			}
			tail = temp;
			temp = temp->next;
			tail->next = NULL;
		}
		temp = NULL;
		delete temp;
	}
}
void SinglyLinkedList::rearranage(void)
{
	if(head == NULL || head->next == NULL || head->next->next == NULL)
	{
		std::cerr << "List has less than two nodes."<<
					" Can't rearrange !"<< std::endl;
		return;
	}
	// Front runner pointer - method
	SinglyLinkedList::Node *curr_ptr = head;
	SinglyLinkedList::Node *fast_ptr = head->next;
	//iterate to the end
	while(fast_ptr->next != NULL )
	{
		if(fast_ptr->next->next != NULL)
		{
			fast_ptr = fast_ptr->next->next; //even nodes
		}
		else
		{
			fast_ptr = fast_ptr->next; // odd number of nodes
		}
		curr_ptr = curr_ptr->next;
	}
	fast_ptr = head;

	while((curr_ptr->next != NULL) && (fast_ptr != curr_ptr))
	{
		Node *temp = curr_ptr->next;
		curr_ptr->next = temp->next;
		temp->next = fast_ptr->next;
		fast_ptr->next = temp;
		fast_ptr = fast_ptr->next->next;
		trash.push_back(temp);
	}
	trash.push_back(curr_ptr);
	trash.push_back(fast_ptr);
	return;
}
/*
 * deleteDupsWithHashSet - Space & time Complexity - O(n)
 */
void SinglyLinkedList::deleteDupsWithHashSet(void)
{
	std::unordered_set<int> elements;
	if((head == NULL) || (head->next == NULL))
	{
		std::cout << "Empty/single element list"<< std::endl;
	}
	Node *temp = head;
	Node *prev = NULL;
	while(temp != NULL)
	{
		if(elements.find(temp->data) != elements.end())
		{
			prev->next = temp->next;
		}
		else
		{
			elements.insert(temp->data);
			prev = temp;
		}
		temp = temp ->next;
	}
}
} /* namespace DataStructures */
