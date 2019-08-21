#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string word;
	string ar;
	string re;
	int i,len1,len2,n,f,num=0,flag=0;
	cin >> word;
	cin.ignore();
	len1 = word.length();

	
	for(n=0;n<len1;n++)
	{
		if ((word[n] >= 'A')&& (word[n] <= 'Z'))
			word[n] += 32;
	}
	getline(cin,ar);
	len2 = ar.length();
	for (n = 0; n < len2; n++)
	{
		if ((ar[n] >= 'A') && (ar[n] <= 'Z'))
			ar[n] += 32;
	}	
	for (n = 0; n < len1; n++)
	{
		re.append("#");
	}

		while (ar.find(word)!=-1)
		{
			n = ar.find(word);
			if (n == 0)
			{
				if (ar[n + len1] == ' ' || ar[n + len1] == NULL)
				{
					num++;
					if (num == 1)
						f = n;
				}
			}
			else
			{
				if (ar[n - 1] == ' ' && (ar[n + len1] == ' ' || ar[n + len1] == NULL))
				{
					num++;

					if (num == 1)
						f = n;
				}
				
			}					
			ar = ar.replace(n, len1, re);

		}
	

	if (num != 0)
		cout << num << " " << f << endl;
	else 
	{		
		cout << -1;
	}
	return 0;
}













//if (n != -1)
//{
//	if (n == 0 && (ar[n + len1] == ' ' || ar[n + len1] == NULL)
//		|| (ar[n - 1] == ' ' && (ar[n + len1] == ' ' || ar[n + len1] == NULL)))
//	{
//		n = ar.find(word);
//		num++;
//		if (num == 1)
//			f = n;
//	}
//}
//else
//{
//	if (num == 0)
//		cout << -1;
//	break;
//}