class Solution{
public:
    vector<int> topoSort(int V, vector<int> adj[]){
        
        // Step 1: Create an indegree array.
        // indegree[i] = Number of incoming edges to vertex i.
        int indegree[V] = {0};

        // Step 2: Calculate the indegree of every vertex.
        // Traverse every node and its neighbours.
        // If there is an edge i -> it,
        // then increase indegree of 'it' by 1.
        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        // Step 3: Push all vertices having indegree 0 into the queue.
        // These are the vertices that have no dependencies,
        // so they can appear first in the topological ordering.
        queue<int> q;

        for(int i = 0; i < V; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        // This vector will store the final topological ordering.
        vector<int> topo;

        // Step 4: Process the queue until it becomes empty.
        while(!q.empty()){

            // Remove the front node from the queue.
            int node = q.front();
            q.pop();

            // Since all its prerequisites are completed,
            // add it to the answer.
            topo.push_back(node);

            // Step 5: Visit all neighbours of the current node.
            // Imagine removing the current node from the graph.
            // Therefore every outgoing edge from this node disappears,
            // reducing the indegree of its neighbours.
            for(auto it : adj[node]){

                indegree[it]--;

                // If a neighbour's indegree becomes 0,
                // it means all of its prerequisites have been processed.
                // So it is ready to be processed next.
                if(indegree[it] == 0)
                    q.push(it);
            }
        }

        // Return the topological ordering.
        return topo;
    }
};
