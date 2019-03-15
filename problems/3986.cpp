#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{	
	string str;
	vector<string> vec;
	int num, cnt = 0;

	cin >> num;
	for (int i=0; i<num; ++i) {
		cin >> str;
		vec.push_back(str);
	}

	for (int i=0; i<num; ++i) {
		stack<char> st;
		for (int j=0; j<vec[i].length(); ++j) {
			if (!st.empty() && st.top() == vec[i][j])
				st.pop();
			else
				st.push(vec[i][j]);
		}

		if (st.empty())
			cnt++;
	}

	cout << cnt << '\n';

	return 0;
}
