#include <bits/stdc++.h>
using namespace std;

template<class node> class ST {
    vector<node> t;
    int n;


public:
    ST(vector<node> &arr) {
        n = arr.size();
        t.resize(n*2);
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n-1; i > 0; --i)
            t[i] = node(t[i<<1], t[i<<1|1]);
    }


    // 0-indexed
    void set_point(int p, const node &value) {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p>>1] = node(t[p], t[p^1]);
    }


    // inclusive exclusive, 0-indexed
    node query(int l, int r) {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) ansl = node(ansl, t[l++]);
            if (r&1) ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};


// Ejemplo de nodo: Range Minimum Query
struct rminq {
    int value;
    rminq() {value = INT_MAX;}
    rminq(int x) {value = x;}
    rminq(const rminq &a, const rminq &b) {
        value = min(a.value, b.value);
    }
};

/* USO:
Se requiere un struct para el nodo (ej: prodsgn).
Un nodo debe tener tres constructores:
    Aridad 0: Construye el neutro de la operación
    Aridad 1: Construye un nodo hoja a partir del input
    Aridad 2: Construye un nodo según sus dos hijos

Construcción del segment tree:
    Hacer un arreglo de nodos (usar ctor de aridad 1).
    ST<miStructNodo> miSegmentTree(arregloDeNodos);
Update:
    miSegmentTree.set_point(indice, miStructNodo(input));
Query:
    miSegmentTree.query(l, r) es inclusivo exclusivo y da un nodo. Usar la info del nodo para obtener la respuesta.
*/

int main() {
  
}
