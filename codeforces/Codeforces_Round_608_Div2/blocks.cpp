#include <iostream>
#include <vector>
using namespace std;

int n;
string s, p;
vector<int> vec;

void f(int k)
{
	p[k] = p[k] == 'W' ? 'B' : 'W';
	p[k+1] = p[k+1] == 'W' ? 'B' : 'W';
}

int main()
{
	cin >> n >> s;

	p = s;
	for (int i=0; i<n-1; ++i) {
		if (p[i] != 'W') {
			vec.push_back(i+1);
			f(i);
		}
	}

	if (p[n-1] != 'B') {
		cout << vec.size() << '\n';
		for (int i=0; i<vec.size(); ++i)
			cout << vec[i] << " ";
		return 0;
	}
	
	p = s;
	vec.clear();
	for (int i=0; i<n-1; ++i) {
		if (p[i] != 'B') {
			vec.push_back(i+1);
			f(i);
		}
	}

	if (p[n-1] != 'W') {
		cout << vec.size() << '\n';
		for (int i=0; i<vec.size(); ++i)
			cout << vec[i] << " ";
		return 0;
	}

	cout << "-1\n";
	
	return 0;
}
