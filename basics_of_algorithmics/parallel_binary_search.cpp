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
///////////////////////////////////////////////GLOBAL DEFINITIONS////////////////////////////////////////////////////////

int L[105];
int R[105];
int mid[105];
int check[105];

int q = 10;
int m = 20;

///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////

void process(){
	//wypełnianie tablicy check
}


void parallel_binary_search(){
	
	for(int i = 0; i < q; i++){
		L[i] = 0; //dolna granica
		R[i] = m; //górna granica
	}
	
	for(int j = 0; j < 25; j++){ // z góry ustawiamy limit liczby przeszukań
		
		for(int i = 0; i < q; i++){
			mid[i] = L[i] + ((R[i] - L[i]) / 2);
			check[i] = false;
		}
		
		process(); // tutaj odbywa się proces wypełniący tablicę check[i]
		
		for(int i = 0; i < q; i++){
			if(check[i]){
				R[i] = mid[i];
			}
			else L[i] = mid[i] + 1;
		}
	}
}

/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])																					 
{ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                  												       
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	
	
	return 0;
}
