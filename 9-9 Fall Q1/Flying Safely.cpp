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

class Vertex
{
    public:
        int num;
        vector<Vertex*> adj;
        bool visited;
        int dist;

        Vertex(int n)
        {
            num = n;
            dist = 0;
            visited = false;
        }

        void addEdge(Vertex* v)
        {
            adj.push_back(v);
            v->adj.push_back(this);
        }
};

int dfs(Vertex* source)
{
    int vC=0;
    stack<Vertex*> s;
    source->visited = true;
    s.push(source);

    while(!s.empty())
    {
        Vertex* u = s.top();
        s.pop();
        //cout << "at: " << u->num << endl;
        for(unsigned i=0; i< u->adj.size(); i++)
        {
            Vertex* v = u->adj.at(i);
            //cout << "adj: " << v->num << endl;
            if (!v->visited)
            {
                vC++;
                v->visited = true;
                //cout << "+1, vC: " << vC << endl;
                s.push(v);
            }
        }
    }
    return vC;
}

int main(){
	FASTER;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int v,e;
        scanf(" %d %d", &v, &e);
        vector<Vertex*> G;
        for(int i=0; i<v; i++)
        {
            Vertex* v = new Vertex(i);
            G.push_back(v);
        }
        for(int j=0; j<e; j++)
        {
            int fr, to;
            scanf(" %d %d", &fr, &to);
            G.at(fr-1)->addEdge(G.at(to-1));
        }
        int ans = dfs(G.at(0));
        printf("%d\n", ans);
    }

	return 0;
}
