/*																													   
 Templatka c++ Kacper Fis																							   																											   //
*/																													  
																								   
#include <bits/stdc++.h>																							   
																													   
using namespace std; 																								   
		
const double eps = 1e-9;																							   
const long long INF = 1e18;																					   
const float PI = 3.14;																								   
typedef long long LL;																								   
																													   
typedef vector<int> vi;																								   
typedef list<int> li;																								   
typedef queue<int> qi; 																								   
typedef pair<int,int> ii; 																							   
typedef map<string,int> msi; //np msi['nazwa'] = 'liczba'															   
typedef vector<ii> vii; //vector par<int>, do tworzenia tablicy dla grafów wagowych #dijkstra #Bellman_Ford			   
typedef priority_queue< pair<LL, LL> , vector< pair<LL, LL> >, greater< pair<LL, LL> > > pq; //kolejka priorytetowa vectorów par(top()=min) #dijkstra	   
																													   																				   
vector<ii>::iterator iter;																							   
																													   																				   
#define print_list(x) for(it = (x).begin(); it != (x).end(); it++) {cout << *it << " ";}							   
#define print_vector(x) for(it2 = (x).begin(); it2 != (x).end(); it2++) {cout << *it2 << " ";}						   
#define search_list(x) for(it = (x).begin(); it != (x).end(); it++)													   
#define search_vector(x) for(it2 = (x).begin(); it2 != (x).end(); it2++);											   
#define pb(x) push_back(x) 																							   
#define pf(x) push_front(x)																							   
#define mp(x, y) make_pair(x, y)                                                                                       
///////////////////////////////////////////////GLOBAL DEFINITIONS////////////////////////////////////////////////////////

int n, m;
li tab[100005]; //graf na liście sąsiedztwa
int preorder[100005]; //tablica preorder
int low[100005]; //tablica przechowująca wartości low
int color[100005]; //tablica color
int idx = 1; //kolejno nadawane indeksy dla preorder[v]

set<int> punkty_artykulacji;

///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////

void dfs(int v, int p = -1){
	color[v] = 1;
	
	preorder[v] = idx++;
	low[v] = preorder[v];
	int children = 0;
	
	for(auto it : tab[v]){
		if(it != p){
			if(color[it] == 1){
				low[v] = min(low[v], preorder[it]);
			}
			else{
				dfs(it, v);
				low[v] = min(low[v], low[it]);
				if(low[it] >= preorder[v] && p != -1){
					punkty_artykulacji.insert(v);
				}
				children++;
			}
		}
	}
	
	if(p == -1 && children > 1){
		punkty_artykulacji.insert(v);
	}
	
}

/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])																					 
{ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                  												       
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*    //WYSZUKIWANIE PUNKTÓW ARTYKULACJI
     * 
     * 1. Najpierw wyliczamy funkcję low przechodząc dfs
     * 2. Jeśli wierzchołek v jest korzeniem i ma więcej niż jednego
     * 	  syna to jest to jest on punktem artykulacji
     * 3. Jeśli potem jakiś wierzchołek v posiada syna s w drzewie
     * 	  DFS, t akiego, że low[s] >= preorder[v], to wierzchołek
     * 	  v jest punktem artykulacji.
     * */
     
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int v1, v2;
		cin >> v1 >> v2;
		tab[v1].pb(v2);
		tab[v2].pb(v1);
	}
	dfs(1);
	
	cout << "Punkty artykulacji: " << endl;
	for(auto it : punkty_artykulacji){
		cout << it << " ";
	}
	cout << endl;

	
	return 0;
}
