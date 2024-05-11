#include"method.h"

int method2014(TreeNode2014 root) {
	int WPL = 0;

	

	return WPL;
}


TreeNode2014 GenerateTree2014() {
	//    1
	// 2     3 
	//4 5   6
	

	//456
	TNode2014* t4 = (TNode2014*)malloc(sizeof(TNode2014));
	if (t4)
	{
		t4->left = nullptr;
		t4->right = nullptr;
		t4->weight = 4;
	}
	
	TNode2014* t5 = (TNode2014*)malloc(sizeof(TNode2014));
	if (t5)
	{
		t5->left = nullptr;
		t5->right = nullptr;
		t5->weight = 5;
	}
	
	TNode2014* t6 = (TNode2014*)malloc(sizeof(TNode2014));
	if (t6)
	{
		t6->left = nullptr;
		t6->right = nullptr;
		t6->weight = 4;
	}

	//23
	TNode2014* t2 = (TNode2014*)malloc(sizeof(TNode2014));
	if (t2)
	{
		t2->left = t4;
		t2->right = t5;
		t2->weight = 2;
	}

	TNode2014* t3 = (TNode2014*)malloc(sizeof(TNode2014));
	if (t3)
	{
		t3->left = t6;
		t3->right = nullptr;
		t3->weight = 3;
	}

	//1
	TNode2014* root = (TNode2014*)malloc(sizeof(TNode2014));
	if (root)
	{
		root->left = t2;
		root->right = t3;
		root->weight = 1;
	}

	return root;
}


int WPL_PreOrder(TNode2014* root,int deep) 
{
	static int wpl = 0;
	//如果root为叶子节点
	if (root->left == nullptr && root->right == nullptr) {
		wpl += (deep)*root->weight;
	}
	//左子树不为空
	if (root->left) {
		WPL_PreOrder(root->left, deep + 1);
	}
	//柚子树不为空
	if (root->right)
	{
		WPL_PreOrder(root->right, deep + 1);
	}
	return wpl;
}