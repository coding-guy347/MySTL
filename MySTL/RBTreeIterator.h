#pragma once
#include"RBNode.h"
namespace mystl
{
	template<typename Key, typename Value>
	class RBTreeIterator
	{
	public:
		using Node = RBNode<Key, Value>;
		using iterator_category = bidirectional_iterator_tag;
		using value_type = Node;
		using difference_type = std::ptrdiff_t;
		using pointer = Node*;
		using reference = Node&;

		Node* ptr;
		RBTreeIterator(Node* p = nullptr)
		{
			if (!p) ptr = nullptr;
			else
			{
				pointer cur = p;
				while (cur->left != nullptr)
				{
					cur = cur->left;
				}
				ptr = cur;
			}
		}

		pointer operator++()
		{
			if(ptr->right)
			{
				ptr = ptr->right;
				while (ptr->left)
				{
					ptr = ptr->left;
				}
				return ptr;
			}
		}
	};
}