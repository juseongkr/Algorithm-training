#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n, m, t;
	int array[100005], result[100005];
	set<int> s;

	cin >> n >> m;

	for (int i=1; i<=n; ++i)
		cin >> array[i];

	for (int i=n; i>=1; --i) {
		s.insert(array[i]);
		result[i] = s.size();
	}

	for (int i=0; i<m; ++i) {
		cin >> t;
		cout << result[t] << '\n';
	}

	return 0;
}
