#include "head.h"

vector<int> twoSum(vector<int>& nums, int target) {
	//1.two sum
	/*unordered_map<int, int> m;
	vector<int> res;
	for (int i = 0; i < nums.size(); i++)
	{
		int t = target - nums[i];
		if (m.count(t))
		{
			res.push_back(i);
			res.push_back(m[t]);
			break;
		}
		m[nums[i]] = i;
	}
	return res;*/
	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < nums.size(); i++)
	{
		int t = target - nums[i];
		if (hash.find(t) != hash.end() && hash[t] != i)
		{
			result.push_back(hash[t]);
			result.push_back(i);
			return result;
		}
		hash[nums[i]] = i;
	}
	return result;
}


vector<vector<int>> threeSum(vector<int>& nums) {
	//15.three sum:先对数组排序，然后遍历数组，设双指针，对每个元素，从下一个元素开始找两个数，使其之和等于这个数的相反数；
	//若当前元素等于上一个元素，则直接跳过；若和小于目标，则i++；否则j--;
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
	for (int k = 0; k < nums.size(); ++k) {
		if (nums[k] > 0) break;
		if (k > 0 && nums[k] == nums[k - 1]) continue;
		int target = 0 - nums[k];
		int i = k + 1, j = nums.size() - 1;
		while (i < j) {
			if (nums[i] + nums[j] == target) {
				res.push_back({ nums[k], nums[i], nums[j] });
				while (i < j && nums[i] == nums[i + 1]) ++i;
				while (i < j && nums[j] == nums[j - 1]) --j;
				++i; --j;
			}
			else if (nums[i] + nums[j] < target) ++i;
			else --j;
		}
	}
	return res;
}

int threeSumClosest(vector<int>& nums, int target) {
	//sum初始值设为最小值,速度就提升？
	//对找数值类问题，首先对数组排序，然后设头尾指针遍历数组；
	//对要求不重复的问题，注意去重判断；
	//此题设置diff，更新diff,更新sum。
	sort(nums.begin(), nums.end());
	int n = nums.size();
	int sum = INT_MIN;
	int diff = INT_MAX;
	for (int i = 0; i < nums.size() - 2; i++)
	{
		int left = i + 1;
		int right = nums.size() - 1;
		int find = target - nums[i];
		while (left < right) {
			if (nums[left] + nums[right] == find) {
				return target;
			}
			else if (nums[left] + nums[right] > find) {
				if (nums[left] + nums[right] - find < diff) {
					diff = nums[left] + nums[right] - find;
					sum = nums[i] + nums[left] + nums[right];

				}
				right--;
			}
			else {
				if (find - nums[left] - nums[right] < diff) {
					diff = find - nums[left] - nums[right];
					sum = nums[i] + nums[left] + nums[right];
				}
				left++;
			}
		}
	}
	return sum;
}

vector<vector<int>> kSum(vector<int>& nums, int k, int index, int target)
{
	//一次到位解决kSum：传入参数为数组，查找的元素个数，查找起始位置，目标数；
	//如果k==2,直接求解；否则k--,index++,target-=nums[i];然后在返回的数组头部插入nums[i]；
	//递归程序出错时，首先在循环里找错误；
	int level = 1;
	if (index >= nums.size()) {
		return {};
	}
	else if (k == 2) {
		vector<vector<int>> res;
		int left = index;
		int right = nums.size() - 1;
		while (left < right) {
			if (nums[left] + nums[right] == target) {
				res.push_back({ nums[left], nums[right] });
				int left_val = nums[left];
				int right_val = nums[right];
				left++;
				right--;
				while (left < right && nums[left + 1] == left_val) left++;
				while (left < right && nums[right - 1] == right_val) right--;
				
			}
			else if (nums[left] + nums[right] < target) {
				left++;
			}
			else {
				right--;
			}
		}
		return res;
	}
	else {
		vector<vector<int>> res;
		int mini = nums[index];
		int max = nums[nums.size() - 1];
		if (k * mini <= target && target <= k * max) {

			for (int i = index; i <= nums.size() - k; i++)
			{
				int this_val = nums[i];//保存数组中当前元素的值；
				vector<vector<int>> _sub = kSum(nums, k - 1, i + 1, target - nums[i]);
				level++;
				cout << "current level" << level << endl;
				for (vector<int> &find: _sub)
				{
					find.insert(find.begin(), nums[i]);
					res.push_back(find);
				}
				while (i < nums.size() && nums[i + 1] == nums[i]) {
					i++;
				}
			}
		}
		cout << "num" << k << "is done" << endl;
		return res;
	}
}



vector<vector<int>> fourSumRecursive(vector<int>& nums, int target)
{
	;
	if (nums.size() < 4) return {};
	sort(nums.begin(), nums.end());
	vector<vector<int>> res = kSum(nums, 4, 0, target);
	return res;
}

bool isValid(string s) {
	//20
	stack<char> parentheses;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			parentheses.push(s[i]);
		}
		else {
			if (parentheses.empty()) return false;
			if (s[i] == ')' && parentheses.top() != '(') return false;
			if (s[i] == ']' && parentheses.top() != '[') return false;
			if (s[i] == '}' && parentheses.top() != '{') return false;
			parentheses.pop();
		}
	}
	return parentheses.empty();
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> res;
	int n = nums.size();
	sort(nums.begin(), nums.end());
	if (nums.empty()) return {};
	for (int i = 0; i < n - 3; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1]) continue;
		for (int j = i + 1; j < n - 2; j++)
		{
			if (j > i + 1 && nums[j] == nums[j - 1]) continue;
			int left = j + 1;
			int right = n - 1;

			while (left < right) {
				int sum = nums[i] + nums[j] + nums[left] + nums[right];
				if (sum == target) {
					res.push_back({ nums[i], nums[j], nums[left], nums[right] });
					while (nums[left + 1] == nums[left]) left++;
					while (nums[right - 1] == nums[right]) right--;
					left++;
					right--;
				}
				else if (sum < target) {
					left++;
				}
				else {
					right--;
				}
			}

		}
	}
	return res;
}

int trap(vector<int>& height) {
	//当前坐标小于n时，做如下循环：当栈非空且当前高度大于栈顶坐标对应的高度时，则可能会形成坑；
	//此时先出栈一个元素，若栈为空，无法形成坑，跳出循环；若非空，则取当前高度和栈顶元素高度的较小值减去之前栈顶元素的高度作为高度，
	//取当前坐标减去栈顶坐标减1作为宽度，宽乘高得到这块雨水的面积，将这块面积加入结果；然后将当前坐标压入栈，当前坐标自增；
	//if判断体外一定要加括号！！！st.push(curr);curr++;很耗时间！！！用st.push(curr++);
	stack<int> st;
	int n = height.size();
	int current = 0, ans = 0;
	while (current < n) {
		while (!st.empty() && height[current] > height[st.top()]) {//栈非空且当前高度大于栈顶高度
			int top = st.top();
			st.pop();
			if (st.empty()) {
				break;
			}
			int distance = current - st.top() - 1;
			int h = min(height[current], height[st.top()]) - height[top];
			ans += distance * h;
		}
		st.push(current++);//将坐标压入栈
	}
	return ans;
}

bool find132pattern(vector<int>& nums)
{
	//对132中的2，要找一个大于2的数和一个小于2的数；
	//用一个栈存储大于2的数，再遍历数组找一个小于2的数；
	//如何维护栈：遍历元素时，只要元素大于2且栈非空，就出栈一个元素，并将栈顶元素赋给2，继续比较当前元素和2的大小，直到当前元素小于栈顶元素为止；
	//维护栈的最后一步：将当前元素入栈。这样就能满足栈顶元素大于2，且栈中元素大小自底向上递减；
	//总结：栈中元素为1，用一个变量存储2，再遍历数组寻找3；维护栈的操作可以理解为在遍历过程中维护尽可能大的2，这样就更容易找3；
	stack<int> st;
	int third = INT_MIN;
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		if (nums[i] < third) {
			return true;
		}
		else while (!st.empty() && nums[i] > third){//维护尽可能大的2
			third = st.top();
			st.pop();
		}
		st.push(nums[i]);
	}
	return false;
}

int calculate(string s) {
	//224基本计算器，递归实现
	int res = 0;
	int sign = 1;
	stack<int> st;
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if (c >= '0') {
			int num = 0;
			while (i < s.size() && s[i] >= '0') {
				num = num * 10 + s[i++] - '0';
			}
			res += num * sign;
			i--;
		}
		else if (c == '+') {
			sign = 1;
		}
		else if (c == '-') {
			sign = -1;
		}
		else if (c == '(') {//遇到左括号则将当前res和sign依次压入栈，然后对它们重新赋值，来计算括号中的值；当碰到右括号时，先将res乘以栈顶元素，既sign，然后出栈；再将结果与栈顶元素相加，即完成对这对括号的处理；
			st.push(res);
			st.push(sign);
			res = 0;
			sign = 1;
		}
		else if (c == ')') {
			res *= st.top();
			st.pop();
			res += st.top();
			st.pop();
		}
	}
	return res;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	//用双端队列存储元素下标而不是元素本身（为什么？？）；
	//每次来新元素时，首先，判断队头元素是否过期，如果是则弹出队头元素；
	//然后比较队尾元素和新元素，若小于新元素，则删除队尾元素，直到队尾元素大于等于新元素为止--
	//（因为这些元素比新来的元素早入栈，且比新来的元素小，没有出头之日），这样就可以始终保持front位置为最大值；
	//然后将当前元素下标入栈，并在第K-1轮时开始取队头元素入返回数组。

	vector<int> res;
	if (nums.empty() || k == 0) {
		return {};
	}
	deque<int> dq;
	for (int i = 0; i < nums.size(); i++)
	{
		if (dq.front() == i - k) {
			dq.pop_front();
		}
		while (!dq.empty() && nums[dq.back()] < nums[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
		if (i >= k - 1) {
			res.push_back(nums[dq.front()]);
		}
	}
	return res;
}

int maxWidthRamp(vector<int>& A) {
	int n = A.size();
	vector<vector<int> > dp(n, vector<int>(2, 0));
	dp[0][0] = 0;
	dp[0][1] = 0;
	for (int i = 1; i < n; i++)//更新low,high；
	{
		for (int j = i - 1; j >= 0; j--) {
			if (A[j] <= A[i]) {
				if (i - j > dp[i - 1][1] - dp[i - 1][0]) {
					dp[i][0] = j;
					dp[i][1] = i;
				}
				else if (i - j == dp[i - 1][1] - dp[i - 1][0] && A[j] < A[dp[i - 1][0]]) {
					dp[i][0] = j;
					dp[i][1] = i;
				}
			}
		}
	}
	return dp[n - 1][1] - dp[n - 1][0];
}

bool isAnagram(string s, string t) {
	//242 valid anagram,用哈希表
	if (s.length() != t.length()) return false;
	/*unordered_map<char, int> counts;
	for(int i = 0; i < s.size(); i++)
	{
		counts[s[i]]++;
		counts[t[i]]--;
	}
	for (auto count : counts)
		if(count.second) return false;
	return true;*/
	int a[26] = { 0 };
	for (int i = 0; i < s.size(); i++)
	{
		a[s[i] - 'a']++;
		a[t[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++) {
		if (a[i]) {
			return false;
		}
	}
	return true;
}

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	//454暴力解法，超时
	int res = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());
	sort(D.begin(), D.end());
	int n = A.size();
	if (A[0] + B[0] + C[0] + D[0] > 0 || A[n - 1] + B[n - 1] + C[n - 1] + D[n - 1] < 0) {
		return 0;
	}
	if (A[0] + B[0] + C[0] + D[0] == 0 || A[n - 1] + B[n - 1] + C[n - 1] + D[n - 1] == 0) {
		return 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int target = -(A[i] + B[j]);
			if (C[0] + D[0] > target) {
				continue;
			}
			else if (C[n - 1] + D[n - 1] < target) {
				continue;
			}
			else {
				int left = 0;
				int right = n - 1;
				while (left >= 0 && left < n && right >= 0 && right < n) {
					if (C[left] + D[right] == target) {
						int p = 1;//若C,D中都有重复元素，则一直遍历，直到跨过所有重复元素；这时假设C中有p个重复元素，D中有q个，则共有p*q对；
						int q = 1;
						while (left < n - 1 && C[left + 1] == C[left]) {
							p++;
							left++;
						}
						while (right > 0 && D[right - 1] == D[right]) {
							q++;
							right--;
						}
						res += p * q;
						left++;
						right--;
					}
					else if (left < n && C[left] + D[right] < target) {
						left++;
					}
					else if (right >= 0) {
						right--;
					}
				}
			}


		}
	}
	return res;
}

int fourSumCountHash(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	//在哈希表中建立两数之和和其出现次数之间的映射，将四次方的复杂度降为平方。
	int res = 0;
	unordered_map<int, int> hash;
	int n = A.size();
	for (int n : A)
		for (int m : B)
			++hash[n + m];
	for (int n : C)
		for (int m : D) {
			int target = -(n + m);
			auto it = hash.find(target);//对C,D的每一对和，在已经建立的哈希表中查找它出现的次数！！
			if (it != hash.end()) {
				res += it->second;
			}
		}
	return res;
}