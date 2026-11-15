#pragma once
#include"ListIterator.h"
#include"ListNode.h"
namespace mystl
{
	
	template<typename T>
	class  List
	{
	public:
		ListNode<T>* head;
		List()
		{
			head = new ListNode<T>();
			head->next = head;
			head ->prev= head;
		 }

		void insert(ListNode<T>*pos,const T&value)
		{
			ListNode<T>* newnode = new ListNode<T>(value);
			newnode->prev = pos->prev;
			newnode->next = pos;
			pos->prev->next = newnode;
			pos->prev = newnode;
		}
		~List()
		{
			clear();
			delete head;
		}
		
		void clear()
		{
			ListNode<T>* cur = head->next;
			while (cur != head)
			{
				ListNode<T>* next = cur->next;
				delete cur;
				cur = next;
			}
			head->next = head;
			head->prev = head;
		}
		
		void push_back(const T&value)
		{
			insert(head, value);
		}

		void push_front(const T& value)
		{
			insert(head->next, value);
		}

		ListIterator<T> begin()
		{
			return ListIterator<T>(head->next);
		}

		ListIterator<T> end()
		{
			return ListIterator<T>(head);
		}

		size_t size()
		{
			int count = 0;
			ListNode<T>*cur = head->next;
			while (cur!=head)
			{
				count++;
				cur = cur->next;
			}
			return count;
		}

		void pop_back()
		{
			if (head->prev == head) return;
			ListNode<T>*Node = head->prev;
			head->prev = Node->prev;
			Node->prev->next = head;
			delete Node;
		}

		void pop_front()
		{
			if (head->next == head) return;
			ListNode<T>* Node = head->next;
			head->next = Node->next;
			Node->next->prev = head;
			delete Node;
		}
		
	};
}