#pragma once
#include"vector.h"
#include"ArraryIterator.h"
#include<utility>
namespace mystl
{
	template<typename T>
	class  stack
	{
	public:
		 stack()=default;
		~ stack()=default;
		
		void push(const T&element)
		{
			data.push_back(element);
		}

		void push(T&& element)
		{
			data.push_back(std::move(element));
		}

		void pop()
		{
			if (empty()) throw empty_container();
			data.pop_back();
		}

		T& top()const
		{
			if (empty()) throw empty_container();
			return *(data.end() - 1);
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
		vector<T>data;
	};
}