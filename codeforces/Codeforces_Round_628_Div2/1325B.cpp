#include <iostream>
#include <set>
using namespace std;

int T, n, num;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		set<int> st;
		for (int i=0; i<n; ++i) {
			cin >> num;
			st.insert(num);
		}
		cout << st.size() << '\n';
	}

	return 0;
}
