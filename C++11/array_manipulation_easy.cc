#include<stdio.h>
typedef long long l;
l a[10000077];
int main(){
int m,n;
scanf("%d%d",&n,&m);

int i,x,y;
l t;
for(i=0;i<m;i++){
    scanf("%d %d %lld",&x,&y,&t);
    a[x] +=t;
    a[y+1]-=t;
}
l ma = 0,sum=0;
for(i=0;i<=n;i++){
    sum+=a[i];
        if(sum>ma)ma = sum;
}
printf("%lld\n",ma);
    return 0;
}
