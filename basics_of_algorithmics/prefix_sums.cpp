/*																													   
 Templatka c++ Kacper Fis																							   																											   //
*/																													  
																								   
#include <bits/stdc++.h>																							   
																													   
using namespace std; 																								   
																													   
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
///////////////////////////////////////GLOBAL DEFINITIONS////////////////////////////////////////////////////////
	
	
///////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////

int prefix_sum[1000005];
int tab[1000005];
int n;


/////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])																					 
{ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                  												       
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> tab[i];
	}
	
	for(int i = 1; i <= n; i++){
		prefix_sum[i] += prefix_sum[i - 1] + tab[i];
	}

	int x;
	cin >> x;
	
	cout << prefix_sum[x] << endl;
	
	return 0;
}
