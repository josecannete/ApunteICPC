struct RMQ{
    static int const neutro = 1e9 + 5;
    static int op(int ans1, int ans2){return min(ans1,ans2);}
};

template<class t> class MO{
    int ne = t::neutro;
    int linearQuery(int l,int r,vector<int> &v){
        int n = ne;
        if(l > r) return ne;
        for(int i = l; i <= r; ++i)
            n = t::op(n,v[i]);
        return n;
    }
    int longQuery(int l,int rq){
        int ll = l/r + 1;
        int rr = rq/r - 1;
        int mint = linearQuery(ll,rr,Pre);
        int f = linearQuery(l,l+r,arr);
        int la = linearQuery(rq-r,rq,arr);
        return t::op(mint,t::op(f,la));
    }
public:
    vector<int> arr; int s,r;
    vector<int> Pre;
    MO(vector<int>& v){
        r = sqrt(v.size()); r += (r*r != v.size()); int s = r*r;
        while(v.size() < s) v.push_back(ne);
        arr = v;
        for(int i = 0; i < s; i+= r)
            Pre.push_back(linearQuery(i,i+r-1,arr));
    }
    int query(int a,int b) {return ( b - a > r ? longQuery(a,b) : linearQuery(a,b,arr));}
};
