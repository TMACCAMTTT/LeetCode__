#include "head.h"

bool isValid(string s) {
	//20
	stack<char> parentheses;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			parentheses.push(s[i]);
		}
		else {
			if (parentheses.empty()) return false;
			if (s[i] == ')' && parentheses.top() != '(') return false;
			if (s[i] == ']' && parentheses.top() != '[') return false;
			if (s[i] == '}' && parentheses.top() != '{') return false;
			parentheses.pop();
		}
	}
	return parentheses.empty();
}

int trap(vector<int>& height) {
	//当前坐标小于n时，做如下循环：当栈非空且当前高度大于栈顶坐标对应的高度时，则可能会形成坑；
	//此时先出栈一个元素，若栈为空，无法形成坑，跳出循环；若非空，则取当前高度和栈顶元素高度的较小值减去之前栈顶元素的高度作为高度，
	//取当前坐标减去栈顶坐标减1作为宽度，宽乘高得到这块雨水的面积，将这块面积加入结果；然后将当前坐标压入栈，当前坐标自增；
	//if判断体外一定要加括号！！！st.push(curr);curr++;很耗时间！！！用st.push(curr++);
	stack<int> st;
	int n = height.size();
	int current = 0, ans = 0;
	while (current < n) {
		while (!st.empty() && height[current] > height[st.top()]) {//栈非空且当前高度大于栈顶高度
			int top = st.top();
			st.pop();
			if (st.empty()) {
				break;
			}
			int distance = current - st.top() - 1;
			int h = min(height[current], height[st.top()]) - height[top];
			ans += distance * h;
		}
		st.push(current++);//将坐标压入栈
	}
	return ans;
}

bool find132pattern(vector<int>& nums)
{
	//对132中的2，要找一个大于它的数和一个小于它的数；用一个栈 存储大于它的数，再遍历数组找一个小于它的数；当遍历到大于它的数时，
	//将栈顶元素的值赋给它，并将栈顶元素换为这个较大的元素。这样就能始终保持栈中元素都大于它。
	stack<int> st;
	int third = INT_MIN;
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		if (nums[i] < third) {
			return true;
		}
		else while (!st.empty() && nums[i] > third){
			third = st.top();
			st.pop();
		}
		st.push(nums[i]);
	}
	return false;
}

int calculate(string s) {
	//224基本计算器，递归实现
	int res = 0;
	int sign = 1;
	stack<int> st;
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if (c >= '0') {
			int num = 0;
			while (i < s.size() && s[i] >= '0') {
				num = num * 10 + s[i++] - '0';
			}
			res += num * sign;
			i--;
		}
		else if (c == '+') {
			sign = 1;
		}
		else if (c == '-') {
			sign = -1;
		}
		else if (c == '(') {
			st.push(res);
			st.push(sign);
			res = 0;
			sign = 1;
		}
		else if (c == ')') {
			res *= st.top();
			st.pop();
			res += st.top();
			st.pop();
		}
	}
	return res;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	//用双端队列存储元素下标；每次来新元素时，删除队列中比新元素小的元素;始终保持front位置为最大值；
	vector<int> res;
	if (nums.empty() || k == 0) {
		return {};
	}
	deque<int> dq;
	for (int i = 0; i < nums.size(); i++)
	{
		if (dq.front() == i - k) {
			dq.pop_front();
		}
		while (!dq.empty() && nums[dq.back()] < nums[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
		if (i >= k - 1) {
			res.push_back(nums[dq.front()]);
		}
	}
	return res;
}