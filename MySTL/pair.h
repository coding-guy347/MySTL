#pragma once
#include<utility>
namespace mystl
{
	template<typename T1,typename T2>
	class pair
	{
	public:
		T1 first;
		T2 second;
		pair( ):first(),second(){}
		pair(const T1&first,const T2&second):first(first),second(second){}
		pair(T1&& first, T2&& second) :first(std::move(first)), second(std::move(second)){}
		pair(const pair<T1,T2>& other)
		{
			*this = other;
		}
		pair(pair<T1,T2>&& other)noexcept
		{
			*this = std::move(other);
		}

		pair& operator=(const pair<T1, T2>& other)
		{
			first = other.first;
			second = other.second;
			return*this;
		}

		pair& operator=(pair<T1, T2>&& other)noexcept
		{
			first = std::move(other.first);
			second = std::move(other.second);
			return *this;
		}

		bool operator==(const pair<T1,T2>& other)const
		{
			return first == other.first && second == other.second;
		}

		bool operator<(const pair<T1, T2>& other)const
		{
			if (first < other.first) return true;
			else if (first == other.first && second < other.second) return true;
			return false;
		}

		bool operator>(const pair<T1, T2>& other)const
		{
			if (first > other.first) return true;
			else if (first == other.first && second > other.second) return true;
			return false;
		}

		~pair() = default;
	};

}