#include<bits/stdc++.h>
using namespace std;
string mult(string c1,int n)
{
string c;
reverse (c1.begin(),c1.end());
int p;
p=0;
int m=c1.length();
for(int i=0;i<m;i++)
{
   int mul=(c1[i]-'0')*n + p;
   c.push_back(mul%10+'0');
   p=mul/10;
}
if(p!=0){
c.push_back(p+'0');
}
reverse(c.begin(),c.end());
return c;
}

string add(string c1,string c2)
{
string c;
if(c1.length()<c2.length()){swap(c1,c2);}
reverse(c1.begin(),c1.end());
reverse(c2.begin(),c2.end());
int n1=c1.length();
int n2=c2.length();
int p=0;
int sum;
for(int i=0;i<n2;i++)
{
   sum=(c1[i]-'0')+(c2[i]-'0')+p;
   p=sum/10;
   c.push_back(sum%10+'0');
}
for(int j=n2;j<n1;j++)
{
   sum=(c1[j]-'0')+p;
   p=sum/10;
   c.push_back(sum%10+'0');
}
if(p!=0){c.push_back(p+'0');}
reverse(c.begin(),c.end());
return c;
}
int main()
{
string c1,c2,c3;
cin>>c1>>c2;
c3='0';
int n1=c1.length();
int n2=c2.length();
reverse(c2.begin(),c2.end());
for(int i=0;i<n2;i++)
{
string c=mult(c1,(c2[i]-'0'));
for (int j=0;j<i;j++)
{
c.push_back('0');
}
c3=add(c3,c);
}
cout<<c3;
return 0;
}

