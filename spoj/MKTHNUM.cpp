#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int N=100005;
map<int,int> id;
int s[20*N],l[20*N],r[20*N],ver[N],peak=0;
int a[N],b[N],value[N],cnt=0;
void update(int p,int q,int pr,int v) {
    if(p>v || q<v || p>q) return;
    s[peak]=s[pr]+1;
    if(p==q) return;
    l[peak]=l[pr];r[peak]=r[pr];
    int mid=(p+q)>>1,node=peak;
    if(v>mid) {
        r[node]=++peak;
        update(mid+1,q,r[pr],v);
    }
    else {
        l[node]=++peak;
        update(p,mid,l[pr],v);
    }
}
int get(int p,int q,int k) {
    int ll=1,rr=cnt,x=ver[p-1],y=ver[q];
    while(ll<rr) {
        int mid=(ll+rr)>>1, inleft=s[l[y]]-s[l[x]];
        if(inleft>=k) {
            x=l[x];
			y=l[y];
			rr=mid;
        } else {
            k-=inleft;
            x=r[x];
			y=r[y];
			ll=mid+1;
        }
    }
    return ll;
}
int main(){
    //freopen("test.inp","r",stdin);
    int n,m,p,q,k,i;
    scanf("%d",&n);
    for(i=1;i<=n;++i) {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    for(i=1;i<=n;++i) if(i==1 || b[i]!=b[i-1])
        id[b[i]]=++cnt,value[cnt]=b[i];
    for(i=1;i<=n;++i) {
        ver[i]=++peak;
        update(1,cnt,ver[i-1],id[a[i]]);
    }
    scanf("%d",&m);
    while(m--) {
        scanf("%d%d%d",&p,&q,&k);
        printf("%d\n",value[get(p,q,k)]);
    }
}