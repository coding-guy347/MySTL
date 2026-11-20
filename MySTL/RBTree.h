#pragma once
#include"RBNode.h"
#include"pair.h"
#include<utility>
#include<iostream>
namespace mystl
{

	template<typename Key,typename Value>
	class RBTree
	{
	private:
		using Node = RBNode<Key, Value>;
		Node* header;
		size_t node_count = 0;
	public:
		RBTree()
		{
			header = new Node;
			header->color = red;
			header->left = header;
			header->right = header;
			header->parent =nullptr;
		}
		~RBTree()=default;

		void insert(const Key&key, const Value&value)
		{
			if (header->parent==nullptr)
			{
				Node*node = new Node(key,value);
				node->color = black;
				header->parent =node;
				header->left =node;
				header->right =node;
				node->parent = header;
				return ;
			}
			Node* cur =header->parent;
			Node* prev = cur;
			while (true)
			{
				if (!cur)
				{
					Node* node = new Node(key,value);
					if (prev->value.first < key)
					{
						prev->right = node;
						node->parent = prev;
					}
					else if (prev->value.first > key)
					{
						prev->left = node;
						node->parent = prev;
					}
					if (node->value.first > header->right->value.first) header->right = node;
					if (node->value.first < header->left->value.first) header->left = node;
					break;
				}
				prev = cur;
				if (cur->value.first<key)
				{
					cur = cur->right;
				}
				else if (cur->value.first>key)
				{
					cur = cur->left;
				}
				else if (cur->value.first==key)
				{
					cur->value.second = value;
					break;
				}
			}
		}

		void fix_insert(Node* node)
		{
			if (node->parent == header) return;
			Node* parent = node->parent;
			Node* grandpa = parent->parent;
			Node* uncle=nullptr;
			if (parent == grandpa->left) uncle = grandpa->right;
			else uncle = grandpa->left;
			if (node->parent->color == red)
			{
				if (node == parent->left && uncle == nullptr || node == parent->left && uncle->color == black)
				{
					parent->right = grandpa;
					if (grandpa == grandpa->parent->left) parent = grandpa->parent->left;
					else parent = grandpa->parent->right;
					parent->parent = grandpa->parent;
					grandpa->parent = parent;
				}
			}
			else return;
		}

		Node* find(const Key& key)
		{
			Node* cur =header->parent;
			while (true)
			{
				if (!cur) break;

				if (cur->value.first == key)
				{
					return cur;
				}

				if (cur->value.first < key)
				{
					cur = cur->right;
				}
				else if (cur->value.first > key)
				{
					cur = cur->left;
				}
			}
			return nullptr;
		}

		Value& operator[](const Key&key)
		{
			Node* target = find(key);
			if (!target)
			{
				insert(key, Value());
				return find(key)->value.second;
			}
			return target->value.second;
		}

		Node* root()const
		{
			return header->parent; 
		}

		Node* begin()const
		{
			return header->left;
		}

		Node* end()const
		{
			return header;
		}

		void inorder(Node*root) {
			if (root == nullptr) return;
			inorder(root->left);
			std::cout << root->value.first << " ";
			inorder(root->right);
		}
	};
}