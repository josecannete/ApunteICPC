struct HeavyLight
{
    vector<int> parent,level,heavy,root,index;
    SegmentTree ST;
    
    HeavyLight(graph &G, vector<ll> &value, int root)
    {
        int N = G.size();
        parent.resize(N); parent[root] = -1;
        level.assign(N,-1); level[root] = 0;
        heavy.assign(N,-1); 
        root.resize(N);
        dfs(G,root);
    
        index.resize(N);
        int currentIndex = 0;
        for(int u = 0; u < N; ++u)
        {
            if(parent[u] == -1 || heavy[parent[u]] != u)
                for(int v = u; v != -1; v = heavy[v])
                {
                    root[v] = u;
                    index[v] = currentIndex++;
                }
        }
        
        vector<ll> V(N);
        for(int u = 0; u < N; ++u)
            V[index[u]] = value[u];
        ST = SegmentTree(V);
    }
    
    int dfs(graph &G, int u)
    {
        int size = 1, maxSubtree = -1;
        for(int v : graph[u]) if(level[v] == -1)
        {
            parent[v] = u;
            level[v] = level[u]+1;
            int subtree = dfs(G,v);
            if(subtree > maxSubtree)
            {
                heavy[u] = v;
                maxSubtree = subtree;
            }
            size += subtree;
        }
        return size;
    }
    /* Version No Recursiva
    void dfs(graph &G)
  {
    vector<int> subTree(G.size(),1);
    stack<int> S; S.push(0); queue<int> Q; Q.push(0); 
    while(!Q.empty())
    {
      int u = Q.front(); Q.pop();
      for(edge &e : G[u])
      {
        int &v = e.first;
        if(level[v] == -1)
        {
          level[v] = level[u]+1;
          parent[v] = u; 
          value[v] = e.second;
          S.push(v); Q.push(v);
        } 
      }
    }

    while(!S.empty())
    {
      int u = S.top(); S.pop();
      int maxSubTree = -1;
      for(edge &e : G[u])
      {
        int &v = e.first;
        if(v != parent[u])
        {
          if(subTree[v] > maxSubTree)
          {
            heavy[u] = v;
            maxSubTree = subTree[v];
          }
          subTree[u] += subTree[v];
        }
      }
    }
  }
    */
    
    int lca(int u, int v)
    {
        for(; root[u] != root[v]; v = parent[root[v]])
            if(level[root[u]] > level[root[v]])
                swap(u,v);
                
        if(level[u] > level[v])
            return v;
        return u;
    }
    
    ll query(int u, int v)
    {
        //Especifica al Problema
        ll ans = 0;
        for(; root[u] != root[v]; v = parent[root[v]])
        {
            if(level[root[u]] > level[root[v]])
                swap(u,v);
            ans = max(ans,ST.query(index[root[v]],index[v]);
        }
        if(level[u] > level[v])
            swap(u,v);
        return max(ans,ST.query(index[u],index[v]));
    }
    
    void update(int u, ll val)
    {
        ST.update(index[u],val);
    }
};
