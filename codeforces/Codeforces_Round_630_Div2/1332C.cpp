#include <iostream>
#include <vector>
using namespace std;
#define MAX 200001

int T, n, k;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> k >> s;
		int ans = 0;
		vector<bool> visit(n, 0);
		for (int i=0; i<n; ++i) {
			if (visit[i])
				continue;

			int len = 0;
			vector<int> freq(26, 0);
			for (int j=i; j<n; j+=k) {
				if (visit[j])
					continue;
				visit[j] = 1;
				freq[s[j]-'a']++;
				len++;
			}

			for (int j=n-1-i; j>=0; j-=k) {
				if (visit[j])
					continue;
				visit[j] = 1;
				freq[s[j]-'a']++;
				len++;
			}

			int mx = 0;
			for  (int i=0; i<26; ++i)
				mx = max(mx, freq[i]);

			ans += len - mx;
		}
		cout << ans << '\n';
	}

	return 0;
}
