#include<string>
#include<stack>
#include<iostream>
using namespace std;
string subtract_fun(string p,string q)
{
string out = "";
int r=0;
stack<int> s1;
stack<int> s2;
stack<int> ans;
int n1 = p.size();
int n2 = q.size();
for(int i=0;i< n1;i++)
{
if(s1.size()!=0 || p[i]!='0') s1.push(p[i]-'0');
}
for(int i = 0; i < n2; ++i)
{
if(s2.size()!=0 || q[i]!='0') s2.push(q[i]-'0');
}
int k;
while(s2.size()!=0)
{
k = s1.top()-s2.top();
if(r==1)
{
k--;
r=0;
}
if(k<0)
{
r=1;
k+=10;
}
ans.push(k);
s1.pop();s2.pop();
}
while(s1.size()!=0)
{
k = s1.top();
if(r==1)
{
k--;
r=0;
}
if(k<0)
{
r=1;
k+=10;
}
ans.push(k);
s1.pop();
}
if(ans.top()==0) ans.pop();
if(r==1)
{
return "Error : The output is not a Natural Number.";
}
while(ans.size()!=0)
{
string s(1,'0'+ans.top());
out.append(s);
ans.pop();
} 
if (out=="") return "0";
else return out;
}

int main()
{
string a,b;
cin>>a;
cout<<'-'<<'\n';
cin>>b;
cout<<'='<<'\n';
cout<< subtract_fun(a,b)<<'\n';
return 0;
}
