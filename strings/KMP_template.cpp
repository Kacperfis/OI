int KMP(string s, string p, int &pos){
	int n = s.length();
	int m = p.length();
		
	int KMPNext[m + 1];
	int b;
		
	KMPNext[0] = -1;
	b = -1;
		
	for(int i = 1; i <= m; i++){
		while((b > -1) && (p[b] != p[i-1])){
			b = KMPNext[b];
		}
		++b;
		if((i == m) || (p[i] != p[b])){
			KMPNext[i] = b;
		}
		else KMPNext[i] = KMPNext[b];
	}
	
	int pp = 0;
	b = 0;
	
	//cout << s << endl;
	
	for(int i = 0; i < n; i++){
		while((b > -1) && (p[b] != s[i]))
			b = KMPNext[b];
		if(++b == m){
			while(pp < i - b + 1){
				//cout << " ";
				pp++;
			}
			//cout << "^";
			pos = pp;
			return pos;
			pp++;
			b = KMPNext[b];
		}
	}
	
	return -1;
	//cout << endl << endl;	
}
