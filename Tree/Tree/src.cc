#include "tree.h"

Node* createBiTree(string& s, int& pos)
{
	++pos;
	Node* t;
	if (pos > s.size()) {
		return NULL;
	}
	else {
		if (s[pos] == '#') {
			t = NULL;
		}
		else {
			t = new Node;
			t->val = s[pos];
			t->left = createBiTree(s, pos);
			t->right = createBiTree(s, pos);
		}
		return t;
	}
}

Node* createBiTree(vector<int>& vec, int& pos)
//创建整数二叉树，空结点值设为null;
{
	++pos;
	Node* t;
	if (pos >= vec.size()) return NULL;
	else {
		if (vec[pos] == null) {
			t = NULL;
		}
		else {
			t = new Node;
			t->val = vec[pos];
			t->left = createBiTree(vec, pos);
			t->right = createBiTree(vec, pos);
		}
		return t;
	}
}

Node* createBiTreeByLevel(vector<int>& vec)
{
	//首先对所有节点赋值，然后用哈希表存储下标及其对应的节点；
	//利用2*i+1的规则，链接所有节点；
	//对值为空的结点，它不是空结点！！！！只是值为空而已！！所以照样打印，可以设置将值为空的结点打印成一个较大的数。
	if (vec.empty()) return NULL;
	Node* t;
	unordered_map<int, Node*> hash;
	int size = vec.size();
	for (int i = 0; i < size; i++)
	{
		t = new Node;
		t->val = vec[i];
		hash[i] = t;
	}
	Node* root = hash[0];
	for (int i = 0; i < size; i++)
	{
		if (2 * i + 1 < size) {
			hash[i]->left = hash[2 * i + 1];
		}
		if (2 * i + 2 < size) {
			hash[i]->right = hash[2 * i + 2];
		}
	}
	return root;
}

void BiTree::preOrder(Node* root)
{
	Node* t = root;
	if (t != NULL) {
		cout << t->val << " ";
		preOrder(t->left);
		preOrder(t->right);
	}
	//cout << endl;
}

void BiTree::inOrder(Node* root)
{
	Node* t = root;
	if (t != NULL) {
		inOrder(t->left);
		cout << t->val << " ";
		inOrder(t->right);
	}
	//cout << endl;
}

void BiTree::postOrder(Node* root)
{
	Node* t = root;
	if (t != NULL) {
		postOrder(t->left);
		postOrder(t->right);
		cout << t->val << " ";
	}
	//cout << endl;
}

void BiTree::levelOrder(Node* root)
{
	//方法1：每次入队头结点的左右孩子，然后pop，直到队列为空；
	/*queue<Node*> queue;
	queue.push(root);
	while (!queue.empty()) {
		Node* temp = queue.front();
		if (temp->left) queue.push(temp->left);
		if (temp->right) queue.push(temp->right);
		queue.pop();
		cout << temp->val << " ";
	}*/
	

	//方法2：每次先保存当前队列，然后出队，直到队列为空；再将下一层结点入队；这样可以统计树高；
	queue<Node*> que;
	queue<Node*> helper;
	que.push(root);
	while (!que.empty()) {
		helper = que;
		while (!que.empty()) {
			cout << que.front()->val << " ";
			que.pop();
		}
		while (!helper.empty()) {
			if (helper.front()->left) que.push(helper.front()->left);
			if (helper.front()->right) que.push(helper.front()->right);
			helper.pop();
		}

	}
	
}

int BiTree::getHeight(Node* root)
{
	Node* t = root;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}

int getHeightByLevel(Node* root) 
{
	int res = 0;
	queue<Node*> que;
	queue<Node*> helper;
	que.push(root);
	while (!que.empty()) {
		helper = que;
		while (!que.empty()) {
			//cout << que.front()->val << " ";
			que.pop();
		}
		res++;
		while (!helper.empty()) {
			if (helper.front()->left) que.push(helper.front()->left);
			if (helper.front()->right) que.push(helper.front()->right);
			helper.pop();
		}
	}
	return res;
}

bool isValidBST(Node* root) {
	Node* prev = NULL;
	//return validate(root, prev);
	return helper(root, NULL, NULL);
}

bool validate(Node* node, Node* &prev) {
	//98.判断是否为有效二叉搜索树
	//98方法一：为什么要传prev的引用：因为prev在递归过程中会变化！
	//递归解法：中序遍历，传入结点和它前面的结点，若值小于等于前面的结点，则返回false;
	if (node == NULL) return true;//空树为二叉搜索树
	if (!validate(node->left, prev)) return false;//验证以当前结点node的左孩子为根节点的树是否为二叉搜索树，开始时prev为空，当递归到最底层开始返回时，prev的值会更新为node前面的结点；
	if (prev != NULL && prev->val >= node->val) return false;//如果当前结点的值小于等于它前面结点的值，则返回false;
	prev = node;//更新前驱结点；
	return validate(node->right, prev);//此时node左子树为二叉搜索树，且左子树的值均小于node的值，开始验证node右子树；
}

bool helper(Node* root, Node* min, Node* max)
{
	//98方法二：传入值当前结点，和它左子树中值最大的结点，右子树中值最小的结点。
	if (root == nullptr) return true;
	if (min != nullptr && root->val >= min->val) return false;
	if (max != nullptr && root->val <= max->val) return false;
	return helper(root->left, root, max) && helper(root->right, min, root);
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
	if (!root) return NULL;
	if ((root == p) || (root == q)) return root;
	Node* left = lowestCommonAncestor(root->left, p, q);
	Node* right = lowestCommonAncestor(root->right, p, q);
	if (left && right) return root;
	if (left) return left;
	if (right) return right;
	return NULL;
}

Node* lowestCommonAncestorNR(Node* root, Node* p, Node* q)
{
	//236.求二叉树中两个结点的最低公共祖先
	//先用一个哈希表，以及一个辅助栈；哈希表从根节点开始存储遍历的每个节点的父节点，直到p,q都在哈希表中为止；
	//对节点p,再建一个哈希表hash，存储它到根节点的路径；在这个过程中，如果p==q或者p==map[q],则返回p;
	//对节点q,在hash中如果找到它的父结点，就返回父结点；否则q更新为它的父节点；
	if (!root) return NULL;
	if ((root == p) || (root == q)) return root;
	stack<Node*> st;
	unordered_map<Node*, Node*> map;
	map[root] = NULL;
	unordered_map<Node*, int> find;
	int index = 1;
	st.push(root);
	while (map.find(p) == map.end() || map.find(q) == map.end()) {
		Node* node = st.top();
		st.pop();
		if (node->left) {
			map[node->left] = node;
			st.push(node->left);
		}
		if (node->right) {
			map[node->right] = node;
			st.push(node->right);
		}
	}
	while (p != root) {
		find[p] = index++;
		p = map[p];
		if (p == q || p == map[q]) return p;//p===q表示q在p到根节点的路径上；p==map[q]表示q为这条路径上其中一个结点的子结点！！
	}
	find[p] = index;
	while (find.find(map[q]) == find.end()) {
		q = map[q];
	}
	return map[q];
}