#include <bits/stdc++.h>
using namespace std;

const int MAX_INT = std::numeric_limits<int>::max();
const int MIN_INT = std::numeric_limits<int>::min();
const int INF = 1.0e9;
const int NEG_INF = -1.0e9;

#define MEM(arr,val)memset(arr,val, sizeof arr)
#define PI acos(0)*2.0
#define eps 1.0e-9
#define are_equal(a,b)fabs(a-b)<eps
#define LS(b)(b& (-b)) // Least significant bit
#define DEG_to_RAD(a)((a*PI)/180.0) // convert to radians

#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
#define fornm(i,n,m) for(int (i) = (n); (i) < (m); (i)++)
#define formn(i,m,n) for(int (i) = (m); (i) > (n); (i)--)
#define DEBUG if(debugging)

#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef pair<int,char> ic;
typedef pair<long,char> lc;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}
int cmp(const void *a, const void *b) {return *(int*)a - *(int*)b;}

const int debugging = 1;

int main() {
	FASTER;

	int t, n, r;
	scanf("%d", &t);
	while(t--)
    {
        int maxV=0, maxC=0, T=0, maxInd;
        scanf("%d", &n);
        forn(i, n)
        {
            scanf("%d", &r);
            T+=r;
            if(r>maxV)
            {
                maxV=r;
                maxC=0;
                maxInd=i;
            }
            else if(r==maxV)
            {
                maxC++;
            }
        }
        if(maxC>0)
            printf("no winner\n");
        else if(maxV/(1.0*T) > 0.5)
            printf("majority winner %d\n", maxInd+1);
        else
            printf("minority winner %d\n", maxInd+1);
    }

	return 0;
}
