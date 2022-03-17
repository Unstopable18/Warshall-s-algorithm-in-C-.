#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long MIN(long a,long b)
{
    if(a<b)return a;
    else return b;
}
int main()
{            
    int m,i,j,k;
    cout<<"**************************************\n";
	cout<<"    *****Warshall's Algorithm*****\n";
    cout<<"**************************************\n";
    cout<<"Enter Total no. of Vertices ";
    cin>>m;
    long W[m][m],Q0[m][m],INF=1000000000;
    cout<<"Enter "<<m*m<<" Matrix Elements:"<<endl;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>W[i][j];
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(W[i][j]==0)Q0[i][j]=INF;
            else Q0[i][j]=W[i][j];
        }
    }
    for(k=0;k<m;k++)
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                Q0[i][j]=MIN(Q0[i][j],Q0[i][k]+Q0[k][j]);
            }
        }
    }
    cout<<"*******************************************\n";
    cout<<"\t-:Shortest Path's Matrix:-"<<endl;
    for(i=0;i<m;i++)
    {
        cout<<"\t";
        for(j=0;j<m;j++)
        {
            cout<<Q0[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"*******************************************\n";
    return 0;
}