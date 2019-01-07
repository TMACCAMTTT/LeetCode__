#include "tree.h"


int main()
{
	Node* prev = NULL;
	BiTree Tree;
	string s = "ABD##E#F##C##";
	int a = -1;
	//vector<int> vec = { 5, 3, 2, NULL, NULL, 4, NULL, NULL, 7, 6, NULL, NULL, 8, NULL, NULL };
	//vector<int> test = {5, 3, 7, 2, 4, 6, 8};
	//vector<int> vec = { -1, 0, -2, 8, null, null, null, 4, null, null, 3, null, null };
	vector<int> level = { -1, 0, 3, -2, 4, null, null, 8 };
	//Node* root = createBiTree(vec, a);
	//Node* root = createBiTreeByLevel(level);
	//Node* q = root->left;
	//cout << "q.val:" << q->val << endl;
	//Node* p = root->left->left->left;
	//cout << "p.val:" << p->val << endl;
	//Tree.preOrder(root);
	//Tree.inOrder(root);
	//Tree.postOrder(root);
	//Tree.levelOrder(root);
	//cout << Tree.getHeight() << endl;
	//cout << getHeightByLevel(root) << endl;
	//cout << isValidBST(root) << endl;
	//Node* find = lowestCommonAncestor(root, q, p);
	//cout << "find:" << find->val << endl;
	//Tree.inOrderNR(root);
	//Tree.preOrderNR(root);
	//Tree.postOrderNR(root);
	//cout << hasPathSum(root, 3) << endl;
	//vector<vector<int>> res = printPathSum(root, 5);
	/*for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}*/
	vector<int> preorder = { 3,9,20,15,7 };
	vector<int> inorder = { 9,3,15,20,7 };
	vector<int> postorder = { 9,15,7,20,3 };
	Node* root = buildTreeIP(inorder, postorder);
	Tree.inOrder(root);
	return 0;
}