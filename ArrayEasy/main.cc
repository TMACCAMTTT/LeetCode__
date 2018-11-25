#include "head.h"

int main()
{
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
	rotate(nums, 4);
	vector<int>::iterator it;
	for (it = nums.begin(); it != nums.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}