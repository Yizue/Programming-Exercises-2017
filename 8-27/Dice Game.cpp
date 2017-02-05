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

	int a1, a2, b1, b2, c1, c2, d1, d2;
	scanf(" %d %d %d %d %d %d %d %d", &a1, &a2, &b1, &b2, &c1, &c2, &d1, &d2);

	int sum1 = a1+a2+b1+b2;
	int sum2 = c1+c2+d1+d2;

	if(sum1 > sum2)
    {
        printf("%s", "Gunnar");
    }
    else if (sum1 < sum2)
    {
        printf("%s", "Emma");
    }
    else
        printf("%s", "Tie");



	return 0;
}
