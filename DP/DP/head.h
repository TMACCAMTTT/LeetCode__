#pragma once

#include<iostream>
#include<iomanip>
#include<cmath>
#include <vector>
#include <algorithm>
using namespace std;
constexpr auto MAX_IN = 10;

class Tsp
{
private:
	int city_number;		//城市个数
	int **distance;			//城市距离矩阵
	int **process;			//求最短路径的过程矩阵
public:
	Tsp(int city_number);		//构造函数
	void correct();			//矫正输入的城市代价矩阵
	void printCity();		//打印城市的距离矩阵
	void getShoretstDistance();	//动态规划法求最短路径
	void printProcess();		//打印过程矩阵

};

//构造函数
/*(Tsp::Tsp(int city_num)
{
	int i = 0, j = 0;
	city_number = city_num;

	//初始化城市距离矩阵
	distance = new int*[city_number];
	cout << "请输入" << city_number << "个城市之间的距离" << endl;
	for (i = 0; i < city_number; i++)
	{
		distance[i] = new int[city_number];
		for (j = 0; j < city_number; j++)
			cin >> distance[i][j];
	}

	//生成过程矩阵
	process = new int*[city_number];
	for (i = 0; i < city_number; i++)
	{
		process[i] = new int[1 << (city_number - 1)];
	}


}

//纠正用户输入的城市代价矩阵
void Tsp::correct()
{
	int i;
	for (i = 0; i < city_number; i++)
	{
		distance[i][i] = 0;
	}
}

//打印城市距离
void Tsp::printCity()
{
	int i, j;
	//打印代价矩阵
	cout << "您输入的城市距离如下" << endl;
	for (i = 0; i < city_number; i++)
	{
		for (j = 0; j < city_number; j++)
			cout << setw(3) << distance[i][j];
		cout << endl;
	}
}

//动态规划法求最短路径
void Tsp::getShoretstDistance()
{
	int i, j, k;
	//初始化第一列
	for (i = 0; i < city_number; i++)
	{
		process[i][0] = distance[i][0];
	}
	//初始化剩余列
	for (j = 1; j < (1 << (city_number - 1)); j++)
	{
		for (i = 0; i < city_number; i++)
		{
			process[i][j] = 0x7ffff;//设0x7ffff为无穷大

			//对于数字x，要看它的第i位是不是1，通过判断布尔表达式 (((x >> (i - 1) ) & 1) == 1的真值来实现

			if (((j >> (i - 1)) & 1) == 1)
			{
				continue;
			}
			for (k = 1; k < city_number; k++)
			{
				//不能达到k城市
				if (((j >> (k - 1)) & 1) == 0)
				{
					continue;
				}
				if (process[i][j] > distance[i][k] + process[k][j ^ (1 << (k - 1))])
				{
					process[i][j] = distance[i][k] + process[k][j ^ (1 << (k - 1))];
					//cout<<i<<"行"<<j<<"列为："<<process[i][j]<<endl;
				}
			}
		}
	}
	cout << "最短路径为" << process[0][(1 << (city_number - 1)) - 1] << endl;

}

//打印过程矩阵
void Tsp::printProcess()
{
	int i, j;
	for (j = 0; j < 1 << (city_number - 1); j++)
	{
		cout << setw(3) << j;
	}
	cout << endl;
	for (i = 0; i < city_number; i++)
	{
		for (j = 0; j < 1 << (city_number - 1); j++)
		{
			if (process[i][j] == 0x7ffff)
				process[i][j] = -1;
			cout << setw(3) << process[i][j];
		}
		cout << endl;

	}
}*/


int minPathSum(vector<vector<int>>& grid);//64最小路径和
int numDecodings(string s);
int rob(vector<int>& nums);//213抢劫2
int nthUglyNumber(int n);//264丑数
int integerBreak(int n);//343分离整数
bool PredictTheWinner(vector<int>& nums);//486
bool stoneGame(vector<int>& piles);//877.石头游戏递归解法
int game(vector<int>& piles, int left, int right);//
bool stoneGameDp(vector<int>& piles);//877.石头游戏动态规划解法
int maxWidthRamp(vector<int>& A);//962最大宽度ramp
int maximalSquare(vector<vector<char>>& matrix);
int maxTurbulenceSize(vector<int>& A);