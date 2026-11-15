#pragma once
#include<cstddef>;

namespace mystl
{
	struct input_iterator_tag{};
	struct output_iterator_tag{};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template<typename T>
	class ArrayIterator
	{
	public:
		using iterator_category = mystl::random_access_iterator_tag;
		using value_type = T;
		using difference_type = std::ptrdiff_t; 
		using pointer = T*;
		using reference = T&;

		T* ptr;
		ArrayIterator(T* p = nullptr):ptr(p) {}

		reference operator*()const { return*ptr; }

		pointer operator->()const { return ptr; }

		

		ArrayIterator& operator++()
		{
			ptr++;
			return*this;
		}

		ArrayIterator operator++(int)
		{
			ArrayIterator temp = *this;
			++ptr;
			return temp;
		}

		ArrayIterator& operator--() { --ptr; return *this; }

		ArrayIterator operator--(int) { ArrayIterator tmp = *this; --ptr; return tmp; }

		bool operator!=(const ArrayIterator& other)
		{
			return ptr != other.ptr;
		}

		bool operator==(const ArrayIterator& other)
		{
			return ptr == other.ptr;
		}
		
		ArrayIterator operator-(difference_type n) const
		{
			return ArrayIterator(ptr - n);
		}

		ArrayIterator operator+(difference_type n)const 
		{
			return ArrayIterator(ptr + n);
		}

		ArrayIterator& operator-=(difference_type n)
		{
			ptr -= n;
			return *this;
		}

		ArrayIterator& operator+=(difference_type n)
		{
			ptr += n;
			return *this;
		}

		difference_type operator-(const ArrayIterator& other) const { return ptr - other.ptr; }

		bool operator<(const ArrayIterator& other) const { return ptr < other.ptr; }

		bool operator<=(const ArrayIterator& other) const { return ptr <= other.ptr; }

		bool operator>(const ArrayIterator& other) const { return ptr >other.ptr; }

		bool operator>=(const ArrayIterator& other) const { return ptr >= other.ptr; }

		friend ArrayIterator operator+(difference_type n, const ArrayIterator& it)
		{
			return it + n;
		}
	};
}