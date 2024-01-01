#include <bits/stdc++.h>
using namespace std;
bool graphExists(vector<int> &a, int n)
{
	while (1)
	{
		sort(a.begin(), a.end(), greater<int>());
		if (a[0] == 0)
			return true;
		int v = a[0];
		if (v >= n)
			return false;
		a.erase(a.begin());
		for (int i = 0; i < v; i++)
		{
			a[i]--;
			if (a[i] < 0)
				return false;
		}
	}
}
int main()
{
	 int k,size;
     cin>>size;
     vector<int>a;
     for(int i = 0;i<size;i++){
     cin>>k;
     a.push_back(k);
     }
	graphExists(a, size) ? cout << "YES" : cout << "NO"  ;
	return 0;
}


