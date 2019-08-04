#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long int s1;
    cin>>s1;
    long long int s= sqrt(s1);
    int flag=0;
    if(s1==0 || s1==1){        cout<<"Given number is not prime"<<endl;}

    else{for(long long int i=2;i<=s;i++){
        if(s1%i==0){
            flag=1;
        }
    }

    if(flag==1){
        cout<<"Given number is not prime"<<endl;
    }
    else{
        cout<<"Given number is prime"<<endl;
    }
    }
}
