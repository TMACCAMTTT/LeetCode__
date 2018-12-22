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
	//��ǰ����С��nʱ��������ѭ������ջ�ǿ��ҵ�ǰ�߶ȴ���ջ�������Ӧ�ĸ߶�ʱ������ܻ��γɿӣ�
	//��ʱ�ȳ�ջһ��Ԫ�أ���ջΪ�գ��޷��γɿӣ�����ѭ�������ǿգ���ȡ��ǰ�߶Ⱥ�ջ��Ԫ�ظ߶ȵĽ�Сֵ��ȥ֮ǰջ��Ԫ�صĸ߶���Ϊ�߶ȣ�
	//ȡ��ǰ�����ȥջ�������1��Ϊ��ȣ���˸ߵõ������ˮ�����������������������Ȼ�󽫵�ǰ����ѹ��ջ����ǰ����������
	//if�ж�����һ��Ҫ�����ţ�����st.push(curr);curr++;�ܺ�ʱ�䣡������st.push(curr++);
	stack<int> st;
	int n = height.size();
	int current = 0, ans = 0;
	while (current < n) {
		while (!st.empty() && height[current] > height[st.top()]) {//ջ�ǿ��ҵ�ǰ�߶ȴ���ջ���߶�
			int top = st.top();
			st.pop();
			if (st.empty()) {
				break;
			}
			int distance = current - st.top() - 1;
			int h = min(height[current], height[st.top()]) - height[top];
			ans += distance * h;
		}
		st.push(current++);//������ѹ��ջ
	}
	return ans;
}

bool find132pattern(vector<int>& nums)
{
	//��132�е�2��Ҫ��һ��������������һ��С������������һ��ջ �洢�������������ٱ���������һ��С����������������������������ʱ��
	//��ջ��Ԫ�ص�ֵ������������ջ��Ԫ�ػ�Ϊ����ϴ��Ԫ�ء���������ʼ�ձ���ջ��Ԫ�ض���������
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
	//224�������������ݹ�ʵ��
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
	//��˫�˶��д洢Ԫ���±ꣻÿ������Ԫ��ʱ��ɾ�������б���Ԫ��С��Ԫ��;ʼ�ձ���frontλ��Ϊ���ֵ��
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