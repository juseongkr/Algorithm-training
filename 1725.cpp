#include <iostream>
#include <stack>
using namespace std;

int h[100001];

int main()
{
	stack<int> st;
	int num, width, result = 0;

	cin >> num;
	for (int i=0; i<num; ++i)
		cin >> h[i];
		
	for (int i=0; i<=num; ++i) {
		while (!st.empty() && h[i] < h[st.top()]) {
			int idx = st.top();
			st.pop();
			
			if (st.empty())
				width = i;
			else
				width = i - st.top() - 1;

			result = max(result, h[idx] * width);
		}
		st.push(i);
	}

	cout << result << '\n';

	return 0;
}
