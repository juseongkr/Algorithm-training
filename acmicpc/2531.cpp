#include <iostream>
#include <vector>
using namespace std;

int dict[3001];
vector<int> sushi;
int n, d, k, c, t, ans, cnt;

void add(int n)
{
	if (!dict[n])
		cnt++;
	dict[n]++;
}

void del(int n)
{
	dict[n]--;
	if (!dict[n])
		cnt--;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> d >> k >> c;
	for (int i=0; i<n; ++i) {
		cin >> t;
		sushi.push_back(t);
	}
	for (int i=0; i<k-1; ++i)
		sushi.push_back(sushi[i]);

	add(c);
	for (int i=0; i<k-1; ++i)
		add(sushi[i]);

	for (int i=0; i<n; ++i) {
		add(sushi[i+k-1]);
		ans = max(ans, cnt);
		del(sushi[i]);
	}
	cout << ans << '\n';

	return 0;
}
