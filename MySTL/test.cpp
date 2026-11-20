#include <iostream>
#include "ArraryIterator.h" // 确保你的头文件名对得上
#include"List.h"
#include"ListIterator.h"
#include"vector.h"
#include<cstring>
#include"queue.h"
#include"stack.h"
#include"priority_queue.h"
#include"pair.h"
#include"RBTree.h"
using namespace mystl;

int main() {
	RBTree<int, int>tree;
	tree.insert(1, 1);
	tree.insert(2, 3);
	tree.insert(-1, 0);
	tree.inorder(tree.root);
	std::cout << tree[2];
}