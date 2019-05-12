#include <iostream>
#include <map>
using namespace std;

map<string, int> num = {{"000",0}, {"001",1}, {"010",2}, {"011",3},
			{"100",4}, {"101",5}, {"110",6}, {"111",7}};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string n;

	cin >> n;
	while (n.length() % 3 != 0)
		n = "0" + n;

	for (int i=0; i<n.length(); i+=3) {
		string t;
		for (int j=i; j<i+3; ++j)
			t += n[j];
		cout << num[t];
	}

	return 0;
}
