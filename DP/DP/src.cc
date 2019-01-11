#include "head.h"

int minPathSum(vector<vector<int>>& grid) {
	if (grid.empty()) return 0;
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> dp(m, vector<int>(n, 0));
	dp[0][0] = 1;
	for (int i = 1; i < n; i++)
	{
		dp[0][i] = dp[0][i - 1] + grid[0][i];
	}
	for (int i = 1; i < m; i++)
	{
		dp[i][0] = dp[i - 1][0] + grid[i][0];
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
		}
	}
	return dp[m - 1][n - 1];
}

int rob(vector<int>& nums) {
	if (nums.empty()) return 0;
	if (nums.size() == 1) return nums[0];
	if (nums.size() == 2) return max(nums[0], nums[1]);
	int n = nums.size();
	vector<int> dp(n, 0);
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);
	for (int i = 2; i < n - 1; i++)
	{
		dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
	}
	int res = dp[n - 2];
	dp[1] = nums[1];
	dp[2] = max(nums[1], nums[2]);
	for (int i = 3; i < n; i++)
	{
		dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
	}
	return max(res, dp[n - 1]);
}

int nthUglyNumber(int n) {
	//264丑数
	vector<int> res(1, 1);
	int i = 0, j = 0, k = 0;
	while (res.size() < n) {
		int curr = min(res[i] * 2, min(res[j] * 3, res[k] * 5));
		res.push_back(curr);
		if (curr == res[i] * 2) i++;
		if (curr == res[j] * 3) j++;
		if (curr == res[k] * 5) k++;
	}
	return res[n - 1];
}

int integerBreak(int n) {
	//343状态转移方程：dp[n]=max(i * dp[n - i]);
	if (!n) return 0;
	if (n == 1) return 0;
	if (n == 2) return 1;
	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i < n + 1; i++)
	{
		int temp = 0;
		for (int j = 1; j < i; j++)
		{
			int t = max(i - j, dp[i - j]);//对每个数i - j，取它自身和它的最大积的较大者作为此时参与运算的，因为此时前面有j作为一个乘数，i-j不需要分解。
			temp = max(temp, j * t);
		}
		dp[i] = temp;
	}
	return dp[n];
}

int maxWidthRamp(vector<int>& A) {
	//962
	int n = A.size();
	if (!n) return 0;
	int left = 0, right = 0;
	vector<pair<int, int>> vec;
	for (int i = 1; i < n; i++)
	{
		if (A[i] >= A[left]) {
			right = i;
		}
		else {
			pair<int, int> p;
			p = make_pair(left, right);
			vec.push_back(p);
			left = i;
			right = i;
		}
	}
	vec.push_back(make_pair(left, right));
	int size = vec.size();
	vector<int> res;
	for (int i = 0; i < size; i++)
	{
		bool l = 0, r = 0;
		int min, MAX;
		int left = vec[i].first;
		while (vec[i].first > 0) {
			vec[i].first--;
			if (A[vec[i].second] >= A[vec[i].first]) {
				min = vec[i].first;
				l = 1;
			}
		}
		int right = vec[i].second;
		while (vec[i].second < n - 1) {
			vec[i].second++;
			if (A[left] <= A[vec[i].second]) {
				MAX = vec[i].second;
				r = 1;
			}
		}
		if (l && r) {
			if (A[min] <= A[MAX]) res.push_back(MAX - min);
			else res.push_back(max(vec[i].second - min, MAX - vec[i].first));
		}
		else if (l) {
			res.push_back(vec[i].second - min);
		}
		else if (r) {
			res.push_back(MAX - vec[i].first);
		}
		else {
			res.push_back(vec[i].second - vec[i].first);
		}
	}
	sort(res.begin(), res.end());
	return res[res.size() - 1];
}