class Solution {
public:
    bool checkCycleInDirectedGraph(int src, unordered_map<int, bool>& visited,
                                   unordered_map<int, bool>& DFScallVisited,
                                   vector<vector<int>>& graph) {
        // O(V+E)
        visited[src] = true;
        DFScallVisited[src] = true; // cycle

        // dfs
        for (auto& nbr : graph[src]) {
            if (!visited[nbr]) {
                bool aageKaAns = checkCycleInDirectedGraph(
                    nbr, visited, DFScallVisited, graph);
                if (aageKaAns)
                    return true;
            }
            // check-cycle logic
            if (visited[nbr] == true && DFScallVisited[nbr] == true)
                return true;
        }

        DFScallVisited[src] = false; // backtrack****jb call wapas hogi to pop
                                     // ho gyi call stack se

        // agar phle return true nhi hua to last m

        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, bool> DFScallVisited;
        unordered_map<int, bool> visited;

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                checkCycleInDirectedGraph(i, visited, DFScallVisited, graph);
        }
        vector<int> safeNodes;

        for (int i = 0; i < n; i++) {
            if (DFScallVisited[i] ==
                false) // iska matlb cycle nhi h iss node se jura..to ye safe
                       // node hua***...nhi to agar cycle jua hota iss node se
                       // to true hota already aur cycle wala nodes kbhi safe
                       // node nhi ho skta***
                safeNodes.push_back(i);
        }

        return safeNodes;
    }
};