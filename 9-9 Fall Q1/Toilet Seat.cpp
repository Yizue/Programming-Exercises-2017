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
    string l;
    getline(cin, l);

    int a=0,b=0,c=0;
    char pos = l.at(0);
    for(int i=1; i<=l.length()-1; i++)
    {
        char pref = l.at(i), prev = l.at(i-1);
        if(prev != pref)
            c++;
        if(i==1)
        {
            if(pref == 'U' && prev == 'U')
                b++;
            else if (pref == 'D' && prev == 'D')
                a++;
            else if (pref == 'D' && prev == 'U')
            {
                a+=2;
                b++;
            }
            else if (pref == 'U' && prev == 'D')
            {
                a++;
                b+=2;
            }
        }
        else
        {
            if(pref == 'U')
                b+=2;
            else if (pref == 'D')
                a+=2;
        }
    }
    cout << a << endl << b << endl << c << endl;

	return 0;
}
