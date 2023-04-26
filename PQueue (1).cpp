/*
 * filename: PQueue.cpp
 *                 
 * Mohammad Sameer Khan
 * 04/7/2023
 */
#include "PQueue.h"


// Description: constructor
PQueue::PQueue()
{
	head = NULL;
}

// Description: destructor
PQueue::~PQueue()
{
	head = NULL;
}


// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool PQueue::isEmpty() const
{
	return head==NULL;
}

// Description: Compares two Events in order to soert correctly
bool PQueue::compare(const Event& element1, const Event& element2) const
{
	if (element1.getTime() < element2.getTime())
		return true;

	if (element1.getTime() == element2.getTime() && element1.isArrival() && !element2.isArrival())
		return true;

	return false;
}

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.   
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.           
bool PQueue::enqueue(const Event& newElement)
{
	if (isEmpty())
	{
		head = new Node(newElement);
	}
	else
	{
		if (compare(newElement, head->data))
		{
			head = new Node(newElement, head);
		}
		else
		{
			Node* node = head;

			while(node->next)
			{
				if (compare(newElement, node->next->data))
					break;
				node = node->next;
			}

			node->next = new Node(newElement, node->next);
		}
	}

	return true;
}

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
bool PQueue::dequeue()
{
	if (!isEmpty())
	{
		head = head->next;
		return true;
	}
	return false;
}

// Description: Retrieves (but does not remove) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
Event PQueue::peek() const throw(EmptyDataCollectionException)
{
	if (isEmpty())
		throw EmptyDataCollectionException();
	else
		return head->data;
}