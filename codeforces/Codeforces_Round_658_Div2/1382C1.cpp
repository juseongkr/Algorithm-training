#include <iostream>
#include <vector>
using namespace std;

int T, n;
string a, b;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> a >> b;
		vector<int> vec;
		for (int i=n-1; i>=0; i--) {
			if (a[i] != b[i]) {
				vec.push_back(i+1);
				vec.push_back(1);
				vec.push_back(i+1);
			}
		}

		cout << vec.size() << ' ';
		for (int i=0; i<vec.size(); ++i)
			cout << vec[i] << ' ';
		cout << '\n';
	}

	return 0;
}
