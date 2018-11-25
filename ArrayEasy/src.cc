#include "head.h"

vector<int> twoSum(vector<int> nums, int target)
{
	//��һ�⣬���±�
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
	//��һ��O��n�����Ӷ�
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
	//���ַ�����˳��ͳ���ַ������ַ�����
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

vector<int> removeDuplicates(vector<int>& nums)
{
	//26,�Ƴ��������ظ�Ԫ��
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
	//27,ɾ��������ָ��Ԫ�أ�������ʣ��Ԫ�صĸ�����
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
	//��28�⣬ʵ��strStr����λ�Ӵ��������±�
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
	//35��������λ�ã����û�оͷ��ز����λ��
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

int divide(vector<int>& nums, int l, int r) {
	//53����η�
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
	sum = mret;    //�����Ѿ����������ߵ���������
	for (int i = mid + 1; i <= r; i++) {
		sum += nums[i];
		//    if(sum < 0) sum = 0;
		mret = max(mret, sum);
	}

	return max(lret, max(rret, mret));
}

vector<int> getRow(int rowIndex) {
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
	//121�����ӣ�ֻ����һ��,��������������
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
	//122�����ӣ������
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
	//189,����kֵ�������鳤�ȵ����
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