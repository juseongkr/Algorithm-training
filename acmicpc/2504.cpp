#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> st;
	string s;
	int flag = 0, result = 0;

	cin >> s;
	if (s.size() == 1) {
		printf("0\n");
		return 0;
	}

	for (int i=0; i<s.length(); ++i) {
		if (s[i] == '(') {
			if (s[i+1] == ')') {
				st.push(2);
				i++;
			} else {
				st.push(-2);
			}
		} else if (s[i] == '[') {
			if (s[i+1] == ']') {
				st.push(3);
				i++;
			} else {
				st.push(-3);
			}
		} else if (s[i] == ')') {
			int sum = 0;
			while (!st.empty() && st.top() != -2) {
				sum += st.top();
				st.pop();
			}
			if (st.empty()) {
				flag = 1;
				break;
			}
			st.pop();
			st.push(2 * sum);
		} else if (s[i] == ']') {
			int sum = 0;
			while (!st.empty() && st.top() != -3) {
				sum += st.top();
				st.pop();
			}
			if (st.empty()) {
				flag = 1;
				break;
			}
			st.pop();
			st.push(3 * sum);
		}
	}

	while (!st.empty()) {
		if (st.top() < 0) {
			flag = 1;
			break;
		}
		result += st.top();
		st.pop();
	}

	if (flag)
		printf("0\n");
	else
		printf("%d\n", result);

	return 0;
}
