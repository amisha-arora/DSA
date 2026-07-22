class Solution{
public:
    bool isCyclic(int N, vector<int> adj[]) {

        int indegree[N] = {0};

        // Calculate indegree
        for(int i = 0; i < N; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;

        // Push all nodes having indegree 0
        for(int i = 0; i < N; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        int cnt = 0;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            cnt++;

            for(auto it : adj[node]){

                indegree[it]--;

                if(indegree[it] == 0)
                    q.push(it);
            }
        }

        // If every node is processed,
        // graph is acyclic.
        if(cnt == N)
            return false;

        return true;
    }
};
