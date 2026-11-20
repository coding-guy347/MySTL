/*手搓仿stl标准库*/

使用前包含头文件，例如#include"vector.h"
使用前包含命名空间，例如mystl::vector或using namespace mystl


//************************//
有关allocator类:

allocator是一个用于给容器分配内存的一个模板类，用于内存连续的容器，例如vector

//************************//

有关type_traits类

type_traits里有多个模板类，用于在编译期对象未实例化的时候判断类型





//***********************//

有关ArraryIterator：
ArraryIterator是一个用于顺序支持随机访问的容器的迭代器，例如vector

//************************//

有关ListIterator：
ListIterator是一个用于顺序非随机访问容器的迭代器，例如List

//**********************//
有关ListNode类：

ListNode是双向链表节点的模板类

//*********************//

有关List:
List是一个双向循环链表容器，内部包含一个private成员head，作为链表的头节点(哑节点)

List构造函数为默认构造函数，在创建一个List对象时，采用默认构造函数经行实例化，例如List<int>data
List.begin()返回指向第一个节点的指针
List.end()返回头节点指针，或链表尾节点的下一个节点(即head)
insert()传一个节点指针和数据，用与在这个节点经行前插
pop_back()：pop最后一个节点
pop_front()：pop第一个节点
push_back：尾插
push_front：前插
size：返回链表节点数量
swap：交换两个节点
clear：清除链表所有节点，将分配的内存还给os
//********************//

有关vector
vector是一个可自动扩容的数组容器
支持多种构造函数
api接口：
begin：返回指向第一个元素的指针
end：返回指向数组末尾的指针（非指向末尾元素）
capacity:返回容器容量大小
clear:清楚所有的元素（不将分配的内存返还给os）
empty:判断现在容器里面是否为空
erase：接受下边，删除改下标的元素
front:返回第一个元素
insert：接受一个下标和元素，在该下表插入元素，后面元素后退
pop_back:尾删
push_back：尾插
pop_front：头删
push_front：头插
reverse：逆置数组
swap：接受两个下标，交换两个下标的元素

