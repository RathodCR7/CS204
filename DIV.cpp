#include<bits/stdc++.h>
using namespace std;
string p12;
int big(string p1,string p2);
string sub(string p1,string p2);
vector<int> mul(string p1,string p2);
string add(string p1,string p2);
int isprime(string p1);
string divide(string p1,string p2);

/*vector<int> mul(string p1,string p2)
{int a,b,c,i,j,carry,multy;
c=big(p1,p2);
if(c==2)
swap(p1,p2);
a=p1.length();
b=p2.length();
carry=0;
vector<int> x,y,z(a+b,0);
for(i=0;i<a;i++)
x.push_back(p1[i]-'0');
for(i=0;i<b;i++)
y.push_back(p2[i]-'0');
reverse(x.begin(),x.end());
reverse(y.begin(),y.end());
for(i=b;i<a;i++)
y.push_back(0);
a=x.size();
b=y.size();
for(j=0;j<b;j++)
{if(carry>0)
{z[a-1+j]=carry+z[a-1+j];
carry=0;}
    for(i=0;i<a;i++)
{multy=x[j]*y[i];
    int temp=z[i+j]+multy+carry;
    z[i+j]=temp%10;
    carry=temp/10;
}}
if(carry>0)
z[a+b-1]=carry;
reverse(z.begin(),z.end());
    return(z);
} */


string sub(string p1,string p2)
{int a,b,i,j,c,sub,carry;
char temp;
string p5="";
c=big(p1,p2);
if(c==2)
swap(p1,p2);
a=p1.length();
b=p2.length();
reverse(p1.begin(),p1.end());
reverse(p2.begin(),p2.end());
for(i=b;i<a;i++)
p2.push_back('0');
for(i=0;i<a;i++)
{if(p1[i]-p2[i]<0)
{temp=p1[i]+10-p2[i]+'0';
p1[i+1]=p1[i+1]-1;
    p5.push_back(temp);
}
else
p5.push_back(p1[i]-p2[i]+'0');}

reverse(p5.begin(),p5.end());
return(p5);}

int big(string p1,string p2)
{int a,b,i=0,j=0,c,d;
while(p1[i]=='0')
i++;
while(p2[j]=='0')
j++;
a=p1.length()-i;
b=p2.length()-j;
if(a<b)
return(2);
if(b<a)
return(1);
if(a==b)
{c=p1.length();
d=p2.length();
reverse(p1.begin(),p1.end());
reverse(p2.begin(),p2.end());
if(c<d)
{for(i=c;i<d;i++)
p1.push_back('0');}
if(d<c)
{for(i=d;i<c;i++)
p2.push_back('0');}
a=p1.length();
    for(i=a-1;i>=0;i--)
{if((p1[i]-'0')!=(p2[i]-'0'))
{if((p1[i]-'0')>(p2[i]-'0'))
return(1);
else
return(2);}}
    return(3);
}}
/*string add(string p1,string p2)
{int sum,carry,i,j,a,b;
char temp;
string p3="";
a=p1.length();
b=p2.length();
if(a<b)
swap(s1,s2);
a=p1.length();
b=p2.length();
reverse(p1.begin(),p1.end());
reverse(p2.begin(),p2.end());
carry=0;
for(i=0;i<b;i++)
{sum=p1[i]-'0'+p2[i]-'0'+carry;
carry=sum/10;
sum=sum%10;
s3.push_back(sum+'0');}
for(i=b;i<a;i++)
{sum=p1[i]-'0'+carry;
carry=sum/10;
sum=sum%10;
p3.push_back(sum+'0');}
if(carry>0)
p3.push_back(carry+'0');
reverse(p3.begin(),p3.end());
return(p3);}*/

string divide(string p1,string p2)
{int i,c,temp;
c=big(p1,p2);
if(c==2)
swap(p1,p2);
int a=p1.length(),b=p2.length();
string p3="",p5="";
for(i=0;i<a;i++)
{
p3.push_back(p1[i]);
if(big(p2,p3)==1)
p5.push_back('0');
else
{int j=0;
for(j=0;big(p2,p3)!=1;j++)
{p3=sub(p3,p2);}
p5.push_back(j+'0');}}
p12=p3;
return(p5);}

/*int isprime(string p1)
{int i,j,a;
cin>>p1;
string p3="",p13="";
p3.push_back('1');
p13.push_back('2');
string p2=divide(p1,p13);
for(i=2;big(p2,p3)==1;i++)
{string p15="";
char f='0'+1;
p15.push_back(f);
p3=add(p3,p15);
divide(p1,p3);
string p4;
p4=p12;
int c=0;
for(i=0;i<p4.length();i++)
{ if(p4[i]=='0')
c++;}
if(c==p4.length())
return(0);}
return(1);}*/




int main()
{int t,k;
 cin>>t;
 for(k=0;k<t;k++)
 {
string p1,p2,p3;

cin>>p1>>p2;
p3=divide(p1,p2);
cout<<p3<<endl;
cout<<p12<<endl;}


  
}
