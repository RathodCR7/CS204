#include<string>
#include<stack>
#include<iostream>
using namespace std;
string add_fun(string p,string q)
{
string out = "";
int r=0;
stack<int> s1;
stack<int> s2;
stack<int> ans;
if(p.size()>=q.size())
{
int n1 = p.size();
int n2 = q.size();
for(int i=0;i< n1;i++)
{
s1.push(p[i]-'0');
}
for(int i = 0; i < n2; ++i)
{
s2.push(q[i]-'0');
}
}
else
{
int n1 = q.size();
int n2 = p.size();
for(int i=0;i<n1;i++)
{
s1.push(q[i]-'0');
}
for(int i = 0; i <n2; ++i)
{
s2.push(p[i]-'0');
}
}
int n1 = s1.size();
int n2 = s2.size();
int k;
while(s2.size()!=0)
{
k = s1.top()+s2.top();
if(r==1)
{
k++;
r=0;
}
if(k>9)
r=1;
ans.push(k%10);
s1.pop();s2.pop();
}
while(s1.size()!=0)
{
k = s1.top();
if(r==1)
{
k++;
r=0;
}
if(k>9)
r=1;
ans.push(k%10);
s1.pop();
}
if(r==1)
{
ans.push(1);
}
while(ans.size()!=0)
{
string s(1,'0'+ans.top());
out.append(s);
ans.pop();
}
return out;
}
int main()
{
string a,b;
cin>>a;
cout<<'+'<<'\n';
cin>>b;
cout<<'='<<'\n';
cout<< add_fun(a,b)<<'\n';
return 0;
}
