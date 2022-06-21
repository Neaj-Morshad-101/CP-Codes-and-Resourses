#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mxn 100005


ll fact[mxn];
//call calc() from main function 
//T.C: O(n)
void calc()
{
    fact[0] = fact[1] = 1;
    for(int i = 2; i < mxn; i++)
    {
        fact[i] = (fact[i-1] * i) % mod; 
    }
    return;
}

//T.C: O(log(n)) 
ll Bigmod(ll x,ll n)
{
    if(n==0) 
        return 1 % mod;
    ll res = Bigmod(x, n/2);
    res = (res * res) % mod;
    if(n & 1)
        res = (res * x) % mod;
    return res;
}
//T.C: O(log(n)) 
ll modInv(ll x) ///// IF mod is prime using Bigmod()
{
    return Bigmod(x,mod-2)%mod; 
}
//T.C: O(log(n)) 
ll nCr(ll n, ll r) /// *** using movInv() function
{
    return mul(fact[n], mul(modInv(fact[r]), modInv(fact[n - r])));
}

///mod Inverse of all fact[i] where i : 1 to N 
///with respect to mod (N < mod and mod is prime)
int inv[mxn];
//T.C: O(n)
//***Call modInvAll() form main function 
void modInvAll() 
{
    //inv[i] = modInv(fact[i]) will takes O(nlog(n)) time..
    int N = mxn;
    inv[N-1] = modInv(fact[N-1]);
    for(int i = N-2; i >= 0; i--) {
        inv[i] = 1ll*inv[i+1]*(i+1)%mod;
    }
}

//T.C: O(1)
ll nCr(ll n, ll r) /// *** using inv[] array... 
{
    ///inv[i] = modInv(fact[i]);
    return mul(fact[n],mul(inv[r], inv[n - r]));
}

ll add(ll a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}
ll sub(ll a,ll b)
{
    a-=b;
    if(a<0)a+=mod;
    return a;
}
ll mul(ll a, ll b) {
    return a * 1ll * b % mod;
}



//Template Ends

///Rough Codes



int add(int a,int b)
{
    a+=b;
    if(a>=mod)a-=mod;
    return a;
}
int sub(int a,int b)
{
    a-=b;
    if(a<0)a+=mod;
    return a;
}
int mul(int a,int b)
{
    ll res = a;
    res *= b;
    if(res >= mod) res %= mod;
    return res;
}

int bigmodIter(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

/// bigmod iterative
ll bigmod (ll a, ll p) { // a^p % mod
    ll res = 1 % mod, x = a % mod;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % mod;
        x = ( x * x ) % mod;
        p >>= 1;
    }
    return res;
}


///Using Extended Euclidian Algorithm
inline long long modInv (long long a, long long m) {
    long long x, y;
    ext_gcd(a, m, x, y);
    x %= m;
    if (x < 0) x += m;
    return x;
}

inline long long bigmod (long long a, long long p, long long m) {
    long long res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}


int main()
{
    ll x,n;
    cin>>x;
    cout<<Bigmod(x)<<endl;
    cout<<modInv(x)<<endl;
    return 0;
}

