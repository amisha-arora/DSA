class Solution {
private:
    void bfs(int startnode,vector<int> adj[],vector<bool>& vis){
        
        queue<int> q;
        // passed 0 always
        q.push(startnode);
        vis[startnode] = 1;
        while(q.size() > 0){
            int node = q.front();
            q.pop();
            for(int i : adj[node]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> adj[v];
        for(int i = 0;i<v;i++){
            for(int j = 0;j<v;j++){
                if(isConnected[i][j] == 1 && i != j){
                    //connected the graph twice 
                    adj[i].push_back(j);

                }
            }
        }
        vector<bool> vis(v,0);
        int cnt = 0;
        for(int i = 0;i<v;i++){
            // did check this condition
            if(!vis[i]){
                cnt++;
                bfs(i, adj , vis);      
            }
        }
        return cnt;
        
    }
};
