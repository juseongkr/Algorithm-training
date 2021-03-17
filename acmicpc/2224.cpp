#include <iostream>
#include <vector>
using namespace std;
#define MAX 26 * 2

vector<string> ans;
int n, map[MAX][MAX];
char x, y;
string p;

int conv(char x) { return ('A' <= x && x <= 'Z') ? x-'A' : x-'a'+26; }
char rev(int x) { return (0 <= x && x <= 25) ? x+'A' : x-26+'a'; }

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> p >> y;
		int u = conv(x);
		int v = conv(y);
		map[u][v] = 1;
	}

	for (int k=0; k<MAX; ++k)
		for (int i=0; i<MAX; ++i)
			for (int j=0; j<MAX; ++j)
				if (map[i][k] && map[k][j])
					map[i][j] = 1;

	for (int i=0; i<MAX; ++i) {
		for (int j=0; j<MAX; ++j) {
			if (i != j && map[i][j]) {
				string s;
				s += rev(i);
				s += " => ";
				s += rev(j);
				ans.push_back(s);
			}
		}
	}

	cout << ans.size() << '\n';
	for (int i=0; i<ans.size(); ++i)
		cout << ans[i] << '\n';

	return 0;
}
