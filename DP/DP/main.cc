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
	//vector<vector<int>> grid = { {1, 2, 5}, {3, 2, 1} };
	//cout << minPathSum(grid) << endl;
	vector<int> nums = {3,28,15,1,4,12,6,19,8,15,3,9,6,4,13,12,6,12,10,1,2,1,4,1,4,0,0,1,1,0};
	//cout << rob(nums) << endl;
	//cout << maxWidthRamp(nums) << endl;
	cout << integerBreak(5) << endl;
	return 0;
}

