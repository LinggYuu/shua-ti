#include <bits/stdc++.h>

using namespace std;
const int MAXN=1e5+10;

string a[MAXN];
string t;

int main(){
	int tot=0;
	while(getline(cin,t)){
		if(t=="EOF")	break;
		for(int i=0;i<t.length();){
			if(i==0&&t[i]=='<'){
				t.erase(i,1);
			}
			else if(t[i]=='<'){
				t.erase(i-1,2);
				i--;
			}
			else ++i;
			//cout<<i<<" ";
		}
		a[++tot]=t;
		//cout<<t<<endl;
	}
	int cnt=0;
	double ans=0;
	while(getline(cin,t)){
		if(t=="EOF")	break;
		for(int i=0;i<t.length();){
			if(i==0&&t[i]=='<'){
				t.erase(i,1);
			}
			else if(t[i]=='<'){
				t.erase(i-1,2);
				i--;
			}
			else ++i;
			//cout<<i<<" ";
		}
		//cout<<"\n";
		//cout<<t<<endl;
		int len=t.length();
		++cnt;
		if(cnt>tot)	continue;
		//cout<<a[cnt]<<" "<<t<<endl;
		int lenb=a[cnt].length();
		for(int i=0;i<len&&i<lenb;++i){
			if(a[cnt][i]==t[i])	ans+=1.0;
		}
	}
	double T;
	cin>>T;
	//cout<<ans<<endl;
	cout<<int(floor(ans/T*60+0.5));
    system("pause");
	return 0;
}