//UVa
//11689 - Soda Surpler
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b)
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sf scanf
#define pf printf
#define wh while
#define inf std::numeric_limits<int>::max()

using namespace std;

int main()
{
    register int t, x, y, z, cnt, tmp;
    sf("%d", &t);
    wh(t--)
    {
        sf("%d %d %d", &x, &y, &z);
        x += y;
        cnt = 0;
        while(!(x < z))
        {
            tmp = x/z;
            x -= tmp*z;
            x += tmp;
            cnt+= tmp;
        }
        pf("%d\n", cnt);
    }
    return 0;
}
