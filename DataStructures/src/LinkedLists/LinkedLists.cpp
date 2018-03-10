/*
 * LinkedLists.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: Saibhavya
 */

#include "LinkedLists.h"
#include <stdio.h>
#include <iostream>
namespace DataStructures {
namespace
{
	void deleteNode(bool front); // true - front, false - back

}
LinkedList::LinkedList(Node *head_ptr)
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

LinkedList::~LinkedList()
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

void LinkedList::insertNodeAtFront(int data)
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

void LinkedList::insertNodeAtBack(int data)
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

void LinkedList::deleteNodeAtFront(void)
{

	deleteNode(true);
}

void LinkedList::deleteNodeAtBack(void)
{
	deleteNode(false);
}
bool LinkedList::searchHelper(Node *curr, int data)
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
bool LinkedList::search(int data)
{
	//using recursion
	Node *curr = head;
	bool found = searchHelper(curr,data);
	trash.push_back(curr);
	return found;
}
void LinkedList::printList()
{
	Node *temp = head;
	std::cout<<"Current list is - ";
	while(temp != NULL)
	{
		std::cout<< temp->data<<"\t";
		temp = temp->next;
	}
	trash.push_back(temp);
	std::cout<<std::endl;
}
void LinkedList::deleteNode(bool at_front)
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
} /* namespace DataStructures */
