#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	vector<int> pos, neg;
	deque<int> pq, nq;
	int n, t;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		if (t > 0)
			pos.push_back(t);
		else
			neg.push_back(t);
	}

	sort(pos.begin(), pos.end(), greater<int>());
	sort(neg.begin(), neg.end());

	for (int i=0; i<pos.size(); ++i) {
		if (i % 2 == 0)
			pq.push_front(pos[i]);
		else
			pq.push_back(pos[i]);
	}

	for (int i=0; i<neg.size(); ++i) {
		if (i % 2 == 0)
			nq.push_front(neg[i]);
		else
			nq.push_back(neg[i]);
	}

	if (pq.size() != 0 && pq[0] > pq[pq.size()-1])
		reverse(pq.begin(), pq.end());

	if (nq.size() != 0 && nq[0] > nq[nq.size()-1])
		reverse(nq.begin(), nq.end());

	while (!nq.empty()) {
		cout << nq.front() << ' ';
		nq.pop_front();
	}

	while (!pq.empty()) {
		cout << pq.front() << ' ';
		pq.pop_front();
	}

	return 0;
}
