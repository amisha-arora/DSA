class Solution{
private:
//pushing happens after recursion. That is called postorder
    void dfs(int src,int vis[],vector<int> adj[],stack <int>& s){
        //arrays are already passed by reference-like behavior in C++ so we dont need to pass them by reference
        vis[src] = 1;
        for(int node : adj[src]){
            if(!vis[node]) dfs(node,vis,adj,s);
            
        }
        //A node is pushed into the stack only after every node that depends on it has already been processed.
        s.push(src);

    }

public:
    vector<int> topoSort(int V, vector<int> adj[]){
        int vis[V] = {0};
        stack <int> s;
        for(int i = 0 ; i<V; i++){
            if(!vis[i]){
                dfs(i,vis,adj,s);
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
