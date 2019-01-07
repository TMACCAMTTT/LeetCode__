#pragma once
constexpr auto null = 9999;//��ֵΪ�յĽ�㣬��ӡ��9999��

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
	void preOrderNR(Node* t);//����ǵݹ�ʽ����
	void inOrder(Node* t);
	void inOrderNR(Node* t);//����ǵݹ�ʽ����
	void postOrder(Node* t);
	void postOrderNR(Node* t);//����ǵݹ�ʽ����
	void levelOrder(Node* t);//��α���
	int getHeight(Node* t);
private:
	Node* root;
	int height;
	//Node* create(string& s, int& pos);
};

Node* createBiTree(string& s, int& pos);//������������ַ���������
Node* createBiTree(vector<int>& vec, int& pos);//�����������������������
Node* createBiTreeByLevel(vector<int>& vec);//��α�������������
int getHeightByLevel(Node* root);//��α�����������߶ȣ�
vector<Node*> generateTrees(int n);//95
vector<Node*> generateTree(int start, int end);//95Ψһ����������
int numTrees(int n);//96��������
bool isValidBST(Node* root);//98.�ж��Ƿ�Ϊ��Ч������������
bool validate(Node* node, Node* &prev);
bool helper(Node* root, Node* min, Node* max);
Node* buildTree(vector<int>& preorder, vector<int>& inorder);//105.���������������ȷ��������
Node* buildTreeHelper(vector<int>& preorder, int& index, int start, int end);
Node* buildTreeIP(vector<int>& inorder, vector<int>& postorder);//106.��������������ȷ��������
Node* buildTreeIPHelper(vector<int>& postorder, int& index, int start, int end);
bool hasPathSum(Node* root, int sum);//112·����
vector<vector<int>> printPathSum(Node* root, int sum);//�ҳ����з���������·��������ӡ
void helper(Node* root, int sum, vector<int>& path, vector<vector<int>>& res);//��������
int majorityElement(vector<int>& nums);//169Ħ��ͶƱ������
vector<int> majorityElementThird(vector<int>& nums);//229Ħ��ͶƱ����
Node* lowestCommonAncestor(Node* root, Node* p, Node* q);//236.�����������
Node* lowestCommonAncestorNR(Node* root, Node* p, Node* q);//236�ǵݹ�
