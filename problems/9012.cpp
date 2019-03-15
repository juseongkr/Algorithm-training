#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int num, flag;
	string str;
	cin >> num;

	for (int i=0; i<num; ++i) {
		cin >> str;
		flag = 0;
		stack<char> st;
		for (int j=0; j<str.size(); ++j) {
			if (str[j] == '(') {
				st.push('(');
			} else if (str[j] == ')' && st.empty()) {
				flag = 1;
				break;
			} else {
				st.pop();
			}
		}

		if (!st.empty() || flag)
			cout << "NO\n";
		else 
			cout << "YES\n";
	}
	
	return 0;
}
