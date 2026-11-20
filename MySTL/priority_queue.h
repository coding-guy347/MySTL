#pragma once
#include"ArraryIterator.h"
#include"vector.h"

namespace mystl
{
	template<typename T> 
	struct  less
	{
		bool operator()(const T& a, const T& b) const { return a < b; }
	};

	template<typename T>
	struct  greater
	{
		bool operator()(const T& a, const T& b)const { return a > b; }
	};


	template<typename T,typename Compare=less<T>>
	class priority_queue
	{
	public:
		priority_queue()=default;
		~priority_queue()=default;

		void push(const T& element)
		{
			data.push_back(element);
			shift_up(data.size() - 1);
		}

		void push(T&& element)
		{
			data.push_back(std::move(element));
			shift_up(data.size() - 1);
		}

		void pop()
		{
			if (data.empty()) throw empty_container();
			data.swap(0, data.size() - 1);
			data.pop_back();
			shift_down(0);
		}

		T& top()
		{
			return data[0];
		}

		bool empty()const
		{
			return data.size() == 0;
		}

		size_t size()const
		{
			return data.size();
		}
	private:
		vector<T>data;
		Compare compare;

		void shift_up(size_t i)
		{
			while (i>0)
			{
				size_t p = (i - 1) / 2;
				if (compare(data[p], data[i]))
				{
					data.swap(p, i);
					i = p;
				}
				else break;
			}
		}

		void shift_down(size_t i)
		{
			size_t n = data.size();
			while (true)
			{
				size_t target = i;
				size_t left = i * 2 + 1;
				size_t right = i * 2 + 2;
				if (left < n && compare(data[target], data[left]))
				{
					target = left;
				}
				if (right < n && compare(data[target], data[right]))
				{
					target = right;
				}

				if (target == i) break;

				data.swap(target, i);
				i =target;
			}
		}
	};
}