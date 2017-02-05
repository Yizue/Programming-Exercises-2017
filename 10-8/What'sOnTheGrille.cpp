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
    int n;
    cin >> n;
    char grid[n][n], read;
    vector<ii> grl;
    string msg;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> read;
            if(read == '.')
                grl.push_back(make_pair(i,j));
            grid[i][j] = 'X';
        }
    }
    cin >> msg;

    bool err = false;
    int it=0;
    for(int k=0; k<4; k++)
    {
        for(int l=0; l<grl.size(); l++)
        {
            ii cds = grl[l];
            if(grid[cds.first][cds.second] != 'X')
            {
                err = true;
                break;
            }
            grid[cds.first][cds.second] = msg.at(it);
            //cout << cds.first << "," << cds.second << ": " << msg.at(it) << ": " << grid[cds.first][cds.second] << endl;
            it++;
        }
        /*
        cout << '(';
        for(int z=0; z<grl.size(); z++)
        {
            ii cds = grl[z];
            cout << cds.first << "," << cds.second << "   ";
        }
        cout << ')' << endl;
        */
        for(int m=0; m<grl.size(); m++)
        {
            int temp = grl[m].first;
            grl[m].first = grl[m].second;
            grl[m].second = n-1-temp;
        }
        sort(grl.begin(), grl.end());
    }

    string ans = "";
    if(!err)
    {
        for(int x=0; x<n; x++)
        {
            for(int y=0; y<n; y++)
            {
                if(grid[x][y] != 'X')
                    ans += grid[x][y];
                else
                {
                    err = true;
                    break;
                }
            }
        }
    }
    if(err)
        cout << "invalid grille" << endl;
    else
        cout << ans << endl;
	return 0;
}
