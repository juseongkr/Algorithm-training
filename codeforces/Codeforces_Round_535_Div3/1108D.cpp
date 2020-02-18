#include <iostream>
#include <cstring>
using namespace std;
#define MAX 200001
const int INF = 1e9+7;

string s;
int n, ans;
char color[3] = {'R', 'G', 'B'};

int main()
{
	cin >> n >> s;
	for (int i=1; i<n; ++i) {
		if (s[i-1] == s[i]) {
			ans++;
			for (int j=0; j<3; ++j) {
				if (s[i-1] != color[j] && s[i+1] != color[j]) {
					s[i] = color[j];
					break;
				}
			}
		}
	}
	cout << ans << '\n' << s << '\n';

	return 0;
}
