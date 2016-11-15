// Implementaci�n general
// El nodo puede ser de un tipo arbitrariamente complejo
template<class node> class SegmentTree {
    // st es el arreglo de nodos del segment tree
    vector<node> arr, st;
    // leaf guarda la ubicaci�n de cada hoja en st
    vector<int> leaf; int n;

    // construir nodo u, que representa al rango [i,j]
    void build(int u, int i, int j) {
        // caso de que el rango representa una hoja
        if (i == j) {
            leaf[i] = u;
            st[u] = arr[i];
            return;
        }
        // l y r son los hijos izquierdo y derecho de u
        int m = (i+j)/2, l = u*2+1, r = u*2+2;
        build(l, i, m);
        build(r, m+1, j); // es importante el +1
        st[u] = node(st[l], st[r]); // query arbitraria
    }

    // query en el rango [a,b], considerando que nos
    // encontramos en el nodo u que representa a [i,j]
    node query(int a, int b, int u, int i, int j) {
        // nodo fuera del rango [a,b], retornar neutro
        if (j < a or b < i)
            return node(); // nodo neutro
        // nodo totalmente contenido en [a,b]
        if (a <= i and j <= b)
            return st[u]; // responder directamente
        // si no, componer queries de ambos hijos
        int m = (i+j)/2, l = u*2+1, r = u*2+2;
        const node &x = query(a, b, l, i, m);
        const node &y = query(a, b, r, m+1, j); // +1 !!
        return node(x, y);
    }

    // actualizar nodo u considerando que uno de sus
    // hijos fue actualizado antes (o es una hoja)
    void update(int u) {
        int l = u*2+1, r = u*2+2;
        st[u] = node(st[l], st[r]); // actualizar info
        // si no es la ra�z (nodo 0) actualizar padre
        if (u != 0) update((u-1)/2);
    }

public:
    // construir segment tree a partir de un vector
    // (debe ser un vector con los nodos hoja!!)
    SegmentTree(vector<node>& v) {
        arr = v;
        n = v.size();
        leaf.resize(n);
        // reservar tama�o para el peor caso, 4*N
        st.resize(n*4+5);
        // construir desde la ra�z
        build(0, 0, n-1);
    }

    // [a,b] es inclusivo inclusivo, indexado desde 0
    // (la query retorna un nodo con la respuesta!!)
    node query(int a, int b) {
        // responder query procesando desde la ra�z
        return query(a, b, 0, 0, n-1);
    }

    // setea un valor en cierto �ndice del arreglo
    void update(int index, const node &value) {
        int u = leaf[index];
        arr[index] = value;
        st[u] = arr[index];
        // chequea si la hoja es ra�z por si N = 1
        if (u != 0) update((u-1)/2);
    }
};

// Ejemplo de nodo para Range Minimum Query
struct RMQ {
    int value; // info del nodo, en este caso solo un int

    // Un nodo debe tener tres constructores:
    // Aridad 0: Construye el neutro de la operaci�n
    // Aridad 1: Construye un nodo hoja a partir del input
    // Aridad 2: Construye un nodo seg�n sus dos hijos

    // El neutro del m�nimo es infinito
    RMQ() {value = INT_MAX;}

    // Para cada int en el arreglo del input, el nodo
    // contiene a ese int (ver implementaci�n espec�fica)
    RMQ(int x) { // recibe un elemento del arreglo input
        value = x;
    }

    // Si tienes ambos hijos puedes determinar al padre
    RMQ(const RMQ &a, const RMQ &b) {
        value = min(a.value, b.value); // range min. query
    }
};

/*
Construcci�n del segment tree:
    Hacer un arreglo de nodos (usar ctor de aridad 1).
    ST<miStructNodo> miSegmentTree(arregloDeNodos);
Update:
    miSegmentTree.update(indice, miStructNodo(input));
Query:
    miSegmentTree.query(l, r) es inclusivo inclusivo y da
    un nodo. Usar la info del nodo para obtener la
    respuesta. (ej: miSegmentTree.query(l, r).value)
*/

// Ejemplo con nodos tipo RMQ:
int n = ...;
vector<int> miArreglo = ...;
vector<RMQ> arregloDeNodos(n);
for (int i = 0; i < n; ++i)
    arregloDeNodos[i] = RMQ(miArreglo[i]);
SegmentTree<RMQ> miSegmentTree(arregloDeNodos);
// Update:
miSegmentTree.update(indice, RMQ(nuevoValor));
// Query:
int minimo = miSegmentTree.query(l, r).value;
