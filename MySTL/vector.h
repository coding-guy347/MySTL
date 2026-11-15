#pragma once
#include"allocator.h"
#include<utility>
#include"ArraryIterator.h"
#include"stl_exception.h"
namespace mystl
{
	template<typename T>
	class  vector
	{
	private:
		T* begin_ptr;
		T* end_ptr;
		T* cap_end_ptr;
	public:
		vector() :begin_ptr(nullptr), end_ptr(nullptr), cap_end_ptr(nullptr) {}
		
		vector(size_t n)
		{
			if (n == 0) begin_ptr = end_ptr = cap_end_ptr = nullptr;
			begin_ptr = allocator<T>::allocate(n);
			for (size_t i = 0;i < n;i++)
			{
				allocator<T>::construct(begin_ptr + i);
			}
			end_ptr = begin_ptr + n;
			cap_end_ptr = begin_ptr + n;
		}

		vector(size_t n, const T& element)
		{
			begin_ptr = allocator<T>::allocate(n);
			for (size_t i = 0;i < n;i++)
			{
				allocator<T>::construct(begin_ptr + i, element);
			}
			end_ptr = begin_ptr + n;
			cap_end_ptr = end_ptr;
		}

		vector(vector<T>&& other)
		{
			begin_ptr = other.begin_ptr;
			other.begin_ptr = nullptr;
			end_ptr = other.end_ptr;
			other.end_ptr = nullptr;
			cap_end_ptr = other.cap_end_ptr;
			other.cap_end_ptr = nullptr;
		}

		vector(const vector<T>& other)
		{
			if (other.size() == 0) {
				begin_ptr = end_ptr = cap_end_ptr = nullptr;
				return;
			}
			begin_ptr = allocator<T>::allocate(other.size());
			for (size_t i = 0;i < other.size();i++)
			{
				allocator<T>::construct(begin_ptr + i, other.begin_ptr[i]);
			}
			end_ptr = begin_ptr + other.size();
			cap_end_ptr = end_ptr;
		}

		size_t size() const
		{
			if (begin_ptr == nullptr) return 0;
			return static_cast<size_t>(end_ptr - begin_ptr);
		}

		~vector()
		{
			if (begin_ptr != nullptr)
			{
				for (auto it = begin_ptr;it != end_ptr;it++)
				{
					allocator<T>::destroy(it);
				}
				allocator<T>::deallocate(begin_ptr, capacity());
			}
		}

		size_t capacity()const
		{
			if (begin_ptr == nullptr) return 0;
			return static_cast<size_t>(cap_end_ptr - begin_ptr);
		}

		void push_back(const T&element)
		{
			if (end_ptr == cap_end_ptr) reallocate();
			allocator<T>::construct(end_ptr,element);
			end_ptr++;
		}

		void pop_back()
		{
			if (end_ptr ==begin_ptr) throw empty_container();
			end_ptr--;
			allocator<T>::destroy(end_ptr);
		}

		void reallocate()
		{
			if (end_ptr == cap_end_ptr)
			{
				size_t old_size = size();
				size_t newsize = (old_size == 0) ? 1 : 2 * old_size;
				T* new_begin_ptr = allocator<T>::allocate(newsize);
				for (size_t i=0;i<old_size;i++)
				{
					allocator<T>::construct(new_begin_ptr + i, std::move(*(begin_ptr + i)));
					allocator<T>::destroy(begin_ptr + i);
				}
				if (begin_ptr != nullptr)
				{
					allocator<T>::deallocate(begin_ptr, capacity());
				}
				begin_ptr = new_begin_ptr;
				new_begin_ptr = nullptr;
				end_ptr = begin_ptr +old_size;
				cap_end_ptr = begin_ptr+newsize;
			}
		}

		vector<T> operator=(const vector<T>& other)
		{
			
		}

		T& operator[](size_t idx)
		{
			if(idx>=size()) throw out_of_range();
			return *(begin_ptr +idx);
		}
		ArrayIterator<T> begin() const
		{
			return ArrayIterator(begin_ptr);
		}

		ArrayIterator<T> end()const
		{
			return ArrayIterator(end_ptr);
		}
	};
}