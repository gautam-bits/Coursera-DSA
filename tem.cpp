//-------We can be heroes , just for one day!!.---------//
    
    #include <bits/stdc++.h>
    using namespace std;
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ knowledge $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
    
    #define pb push_back
    #define MP make_pair
    #define F first
    #define S second
    #define ll long long
    #define fo(i,a,b) for(int i=a;i<b;i++)
    #define rfo(i,b,a) for(int i=b;i>=a;i--)
    #define deb(x) cout<<#x<<' '<<x<<endl;
    #define mem( a, val ) memset(a, val, sizeof( a ) )
    #define deci( x ) cout<<fixed<<setprecision( x )
    #define bitcount( x ) __builtin_popcountll( x )
    #define endl "\n" 
    
    
    typedef vector<int> vi;
    typedef pair<int,int> pi;
    
    const int MOD =  1000000007 ;
    const int MAX = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

vi helpArr(ll no, ll k){
    vi ans;
    ll crr;
    
    while(k) {
        crr = no/k;
        ans.pb(crr);
        no -= crr;
        k--;
    }
    return ans;

}  
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    t = 1;
    
    while(t--)
    {
        ll n,k,tem,ans = 0;
        cin>>n>>k;
        multiset<ll,greater<ll>> length;

        fo(i,0,n){
            cin>>tem;
            length.insert(tem);
        }
        if(n == 1){

            vi arr = helpArr(*length.begin(),k);
            for(ll x : arr) ans += x*x;
            cout<<ans<<endl;
        }
        else {
            while(length.size()<k){
                auto itr = length.begin();
                ll max1 = *itr;
                itr++;
                ll max2 = *itr;

                ll times = max1/((max2+1)/2);

                times = min(times + 1,k - length.size() + 1);

                vi arr = helpArr(max1,times);

                length.erase(length.find(max1));
                
                for(ll x : arr) length.insert(x);
            }
            for(ll x : length) ans += x*x;

            cout<<ans<<endl;
        }

        

    
    
    }
    return 0;
}