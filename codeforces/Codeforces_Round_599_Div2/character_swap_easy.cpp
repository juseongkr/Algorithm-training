#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string a, b;
	int t, n;

	cin >> t;
	while (t--) {
		vector<int> vec;
		cin >> n >> a >> b;
		if (a == b) {
			cout << "Yes\n";
			continue;
		}

		for (int i=0; i<n; ++i)
			if (a[i] != b[i])
				vec.push_back(i);

		if (vec.size() != 2) {
			cout << "No\n";
		} else {
			if (a[vec[0]] == a[vec[1]] && b[vec[0]] == b[vec[1]])
				cout << "Yes\n";
			else
				cout  << "No\n";
		}
	}

	return 0;
}
