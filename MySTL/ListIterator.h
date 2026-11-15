#pragma once
#include"ListNode.h"
#include"ListIterator.h"
namespace mystl
{
	

	template<typename T>
	class ListIterator
	{
	public:
		using iterator_category = bidirectional_iterator_tag;
		using value_type = T;
		using difference_type = std::ptrdiff_t;
		using pointer = T*;
		using reference = T&;

		ListNode<T>* ptr;
		
		ListIterator(ListNode<T>*p=nullptr):ptr(p){}

		ListIterator& operator++()
		{
			ptr = ptr->next;
			return *this;
		}

		ListIterator operator++(int)
		{
			ListIterator temp = *this;
			ptr = ptr->next;
			return temp;
		}

		ListIterator& operator--()
		{
			ptr = ptr->prev;
			return *this;
		}

		ListIterator operator--(int)
		{
			ListIterator temp = *this;
			ptr = ptr->prev;
			return temp;
		}

		bool operator!=(const ListIterator<T>& other)const
		{
			return ptr != other.ptr;
		}

		bool operator==(const ListIterator<T>& other)const
		{
			return ptr == other.ptr;
		}
		reference operator*()const
		{
			return ptr->value;
		}
	};
}