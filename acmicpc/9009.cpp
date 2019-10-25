#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000000001

int main()
{
	int n, t;
	vector<int> fibo;
	fibo.push_back(1);
	fibo.push_back(1);

	for (int i=2; ; ++i) {
		int f = fibo[i-1] + fibo[i-2];
		if (f > MAX)
			break;
		fibo.push_back(f);
	}
	reverse(fibo.begin(), fibo.end());

	cin >> t;
	while (t--) {
		vector<int> ans;
		cin >> n;
		for (int i=0; i<fibo.size(); ++i) {
			if (n >= fibo[i]) {
				n -= fibo[i];
				ans.push_back(fibo[i]);
			}
		}
		for (int i=ans.size()-1; i>=0; i--)
			cout << ans[i] << " ";
		cout << '\n';
	}

	return 0;
}
