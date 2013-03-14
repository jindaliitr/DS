#include<iostream>
using namespace std;
int main()
{
    int test, m, n, i;
    cin>>test;
    for(i=0; i<test; i++)
    {
        cin>>m>>n;
        if(m>n)
        cout<<"1\n";
        else
        {
            if(n%m==0)
            cout<<(n/m)*4-1<<endl;
            else
            cout<<(n/m+1)*4-1<<endl;
        }
    }
}
