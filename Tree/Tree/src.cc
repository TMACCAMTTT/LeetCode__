#include "tree.h"
unordered_map<int, int> hash105;
unordered_map<int, int> hash106;

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
	//������򣺶�ÿ���ڵ㣬���������Һ��Ӷ��������ڣ������Һ��ӵ�ֵ��Ϊ9999����Ϊ��Ч�ڵ㣬�������ӣ����򣨼����Һ��ӳ������鷶Χ�����������鷶Χ�ڣ�����ֵΪ9999������Ϊ�սڵ㣡
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
		if (2 * i + 1 < size && hash[2 * i + 1]->val != 9999) {
			hash[i]->left = hash[2 * i + 1];
		}
		else {
			hash[i]->left = NULL;
		}
		if (2 * i + 2 < size && hash[2 * i + 2]->val != 9999) {
			hash[i]->right = hash[2 * i + 2];
		}
		else {
			hash[i]->right = NULL;
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

void BiTree::preOrderNR(Node* root)
 {
	if (!root) return;
	stack<Node*> st;
	st.push(root);
	/*TreeNode* p = root;
	while(p || !st.empty()){
		if(p){
			st.push(p);//������ڵ㣬Ϊ�˺������������Һ��ӣ�
			res.push_back(p->val);
			p = p->left;
		}else{
			p = st.top();
			st.pop();
			p = p->right;
		}
	}*/
	while (!st.empty()) {
		Node* p = st.top();
		st.pop();
		cout << p->val << " ";
		if (p->right) st.push(p->right);
		if (p->left) st.push(p->left);
	}
	cout << endl;
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

void BiTree::inOrderNR(Node* root)
{
	//94.��������������ǵݹ鷽��
	stack<Node*> st;
	Node* p = root;
	while (p || !st.empty()) {
		while (p) {
			st.push(p);
			p = p->left;//һֱ��p��ջ��������Ϊp�����ӣ�ֱ��pΪ�գ����������pΪ��ʱ������ֻҪջ�ǿգ���Ӧ�ó�ջ�����ʣ�
		}
		//1.��pΪ��ʱ����ջ�ǿգ���˵��ջ�����Ϊ�����p�ĸ���㣻
		//���Ǹ�������������򣬳�ջ������ջ����㣻Ȼ�����Ϊջ�������Һ��ӣ��Բ鿴���Ƿ����Һ��ӣ�
		//2.��pΪ��ʱ����ջΪ�գ�
		if (!st.empty()) {
			p = st.top();
			st.pop();
			cout << p->val << " ";
			p = p->right;//���º����pΪ�գ������ĸ����ض��ѱ����ʹ��������ĸ����Ҳ���ܱ����ʹ�����֮��ǰջ�����Ϊδ�����ʹ��Ľ�������Ľ�㣻���ǳ�ջ�����ʣ�Ȼ��鿴�����Һ��ӣ�
		}
	}
	cout << endl;
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

vector<Node*> generateTrees(int n)
{
	//95Ψһ����������������һ��������������а���1-n��n�����Ķ�����������
	if (n <= 0) return {};
	return generateTree(1, n);

}

vector<Node*> generateTree(int start, int end)
{
	if (start > end) return {NULL};
	vector<Node*> res;
	for (int i = start; i <= end; i++)
	{
		vector<Node*> left = generateTree(start, i - 1);
		vector<Node*> right = generateTree(i + 1, end);
		for (int j = 0; j < left.size(); j++)
		{
			for (int k = 0; k < right.size(); k++)
			{
				Node* curr = new Node;
				curr->val = i;
				curr->left = left[j];//�Ե�ǰ���curr,���ĺ��ӹ���left.size() * right.size()����ϣ�
 				curr->right = right[k];
				res.push_back(curr);
			}
		}
	}
	return res;
}

int numTrees(int n) {
	//96�����������ƹ�ʽ����G(n)Ϊn�Ŀ���������F��i, n��Ϊ��iΪ�����ʱ�Ŀ�����������G(n)=F(1,n) + ... + F(n, n).
	//F(i,n)=G(i - 1) * G(n - i),����G(n) = G(0)*G( n - 1) + G(1) * G(n - 2) + ... + G(n - 1) * G(0);
	vector<int> res(n + 1, 0);
	res[0] = 1;
	res[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			res[i] += res[j] * res[i - j - 1];
		}
	}
	return res[n];
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	for (int i = 0; i < inorder.size(); i++)
	{
		hash105[inorder[i]] = i;
	}
	int n = 0;
	return buildTreeHelper(preorder, n, 0, inorder.size() - 1);
}

Node* buildTreeHelper(vector<int>& preorder, int& index, int start, int end)
{
	//105��������ȷ����������indexΪ��ʱ�������preorder�е��±ꣻ����ȷ������㣬Ȼ��ݹ��������ҽ�㣻index�ڱ仯��ÿ�εݹ��1��
	if (start > end) return NULL;
	Node* root = new Node;
	root->val = preorder[index];
	int rootIndex = hash105[preorder[index]];
	index++;

	root->left = buildTreeHelper(preorder, index, start, rootIndex - 1);
	root->right = buildTreeHelper(preorder, index, rootIndex + 1, end);
	return root;
}

Node* buildTreeIP(vector<int>& inorder, vector<int>& postorder)
{
	//106��������������ȷ��������
	for (int i = 0; i < inorder.size(); i++)
	{
		hash106[inorder[i]] = i;
	}
	int n = inorder.size() - 1;
	return buildTreeIPHelper(postorder, n, 0, inorder.size() - 1);
}

Node* buildTreeIPHelper(vector<int>& postorder, int& index, int start, int end)
{
	if (start > end) return NULL;
	Node* root = new Node;
	root->val = postorder[index];
	int rootIndex = hash106[postorder[index]];
	index--;

	root->right = buildTreeIPHelper(postorder, index, rootIndex + 1, end);//��ʱ���������������������Һ��ӣ��������ӣ�
	root->left = buildTreeIPHelper(postorder, index, start, rootIndex - 1);
	
	return root;
}

void BiTree::postOrderNR(Node* t)
{
	//145��������������ǵݹ顣��һ��last��¼������ʹ��Ľ�㣬��ĳ��������Һ������Һ���δ�����ʹ�ʱ����Ҫת���Һ��ӣ�������ʸý�㡣
	if (!t) return;
	Node* last = NULL;
	stack<Node*> st;
	Node* p = t;
	while (p || !st.empty()) {
		if(p) {
			st.push(p);
			p = p->left;
		}
		else {
			p = st.top();
			if (p->right && p->right != last) {
				p = p->right;
			}
			else {
				st.pop();
				cout << p->val << " ";
				last = p;
				p = NULL;
			}
		}

	}
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
	

	
	//����2����һ�����У�ÿ�ν���ǰ����������Ԫ�س��Ӳ����ʣ�����һ���㣻
	queue<Node*> queue;
	queue.push(root);
	while (!queue.empty()) {
		int size = queue.size();
		for (int i = 0; i < size; i++)
		{
			Node* curr = queue.front();
			if (curr->left) queue.push(curr->left);
			if (curr->right) queue.push(curr->right);
			cout << curr->val << " ";
			queue.pop();
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

bool hasPathSum(Node* root, int sum) 
{
	//112�Ƿ���·����
	if (!root) return 0;
	if (root->val == sum && !root->left && !root->right) return 1;
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

vector<vector<int>> printPathSum(Node* root, int sum)
{
	vector<vector<int>> res;
	vector<int> path;
	helper(root, sum, path, res);
	return res;
}

void helper(Node* root, int sum, vector<int>& path, vector<vector<int>>& res)
{
	if (!root) return;
	path.push_back(root->val);
	if (root->val == sum && !root->left && !root->right) {
		res.push_back(path);
	}
	helper(root->left, sum - root->val, path, res);
	helper(root->right, sum - root->val, path, res);
	path.pop_back();
}

int majorityElement(vector<int>& nums) {
	//169����
	/*unordered_map<int, int> hash;
	for(int i = 0; i < nums.size(); i++)
	{
		if(hash.find(nums[i]) == hash.end()){
			hash[nums[i]] = 1;
		}else{
			hash[nums[i]]++;
		}
	}
	for(int i = 0; i < nums.size(); i++)
	{
		if(hash[nums[i]] > nums.size()/2)
			return nums[i];
	}*/

	//Ħ��ͶƱ������ʼʱ��һ����ѡ�ߣ�һ����������ֵΪ1���������飬��ѡ���뵱ǰ����ֵ��ͬ�����������һ�������һ��������������0���򽫺�ѡ�߸���Ϊ��ǰֵ��
	//����:�������Ӱ��ʱ�䣻
	int count = 0;
	int candidate = nums[0];
	for (int num : nums) {
		if (count == 0) {
			candidate = num;
			count++;
		}
		else if (candidate == num) {
			count++;
		}
		else
			count--;
	}
	return candidate;
}

vector<int> majorityElementThird(vector<int>& nums) {
	//229
	//����������ѡ��m,n����������
	vector<int> res;
	int m = 0, n = 0, cm = 0, cn = 0;
	for (auto &a : nums) {
		if (a == m) ++cm;
		else if (a == n) ++cn;
		else if (cm == 0) m = a, cm = 1;
		else if (cn == 0) n = a, cn = 1;
		else --cm, --cn;
	}
	cm = cn = 0;
	for (auto &a : nums) {
		if (a == m) ++cm;
		else if (a == n) ++cn;
	}
	if (cm > nums.size() / 3) res.push_back(m);
	if (cn > nums.size() / 3) res.push_back(n);
	return res;
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
	//236.�ݹ鷨������������ȣ������Ϊ�գ����ؿս�㣻�����Ϊp��q,��ֱ�ӷ��ظ���㣬����ȥ���Һ����еݹ���ң������ҵ����򷵻ظ���㣻���򷵻����ӻ��Һ��ӣ�
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
	//�Խڵ�p,�ٽ�һ����ϣ��find���洢�������ڵ��·��������������У����p==q����p==map[q],�򷵻�p;
	//�Խڵ�q,��find������ҵ����ĸ���㣬�ͷ��ظ���㣻����q����Ϊ���ĸ��ڵ㣻
	if (!root) return NULL;
	if ((root == p) || (root == q)) return root;
	stack<Node*> st;
	unordered_map<Node*, Node*> map;
	map[root] = NULL;
	unordered_map<Node*, int> find;
	int index = 1;
	st.push(root);
	while (map.find(p) == map.end() || map.find(q) == map.end()) {//�Ӹ���㿪ʼ�洢ÿ�����ĸ���㣬ֱ������p,qΪֹ��
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

	while (p != root) {//��find�洢���p��������·�������øոյõ���map����·�������п���ֱ�ӷ��أ�
		find[p] = index++;
		p = map[p];
		if (p == q || p == map[q]) return p;//p===q��ʾq��p�����ڵ��·���ϣ�p==map[q]��ʾqΪ����·��������һ�������ӽ�㣡��
	}
	find[p] = index;

	while (find.find(map[q]) == find.end()) {//�ڸո���õ�·������q�ĸ���㣬���ҵ��򷵻ظ���㣬����q����Ϊ���ĸ���㣻
		q = map[q];
	}
	return map[q];
}