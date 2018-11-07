

#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<int,bool>arr;

    int n;
    cin>>n;
    int a1[n],a2[n];

    for(int i=0; i<n; i++)
    {
        scanf("%d",&a1[i]);
        arr[a1[i]]=1;
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a2[i]);
        arr[a2[i]]=1;
    }
    int temp=0,coun=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            temp=a1[i]^a2[j];
            if(arr.find(temp)!=arr.end())
            {
                coun++;
            }
        }
    }
    if(coun%2== 0)
    {
        cout<<"Karen"<<endl;
    }
    else
        cout<<"Koyomi"<<endl;

    return 0;
}
