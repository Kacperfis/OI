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
int n;
vii tab[1000];
int d[1000];
int p[1000];
bool QS[1000];
int total_wt = 0; //the sum of all weights of edges

///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////

void Prim(int root)
{
	int v, u, wt;
	pq Q;
	d[root] = 0;
	
	Q.push(mp(0, root));
	
	while(!Q.empty())
	{
		u = Q.top().second;
		Q.pop();
		QS[u] = true;
			
		for(iter = tab[u].begin(); iter != tab[u].end(); iter++)
		{
			v = iter->first;
			wt = iter->second;
			
			if(!QS[v] && d[v] > wt)
			{
				d[v] = wt;
				p[v] = u;
				Q.push(mp(d[v], v));
			}
		}
	}
}

/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])																					   //
{ios_base::sync_with_stdio(false); cin.tie(NULL);                  												       //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //PRIM'S MINIMUM SPANNING TREE
    
	int m, v1, v2, v3;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
	{
		d[i]= INF;
		p[i] = -1;
		QS[i] = false;
	}
	
	for(int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> v3;
		tab[v1].pb(mp(v2, v3));
		tab[v2].pb(mp(v1, v3));
	}
    
	Prim(0);
	
	for(int i = 1; i < n; i++)
	{
		cout << p[i] << "->" << i << ": " << d[i] << endl;
		total_wt += d[i];
	}
	
	cout << "total weight: " << total_wt << endl;
	
	return 0;
}
