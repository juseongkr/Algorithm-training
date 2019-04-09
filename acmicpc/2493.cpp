#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<pair<int, int>> st;
	int list[500001], n;
	
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", &list[i]);

	for (int i=0; i<n; ++i) {
		if (st.empty()) {
			st.push({list[i], i+1});
			printf("0 ");
		} else {
			while (!st.empty() && st.top().first < list[i])
				st.pop();

			if (st.empty())
				printf("0 ");
			else
				printf("%d ", st.top().second);

			st.push({list[i], i+1});
		}
	}
	return 0;
}
