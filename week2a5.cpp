#include <bits/stdc++.h>
using namespace std;
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int sum = A.size() * (A.size() + 1) / 2;
    int sumact=0;
    map<int,int> mpp;
    int missi;
    for(int i=0;i<A.size();i++)
    {
        sumact+=A[i];
        mpp[A[i]]++;
    }
    int dou;
    int mill;
    missi=sum-sumact;
    for(int i=0;i<A.size();i++)
    {
        if(mpp[A[i]]==2)
        {
            dou=A[i];
            break;
        }
        
    }
    mill=missi+dou;
    return {dou,mill};
    
    
    
}
