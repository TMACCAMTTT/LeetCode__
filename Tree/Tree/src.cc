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
	//具体规则：对每个节点，若它的左右孩子都在数组内，且左右孩子的值不为9999，则为有效节点，将其链接；否则（既左右孩子超过数组范围，或者在数组范围内，但是值为9999），就为空节点！
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
			st.push(p);//保存根节点，为了后续访问它的右孩子；
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
	//94.二叉树中序遍历非递归方法
	stack<Node*> st;
	Node* p = root;
	while (p || !st.empty()) {
		while (p) {
			st.push(p);
			p = p->left;//一直将p入栈，并更新为p的左孩子，直到p为空；这种情况下p为空时，于是只要栈非空，就应该出栈并访问；
		}
		//1.当p为空时，若栈非空，则说明栈顶结点为这个空p的父结点；
		//于是根据中序遍历规则，出栈并访问栈顶结点；然后更新为栈顶结点的右孩子，以查看它是否有右孩子；
		//2.当p为空时，若栈为空，
		if (!st.empty()) {
			p = st.top();
			st.pop();
			cout << p->val << " ";
			p = p->right;//更新后如果p为空，则它的父结点必定已被访问过，父结点的父结点也可能被访问过，总之当前栈顶结点为未被访问过的结点中最靠左的结点；于是出栈并访问，然后查看它的右孩子；
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
	//95唯一二叉搜索树，给定一个整数，求出所有包含1-n这n个结点的二叉搜索树；
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
				curr->left = left[j];//对当前结点curr,它的孩子共有left.size() * right.size()种组合；
 				curr->right = right[k];
				res.push_back(curr);
			}
		}
	}
	return res;
}

int numTrees(int n) {
	//96卡特兰数递推公式：设G(n)为n的卡特兰数，F（i, n）为以i为根结点时的卡特兰数，则G(n)=F(1,n) + ... + F(n, n).
	//F(i,n)=G(i - 1) * G(n - i),所以G(n) = G(0)*G( n - 1) + G(1) * G(n - 2) + ... + G(n - 1) * G(0);
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
	//105先序中序确定二叉树：index为此时根结点在preorder中的下标；首先确定根结点，然后递归求其左右结点；index在变化，每次递归加1；
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
	//106利用中序后序遍历确定二叉树
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

	root->right = buildTreeIPHelper(postorder, index, rootIndex + 1, end);//此时与先序中序有区别：先求右孩子，再求左孩子；
	root->left = buildTreeIPHelper(postorder, index, start, rootIndex - 1);
	
	return root;
}

void BiTree::postOrderNR(Node* t)
{
	//145二叉树后序遍历非递归。用一个last记录最近访问过的结点，当某个结点有右孩子且右孩子未被访问过时，需要转到右孩子；否则访问该结点。
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
	

	
	//方法2：用一个队列，每次将当前队列中所有元素出队并访问，即这一层结点；
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

bool hasPathSum(Node* root, int sum) 
{
	//112是否有路径和
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
	//169众数
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

	//摩尔投票法：开始时设一个候选者，一个计数器，值为1；遍历数组，候选者与当前数组值相同，则计数器加一，否则减一；若计数器减到0，则将候选者更新为当前值；
	//少用:运算符，影响时间；
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
	//设置两个候选者m,n；遍历数组
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
	//236.递归法求最近公共祖先：根结点为空，返回空结点；根结点为p或q,则直接返回根结点，否则去左右孩子中递归查找；若都找到，则返回根结点；否则返回左孩子或右孩子；
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
	//对节点p,再建一个哈希表find，存储它到根节点的路径；在这个过程中，如果p==q或者p==map[q],则返回p;
	//对节点q,在find中如果找到它的父结点，就返回父结点；否则q更新为它的父节点；
	if (!root) return NULL;
	if ((root == p) || (root == q)) return root;
	stack<Node*> st;
	unordered_map<Node*, Node*> map;
	map[root] = NULL;
	unordered_map<Node*, int> find;
	int index = 1;
	st.push(root);
	while (map.find(p) == map.end() || map.find(q) == map.end()) {//从根结点开始存储每个结点的父结点，直到包含p,q为止；
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

	while (p != root) {//用find存储结点p到根结点的路径，利用刚刚得到的map；求路径过程中可能直接返回；
		find[p] = index++;
		p = map[p];
		if (p == q || p == map[q]) return p;//p===q表示q在p到根节点的路径上；p==map[q]表示q为这条路径上其中一个结点的子结点！！
	}
	find[p] = index;

	while (find.find(map[q]) == find.end()) {//在刚刚求得的路径中找q的父结点，若找到则返回父结点，否则q更新为它的父结点；
		q = map[q];
	}
	return map[q];
}