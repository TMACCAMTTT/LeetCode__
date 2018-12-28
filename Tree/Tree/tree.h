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
bool isValidBST(Node* root);//98.�ж��Ƿ�Ϊ��Ч������������
bool validate(Node* node, Node* &prev);
bool helper(Node* root, Node* min, Node* max);
Node* lowestCommonAncestor(Node* root, Node* p, Node* q);//236.�����������
Node* lowestCommonAncestorNR(Node* root, Node* p, Node* q);//236�ǵݹ�
