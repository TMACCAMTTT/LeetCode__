#include "head.h"


int main()
{
	/*cout << "欢迎来到动态规划求旅行商问题，请输入城市个数";
	int city_number;
	while (cin >> city_number)
	{
		Tsp tsp(city_number);		//初始化城市代价矩阵
		tsp.correct();					//纠正用户输入的代价矩阵
		tsp.printCity();				//打印城市
		tsp.getShoretstDistance();		//求出最短路径
		tsp.printProcess();			//打印计算矩阵
		cout << "---------------------------------------" << endl;
		cout << "欢迎来到动态规划求旅行商问题，请输入城市个数";
	}*/
	vector<vector<int>> grid = { {1, 2, 5}, {3, 2, 1} };
	//cout << minPathSum(grid) << endl;
	//vector<int> nums = {7,7,12,16,41,48,41,48,11,9,34,2,44,30,27,12,11,39,31,8,23,11,47,25,15,23,4,17,11,50,16,50,38,34,48,27,16,24,22,48,50,10,26,27,9,43,13,42,46,24};
	//cout << rob(nums) << endl;
	//cout << maxWidthRamp(nums) << endl;
	//cout << integerBreak(5) << endl;
	//vector<int> nums = { 1, 5, 2 };
	//cout << stoneGameDp(nums) << endl;
	string s = "12";
	//vector<int> nums(5, 0);
	//for (int i = 0; i < 5; i++)
	//{
	//	nums[i] = int(s[i] - '0');
	//}
	int res = numDecodings(s);
	vector<vector<char>> matrix = { {'0', '0', '0', '1'}, {'1', '1', '0', '1'}, {'1', '1', '1', '1'}, {'0', '1', '1', '1'}, {'0', '1', '1', '1'} };
	//cout << maximalSquare(matrix) << endl;
	vector<int> nums = { 1 };
	cout << maxTurbulenceSize(nums) << endl;
	return 0;
}


