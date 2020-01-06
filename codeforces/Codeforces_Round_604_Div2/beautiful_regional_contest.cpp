#include <iostream>
#include <vector>
using namespace std;
#define MAX 400001

int p[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	vector<int> vec;
	int t, n, k;

	cin >> t;
	while (t--) {
		int g = 0, s = 0, b = 0;
		vec.clear();

		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> p[i];

		for (int i=0; i<n; ++i) {
			int k = 0, j;
			for (j=i; j<n; ++j) {
				if (p[i] == p[j]) {
					k++;
				} else {
					break;
				}
			}
			i = j-1;
			vec.push_back(k);
		}

		g = vec[0];
		for (int i=1; i<vec.size(); ++i) {
			if (g >= s)
				s += vec[i];
			else if (g + s + b + vec[i] <= n/2)
				b += vec[i];
			else
				break;
		}

		if (g < s && g < b)
			cout << g << " " << s << " " << b << '\n';
		else
			cout << "0 0 0\n";
	}

	return 0;
}
