
#include "linked_list.h"
#include <stdexcept>
// #include <iostream>

template <typename T>
void LinkedList<T>::push_back(T item)
{
	Node<T> *n = new Node<T>; 
	n->data = item;
	numItems++;

	if (head == nullptr)
	{
		head = n;
		tail = n;
		return;
	}

	tail->next = n;
	n->prev = tail;
	tail = n;
}

template <typename T>
void LinkedList<T>::push_front(T item)
{
	Node<T> *n = new Node<T>; 
	n->data = item;
	numItems++;

	if (head == nullptr)
	{
		head = n;
		tail = n;
		return;
	}

	head->prev = n;
	n->next = head;
	head = n;
}

template <typename T>
T LinkedList<T>::at(size_t idx)
{
	if (idx >= numItems)
	{
		throw std::invalid_argument("List index out of range: " + std::to_string(idx));
	}

	Node<T> *n = get_node(idx);
	return n->data;
}

template <typename T>
Node<T> *LinkedList<T>::get_node(size_t idx)
{

	size_t i = 0;
	Node<T> *cur = head;
	while (i < idx)
	{
		cur = cur->next;
		i++;
	}

	return cur;
}

// submit this


template <typename T>
	LinkedList<T>::~LinkedList(){  
 
	}


template <typename T>
void LinkedList<T>::insert(size_t pos, T item)
{
	if (pos > size() || pos < 0)
	{
		throw std::invalid_argument("some message");
	}

	Node<T> *cur = head;
	Node<T> *previousN;
	Node<T> *new_node = new Node<T>; 
	new_node->data = item;
	
	while (pos >= 0)
	{ 

		if (pos == 0)
		{  
			if (cur == head)
			{
				push_front(new_node->data);
				break;
			}


			if (cur->prev != nullptr)
			{
				previousN = cur->prev;
				cur->prev = new_node;
				new_node->next = cur;
				previousN->next = new_node;
				new_node->prev = previousN;
			}
			else
			{
				cur->prev = new_node;
				new_node->next = cur;
			}

			
			numItems++;
			break;
		}

					if (cur->next == nullptr)
			{
				push_back(new_node->data);
				break;
			}
cur=cur->next;
		pos--;
	}
}
