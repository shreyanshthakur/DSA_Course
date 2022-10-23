//Solution 1
bool haveConflict(vector<string>& e1, vector<string>& e2) {
        return e1[0] <= e2[1] && e2[0] <= e1[1];
}
//Solution 2
bool haveConflict(vector<string>& e1, vector<string>& e2) {
        return max(e1[0], e2[0]) <= min(e1[1], e2[1]);
    }
