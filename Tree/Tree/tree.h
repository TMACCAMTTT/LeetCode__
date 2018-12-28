#pragma once
constexpr auto null = 9999;//对值为空的结点，打印成9999；

#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

//Definition for a binary tree node
typedef class BiTreeNode {
public:
	int val;
	BiTreeNode *left;
	BiTreeNode *right;
}Node;

//Definition for a  binary tree
class BiTree {
public:
	BiTree() {
		root = NULL;
		height = 0;
	}

	void preOrder(Node* t);
	void preOrderNR(Node* t);//先序非递归式遍历
	void inOrder(Node* t);
	void inOrderNR(Node* t);//中序非递归式遍历
	void postOrder(Node* t);
	void postOrderNR(Node* t);//后序非递归式遍历
	void levelOrder(Node* t);//层次遍历
	int getHeight(Node* t);
private:
	Node* root;
	int height;
	//Node* create(string& s, int& pos);
};

Node* createBiTree(string& s, int& pos);//先序遍历创建字符二叉树；
Node* createBiTree(vector<int>& vec, int& pos);//先序遍历创建整数二叉树；
Node* createBiTreeByLevel(vector<int>& vec);//层次遍历创建二叉树
int getHeightByLevel(Node* root);//层次遍历求二叉树高度；
bool isValidBST(Node* root);//98.判断是否为有效二叉搜索树；
bool validate(Node* node, Node* &prev);
bool helper(Node* root, Node* min, Node* max);
Node* lowestCommonAncestor(Node* root, Node* p, Node* q);//236.最近公共祖先
Node* lowestCommonAncestorNR(Node* root, Node* p, Node* q);//236非递归
