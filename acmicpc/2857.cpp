#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	string s;
	bool flag;

	for (int k=1; k<=5; ++k) {
		flag = false;
		cin >> s;
		for (int i=0; i<s.length()-2; ++i)
			if (s[i] == 'F' && s[i+1] == 'B' && s[i+2] == 'I')
				flag = true;
		if (flag)
			v.push_back(k);
	}

	sort(v.begin(), v.end());

	if (v.size() == 0)
		cout << "HE GOT AWAY!\n";
	else
		for (int i=0; i<v.size(); ++i)
			cout << v[i] << " ";

	return 0;
}
