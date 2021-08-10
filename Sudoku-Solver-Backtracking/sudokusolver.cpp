#include <bits/stdc++.h>
using namespace std;
//typedefs and flash
#define STEXT freopen("cin.in","r",stdin);freopen("cout.in","w",stdout)
#define NEWBMASTER69 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define V vector<int>
#define VS vector < set<int,greater<int>> >
#define Vll vector <long long>
#define VV vector<vector<int>>
#define VVll vector<vector<long long>>
#define ll long long
#define lll unsigned long long 
#define pb push_back
#define mp make_pair
#define ppp pair <int,int>
#define pq priority_queue 
#define ff first
#define ss second
//inputs
#define inp(n) int n;cin>>n
#define inp2(n,m) int n,m;cin>>n>>m
#define inp3(n,m,k) int n,m,k;cin>>n>>m>>k
#define linp(n) ll n;cin>>n
#define linp2(n,m) ll n,m;cin>>n>>m
#define linp3(n,m,k) ll n,m,k;cin>>n>>m>>k
#define sinp(s) string s;cin>>s
#define vinp(v,n) V v;fup(i,0,n) {int temp; cin>>temp; v.pb(temp);}
#define lvinp(v,n) Vll v;fup(i,0,n) {ll temp; cin>>temp; v.pb(temp);}
//loops
#define fup(i,L,R) for(int i=L;i<R;i++)
#define fdo(i,L,R) for(int i=L;i>R;i--)
//VECTOR print statements/functions
#define vsubout(v,L,R) fup(i,L,R) {cout<<v[i]<<" ";}
#define vout(v) vsubout(v,0,v.size());cout<<endl
#define vvout(v,n,m) fup(i,0,n){fup(j,0,m){cout<<v[i][j]<<" ";}cout<<endl;}
#define qsort(v) sort(v.begin(),v.end())
//imp numbers or functions
#define MAX1 1000000007

//taking input and sublime test part
void stext(){
    #ifndef ONLINE_JUDGE
        STEXT;
    #endif
}
//////////////////////////////////////////////////////////////////////////////////////////
int test(int f){if(f==0){return 1;}else{inp(tt);return tt;}} 
#define inptest(n) int ttt = test(n)
//////////////////////////////////////////////////////////////////////////////////////////
Vll factorial;
ll power(ll x,ll y,ll m) { if (y == 0) {return 1;} ll p = power(x, y/2,m) % m; p = (p * p) % m;return (y%2 == 0)? p : (x * p) % m;} 
ll modInverse(ll a, ll m){return power(a, m-2, m);} 
void wfact(ll n){factorial.pb(1);fup(i,1,n+1){ll temp = i*factorial[i-1];factorial.pb(temp%MAX1);}return;}
ll P(ll n,ll r){return (factorial[n]*modInverse(factorial[n-r],MAX1))%MAX1;}
ll C(ll n,ll r){return (P(n,r)*modInverse(factorial[r],MAX1))%MAX1;}
//////////////////////////////////////////////////////////////////////////////////////////
ll gcd(ll a,ll b) {if(a == 0){return b;}if(b == 0) {return a;} if (a == b) {return a;}  if (a > b) {return gcd(a-b, b);} return gcd(a, b-a); }    
ll lcm(ll a,ll b){if(a>b){ll temp = a;a=b;b=temp;}return a*(b/gcd(a,b));}
//////////////////////////////////////////////////////////////////////////////////////////
//graphs
VV adj;
V gvisit;
void dfs(int node,int par){
    gvisit[node]=1;
    cout<<node<<" ";
    int j = adj[node].size();
    fup(i,0,j){
        if(gvisit[adj[node][i]]==0){
            dfs(adj[node][i],node);
        }
    }
}
void bfs(int node,int par){
    if(par==-1){
        gvisit[node]=1;
        cout<<node<<" ";    
    }
    int j = adj[node].size();
    V v;
    fup(i,0,j){
        if(gvisit[adj[node][i]]==0){
            v.pb(adj[node][i]);
            gvisit[adj[node][i]]=1;
            cout<<adj[node][i]<<" ";
        }
    }
    j = v.size();
    fup(i,0,j){
        bfs(v[i],node);
    }
}
int hasho(int x,int y){
    return 3*(x/3)+y/3;
}
////////////////////////////////////////////////////////////////////////
bool myfunc(VV& mat,V& x,V& y,VS& r,VS& c,VS& block){
    if(x.size()==0){
        return true;
    }
        int i,j;
        int size = x.size();
        i = x[size-1];
        j = y[size-1];
        for(int k=1;k<10;k++){
            if(r[i].find(k)==r[i].end()&&c[j].find(k)==c[j].end()&&block[hasho(i,j)].find(k)==block[hasho(i,j)].end()){
                mat[i][j]=k;
                r[i].insert(k);
                c[j].insert(k);
                block[hasho(i,j)].insert(k);
                x.pop_back();
                y.pop_back();
                if(myfunc(mat,x,y,r,c,block)){
                    return true;
                }
                else{
                    mat[i][j]=0;
                    x.pb(i);
                    y.pb(j);
                    r[i].erase(r[i].find(k));
                    c[j].erase(c[j].find(k));
                    block[hasho(i,j)].erase(block[hasho(i,j)].find(k));
                }
                //cout<<k<<" ";
            }
        }
    return false;
}
int main(){
    V prop;
    stext();
    NEWBMASTER69;
    inptest(1);
    //wfact(1000);
    while(ttt--){
        //code;
        VV mat;
        for(int i = 0;i<9;i++){
            mat.push_back(prop);
        }
        for(int i=0;i<9;i++){
            vinp(v,9);
            mat[i]=v;
        }
        vector < set<int,greater<int>> > r,c,block;
        set <int,greater<int>> sprop;
        for(int i=0;i<9;i++){
            r.push_back(sprop);
            c.push_back(sprop);
            block.push_back(sprop);
        }
        V x,y;
        for(int i = 0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mat[i][j]>0){
                    r[i].insert(mat[i][j]);
                    c[j].insert(mat[i][j]);
                    block[hasho(i,j)].insert(mat[i][j]);
                }
                else{
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        int size = x.size();
        if(myfunc(mat,x,y,r,c,block)){
            //do nothing
        }
        vvout(mat,9,9);
        cout<<"exec ended"<<endl;;
    }
    return 0;
}

