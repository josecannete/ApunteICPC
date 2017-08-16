typedef double compt; //componente de un punto, podría ser int
struct point {
    compt x, y;
    point(compt xx, compt yy) {x = xx; y = yy;}
    bool operator<(point const o) const {return make_pair(x, y) < make_pair(o.x, o.y);}
};

//asegúrate de que copiaste bien esta función
compt cross(point o, point a, point b) {
    return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}

//recibe “ch” vacío para dejar la convex hull en “ch”
void convex_hull(vector<point> &p, vector<point> &ch) {
    sort(p.begin(), p.end());
    vector<point> L, U;
    int n = p.size();
    #define tmp(x) {\
        while (x.size() >= 2 and cross(x[x.size()-2], x.back(), p[i]) <= 0)\
            x.pop_back(); x.pb(p[i]); }
    rep(i, n) tmp(L) invrep(i, n) tmp(U)
    #undef tmp
    rep(i, L.size()-1) ch.pb(L[i]);
    rep(i, U.size()-1) ch.pb(U[i]);
}
