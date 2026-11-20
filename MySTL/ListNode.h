#pragma once
#include<utility>
namespace mystl
{
	template<typename T>
	struct  ListNode
	{
		T value;
		ListNode* prev;
		ListNode* next;
		ListNode() : prev(nullptr), next(nullptr), value() {}
		ListNode(const T& val) : prev(nullptr), next(nullptr), value(val) {}
		ListNode(T&&val):prev(nullptr),next(nullptr),value(std::move(val)){}
	};
}