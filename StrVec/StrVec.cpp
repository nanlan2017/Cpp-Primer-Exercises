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
	// ��֤�����㹻
	chk_n_alloc();
	// ʹ��allocator����Ԫ��
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
	�����»�ȡ�������ڴ棻��2����
	�ѵ�ǰ���ݿ�����ȥ��
	�ͷŵ�ǰ�ڴ棻
	^^^^^^^^^^^^^^^^^^^^^^^^*/
	string* new_elements = alloc.allocate(2 * size());

}
