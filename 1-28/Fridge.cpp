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
typedef pair<int,ii> iii;
typedef pair<int,char> ic;
typedef pair<long,char> lc;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<dd> vdd;


int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}
int cmp(const void *a, const void *b) {return *(int*)a - *(int*)b;}

const int debugging = 1;

/*
	__builtin_popcount(int d) // count bits
	__builtin_popcountll(long long d)
	strtol(s, &end, base); // convert base number
*/
//----------------------------------------------------------------------//

int main() {
	FASTER;
	string in;
	getline(cin, in);
	int cnt[10]; MEM(cnt, 0);

	forn(i, in.length())
	    cnt[(int) (in[i] - '0')]++;
    //forn(l, 10)
        //cout << cnt[l] << " ";
    //cout << endl;
    int m = 2000, mI = 20;
    for(int j=0; j<10; j++)
    {
	    if(m > cnt[j])
            { m = cnt[j]; mI = j; }
        if(m == cnt[j] && mI == 0)
            { m = cnt[j]; mI = j; }
    }
    //cout << "M: " << m << " mI: " << mI << endl;
    if (mI == 0)
        cout << "1";
    forn(k, m+1) cout << mI;
	return 0;
}
