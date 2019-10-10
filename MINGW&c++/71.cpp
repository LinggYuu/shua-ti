// p1603
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

string word;
string r[6];
string result;
int rr[6];
string a[26]={"one","two","three","four","five","six","seven","eight","nine",
            "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
            "eighteen","nineteen","twenty"," a ","both","another","first","second","third"};
string aa[26]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20"
            ,"1","2","1","1","2","3"};
int aaa[26]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,1,2,1,1,2,3};
//erase(3,4)从第三个位置开 始删除4个字符，不输入4就删到结尾


int main()
{
    int t=0;
    getline(cin,word,'.');
    for(int i=0;i<26;i++)
    {
        if(word.find(a[i])!=word.npos)
        {   
            rr[t++]=aaa[i];
            word.erase(word.find(a[i]),a[i].size());
            // cout<<word<<endl;
            i--;
        }
    }

    for(int i=0;i<t;i++)
    {
        rr[i]*=rr[i];
        rr[i]%=100;
        string w=to_string(rr[i]);
        if(w.size()<2)
            r[i]+="0";
        r[i]+=w;   
    }
    sort(r,r+t);
    for(int i=0;i<t;i++)
    {
        result+=r[i];
    }
    if(result.empty())
        cout<<0;
    else
    {
    while(result[0]=='0')
        result.erase(0,1);
    cout<<result;
    }
    system("pause");
    return 0;
}