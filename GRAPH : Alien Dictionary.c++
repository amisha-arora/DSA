class Solution {
public:
    vector<int> topoSort(int K,vector<vector<int>>& adj){
        vector<int> indegree(K, 0);

        for(int i = 0 ; i<K;i++){
            for(int it : adj[i]){
                indegree[it] ++;
            }
        }
        queue<int> q;
        for(int i = 0 ; i<K;i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it] --;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return topo;

    }
	string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);
    // we will take 2 pairs each time and compare each and every character of them
        for(int i = 0; i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
          // we will take the minimum length of both the string 
            int len = min(s1.size(),s2.size());
            for(int ptr = 0 ; ptr<len;ptr++){
                if(s1[ptr] != s2[ptr]){
                  // pushing character in alien alphabet order 
                  //The first different character of s1 must come before the first different character of s2, 
                  //so create an edge from s1's character to s2's character, and edges are stored in form of numbers
                    adj[s1[ptr] -'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }  
        }
        vector<int> topo = topoSort(K,adj);
         // If topo doesn't contain all K characters,
        // there is a cycle -> no valid alphabet order.
        if(topo.size() != K) {
            return "";
        }
    // the answer needs to be returned as a string, not a vector 
        string ans = "";
        for(auto it : topo){
          // converting the number to a character again
            ans += char(it + 'a');
        }
        return ans;
		
	}
};
