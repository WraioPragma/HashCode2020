#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<long,long>
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define forn(n) for(int i=0;i<n;i++)
#define forn(i,n) for(int i=0;i<n;i++)
#define forn(l,i,n) for(int i=l;i<n;i++)
#define nfor(n) for(int i=n-1;i>=0;i--)
#define nfor(i,n) for(int i=n-1;i>=0;i--)
#define nfor(l,i,n) for(int i=n-1;i>=l;i--)
#define all(vec) vec.begin(),vec.end()
#define rall(vec) vec.rbegin() vec.rend()

using namespace std;
void read_output();
void read_input();
void write_out();
void solve();
double costf();
ll cost();

int main()
{
    ios::sync_with_stdio(false);
    read_output();
    read_input();
    auto start = chrono::high_resolution_clock::now();
    auto fin = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::microseconds>(fin - start);
    while(dur<chrono::microseconds(3000000))
    {
//        cerr<<dur.count()<<' '<<(dur<chrono::microseconds(3000000))<<'\n';      
        solve();
        fin = chrono::high_resolution_clock::now();
        dur = chrono::duration_cast<chrono::microseconds>(fin - start);
//        cerr<<dur.count()<<' '<<(dur<chrono::microseconds(3000000))<<'\n';      
    }
cerr<<cost()<<' '<<costf()<<'\n';
write_out();
}

void read_output()
{
    
}

void read_input()
{
    
}

void write_out()
{
    cout<<1;
}

void solve()
{
    
}

double costf()
{
    return 0.0;
}

ll cost()
{
    return 0;
}

