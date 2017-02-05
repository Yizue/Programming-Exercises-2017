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

bool arr[65537];
vi pr;

void prime()
{
    arr[0] = arr[1] = true;
    for(int i=2; i<65537; i++)
    {
        if(!arr[i])
            pr.push_back(i);
        for(int j=2*i; j<65537; j+=i)
        {
            arr[j]=true;
        }
    }
}

int main() {
	FASTER;

	MEM(arr, 0);
	prime();

	//forn(i,100)
        //cout << pr[i] << endl;

	int val;
	scanf("%d", &val);
	while (val != 0){
        if( val < 7){
            if(val==3)
                printf("4\n");
            else
                printf("No such base\n");
        }
        else if((val - 3) % 2 == 0)
        {
            if (val % 4 == 3)
                printf("4\n");
            else {
                int i;
                for(i = 2; i < pr.size(); i++){
                    if (val % pr[i] == 3){
                        break;
                    }
                }
                if(i==pr.size()){
                    if (val % 3 == 0)
                        printf("6\n");
                    else
                        printf("%d\n", (val-3)/2);
                }
                else {
                    if (pr[i] > 5 && val % 3 == 0)
                        printf("6\n");
                    else
                        printf("%d\n", pr[i]);
                }
            }
        }
        else if (val % 3 == 0){
                int i;
                for(i = 2; i < pr.size(); i++){
                    if (val % pr[i] == 3){
                        break;
                    }
                }
                if(i==pr.size()){
                    if (val % 9 == 3)
                        printf("9\n");
                    else
                        printf("%d\n", (val-3)/3);
                }
                else{
                    if (pr[i] > 9 && val % 9 == 3)
                        printf("9\n");
                    else
                        printf("%d\n", pr[i]);
                }
        }
        else{
	    int i;
        for(i = 2; i < pr.size(); i++){
            if (val % pr[i] == 3){
                break;
            }
        }
        if(i==pr.size()){
            printf("%d\n", val-3);
        }
        else
            printf("%d\n", pr[i]);
        }
        scanf("%d", &val);
	}
	return 0;
}
