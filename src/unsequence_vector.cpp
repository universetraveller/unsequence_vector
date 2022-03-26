#include "unsequence_vector.h"
template <typename elemtype, int integer>
void unsequence_vector<elemtype,integer>::pushback(elemtype input) {
	if (con_pointer_ != last_pointer_) {
		*con_pointer_ = input;
		con_pointer_++;		//赋值
	}
	else {
		NodeArray<elemtype, integer> newArray;	//内容超过容量时扩张
		this->head_pointers_.push_back(newArray.head_pointer);
		last_pointer_ = newArray.tail_pointer;
		con_pointer_ = newArray.head_pointer;
		*con_pointer_ = input;
		con_pointer_++;
	}
}
template<typename elemtype, int integer>
elemtype& unsequence_vector<elemtype, integer>::operator[](unsigned input)const{
	static unsigned main_number;
	static unsigned sub_number;
	main_number = input / integer;
	if (!main_number) {
		return *(this->begin_pointer_ + input);
	}
	sub_number = input % integer;
	return *(this->head_pointers_[main_number] + sub_number);
}

template<typename elemtype, int integer>
unsequence_vector<elemtype, integer>::~unsequence_vector(){
	for (int i = 0; i < head_pointers_.size(); i++) {
		delete[]head_pointers_[i];
	}
}


