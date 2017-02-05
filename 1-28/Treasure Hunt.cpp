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
	int r,c, x=0, y=0, ans=0;
	cin >> r >> c;
	char gr[r][c], read;
	forn(i, r)
        forn(j, c)
            { cin >> read; gr[i][j] = read; }
    bool found = false;
    forn(k, r*c+1)
    {
        //cout << "k: " << k <<  ": " << x << "," << y << endl;
        if(gr[x][y] == 'T') {cout << ans; found = true; break;}
        if (gr[x][y] == 'N')
        {
            if(x-1 < 0) {cout << "Out"; found = true; break;}
            else {x--; ans++;}
        }
        if (gr[x][y] == 'S')
        {
            if(x+1 == r) {cout << "Out"; found = true; break;}
            else {x++; ans++;}
        }
        if (gr[x][y] == 'W')
        {
            if(y-1 < 0) {cout << "Out"; found = true; break;}
            else {y--; ans++;}
        }
        if (gr[x][y] == 'E')
        {
            if(y+1 == c) {cout << "Out"; found = true; break;}
            else {y++; ans++;}
        }
    }
    if(!found) cout << "Lost";

	return 0;
}
