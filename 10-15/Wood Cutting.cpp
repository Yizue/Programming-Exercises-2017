#include <bits/stdc++.h>
using namespace std;

#define MEM(arr,val)memset((arr),(val), sizeof (arr))
#define PI (acos(0)*2.0)
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

ll gcd(ll a,ll b){return b == 0 ? a : gcd(b,a%b);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
//----------------------------------------------------------------------//

int main()
{
    FASTER;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        vll sum;

        for(int i=0; i<n; i++)
        {
            int m, val;
            sum.push_back(0);

            scanf("%d", &m);
            for(int j=0; j<m; j++)
            {
                scanf("%d", &val);
                sum[i] += val;
            }
        }
        //sort the sums
        sort(sum.begin(),sum.end());
        vll pSum;
        pSum.push_back(sum[0]);
        for(int x=1; x<n; x++)
        {
            pSum.push_back(pSum[x-1]+sum[x]);
        }
        ll accS = 0;
        for(int y=0; y<pSum.size(); y++)
        {
            accS += pSum[y];
        }
        printf("%.10f\n", accS/(n*1.0));
    }
    return 0;
}
