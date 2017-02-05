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

string convertNum(int num)
{
    string ones[10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string teens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string numW = "";
    if (num >= 100)
    {
        int hundD = num / 100;
        numW += (ones[hundD] + "hundred");
        num = num % 100;
    }
    if (num >= 20)
    {
        int tenD = num / 10;
        int oneD = num % 10;
        numW += (tens[tenD] + ones[oneD]);
    }
    if (num >= 10 && num < 20)
    {
        int teenD = num - 10;
        numW += teens[teenD];
    }
    if (num < 10)
    {
        numW += ones[num];
    }
    return numW;
}

int main(){
	FASTER;

    int n;
    vector<string> line;
    int i=0, ind, charC=0;
    string word;
    cin >> n;
    getline(cin, word);
    cin.clear();
    while(n--)
    {
        getline(cin, word);
        if(word == "$")
        {
            ind = i;
            line.push_back(word);
        }
        else
        {
            i++;
            charC += word.length();
            line.push_back(word);
        }
    }
    bool found = false;
    string ansNum = "";
    int nC = charC+1;
    while (!found && nC < 1001)
    {
        string wrd = convertNum(nC);
        if (charC + wrd.length() == nC)
        {
            ansNum += wrd;
            found = true;
        }
        else
            nC++;
    }

    for(int i=0; i<line.size(); i++)
    {
        if(line.at(i) == "$")
            cout << ansNum << " ";
        else
            cout << line.at(i) << " ";
    }

	return 0;
}
