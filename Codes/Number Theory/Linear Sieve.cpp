#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000000

vector <int> prime;
bool is_composite[MAXN];
int composite_cnt=0;
void linear_sieve (int n) {
	fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			composite_cnt++;
			if (i % prime[j] == 0) break;
		}
	}
}

int main()
{
    int n;
    cin>>n;
    linear_sieve(n);
    int prime_cnt=0;
    for(auto it=prime.begin();it!=prime.end();it++)
    {
        cout<<*it<<" ";
        prime_cnt++;
    }
    cout<<endl<<"Num of Prime : "<<prime_cnt<<endl;
    cout<<"Composite Checked : "<<composite_cnt<<endl;
    return 0;
}
