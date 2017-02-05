#include <bits/stdc++.h>
using namespace std;

#define MEM(arr,val)memset((arr),(val), sizeof (arr))
#define PI (acos(0)*2.0)
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll gcd(ll a,ll b){return b == 0 ? a : gcd(b,a%b);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}

/**
 * __builtin_popcount(int d) // count bits
 * strtol(s, &end, base); // convert base number
 */
//----------------------------------------------------------------------//

int main(){
	FASTER;

    int n, IorD=0;
    char prev[12], cur[12];
    scanf("%d %s", &n, cur);

    for(int i=1; i<n; i++)
    {
        strcpy(prev, cur);
        scanf(" %s", cur);
        int cmp = strcmp(cur, prev);
        //cout << "cmp: " << cmp << endl;
        //cout << "IorD: " << IorD << endl;
        if(i==1)
        {
            if(cmp > 0)
                IorD=1;
            else
                IorD=-1;
        }
        else
        {
            if( (cmp > 0 && IorD==-1) || (cmp < 0 && IorD==1) )
            {
                IorD=0;
                break;
            }
        }

    }
    if(IorD==1)
        printf("INCREASING");
    else if(IorD==-1)
        printf("DECREASING");
    else
        printf("NEITHER");

	return 0;
}
