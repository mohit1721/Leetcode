class Solution {
public:
int n;
void solve(string &tiles,int curr, vector<bool>&used, unordered_set<string>&result,string &possibleSequence){

 result.insert(possibleSequence);

// loop
for(int i=0;i<n;i++)
{
    if(used[i]==true) continue; //not re-use
    // do
    used[i] = true;
    possibleSequence.push_back(tiles[i]);
    // explore
    solve(tiles, curr+1,used, result, possibleSequence);
    // undo
    used[i]=false;
    possibleSequence.pop_back();
}


}

    int numTilePossibilities(string &tiles) {
        // similar to subsets...KHANDANI BACKTRACK PROBLEM
        // just TREE DIAGRAM & For loop needed to be focused..*

        // FOR LOOP -> 2 pattern abhi tk encounter kiye h,,ek susets jo sirf forward hoga uske liye itr -> i+1 se n
        // 2nd jo iss proble m h.. itr hmesa 0 -> n ...goga...taki agar ABC mila h to iska CBA bhi mile***


        // VVI points to note above,,,
        n = tiles.length();
        unordered_set<string>result;
        string possibleSequence="";
        vector<bool>used(n , false);
        solve(tiles,0, used ,result, possibleSequence);

        return result.size() - 1; //not include emptty string



    }
};