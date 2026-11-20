#pragma once
#include"ListIterator.h"
#include"ListNode.h"
namespace mystl
{
	
	template<typename T>
	class  List
	{
	public:
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

		ListIterator<T> begin()const
		{
			return ListIterator<T>(head->next);
		}

		ListIterator<T> end()const
		{
			return ListIterator<T>(head);
		}

		size_t size()const
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
		
		void swap(ListNode<T>* p, ListNode<T>* q)
		{
			if (p == q) return;
			ListNode<T>* p_prev = p->prev;
			ListNode<T>* q_prev = q->prev;
			unlink(p);
			unlink(q);
			insert_prev(p_prev->next, q);
			insert_prev(q_prev->next, p);
		}
	private:
		ListNode<T>* head;
		void insert_prev(ListNode<T>* pos, ListNode<T>* p)
		{
			p->prev = pos->prev;
			p->next = pos;
			pos->prev->next = p;
			pos->prev = p;
		}

		void unlink(ListNode<T>* node)
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
	};
}