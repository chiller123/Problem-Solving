#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

string str;

// foramt�� �ٲ��ִ� ���� �����Դϴ�.

void typeA() {
	int cIdx = str.find('C');
	int rNum = stoi(str.substr(1,cIdx-1));
	int cNum = stoi(str.substr(cIdx+1,str.length()-cIdx-1));
	
	string col;
	while(cNum){
		// ����->���ĺ��� ���ĺ�->���ڸ� �Ųٷ� �����Ѵٰ� �����ϸ� �˴ϴ�. (+1�� -1��)
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