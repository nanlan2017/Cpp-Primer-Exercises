#include "common_tools.h"
#include "test_tools.h"

using wjh::Dog;
using wjh::NullInstance;

void wjh::usecase__NullInstance() {
	Dog dog1;
	if (dog1 == NullInstance<Dog>()) {
		std::cout << "dog1 is \"the null dog\"";
	} else {
		std::cout << "dog1 is another dog";
	}


	Dog dog2 = wjh::backDog();
	if (dog2== NullInstance<Dog>()) {
		std::cout << "the Dog instance returned is \"master-dog\"";
	} else {
		std::cout << "failed test";
	}
}


