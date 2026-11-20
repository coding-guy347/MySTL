#pragma once
#include"List.h"
#include"ListIterator.h"
#include<utility>
namespace mystl
{
	template<typename T>
	class queue
	{
	public:
		queue()=default;
		~queue()=default;
		
		void push(const T&element)
		{
			data.push_back(element);
		}

		void push(T&& element)
		{
			data.push_back(std::move(element));
		}

		T& front()const
		{
			if (empty()) throw empty_container();
			return *data.begin();
		}

		T& back()const
		{
			if (empty()) throw empty_container();
			auto it = data.end();
			it--;
			return *it;
		}

		void pop()
		{
			if (empty()) throw empty_container();
			data.pop_front();
		}

		bool empty()const
		{
			return data.size() == 0;
		}

		size_t size()const
		{
			return data.size();
		}

		void clear()
		{
			data.clear();
		}
	private:
		List<T>data;
	};

	template<typename T>
	class deque
	{
	public:
		deque()=default;
		~deque()=default;
		
		void push_back(const T& element)
		{
			data.push_back(element);
		}

		void push_front(const T& element)
		{
			data.push_front(element);
		}

		void push_back(T&& element)
		{
			data.push_back(std::move(element));
		}

		void push_front(T&& element)
		{
			data.push_front(std::move(element));
		}

		void pop_back()
		{
			if (empty()) throw empty_container();
			data.pop_back();
		}

		void pop_front()
		{
			if (empty()) throw empty_container();
			data.pop_front();
		}

		T& front()const
		{
			if (empty()) throw empty_container();
			return *(data.begin());
		}

		T& back()const
		{
			if (empty()) throw empty_container();
			auto it = data.end();
			it--;
			return *it;
		}

		size_t size()const
		{
			return data.size();
		}

		bool empty()const
		{
			return data.size() == 0;
		}

		void clear()
		{
			data.clear();
		}
	private:
		List<T>data;
	};
}