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
#define UNVISITED 0
#define VISITED 1

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


/*
	__builtin_popcount(int d) // count bits
	__builtin_popcountll(long long d)
	strtol(s, &end, base); // convert base number
*/
//----------------------------------------------------------------------//

int V = 32;
vector<vii> G;
vi vis;
map<string, int> N;
vector<string> name;
vi parent;

void dfs(int u) {
    vis[u] = VISITED;
    forn(j, (int)G[u].size()) {
        ii e = G[u][j];
        if (vis[e.first] == UNVISITED) {
            parent[e.first] = u;
            dfs(e.first);
        }
    }
}

int main() {
	FASTER;
    int n, cnt=0;
    string s, t, b;
    cin >> n;
    getline(cin, b);

    G.assign(V, vii());
    vis.assign(V, UNVISITED);
    name.assign(V, "");
    parent.assign(V, -1);

    forn(i, n)
    {
        vector<string> tok;
        getline(cin, s);
        string buf;
        stringstream ss(s); // Insert the string into a stream

        while (ss >> buf)
            tok.push_back(buf);

        int ind;
        if(N.find(tok[0]) == N.end()) // Not found
        {
            N[tok[0]] = cnt;
            name[cnt] = tok[0];
            ind = cnt;
            cnt++;
        }
        else // Found
        {
            ind = N[tok[0]];
        }

        fornm(j, 1, tok.size())
        {
            int ind2;
            if(N.find(tok[j]) == N.end()) // Not found
            {
                N[tok[j]] = cnt;
                name[cnt] = tok[j];
                ind2 = cnt;
                cnt++;
            }
            else // Found
            {
                ind2 = N[tok[j]];
            }
            G[ind].push_back(ii(ind2, 1));
            G[ind2].push_back(ii(ind, 1));
        }

    }
    /*
    forn(k, G.size())
    {
        cout << name[k] << ": " << k << ":: ";
        forn(l, G[k].size())
        {
            cout << G[k][l].first << ' ';
        }
        cout << endl;
    } */

    string src, des;
    int srcN, desN;
    cin >> src >> des;
    if(N.find(src) == N.end()) // Not found
    {
        N[src] = cnt;
        name[cnt] = src;
        srcN = cnt;
        cnt++;
    }
    else // Found
    {
        srcN = N[src];
    }
    if(N.find(des) == N.end()) // Not found
    {
        N[des] = cnt;
        name[cnt] = des;
        desN = cnt;
        cnt++;
    }
    else // Found
    {
        desN = N[des];
    }

    dfs(srcN);

    if (vis[desN] == UNVISITED)
    {
        cout << "no route found";
    }
    else
    {
        stack<string> path;
        int curr = desN;
        while (curr != -1)
        {
            path.push(name[curr]);
            curr = parent[curr];
        }

        while(!path.empty())
        {
            //cout << "top: " << path.top() << endl;
            cout << path.top() << " ";
            path.pop();
        }
    }

	return 0;
}
