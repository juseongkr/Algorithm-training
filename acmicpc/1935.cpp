#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;

int num[26];

int main()
{
	stack<double> st;
	string s;
	int n;
	
	cin >> n >> s;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	for (int i=0; i<s.length(); ++i) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();

			if (s[i] == '+')
				st.push(b + a);
			else if (s[i] == '-')
				st.push(b - a);
			else if (s[i] == '*')
				st.push(b * a);
			else if (s[i] == '/')
				st.push(b / a);
		} else {
			st.push(num[s[i]-'A']);
		}
	}

	cout << fixed << setprecision(2) << st.top() << '\n';

	return 0;
}
