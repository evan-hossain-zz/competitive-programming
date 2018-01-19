#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int test;
    cin >> test;
	while(test--){
		long long n, init, finl, amount;
		string x;
		cin >> init >> finl;
		cin >> n;
		while(n--)
		{
			cin >> x >> amount;
			if(x == "in")
				init += amount;
			else
				init -= amount;
			if(init < 0)
				break;
		}
		if(init != finl)
			cout << "no\n";
		else
			cout << "yes\n";
	}
	return 0;
}
