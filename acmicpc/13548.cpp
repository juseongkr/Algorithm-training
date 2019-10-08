#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 100001

int sq;
struct Query {
	int s, e, n;
	Query() : Query(0, 0, -1) { }
	Query(int s1, int e1, int n1) : s(s1), e(e1), n(n1) { }
	bool operator<(const Query &q) const {
		if (s/sq != q.s/sq)
			return s < q.s;
		return e < q.e;
	}
};

int n, m, s, e;
Query query[MAX];
int num[MAX], result[MAX], cnt[MAX], cnt2[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	sq = sqrt(n);
	for (int i=0; i<n; ++i)
		cin >> num[i];

	cin >> m;
	for (int i=0; i<m; ++i) {
		cin >> s >> e;
		query[i] = Query(s-1, e, i);
	}
	sort(query, query+m);

	int max_count = 0;
	s = query[0].s;
	e = query[0].e;
	for (int i=s; i<e; ++i) {
		int t = ++cnt[num[i]];
		cnt2[t]++;
		if (t > max_count)
			max_count++;
	}
	result[query[0].n] = max_count;

	for (int i=1; i<m; ++i) {
		while (query[i].s < s) {
			int t = ++cnt[num[--s]];
			cnt2[t]++;
			if (t > max_count)
				max_count++;
		}

		while (e < query[i].e) {
			int t = ++cnt[num[e++]];
			cnt2[t]++;
			if (t > max_count)
				max_count++;
		}

		while (query[i].s > s) {
			int t = cnt[num[s++]]--;
			if (--cnt2[t] == 0)
				if (t == max_count)
					max_count--;
		}

		while (e > query[i].e) {
			int t = cnt[num[--e]]--;
			if (--cnt2[t] == 0)
				if (t == max_count)
					max_count--;
		}

		result[query[i].n] = max_count;
	}

	for (int i=0; i<m; ++i)
		cout << result[i] << '\n';

	return 0;
}
