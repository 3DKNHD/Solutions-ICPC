#include<bits/stdc++.h>
using std::vector;
void binsearch(int l, int r, vector<int> & ar, int steps){
    if(l>r)return;
    else{
        int mid = (l+r)/2;
        ar[mid] = steps;
        binsearch(l,mid-1,ar,steps+1);
        binsearch(mid+1,r,ar,steps+1);
    }
}
int main(void){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n,e;
        scanf("%d%d",&n,&e);
        vector<int> ar(n);
        binsearch(0,n-1,ar,1);
        for(int i=0;i<n;i++)if(ar[i]==e)printf("%d ",i);
        printf("\n");
    }
    return 0;
}