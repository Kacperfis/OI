/*																													   //
 Templatka c++ Kacper Fis																							   //																												   //
*/																													   //
																									   //
#include <bits/stdc++.h>																							   //
																													   //
using namespace std; 																								   //
																													   //
const int INF =  1000000001;																						   //
const float PI = 3.14;																								   //
typedef long long LL;																								   //
																													   //
typedef vector<int> vi;																								   //
typedef list<int> li;																								   //
typedef queue<int> qi; 																								   //
typedef pair<int,int> ii; 																							   //
typedef map<string,int> msi; //np msi['nazwa'] = 'liczba'															   //
typedef vector<ii> vii; //vector par<int>, do tworzenia tablicy dla grafów wagowych #dijkstra #Bellman_Ford			   //
typedef priority_queue< ii, vector<ii>, greater<ii> > pq; //kolejka priorytetowa vectorów par(top()=min) #dijkstra	   //
																													   //
list<int>::iterator it;																								   //
list<int>::iterator it1;																							   //
vector<int>::iterator it2;																							   //
vector<int>::iterator it3;																							   //
set<int>::iterator it4;																								   //
map<string, int>::iterator it5; 																					   //
vector<ii>::iterator iter;																							   //
																													   //																				   //
#define print_list(x) for(it = (x).begin(); it != (x).end(); it++) {cout << *it << " ";}							   //
#define print_vector(x) for(it2 = (x).begin(); it2 != (x).end(); it2++) {cout << *it2 << " ";}						   //
#define search_list(x) for(it = (x).begin(); it != (x).end(); it++)													   //
#define search_vector(x) for(it2 = (x).begin(); it2 != (x).end(); it2++);											   //
#define pb(x) push_back(x) 																							   //
#define pf(x) push_front(x)																							   //
#define mp(x, y) make_pair(x, y)                                                                                       //
///////////////////////////////////////////////GLOBAL DEFINITIONS////////////////////////////////////////////////////////

int p[1000], n, m;
pair <int, pair<int, int> > tab[1000];

///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////

void makeset()
{
    for(int i = 0; i < 1000; ++i)
        p[i] = i;
}
 
int find(int x)
{
    while(p[x] != x)
    {
        p[x] = p[p[x]];
        x = p[x];
    }
    return x;
}
 
void Union(int x, int y)
{
    int a = root(x);
    int b = root(y);
    p[a] = p[b];
}
 
int kruskal(pair<int, pair<int, int> > tab[])
{
    int x, y;
    int wt, total_wt = 0;
    for(int i = 0; i < m; ++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = tab[i].second.first;
        y = tab[i].second.second;
        wt = tab[i].first;
        // Check if the selected edge is creating a cycle or not
        if(find(x) != find(y))
        {
            total_wt += wt;
            Union(x, y);
        }    
    }
    return total_wt;
}

/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])																					   //
{ios_base::sync_with_stdio(false); cin.tie(NULL);                  												       //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int v1, v2, v3;
    int total_wt;
    makeset();
    cin >> n >> m;
    for(int i = 0;i < m;++i)
    {
        cin >> v1 >> v2 >> v3;
        tab[i] = make_pair(v3, make_pair(v1, v2));
    }
    // Sort the edges in the ascending order
    sort(tab, tab + m);
    total_wt = kruskal(tab);
    
    cout << total_wt << endl;
    
	return 0;
}
