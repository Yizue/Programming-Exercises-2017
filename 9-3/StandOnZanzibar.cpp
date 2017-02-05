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
    int n, pop, Z, notZ;
    scanf("%d", &n);
    while(n--)
    {
       scanf(" %d", &pop);
       Z=pop;
       notZ=0;

       while(scanf(" %d", &pop), pop != 0)
       {
            int possZ = (Z + notZ)*2 - notZ;
            if (pop > possZ)
            {
                Z = possZ;
                notZ = pop - Z;
            }
            else
            {
                Z += (pop - (Z+notZ));
            }
       }
       printf("%d\n", notZ);
    }

	return 0;
}
