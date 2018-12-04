#pragma once
#pragma once
#include <map>
#include <stack>
#include <unordered_map>
#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

int CountLetter(string a);
vector<int> twoSum(vector<int> nums, int target);//1
vector<int> twoSum_On(vector<int> nums, int target);//1
int maxArea(vector<int>& height);//11
vector<int> removeDuplicates(vector<int>& nums);//26
int removeElement(vector<int>& nums, int val);//27
int strStr(string str1, string str2);//28
int searchInsert(vector<int>& nums, int target);//35
int trap(vector<int>& height);//42
int trap_stack(vector<int>& height);//42
int trap_dp(vector<int>& height);//42
int trap_dp_2(vector<int>& height);//42
int divide(vector<int>& nums, int l, int r);//53
vector<int> getRow(int rowIndex);//119
int minimumTotal(vector<vector<int>>& triangle);//120
int maxProfit2(vector<int>& prices);//122
int maxProfit3(vector<int>& prices);//123
int maxProfit4(vector<int>& prices);//124
int maxProduct(vector<int>& nums);//152
int maxProfitK(int k, vector<int>& prices);//188
void rotate(vector<int>& nums, int k);//189
vector<int> countBits(int num);//338
