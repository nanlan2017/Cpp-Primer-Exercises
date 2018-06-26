#include "test_tools.h"
#include "common_tools.h"

using namespace wjh;

Dog& wjh::backDog() {
	return NullInstance<Dog>().get();
}