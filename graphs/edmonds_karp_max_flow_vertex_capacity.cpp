/*
 Templatka c++ Kacper Fis																							   																											   //
*/

#include <iostream>
#include <cstdio>
#include <limits>
#include <cstdlib>
#include <utility>
#include <iterator>
#include <bitset>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
#include <time.h>
#include <iomanip>
#include <sstream>
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

list<int>::iterator it;
list<int>::iterator it1;
vector<int>::iterator it2;
vector<int>::iterator it3;
set<int>::iterator it4;
map<string, int>::iterator it5;
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
li tab[1000];
int capacity[1000][1000];
int vertex_capacity[1000];

///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////

int BFS(int s, int t, int parent[])
{
	for(int i = 1; i <= 1000; i++){ parent[i] = -1;}
	parent[s] = -2;
	queue<ii> Q;
	Q.push(mp(s, INF));

	while(!Q.empty()){
		int current = Q.front().first;
		int flow = Q.front().second;
		Q.pop();

		for(it = tab[current].begin(); it != tab[current].end(); it++){
			if(parent[*it] == -1 && capacity[current][*it]){
				parent[*it] = current;
				int new_flow = min(flow, capacity[current][*it]);
				if(*it == t)
					return new_flow;

				Q.push(mp(*it, new_flow));
			}
		}
	}
	return 0;
}

int MaxFlow(int s, int t)
{
	int flow = 0;
	int parent[1000]; for(int i = 1; i <= 1000; i++) {parent[i] = 0;}
	int new_flow;

	while(new_flow = BFS(s, t, parent)){
		flow += new_flow;
		int current = t;
		while(current != s){
			int previous = parent[current];
			capacity[previous][current] -= new_flow;
			capacity[current][previous] += new_flow;
			current = previous;
		}
	}
	return flow;
}

/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{ios_base::sync_with_stdio(false); cin.tie(NULL);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  int m, v1, v2, v3, s, t;

	cin >> n;

	for(int i = 1; i <= n; i++)
    {
        cin >> vertex_capacity[i]; //cout wczytywanie przepustowosci wierzcholkow od 1 do n
    }

    cin >> m;

	for(int i = 1; i <= m; i++){

        cin >> v1 >> v2 >> v3; //tworzenie w petli polaczenia: v1->v1'->v2
        tab[v1].pb(100+v1);
        tab[100+v1].pb(v1);
        capacity[v1][100+v1] = vertex_capacity[i];
        capacity[100+v1][v1] = 0;
        tab[100+v1].pb(v2);
        tab[v2].pb(100+v1);
        tab[100+v1].pb(v2);
        capacity[100+v1][v2] = v3;
        capacity[v2][100+v1] = 0;
	}
	cin >> s >> t;  //wczytywanie zrodla i ujscia

	int wynik = MaxFlow(s, t);

	cout << "Max Flow in network: " << wynik << endl;

	return 0;
}
