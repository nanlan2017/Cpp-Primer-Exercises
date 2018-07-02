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
		// ԭ��Դ���ͷŲ��ù��ˡ� ԭinstance��һֱ���ڵģ�ֻ�Ǹ�ֵ���ѡ�
		// �~�~�~�~ ֱ�ӵ��ÿ������죿(���ܣ�ֻ�Ǹ�ֵ��rhs��ֵ���������ٴι����rhsֵ��instance)
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
