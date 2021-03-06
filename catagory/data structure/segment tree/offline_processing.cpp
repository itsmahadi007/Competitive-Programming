// LightOJ
// 1188 - Fast Queries
// Offline Processing + (Segment Tree/BIT)

// Take all Queries in memory, Sort them according to the right points
// loop through the sorted queries, for each query:
// 1. Scan from the 1'st point to the right point of this query (for second query, we'll start from this point to the next right point)
// 2. in each point :
//                      i. if new value is found, add 1 to this position in segment tree
//                      ii. if the value is found previous, then add -1 to the previous position, and add 1 to this position
// 3. now for each ranges in this query the ans will be the Range Sum Query of the segment tree

#include <bits/stdc++.h>
using namespace std;
#define MAX                 100010
#define EPS                 1e-9
#define INF                 1e9+10
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS)) 
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari)          cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;


struct FindUnique {
    int tree[4*MAX], prop[4*MAX], v[MAX], IDX[MAX];
    map<int, vector<int> >Map;
    map<pair<int, int>, int>Ans;
    vector<pair<int, int> > Query;
    
    void init() {
        memset(IDX, -1, sizeof IDX);
        memset(tree, 0, sizeof tree);
        Ans.clear(), Map.clear(), Query.clear();
    }
    void update(int pos, int L, int R, int idx, int val) {
        if(idx < L || R < idx) return;
        if(L == R) {
            tree[pos]+= val;
            return;
        }
        int mid = (L+R)>>1;
        update(pos<<1, L, mid, idx, val);
        update(pos<<1|1, mid+1, R, idx, val);
        tree[pos] = tree[pos<<1] + tree[pos<<1|1];
    }
    int query(int pos, int L, int R, int l, int r) {
        if(r < L || R < l)      return 0;
        if(l <= L && R <= r)    return tree[pos];
        int mid = (L+R)>>1;
        int lft = query(pos<<1, L, mid, l, r);
        int rht = query(pos<<1|1, mid+1, R, l, r);
        return lft+rht;
    }
    void ArrayInput(int SZ) {
        for(int i = 1; i <= SZ; ++i) scanf("%d", &v[i]);
    }
    void QueryInput(int q) {
        int l, r;
        while(q--) {
            scanf("%d %d", &l, &r);
            Query.push_back(make_pair(l, r));
            Map[r].push_back(l);                        // Used for sorting
    }}
    void GenAns(int SZ) {
        map<int, vi> :: iterator it;
        int lPos = 0;
        for(it = Map.begin(); it != Map.end(); ++it) {      // For each query's right points
            while(lPos < it->first) {                       // Update from last left position to this queries right position
                lPos++;
                if(IDX[v[lPos]] == -1) {
                    IDX[v[lPos]] = lPos;
                    update(1, 1, SZ, lPos, 1);              // if new value found, increment 1 to the
                }
                else {
                    int pastIDX = IDX[v[lPos]];
                    IDX[v[lPos]] = lPos;
                    update(1, 1, SZ, pastIDX, -1);           // if value found previous, then remove 1 from previous index (add -1)
                    update(1, 1, SZ, lPos, 1);               // add 1 to the new position
            }}
            for(int i = 0; i < (int)(it->second).size(); ++i)       // Range sum query for all queries that ends on this point
                Ans[make_pair(it->second[i], it->first)] = query(1, 1, SZ, it->second[i], it->first);       
    }}
    void PrintAns() {
        for(int i = 0; i < (int)Query.size(); ++i)                    // Output according to input query
            printf("%d\n", Ans[mp(Query[i].first, Query[i].second)]);
}};

FindUnique ST;

int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int t, n, q;
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d %d", &n, &q);
        pf("Case %d:\n", Case);
        
        ST.init();
        ST.ArrayInput(n);
        ST.QueryInput(q);
        ST.GenAns(n);
        ST.PrintAns();
    }
    
    return 0;
}
