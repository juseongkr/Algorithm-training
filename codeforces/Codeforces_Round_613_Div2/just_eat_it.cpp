#include <iostream>
using namespace std;
#define MAX 100001
 
int t, n;
long long num[MAX];
 
int main()
{
	cin >> t;
	while (t--) {
		cin >> n;
		long long total = 0, sum = 0, left = 0, right = 0;
		for (int i=0; i<n; ++i) {
			cin >> num[i];
			total += num[i];
		}

		for (int i=0; i<n-1; ++i) {
			if (sum < 0)
				sum = 0;
			sum += num[i];
			left = max(left, sum);
		}
		sum = 0;

		for (int i=1; i<n; ++i) {
			if (sum < 0)
				sum = 0;
			sum += num[i];
			right = max(right, sum);
		}
 
		if (total > max(left, right))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
 
	return 0;
}
