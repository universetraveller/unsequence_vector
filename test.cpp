#include "unsequence_vector.h"
#include <iostream>
#include "unsequence_vector.cpp"
int main() {
	unsigned int one = 1;
	unsequence_vector<int,3> test;
	test.pushback(3);
	test.pushback(4);
	test.pushback(5);
	test.pushback(12);
	test.pushback(13);
	test.pushback(14);
	test.pushback(15);
	std::cout << test[0] <<" " << test[one] <<" " << test[2] <<" " << test[3] << " " << test[4] << " " << test[5]<<" "
		<< test[6] << " " << test[7] << " " << test[0];
	return 0;
}
int main1() {
	std::vector<int> a;
	unsequence_vector<int, 128> b;
	for (int i = 0; i < 100000; i++) {
		//a.push_back(5);  11ms
		//b.pushback(5);  7ms
	}
	return 0;
}