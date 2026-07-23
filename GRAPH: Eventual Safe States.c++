class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        // Number of nodes in the graph
        int N = graph.size();

        // We will create a REVERSED graph.
        //
        // If original graph has:
        //      0 -> 1
        //
        // reversed graph will have:
        //      1 -> 0
        //
        // adj will store this reversed graph.
        vector<vector<int>> adj(N);


        // Here indegree[i] actually represents the number of
        // OUTGOING edges of node i in the ORIGINAL graph.
        //
        // Example:
        //      0 -> 1
        //      0 -> 2
        //
        // indegree[0] = 2
        //
        // We use this because a terminal node has
        // NO outgoing edges, so its value will be 0.
        vector<int> indegree(N, 0);


        // ------------------------------------------------
        // STEP 1: Create the reversed graph
        // ------------------------------------------------

        // Traverse every node of the ORIGINAL graph
        for(int i = 0; i < N; i++) {

            // 'it' is a neighbour of i in the original graph
            for(auto it : graph[i]) {

                // Original edge:
                //      i -> it
                //
                // Reverse it:
                //      it -> i
                //
                // Example:
                // Original:  0 -> 1
                // Reversed:  1 -> 0
                adj[it].push_back(i);


                // Count how many outgoing edges node i
                // has in the ORIGINAL graph.
                //
                // Every neighbour of i means one outgoing edge.
                indegree[i]++;
            }
        }


        // ------------------------------------------------
        // STEP 2: Find terminal nodes
        // ------------------------------------------------

        queue<int> q;

        for(int i = 0; i < N; i++) {

            // indegree[i] == 0 here means:
            //
            // node i had NO outgoing edges in the original graph.
            //
            // Therefore it is a TERMINAL NODE.
            //
            // Terminal nodes are always safe, so start BFS from them.
            if(indegree[i] == 0) {
                q.push(i);
            }
        }


        // Stores all eventual safe nodes
        vector<int> safeNodes;


        // ------------------------------------------------
        // STEP 3: BFS / Kahn's Algorithm
        // ------------------------------------------------

        while(!q.empty()) {

            // Take a safe node from the queue
            int node = q.front();
            q.pop();


            // This node is safe, so add it to our answer.
            safeNodes.push_back(node);


            // Because adj is the REVERSED graph,
            // adj[node] contains nodes that originally pointed
            // TO this safe node.
            //
            // Original:
            //      it -> node
            //
            // Reversed:
            //      node -> it
            for(auto it : adj[node]) {

                // One outgoing path of 'it' has now been
                // confirmed to lead towards a safe node.
                //
                // So remove that outgoing edge from consideration.
                indegree[it]--;


                // If it becomes 0, ALL outgoing paths from
                // this node have been removed/confirmed safe.
                //
                // Therefore 'it' is also an eventual safe node.
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }


        // The question expects safe nodes
        // in increasing order.
        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};
