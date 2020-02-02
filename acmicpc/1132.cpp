#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 51

vector<int> num;
string s[MAX];
bool visit[26];
long long sum[10];
int n;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s[i];
		visit[s[i][0]-'A'] = 1;

		long long k = 1;
		for (int j=s[i].length()-1; j>=0; j--) {
			int c = s[i][j]-'A';
			sum[c] += k;
			k *= 10;
		}
	}

	for (int i=0; i<10; ++i)
		num.push_back(i);

	long long ans = 0;
	do {
		if (!visit[num[0]]) {
			long long t = 0;
			for (int i=1; i<=9; ++i)
				t += sum[num[i]] * i;
			ans = max(ans, t);
		}
	} while (next_permutation(num.begin(), num.end()));

	cout << ans << '\n';

	return 0;
}
