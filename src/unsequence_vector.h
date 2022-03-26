#pragma once
#include <vector>
//#include "NodeArray.h"
template <typename elemname, int node_capacity>
class NodeArray;

template <typename elemtype, int integer=64> class unsequence_vector {
public:
	unsequence_vector() {
		NodeArray<elemtype,integer> default_node;	//默认构造一个节点
		begin_pointer_ = default_node.head_pointer;
		head_pointers_.push_back(begin_pointer_);
		last_pointer_ = default_node.tail_pointer;
		con_pointer_ = default_node.head_pointer;
	}
	void pushback(elemtype);
	elemtype& operator[](unsigned)const;
	~unsequence_vector();
private:
	std::vector<elemtype*> head_pointers_;  //存储数值头指针，选用利于连续读取的vector
	elemtype* begin_pointer_ = 0;	//总头指针
	elemtype* last_pointer_ = 0;	//总尾指针+1
	elemtype* con_pointer_ = 0;		//当前最高位
};

template <typename elemname, int node_capacity>
class NodeArray {
public:
	NodeArray() {};	//数组节点，按单位扩张
	friend class unsequence_vector<elemname, node_capacity>;
private:
	elemname* head_pointer = new elemname[node_capacity];	//头指针
	elemname* tail_pointer = head_pointer + node_capacity;	//尾指针+1
};