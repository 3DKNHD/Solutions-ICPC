#include<stdio.h>

int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        short int a,b;
        scanf("%hd%hd",&a,&b);
        printf("%hd\n",14-a-b);
    }
}