#ifndef EX_13_28
#define EX_13_28

#include "compile_options.h"

#include <string>
#include <memory>

using namespace std;

#ifdef REFERENCE_SEMANTICS
class TreeNode
{
	TreeNode() :
		value(string()),
		count(0),
		_left(nullptr),
		_right(nullptr){ }

	TreeNode(const TreeNode& rhs) = default;

	TreeNode& operator =(const TreeNode& rhs) = default;

private:
	string value;
	int count;
	shared_ptr<TreeNode> _left;
	shared_ptr<TreeNode> _right;
};

class BinStrTree
{
	BinStrTree() :
		_root(nullptr){ }
private:
	shared_ptr<TreeNode> _root;
};
#else
class TreeNode {
	TreeNode() :
		value(string()),
		count(0),
		_left(nullptr),
		_right(nullptr){ }

	TreeNode(const TreeNode& rhs):
		value(rhs.value),
		count(rhs.count)
	{
		_left = make_shared<TreeNode>(*rhs._left);
		_right = make_shared<TreeNode>(*rhs._right);
	}

	TreeNode& operator =(const TreeNode& rhs) 
	{
		// 原资源的释放不用管了。 原instance是一直存在的，只是改值而已。
		// ▇▇▇▇ 直接调用拷贝构造？(不能！只是改值成rhs的值，而不是再次构造个rhs值的instance)
		value = rhs.value;
		count = rhs.count;
		_left = make_shared<TreeNode>(*rhs._left);
		_right = make_shared<TreeNode>(*rhs._right);
		return *this;
	}
	


private:
	string value;
	int count;
	shared_ptr<TreeNode> _left;
	shared_ptr<TreeNode> _right;
};

class BinStrTree {
	BinStrTree() :
		_root(nullptr){ }
private:
	shared_ptr<TreeNode> _root;
};
#endif

#endif
