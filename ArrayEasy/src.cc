#include "head.h"

vector<int> twoSum(vector<int> nums, int target)
{
	//第一题，求下标
	unordered_map<int, int> m;
	vector<int> res;
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		m[nums[i]] = i;
	}
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		int t = target - nums[i];
		if (m.count(t) && m[t] != i)
		{
			res.push_back(i);
			res.push_back(m[t]);
			break;
		}
	}
	return res;
}

vector<int> twoSum_On(vector<int> nums, int target)
{
	//第一题O（n）复杂度
	unordered_map<int, int> hash;
	vector<int> result;
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		int t = target - nums[i];
		if (hash.find(t) != hash.end())
		{
			result.push_back(hash[t]);
			result.push_back(i);
			return result;
		}
		hash[nums[i]] = i;
	}
	return result;
}

int CountLetter(string a)
{
	//按字符出现顺序统计字符串中字符个数
	int len = a.length();
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (a[i] >= 'a' && a[i] <= 'z')
			a[i] -= 32;
	}
	char c = a[0];
	for (int i = 0; i < len; i++)
	{
		if (a[i] == c)
			count++;
		else {
			printf("(%c, %d)", c, count);
			c = a[i];
			count = 1;
		}
	}
	printf("(%c, %d)", c, count);
	return 0;
}

int maxArea(vector<int>& height)
{
	//11, 最大面积
	int res = 0;
	int i = 0, j = height.size() - 1;
	while (i < j) {
		res = max(res, min(height[i], height[j]) * (j - i));
		if (height[i] < height[j]) {
			i++;
		}
		else {
			j--;
		}
	}
	return res;
}

vector<int> removeDuplicates(vector<int>& nums)
{
	//26,移除数组中重复元素
	if (nums.empty())
		return nums;
	int len = 1;
	int pre = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] != pre)
		{
			nums[len] = nums[i];
			len++;
			pre = nums[i];
		}
	}
	return nums;
}

int removeElement(vector<int>& nums, int val)
{
	//27,删除数组中指定元素，并返回剩余元素的个数。
	int len = nums.size();
	for (int i = 0; i < len; i++)
	{
		if (nums[i] == val)
		{
			nums.erase(nums.begin() + i);
			len--;
			i--;
		}
	}
	return len;
}

int strStr(string str1, string str2)
{
	//第28题，实现strStr，定位子串并返回下标
	int m = str1.length(), n = str2.length();
	for (int i = 0; i < m - n + 1; i++)
	{
		if (!n) {
			return 0;
		}
		int j = 0;
		for (; j < n; j++)
		{
			if (str1[i + j] != str2[j]) {
				break;
			}
		}
		if (j == n) {
			return i;
		}
	}
	return -1;
}

int searchInsert(vector<int>& nums, int target)
{
	//35返回数字位置，如果没有就返回插入的位置
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == target) {
			return i;
		}
		else if (nums[i] > target) {
			return i;
		}
	}
	return nums.size();
}

int trap(vector<int>& height) {
	//双指针法收集雨水， 从两边往中间走；对于左边的某个高度A， 当A右边比它矮时，结果增加；对于右边的某个高度B
	//，当B左边比它矮时，结果增加。
	int l = 0, r = height.size() - 1, res = 0;
	while (l < r) {
		int mn = min(height[l], height[r]);
		if (mn == height[l]) {
			++l;
			while (l < r && height[l] < mn) {
				res += mn - height[l++];
			}
		}
		else {
			--r;
			while (l < r && height[r] < mn) {
				res += mn - height[r--];
			}
		}
	}
	return res;
}

int trap_stack(vector<int>& height)
{
	//利用栈。如果栈为空，或者当前高度小于栈顶高度，则将当前坐标压入栈。如果当前高度大于栈顶高度，则可能有坑。pop一下，如果栈为空，则没坑；否则，宽度为
	//当前坐标-栈顶坐标-1， 高度为当前高度与栈顶高度之间的较小值减去刚刚出栈的高度。将水量计入结果。
	int ans = 0, current = 0;
	stack<int> st;
	while (current < height.size()) {
		while (!st.empty() && height[current] > height[st.top()]) {
			int top = st.top();
			st.pop();
			if (st.empty())
				break;
			int distance = current - st.top() - 1;
			int bounded_height = min(height[current], height[st.top()]) - height[top];
			ans += distance * bounded_height;
		}
		st.push(current++);
	}
	return ans;
}

int trap_dp(vector<int>& height)
{
	//动态规划1，两个数组存储每个坐标左边和右边的最大值。最后遍历每个坐标求和。
	if (height.empty())
		return 0;
	int ans = 0;
	int size = height.size();
	vector<int> left_max(size), right_max(size);
	left_max[0] = height[0];
	for (int i = 1; i < size; i++) {
		left_max[i] = max(height[i], left_max[i - 1]);
	}
	right_max[size - 1] = height[size - 1];
	for (int i = size - 2; i >= 0; i--) {
		right_max[i] = max(height[i], right_max[i + 1]);
	}
 	for (int i = 1; i < size - 1; i++) {
		ans += min(left_max[i], right_max[i]) - height[i];
	}
	return ans;
}

int trap_dp_2(vector<int>& height)
{
	//动态规划改进，不需要保存每个坐标右边最大值
	int ans = 0;
	if (height.empty()) {
		return 0;
	}
	int n = height.size();
	vector<int> left_max(n);
	left_max[0] = height[0];
	for (int i = 1; i < n; i++)
	{
		left_max[i] = max(left_max[i - 1], height[i]);
	}
	int right_max = height[n - 1];
	for (int i = n - 1; i >= 0; i--)
	{
		right_max = max(right_max, height[i]);
		ans += min(right_max, left_max[i]) - height[i];
	}
	return ans;
}

int divide(vector<int>& nums, int l, int r) {
	//53题分治法
	if (l == r)  return nums[l];
	if (l == r - 1) return max(nums[l], max(nums[r], nums[l] + nums[r]));

	int mid = (l + r) >> 1;
	int lret = divide(nums, l, mid - 1);
	int rret = divide(nums, mid + 1, r);

	int mret = nums[mid];
	int sum = mret;
	for (int i = mid - 1; i >= l; i--) {
		sum += nums[i];
		//    if(sum < 0) sum = 0;
		mret = max(mret, sum);
	}
	sum = mret;    //保存已经计算过的左边的最大子序和
	for (int i = mid + 1; i <= r; i++) {
		sum += nums[i];
		//    if(sum < 0) sum = 0;
		mret = max(mret, sum);
	}

	return max(lret, max(rret, mret));
}

vector<int> getRow(int rowIndex) 
{
	vector<vector<int>> res(rowIndex + 1, vector<int>());
	for (int i = 0; i < rowIndex + 1; i++)
	{
		res[i].resize(i + 1, 1);
		for (int j = 1; j < i; j++)
		{
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
	}
	return res[rowIndex];
}

int maxProfit1(vector<int>& prices)
{
	//121卖袜子，只能卖一次,待定！！！！！
	int buy = prices[0], res = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		buy = min(buy, prices[i]);
		res = min(res, prices[i] - buy);
	}
	return 0;
}

int maxProfit2(vector<int>& prices)
{
	//122卖袜子，卖多次
	int res = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] > prices[i - 1]) {
			res += prices[i] - prices[i - 1];
		}
	}
	return res;
}

void rotate(vector<int>& nums, int k)
{
	//189,考虑k值大于数组长度的情况
	if (k >= nums.size()) {
		k %= nums.size();
	}
	if (k == 0) return;
	vector<int> vec = nums;
	for (int i = nums.size() - 1; i >= k; i--)
	{
		nums[i] = vec[i - k];
	}
	for (int i = 0; i < k; i++)
	{
		nums[i] = vec[i + nums.size() - k];
	}
	return;
}