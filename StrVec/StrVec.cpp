#include "StrVec.h"
#include <memory>

StrVec::StrVec(const StrVec& copyobj) {
	auto pair = alloc_n_copy(copyobj._elments, copyobj._first_free);
	_elments = pair.first;
	_cap= _first_free = pair.second;
}

StrVec& StrVec::operator=(const StrVec& right) {
	
	return *this;
}

StrVec::~StrVec() {
	free();
}

void StrVec::push_back(string& str) {
	// 保证容量足够
	chk_n_alloc();
	// 使用allocator构造元素
	alloc.construct(_first_free++, str);
}

pair<string*, string*> StrVec::alloc_n_copy(const string* begin, const string* end) {
	auto data = alloc.allocate(end - begin);
	return	{ data,uninitialized_copy(begin,end,data) };
}

void StrVec::free() {
	for (auto pt = _elments; pt != _first_free; pt++) {
		alloc.destroy(pt);
	}
	alloc.deallocate(_elments, size());
}

void StrVec::reallocate() {
	/*>>>>>>>>>>>>>>>>>>>>>>>
	先重新获取块更大的内存；（2倍）
	把当前内容拷贝过去；
	释放当前内存；
	^^^^^^^^^^^^^^^^^^^^^^^^*/
	string* new_elements = alloc.allocate(2 * size());

}
