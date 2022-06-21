#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef pair<int, int> pii;

///define constant
const ll mxn = 200005;
const int mod = 100000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........

int n,m;
string s, t;
ll dp[103][103];
ll vis[103][103];
int test_no;

int lcs(int i, int j)
{
    if(i == n or j == m) return 0;

    if(vis[i][j] == test_no)
    {
        return dp[i][j];
    }
    vis[i][i] = test_no;

    ll ans = 0;

    if(s[i] == t[j])
    {
        ans = 1 + lcs(i + 1, j + 1);
    }
    else
    {
        int val = lcs(i + 1, j);
        int val2 = lcs(i, j + 1);

        ans = max(val, val2);
    }

    return dp[i][j] = ans;

}


void solve_case(int tc)
{
    test_no = tc;
    cout<<"Case "<<tc<<": ";
    
    cin>>s>>t;

    n = s.size(); m = t.size();

    
    cout<<lcs(0, 0)<<endl;

    return;
}

int main()
{
    faster_io;

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int test_case=1;
    cin>>test_case;
    for(int tc=1 ; tc<=test_case; tc++)
    {
        solve_case(tc);
    }
///  KeyPoint


///  Corner Cases




    return 0;
}


