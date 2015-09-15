//
//  main.cpp
//  uva_11503
//
//  Created by Shuvro Sarker on 9/15/15.
//  Copyright (c) 2015 Shuvro Sarker. All rights reserved.
//
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define max 200010
using namespace std;

int par[max];
int num[max];
map<string, int> frnds;


void makeSet(int x)
{
    frnds.clear();
    par[x]=x;
    num[x]=1;
}

int Find(int x)
{
    if (par[x] == x)
    {
        return x;
    }
    return par[x]= Find(par[x]);
}


void Union(int x,int y)
{
    int u = Find(x);
    int v = Find(y);
    if(u!=v)
    {
        par[u] = v;
        num[v]+=num[u];
        
    }
    cout<< num[v]<<endl;
}
int main(int argc, const char * argv[])
{
    int t_case, num_of_grp;
    cin>>t_case;
    while (t_case--)
    {
        cin >> num_of_grp;
        string s1,s2;
        for (int i=1; i<=num_of_grp * 2; i++)
        {
            makeSet(i);
        }
        for (int i = 1,j =1; i <= num_of_grp; i++)
        {
            
            cin>> s1 >> s2;
            if(!frnds[s1])
            {
                frnds[s1] = j++;
            }
            if (!frnds[s2])
            {
                frnds[s2] = j++;
            }
            Union(frnds[s1], frnds[s2]);
            
        }
        
        
    }
    return 0;
}
