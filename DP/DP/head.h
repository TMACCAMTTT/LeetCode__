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
	int city_number;		//���и���
	int **distance;			//���о������
	int **process;			//�����·���Ĺ��̾���
public:
	Tsp(int city_number);		//���캯��
	void correct();			//��������ĳ��д��۾���
	void printCity();		//��ӡ���еľ������
	void getShoretstDistance();	//��̬�滮�������·��
	void printProcess();		//��ӡ���̾���

};

//���캯��
/*(Tsp::Tsp(int city_num)
{
	int i = 0, j = 0;
	city_number = city_num;

	//��ʼ�����о������
	distance = new int*[city_number];
	cout << "������" << city_number << "������֮��ľ���" << endl;
	for (i = 0; i < city_number; i++)
	{
		distance[i] = new int[city_number];
		for (j = 0; j < city_number; j++)
			cin >> distance[i][j];
	}

	//���ɹ��̾���
	process = new int*[city_number];
	for (i = 0; i < city_number; i++)
	{
		process[i] = new int[1 << (city_number - 1)];
	}


}

//�����û�����ĳ��д��۾���
void Tsp::correct()
{
	int i;
	for (i = 0; i < city_number; i++)
	{
		distance[i][i] = 0;
	}
}

//��ӡ���о���
void Tsp::printCity()
{
	int i, j;
	//��ӡ���۾���
	cout << "������ĳ��о�������" << endl;
	for (i = 0; i < city_number; i++)
	{
		for (j = 0; j < city_number; j++)
			cout << setw(3) << distance[i][j];
		cout << endl;
	}
}

//��̬�滮�������·��
void Tsp::getShoretstDistance()
{
	int i, j, k;
	//��ʼ����һ��
	for (i = 0; i < city_number; i++)
	{
		process[i][0] = distance[i][0];
	}
	//��ʼ��ʣ����
	for (j = 1; j < (1 << (city_number - 1)); j++)
	{
		for (i = 0; i < city_number; i++)
		{
			process[i][j] = 0x7ffff;//��0x7ffffΪ�����

			//��������x��Ҫ�����ĵ�iλ�ǲ���1��ͨ���жϲ������ʽ (((x >> (i - 1) ) & 1) == 1����ֵ��ʵ��

			if (((j >> (i - 1)) & 1) == 1)
			{
				continue;
			}
			for (k = 1; k < city_number; k++)
			{
				//���ܴﵽk����
				if (((j >> (k - 1)) & 1) == 0)
				{
					continue;
				}
				if (process[i][j] > distance[i][k] + process[k][j ^ (1 << (k - 1))])
				{
					process[i][j] = distance[i][k] + process[k][j ^ (1 << (k - 1))];
					//cout<<i<<"��"<<j<<"��Ϊ��"<<process[i][j]<<endl;
				}
			}
		}
	}
	cout << "���·��Ϊ" << process[0][(1 << (city_number - 1)) - 1] << endl;

}

//��ӡ���̾���
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


int minPathSum(vector<vector<int>>& grid);//64��С·����
int numDecodings(string s);
int rob(vector<int>& nums);//213����2
int nthUglyNumber(int n);//264����
int integerBreak(int n);//343��������
bool PredictTheWinner(vector<int>& nums);//486
bool stoneGame(vector<int>& piles);//877.ʯͷ��Ϸ�ݹ�ⷨ
int game(vector<int>& piles, int left, int right);//
bool stoneGameDp(vector<int>& piles);//877.ʯͷ��Ϸ��̬�滮�ⷨ
int maxWidthRamp(vector<int>& A);//962�����ramp
int maximalSquare(vector<vector<char>>& matrix);
int maxTurbulenceSize(vector<int>& A);