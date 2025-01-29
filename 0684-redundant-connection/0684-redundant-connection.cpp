class Solution {
public:
    bool hasCycle(vector<vector<int>>&adjList,int src,int n){
        queue<pair<int,int>>q;
        vector<bool>vis(n+1,false);
        q.push({src,-1});
        vis[src]=true;
        while(!q.empty()){
            auto [node,parent]=q.front();
            q.pop();
            for(auto x:adjList[node]){
                if(!vis[x]){
                    vis[x]=true;
                    q.push({x,node});
                }else{
                    if(x!=parent){
                        return true;
                    }
                }
            }
        }
        return false;;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adjList(n+1);
        for(auto v:edges){
            int src=v[0],dest=v[1];
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
            if(hasCycle(adjList,src,n)) return v;
        }
        return {};
    }
};