/*																													   
 Templatka c++ Kacper Fis																							   																											   //
*/																													  
																								   
#include <bits/stdc++.h>																							   
																													   
using namespace std; 																								   
		
const double eps = 1e-9;																							   
const int INF = 1000000001;																						   
const float PI = 3.14;																								   
typedef long long LL;																								   
																													   
typedef vector<int> vi;																								   
typedef list<int> li;																								   
typedef queue<int> qi; 																								   
typedef pair<int,int> ii; 																							   
typedef map<string,int> msi; //np msi['nazwa'] = 'liczba'															   
typedef vector<ii> vii; //vector par<int>, do tworzenia tablicy dla grafów wagowych #dijkstra #Bellman_Ford			   
typedef priority_queue< ii, vector<ii>, greater<ii> > pq; //kolejka priorytetowa vectorów par(top()=min) #dijkstra	   
																													   																				   
vector<ii>::iterator iter;																							   
																													   																				   
#define print_list(x) for(it = (x).begin(); it != (x).end(); it++) {cout << *it << " ";}							   
#define print_vector(x) for(it2 = (x).begin(); it2 != (x).end(); it2++) {cout << *it2 << " ";}						   
#define search_list(x) for(it = (x).begin(); it != (x).end(); it++)													   
#define search_vector(x) for(it2 = (x).begin(); it2 != (x).end(); it2++);											   
#define pb(x) push_back(x) 																							   
#define pf(x) push_front(x)																							   
#define mp(x, y) make_pair(x, y)                                                                                       
///////////////////////////////////////////////GLOBAL DEFINITIONS////////////////////////////////////////////////////////

int n;
li tab[30005];
int lca[17][30005];
int d[30005];

///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////

void dfs(int v, int p){
	lca[0][v] = p;
	for(auto it : tab[v]){
		if(it != p){
			d[it] = d[v] + 1;
			dfs(it, v);
		}
	}
}

int query(int p, int q){
	int log;
	
	if(d[p] < d[q]){
		swap(p, q);
	}
	
	for(log = 1; (1 << log) <= d[p]; log++){}
	log--;
	//cout << "log: " << log << endl;
	
	for(int i = log; i >= 0; i--){
		if(d[p] - (1 << i) >= d[q])
			p = lca[i][p];
	}
	
	if(p == q)
		return p;
		
	for(int i = log; i >= 0; i--){
		if(lca[i][q] != -1 && lca[i][p] != lca[i][q])
			p = lca[i][p], q = lca[i][q];
	}
	return lca[0][p];
}

/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])																					 
{ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                  												       
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*  przykładowy graf do testów:
     * 
	 *	5
	 *	1 2
	 *	1 5
	 *	3 5
	 * 	4 5
	 *
	 *	*Wzór na odległość między wierzchołkiem p i q: 
	 *	odleglosc(p, q) = d[p] + d[q] - 2 * d[lca[p][q]]
	 * 
     * * * * */
    
    
    cin >> n;
    for(int i = 0; i < n-1; i++){ //wczytujemy drzewo
		int v1, v2;
		cin >> v1 >> v2;
		tab[v1].pb(v2);
		tab[v2].pb(v1);
	}
	
	dfs(1, 0); //korzen = 1, przechodzimy dfs znajdując przodka każdego z wierzchołków
	
	for(int i = 1; i < 17; i++){ //obliczamy wszystkich przodków wierzchołków(potęgi 2)(1-wszy, 2-ugi, 4-ty, 8-my)(dp)
		for(int v = 1; v <= n; v++){
			lca[i][v] = lca[i - 1][lca[i - 1][v]];
		}
	}
	
	//cout << "przodkowie: " << endl;
	//for(int i = 0; i < 3; i++){
		//for(int v = 1; v <= n; v++){
			//cout << pow(2, i) << " przodek wierzchołka " << v << ": " << lca[i][v] << endl;
		//}
	//}
	
	//cout << "najniższy wspólny przodek 3 i 4: " << query(3, 4) << endl;
	//cout << "najniższy wspólny przodek 3 i 2: " << query(3, 2) << endl;
	//cout << "najniższy wspólny przodek 4 i 5: " << query(4, 5) << endl;
	
	
		
	return 0;
}
