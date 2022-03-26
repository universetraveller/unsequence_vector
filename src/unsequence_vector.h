#pragma once
#include <vector>
//#include "NodeArray.h"
template <typename elemname, int node_capacity>
class NodeArray;

template <typename elemtype, int integer=64> class unsequence_vector {
public:
	unsequence_vector() {
		NodeArray<elemtype,integer> default_node;	//Ĭ�Ϲ���һ���ڵ�
		begin_pointer_ = default_node.head_pointer;
		head_pointers_.push_back(begin_pointer_);
		last_pointer_ = default_node.tail_pointer;
		con_pointer_ = default_node.head_pointer;
	}
	void pushback(elemtype);
	elemtype& operator[](unsigned)const;
	~unsequence_vector();
private:
	std::vector<elemtype*> head_pointers_;  //�洢��ֵͷָ�룬ѡ������������ȡ��vector
	elemtype* begin_pointer_ = 0;	//��ͷָ��
	elemtype* last_pointer_ = 0;	//��βָ��+1
	elemtype* con_pointer_ = 0;		//��ǰ���λ
};

template <typename elemname, int node_capacity>
class NodeArray {
public:
	NodeArray() {};	//����ڵ㣬����λ����
	friend class unsequence_vector<elemname, node_capacity>;
private:
	elemname* head_pointer = new elemname[node_capacity];	//ͷָ��
	elemname* tail_pointer = head_pointer + node_capacity;	//βָ��+1
};