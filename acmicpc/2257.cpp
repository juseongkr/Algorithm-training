#include <iostream>
#include <stack>
using namespace std;
#define MAX 101

string s;
stack<int> st;

int main()
{
	cin >> s;
	st.push(0);
	int prev = 0;
	for (int i=0; i<s.length(); ++i) {
		if (s[i] == 'H') {
			prev = 1;
			st.top() += 1;
		} else if (s[i] == 'C') {
			prev = 12;
			st.top() += 12;
		} else if (s[i] == 'O') {
			prev = 16;
			st.top() += 16;
		} else if (s[i] == '(') {
			st.push(0);
		} else if (s[i] == ')') {
			prev = st.top();
			st.pop();
			st.top() += prev;
		} else {
			st.top() += (s[i]-'1') * prev;
		}
	}

	cout << st.top() << '\n';

	return 0;
}
