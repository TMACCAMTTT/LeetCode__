#include "head.h"

int main()
{
	vector<int> nums = { 1, 2, -3, 4, 5, -2, -1};
	vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	vector<int> height1 = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	vector<vector<int>> triangle = { {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3} };
	vector<int> vec = countBits(5);
	vector<int> prices = { 0, 8, 5, 7, 4, 7 };
	vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << maxProfitK(2, prices) << endl;
	//cout << maxArea(height) << endl;
	//cout << maxProduct(nums) << endl;
	return 0;
}