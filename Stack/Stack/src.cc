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
	//15.three sum:�ȶ���������Ȼ��������飬��˫ָ�룬��ÿ��Ԫ�أ�����һ��Ԫ�ؿ�ʼ����������ʹ��֮�͵�����������෴����
	//����ǰԪ�ص�����һ��Ԫ�أ���ֱ������������С��Ŀ�꣬��i++������j--;
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
	//sum��ʼֵ��Ϊ��Сֵ,�ٶȾ�������
	//������ֵ�����⣬���ȶ���������Ȼ����ͷβָ��������飻
	//��Ҫ���ظ������⣬ע��ȥ���жϣ�
	//��������diff������diff,����sum��
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
	//һ�ε�λ���kSum���������Ϊ���飬���ҵ�Ԫ�ظ�����������ʼλ�ã�Ŀ������
	//���k==2,ֱ����⣻����k--,index++,target-=nums[i];Ȼ���ڷ��ص�����ͷ������nums[i]��
	//�ݹ�������ʱ��������ѭ�����Ҵ���
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
				int this_val = nums[i];//���������е�ǰԪ�ص�ֵ��
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
	//��ǰ����С��nʱ��������ѭ������ջ�ǿ��ҵ�ǰ�߶ȴ���ջ�������Ӧ�ĸ߶�ʱ������ܻ��γɿӣ�
	//��ʱ�ȳ�ջһ��Ԫ�أ���ջΪ�գ��޷��γɿӣ�����ѭ�������ǿգ���ȡ��ǰ�߶Ⱥ�ջ��Ԫ�ظ߶ȵĽ�Сֵ��ȥ֮ǰջ��Ԫ�صĸ߶���Ϊ�߶ȣ�
	//ȡ��ǰ�����ȥջ�������1��Ϊ��ȣ���˸ߵõ������ˮ�����������������������Ȼ�󽫵�ǰ����ѹ��ջ����ǰ����������
	//if�ж�����һ��Ҫ�����ţ�����st.push(curr);curr++;�ܺ�ʱ�䣡������st.push(curr++);
	stack<int> st;
	int n = height.size();
	int current = 0, ans = 0;
	while (current < n) {
		while (!st.empty() && height[current] > height[st.top()]) {//ջ�ǿ��ҵ�ǰ�߶ȴ���ջ���߶�
			int top = st.top();
			st.pop();
			if (st.empty()) {
				break;
			}
			int distance = current - st.top() - 1;
			int h = min(height[current], height[st.top()]) - height[top];
			ans += distance * h;
		}
		st.push(current++);//������ѹ��ջ
	}
	return ans;
}

bool find132pattern(vector<int>& nums)
{
	//��132�е�2��Ҫ��һ������2������һ��С��2������
	//��һ��ջ�洢����2�������ٱ���������һ��С��2������
	//���ά��ջ������Ԫ��ʱ��ֻҪԪ�ش���2��ջ�ǿգ��ͳ�ջһ��Ԫ�أ�����ջ��Ԫ�ظ���2�������Ƚϵ�ǰԪ�غ�2�Ĵ�С��ֱ����ǰԪ��С��ջ��Ԫ��Ϊֹ��
	//ά��ջ�����һ��������ǰԪ����ջ��������������ջ��Ԫ�ش���2����ջ��Ԫ�ش�С�Ե����ϵݼ���
	//�ܽ᣺ջ��Ԫ��Ϊ1����һ�������洢2���ٱ�������Ѱ��3��ά��ջ�Ĳ����������Ϊ�ڱ���������ά�������ܴ��2�������͸�������3��
	stack<int> st;
	int third = INT_MIN;
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		if (nums[i] < third) {
			return true;
		}
		else while (!st.empty() && nums[i] > third){//ά�������ܴ��2
			third = st.top();
			st.pop();
		}
		st.push(nums[i]);
	}
	return false;
}

int calculate(string s) {
	//224�������������ݹ�ʵ��
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
		else if (c == '(') {//�����������򽫵�ǰres��sign����ѹ��ջ��Ȼ����������¸�ֵ�������������е�ֵ��������������ʱ���Ƚ�res����ջ��Ԫ�أ���sign��Ȼ���ջ���ٽ������ջ��Ԫ����ӣ�����ɶ�������ŵĴ���
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
	//��˫�˶��д洢Ԫ���±������Ԫ�ر���Ϊʲô��������
	//ÿ������Ԫ��ʱ�����ȣ��ж϶�ͷԪ���Ƿ���ڣ�������򵯳���ͷԪ�أ�
	//Ȼ��Ƚ϶�βԪ�غ���Ԫ�أ���С����Ԫ�أ���ɾ����βԪ�أ�ֱ����βԪ�ش��ڵ�����Ԫ��Ϊֹ--
	//����Ϊ��ЩԪ�ر�������Ԫ������ջ���ұ�������Ԫ��С��û�г�ͷ֮�գ��������Ϳ���ʼ�ձ���frontλ��Ϊ���ֵ��
	//Ȼ�󽫵�ǰԪ���±���ջ�����ڵ�K-1��ʱ��ʼȡ��ͷԪ���뷵�����顣

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
	for (int i = 1; i < n; i++)//����low,high��
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
	//242 valid anagram,�ù�ϣ��
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
	//454�����ⷨ����ʱ
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
						int p = 1;//��C,D�ж����ظ�Ԫ�أ���һֱ������ֱ����������ظ�Ԫ�أ���ʱ����C����p���ظ�Ԫ�أ�D����q��������p*q�ԣ�
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
	//�ڹ�ϣ���н�������֮�ͺ�����ִ���֮���ӳ�䣬���Ĵη��ĸ��ӶȽ�Ϊƽ����
	int res = 0;
	unordered_map<int, int> hash;
	int n = A.size();
	for (int n : A)
		for (int m : B)
			++hash[n + m];
	for (int n : C)
		for (int m : D) {
			int target = -(n + m);
			auto it = hash.find(target);//��C,D��ÿһ�Ժͣ����Ѿ������Ĺ�ϣ���в��������ֵĴ�������
			if (it != hash.end()) {
				res += it->second;
			}
		}
	return res;
}