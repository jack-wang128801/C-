#if 0
//改进的二叉搜索树
//平衡树的建设

#include<iostream>

using namespace std;

template<class T>
//结点的定义
struct AVLNode
{
	AVLNode(const T& val = T())
	:_data(val)
	, _pLeft(nullptr)
	, _pRight(nullptr)
	, _pParent(nullptr)
	, _bf(0)
	{}
	T _data;
	AVLNode<T>* _pLeft;
	AVLNode<T>* _pRight;
	AVLNode<T>* _pParent;
	//平衡因子，用来记录结点的左右子树高度差
	int _bf;
};

template <class T>
class AVLTree
{
public:
	typedef AVLNode<T> Node;
	typedef Node* pNode;

	//插入结点
	/*
	若根结点为空,申请一个结点进行初始化
	若不为空,
	*/
	bool insert(const T& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}

		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_data > val)
			{
				cur = cur->_pLeft;
			}
			else if (cur->_data < val)
			{
				cur = cur->_pRight;
			}
			else
				return false;
		}

		//开始插入
		pNode newNode = new Node(val);
		if (parent->_data > val)
			parent->_pLeft = newNode;
		else
			parent->_pRight = newNode;
		newNode->_pParent = parent;
		//将新结点与父节点联系起来

		//调整，保证平衡
		while (parent)
		{
			//更新当前节点的平衡因子
			if (parent->_data > val)
				--parent->_bf;
			else
				++parent->_bf;
			//检查平衡因子，_bf ==0, 高度没有发生变化，停止更新
			if (parent->_bf == 0)
				break;
			//高度加1，更新此路径上的祖先节点的平衡因子
			if (parent->_bf == 1 || parent->_bf = -1)
				parent = parent->_pParent;
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//不平衡，需要调整
				//左旋
				if (parent->_bf == 2 && parent->_pRight->_bf == 1)
				{
					RotateL(parent);
				}
				else if (.....)

					//旋转结束，已经平衡，结束调整
					break;
			}

		}

	}


	//左旋
	void RotateL(pNode parent)
	{
		pNode subR = parent->_pRight;
		pNode subRL = subR->_pLeft;
		//旋转
		subR->_pLeft = parent;
		parent->_pRight = subRL;

		//更新三叉链
		//链接subRL 和parent
		if (subRL)
			subRL->_pParent = parent;

		//链接subR 和 parent->_pParent
		if (parent != _root)
		{
			pNode gParent = parent->_pParent;
			//判断parent之前是parent->_pParent的那一边的节点
			//把subR链接到对应的边
			if (gParent->_pLeft = parent)
				gParent->_pLeft = subR;
			else
				gParent->_pRight = subR;
			//更新subR的pParent
			subR->_pParent = gParent;
		}
		else
		{
			//如果parent是根，subR变成新的根
			subR->_pParent = nullptr;
			_root = subR;
			//更新根节点
		}

		//链接subR 和 parent
		parent->_pParent = subR;


		//更新平衡因子
		subR->_bf = parent->_bf = 0;
	}

private:
	pNode _root = nullptr;
};
int main(){

	return 0;
}
#endif