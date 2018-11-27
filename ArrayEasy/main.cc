#include "head.h"

int main()
{
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	vector<int> height1 = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	/*rotate(nums, 4);
	vector<int>::iterator it;
	for (it = nums.begin(); it != nums.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;*/
	//cout << maxArea(height) << endl;
	cout << trap_dp_2(height1) << endl;
	return 0;
}