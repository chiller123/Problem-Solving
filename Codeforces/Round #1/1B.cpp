#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

string str;

// foramt을 바꿔주는 구현 문제입니다.

void typeA() {
	int cIdx = str.find('C');
	int rNum = stoi(str.substr(1,cIdx-1));
	int cNum = stoi(str.substr(cIdx+1,str.length()-cIdx-1));
	
	string col;
	while(cNum){
		// 숫자->알파벳은 알파벳->숫자를 거꾸로 구현한다고 생각하면 됩니다. (+1을 -1로)
		col = char((cNum-1)%26+'A') + col;
		cNum = (cNum-1)/26;
	}
	cout << col << rNum << '\n';
}

void typeB() {
	int idx=0, cNum=0; 
	
	while(!isdigit(str[idx])) idx++;
	int rNum = stoi(str.substr(idx, str.length()-idx));
	
	for(int i=0; i<idx; ++i) {
		cNum = 26*cNum+str[i]-'A'+1;
	}

	cout << 'R' << rNum << 'C' << cNum << '\n';
}

int main(){	
	int t; cin >> t;
	while(t--) {
		cin >> str; 
		int cnt = 0;

		for(int i=0; i<str.length()-1; ++i){
			if(isalpha(str[i]) && isdigit(str[i+1])) 
				cnt++;
		}

		if(cnt==2) typeA();
		else typeB();
	}
}