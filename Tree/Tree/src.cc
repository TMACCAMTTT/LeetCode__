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
//�����������������ս��ֵ��Ϊnull;
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
	//���ȶ����нڵ㸳ֵ��Ȼ���ù�ϣ��洢�±꼰���Ӧ�Ľڵ㣻
	//����2*i+1�Ĺ����������нڵ㣻
	//��ֵΪ�յĽ�㣬�����ǿս�㣡������ֻ��ֵΪ�ն��ѣ�������������ӡ���������ý�ֵΪ�յĽ���ӡ��һ���ϴ������
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
	//����1��ÿ�����ͷ�������Һ��ӣ�Ȼ��pop��ֱ������Ϊ�գ�
	/*queue<Node*> queue;
	queue.push(root);
	while (!queue.empty()) {
		Node* temp = queue.front();
		if (temp->left) queue.push(temp->left);
		if (temp->right) queue.push(temp->right);
		queue.pop();
		cout << temp->val << " ";
	}*/
	

	//����2��ÿ���ȱ��浱ǰ���У�Ȼ����ӣ�ֱ������Ϊ�գ��ٽ���һ������ӣ���������ͳ�����ߣ�
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
	//98.�ж��Ƿ�Ϊ��Ч����������
	//98����һ��ΪʲôҪ��prev�����ã���Ϊprev�ڵݹ�����л�仯��
	//�ݹ�ⷨ��������������������ǰ��Ľ�㣬��ֵС�ڵ���ǰ��Ľ�㣬�򷵻�false;
	if (node == NULL) return true;//����Ϊ����������
	if (!validate(node->left, prev)) return false;//��֤�Ե�ǰ���node������Ϊ���ڵ�����Ƿ�Ϊ��������������ʼʱprevΪ�գ����ݹ鵽��ײ㿪ʼ����ʱ��prev��ֵ�����Ϊnodeǰ��Ľ�㣻
	if (prev != NULL && prev->val >= node->val) return false;//�����ǰ����ֵС�ڵ�����ǰ�����ֵ���򷵻�false;
	prev = node;//����ǰ����㣻
	return validate(node->right, prev);//��ʱnode������Ϊ����������������������ֵ��С��node��ֵ����ʼ��֤node��������
}

bool helper(Node* root, Node* min, Node* max)
{
	//98������������ֵ��ǰ��㣬������������ֵ���Ľ�㣬��������ֵ��С�Ľ�㡣
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
	//236.�������������������͹�������
	//����һ����ϣ���Լ�һ������ջ����ϣ��Ӹ��ڵ㿪ʼ�洢������ÿ���ڵ�ĸ��ڵ㣬ֱ��p,q���ڹ�ϣ����Ϊֹ��
	//�Խڵ�p,�ٽ�һ����ϣ��hash���洢�������ڵ��·��������������У����p==q����p==map[q],�򷵻�p;
	//�Խڵ�q,��hash������ҵ����ĸ���㣬�ͷ��ظ���㣻����q����Ϊ���ĸ��ڵ㣻
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
		if (p == q || p == map[q]) return p;//p===q��ʾq��p�����ڵ��·���ϣ�p==map[q]��ʾqΪ����·��������һ�������ӽ�㣡��
	}
	find[p] = index;
	while (find.find(map[q]) == find.end()) {
		q = map[q];
	}
	return map[q];
}