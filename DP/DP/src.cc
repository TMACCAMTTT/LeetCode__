#include "head.h"

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	//63
	if (obstacleGrid.empty()) return 0;
	int n = obstacleGrid.size();//n��m��
	int m = obstacleGrid[0].size();
	if (obstacleGrid[0][0] || obstacleGrid[n - 1][m - 1]) return 0;
	vector<vector<int>> dp(n, vector<int>(m, 0));
	for (int i = 0; i < m; i++) {
		if (!obstacleGrid[0][i]) {
			dp[0][i] = 1;
		}
		else {
			break;
		}
	}
	for (int i = 1; i < n; i++) {
		if (!obstacleGrid[i][0]) {
			dp[i][0] = 1;
		}
		else {
			break;
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (obstacleGrid[i][j]) {
				dp[i][j] = 0;
			}
			else if (!obstacleGrid[i - 1][j] && !obstacleGrid[i][j - 1]) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
			else if (obstacleGrid[i - 1][j] && obstacleGrid[i][j - 1]) {
				dp[i][j] = 0;
			}
			else if (obstacleGrid[i - 1][j]) {
				dp[i][j] = dp[i][j - 1];
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[n - 1][m - 1];
}

int minPathSum(vector<vector<int>>& grid) {
	//64
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

int numDecodings(string s) {
	//91���뷽����
	//���ַ���s��СΪn��dp[i]Ϊ�ߵ�s�ĵ�iλʱ����Ӧ�Ľ��뷽����Ŀ��i=0,1,...,n-1��
	//1. i < 0 => dp[i] = 0;
	//2. ��s[i]==0 : (1)s[i-1] == 0 || s[i-1] > 2 => dp[i]=0;
	//               (2)s[i-1] = 1 || s[i - 1] = 2 => dp[i] = dp[i - 2];
	//   ��s[i] != 0 : (1)s[i-1] == 0 || s[i-1] > 2 => dp[i] = dp[i - 1];
	//                 (2)s[i-1] = 1 || s[i - 1] = 2 => dp[i] = dp[i - 1] + 2dp[i - 2];���������λ���27,28,29ʱ�����
	int n = s.size();
	if (!n) return 0;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
	{
		v[i] = int(s[i] - '0');
	}
	vector<int> dp(n, 0);
	if (v[0]) dp[0] = 1;//�ַ�����һλ��Ϊ0����dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		if (!v[i]) {//s[i] = 0ʱ�������
			if (!v[i - 1] || v[i - 1] > 2) dp[i] = 0;
			else {
				if (i == 1) dp[i] = 1;
				else dp[i] = dp[i - 2];
			}
		}
		else {//s[i] != 0ʱ�������
			if (!v[i - 1] || v[i - 1] > 2) dp[i] = dp[i - 1];
			else {
				if (v[i - 1] == 2 && v[i] > 6) dp[i] = dp[i - 1];
				else {
					if (i == 1) dp[i] = 2;
					else dp[i] = dp[i - 1] + dp[i - 2];
				}
			}
		}
	}
	return dp[n - 1];
}

int rob(vector<int>& nums) {
	//213
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

int maximalSquare(vector<vector<char>>& matrix) {
	//�ö�άdp���飬��¼�Ծ�����ÿ����Ϊ�յ����������εı߳���ͬʱ��¼�������ֵ��
	//��k = dp[i - 1][j - 1], ����ǰ�����k���㣬�Ϸ�k�����Ϊ1����״̬ת�Ʒ���Ϊ��dp[i][j] = dp[i - 1][j - 1] + 1;
	//����ȡ��ߺ��Ϸ�����1�ĳ��ȵĽ�С�ߣ���Ϊ��ǰ���dp��ֵ��
	if (matrix.empty()) return 0;
	int length = matrix.size();
	int breadth = matrix[0].size();
	vector<vector<int>> dp(length, vector<int>(breadth, 0));
	int res = 0;
	//��ʼ��dp����ĵ�һ�к͵�һ�У�
	for (int i = 0; i < breadth; i++)
	{
		dp[0][i] = matrix[0][i] - '0';
		res = max(res, dp[0][i]);
	}
	for (int i = 1; i < length; i++)
	{
		dp[i][0] = matrix[i][0] - '0';
		res = max(res, dp[i][0]);
	}
	for (int i = 1; i < length; i++)
	{
		for (int j = 1; j < breadth; j++)
		{
			if (matrix[i][j] == '1') {
				int flagx = 1, flagy = 1;
				int x = 1, y = 1;
				int l = dp[i - 1][j - 1];
				for (int k = 1; k <= l; k++)
				{
					if (!(matrix[i - k][j] - '0')) {
						flagy = 0;
						break;
					}
					y++;
				}
				for (int k = 1; k <= l; k++)
				{
					if (!(matrix[i][j - k] - '0')) {
						flagx = 0;
						break;
					}
					x++;
				}
				if (flagx && flagy) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = min(x, y);
				res = max(res, dp[i][j]);
			}
		}
	}
	return res * res;
}
int nthUglyNumber(int n) {
	//264����
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
	//343״̬ת�Ʒ��̣�dp[n]=max(i * dp[n - i]);
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
			int t = max(i - j, dp[i - j]);//��ÿ����i - j��ȡ����������������Ľϴ�����Ϊ��ʱ��������ģ���Ϊ��ʱǰ����j��Ϊһ��������i-j����Ҫ�ֽ⡣
			temp = max(temp, j * t);
		}
		dp[i] = temp;
	}
	return dp[n];
}

bool PredictTheWinner(vector<int>& nums) {
	if (nums.empty()) return false;
	int n = nums.size();
	if (n == 1) return true;
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		dp[i][i] = nums[i];
	}
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
		}
	}
	if (dp[0][n - 1] >= 0) return true;
	return false;
}

bool stoneGame(vector<int>& piles) {
	int res = game(piles, 0, piles.size() - 1);
	if (res) return true;
	return false;
}

int game(vector<int>& piles, int left, int right)
{
	//877�ݹ��㷨������Alice��������ѡ�������£�Alice��Lee�÷ֵĲ�ֵ��
	if (piles.empty()) return 0;
	int left_diff;
	int right_diff;
	if (right - left == 1) return abs(piles[left] - piles[right]);
	else {
		left_diff = min(piles[left] - piles[left + 1] + game(piles, left + 2, right), piles[left] - piles[right] + game(piles, left + 1, right - 1));//Aliceѡ���ʱ��Lee��������ѡ��󣬵÷ֵĲ�ֵ��
		right_diff = min(piles[right] - piles[left] + game(piles, left + 1, right - 1), piles[right] - piles[right - 1] + game(piles, left, right - 2));//Aliceѡ�ұ�ʱ��Lee��������ѡ��󣬵÷ֵĲ�ֵ��
	}
	return max(left_diff, right_diff);//ֻҪ��������һ�������㣬Alice���Ȳ�ʤȯ��
}

bool stoneGameDp(vector<int>& piles) {
	if (piles.empty()) return true;
	if (piles.size() == 2) return true;
	int n = piles.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		dp[i][i] = piles[i];
	}
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
		}
	}
	if (dp[0][n - 1]) return true;
	return false;
}

int maxWidthRamp(vector<int>& A) {
	//962���Ƚ���������ֳ����ɶΣ�����Ϊ�ӵ�һ������ʼ��һֱ������ֱ������һ���ȵ�һ��С����Ϊֹ����Ϊ��һ�Σ��������β���±�������飬Ȼ��ʼѰ����һ�Σ�
	//�ֶ����֮�󣬶�ÿһ�������²�������¼��ʼ�Ķ��׶�β���Ӷ������������ֱ������һ�����ڶ�β����Ϊֹ���������б仯����������ǣ��Ӷ�β���ұ�����ֱ������һ��С�ڶ��׵���Ϊֹ��ͬ��Ҫ��ǣ�
	//�����׶�β���б仯�����µĶ��ж���С�ڵ��ڶ�β�����¶γ��Ȳ��������飻�����״��ڶ�β��ѡ��仯�ϴ��һ�����������飻
	//��ֻ�ж��׻��߶�β�б仯������Ӧ���¶εĳ��Ȳ��������飻����ԭ�γ��Ȳ��룻
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

int maxTurbulenceSize(vector<int>& A) {
	//978.�����������飺1<2>3<4>5;��һ�������н����������������󳤶ȣ�
	if (A.empty()) return 0;
	int size = A.size();
	int res = 0;
	vector<int> dp(size, 0);
	dp[0] = 1;
	if (size == 1) return 1;
	int preflag, curflag;
	if (A[0] == A[1]) {
		preflag = 0;
		dp[1] = 1;
	}
	else if (A[0] < A[1]) {
		preflag = -1;
		dp[1] = 2;
	}
	else {
		preflag = 1;
		dp[1] = 2;
	}
	if (size == 2) return 2 - (preflag == 0);
	for (int i = 2; i < size; i++)
	{
		if (A[i - 1] == A[i]) curflag = 0;
		else if (A[i - 1] < A[i]) curflag = -1;
		else curflag = 1;
		if (!curflag) dp[i] = 1;
		else {
			if (curflag + preflag == 0) {
				dp[i] = dp[i - 1] + 1;
				res = max(res, dp[i]);
			}
			else {
				dp[i] = 2;
				res = max(res, dp[i - 1]);
			}
		}
		preflag = curflag;
	}
	return res;
}
