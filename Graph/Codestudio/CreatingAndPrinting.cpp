vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<vector<int>> v(n);
    for(int i=0;i<n;i++){
        v[i].push_back(i);
    }
    for(int i=0;i<m;i++){
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
    }
    return v;
}