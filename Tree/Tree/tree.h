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
vector<Node*> generateTrees(int n);//95
vector<Node*> generateTree(int start, int end);//95唯一二叉搜索树
int numTrees(int n);//96卡特兰数
bool isValidBST(Node* root);//98.判断是否为有效二叉搜索树；
bool validate(Node* node, Node* &prev);
bool helper(Node* root, Node* min, Node* max);
Node* buildTree(vector<int>& preorder, vector<int>& inorder);//105.利用先序中序遍历确定二叉树
Node* buildTreeHelper(vector<int>& preorder, int& index, int start, int end);
Node* buildTreeIP(vector<int>& inorder, vector<int>& postorder);//106.利用中序后序遍历确定二叉树
Node* buildTreeIPHelper(vector<int>& postorder, int& index, int start, int end);
bool hasPathSum(Node* root, int sum);//112路径和
vector<vector<int>> printPathSum(Node* root, int sum);//找出所有符号条件的路径，并打印
void helper(Node* root, int sum, vector<int>& path, vector<vector<int>>& res);//辅助函数
int majorityElement(vector<int>& nums);//169摩尔投票法！！
vector<int> majorityElementThird(vector<int>& nums);//229摩尔投票法，
Node* lowestCommonAncestor(Node* root, Node* p, Node* q);//236.最近公共祖先
Node* lowestCommonAncestorNR(Node* root, Node* p, Node* q);//236非递归
