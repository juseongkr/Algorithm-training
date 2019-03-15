#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	vector<int> input;
	vector<char> output;
	stack<int> st;
	int num, e, cnt = 0;

	cin >> num;
	for (int i=0; i<num; ++i) {
		cin >> e;
		input.push_back(e);
	}

	for (int i=1; i<=num; ++i) {
		st.push(i);
		output.push_back('+');
		
		while (!st.empty() && st.top() == input[cnt]) {
			cnt++;
			st.pop();
			output.push_back('-');
		}
	}

	if (!st.empty()) {
		cout << "NO\n";
	} else {
		for (int i=0; i<output.size(); ++i)
			cout << output[i] << '\n';
	}

	return 0;
}
