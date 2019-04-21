#include <iostream>
#include <stack>
using namespace std;

int main()
{
	string str;
	bool flag;

	while (1) {
		getline(cin, str);
		if (str == "." && str.length() == 1)
			break;
		stack<char> st;
		flag = true;

		for (int i=0; i<str.length(); ++i) {
			if (str[i] == '(') {
				st.push('(');
			} else if (str[i] == '[') {
				st.push('[');
			} else if (str[i] == ')') {
				if (!st.empty() && st.top() == '(') {
					st.pop();
				} else {
					flag = false;
					break;
				}
			} else if (str[i] == ']') {
				if (!st.empty() && st.top() == '[') {
					st.pop();
				} else {
					flag = false;
					break;
				}
			}
		}

		if (flag && st.empty())
			printf("yes\n");
		else
			printf("no\n");

	}
	
	return 0;
}
