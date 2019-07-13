#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 10

vector<int> num;
string s;
int n, k;
char c;

bool check()
{
	for (int i=0; i<s.length(); ++i) {
		if (s[i] == '<' && num[i] > num[i+1])
			return false;
		if (s[i] == '>' && num[i] < num[i+1])
			return false;
	}
	return true;
}

int main()
{
	cin >> k;
	for (int i=0; i<k; ++i) {
		cin >> c;
		s += c;
	}

	for (int i=0; i<=k; ++i)
		num.push_back(9-i);
	do {
		if (check())
			break;
	} while (prev_permutation(num.begin(), num.end()));

	for (int i=0; i<=k; ++i)
		cout << num[i];
	cout << '\n';

	num.clear();
	for (int i=0; i<=k; ++i)
		num.push_back(i);
	do {
		if (check())
			break;
	} while (next_permutation(num.begin(), num.end()));

	for (int i=0; i<=k; ++i)
		cout << num[i];
	cout << '\n';

	return 0;
}
