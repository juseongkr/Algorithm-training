#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> vec;
int n;

int main()
{
	cin >> n;
	for (int i=1; i<(1 << 10); ++i) {
		long long num = 0;
		for (int j=0; j<10; ++j) {
			if ((1 << j) & i)
				num = num * 10 + (9 - j);
		}
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());
	if (n <= vec.size())
		cout << vec[n-1] << '\n';
	else
		cout << "-1\n";

	return 0;
}
