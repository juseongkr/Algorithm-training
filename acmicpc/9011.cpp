#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int t, n, x;

	cin >> t;
	while (t--) {
		cin >> n;
		stack<int> st;
		vector<int> num, input;
		for (int i=1; i<=n; ++i)
			num.push_back(i);

		for (int i=0; i<n; ++i) {
			cin >> x;
			input.push_back(x);
		}

		bool flag = true;
		for (int i=n-1; i>=0; i--) {
			if (input[i] >= num.size()) {
				flag = false;
				cout << "IMPOSSIBLE\n";
				break;
			}
			st.push(num[input[i]]);
			num.erase(num.begin() + input[i]);
		}
		if (flag) {
			while (!st.empty()) {
				cout << st.top() << " ";
				st.pop();
			}
			cout << '\n';
		}
	}

	return 0;
}
