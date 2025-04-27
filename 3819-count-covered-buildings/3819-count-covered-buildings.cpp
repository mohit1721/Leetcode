class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // rowBuildings[x] => x row mein kaunse y positions par building hai
        map<int, set<int>> rowBuildings;
        // colBuildings[y] => y column mein kaunse x positions par building hai
        map<int, set<int>> colBuildings;

        // Step 1: Sare buildings ko row-wise aur column-wise store kar lo
        for (auto& building : buildings) {
            int x = building[0];
            int y = building[1];
            rowBuildings[x].insert(y);
            colBuildings[y].insert(x);
        }

        int coveredCount = 0;

        // Step 2: Har building ke liye check karo 4 directions mein building hai ya nahi
        for (auto& building : buildings) {
            int x = building[0];
            int y = building[1];

            // ----- Left aur Right check karne ke liye -----
            auto itRow = rowBuildings[x].lower_bound(y);
            // Lower_bound y wale point par iterator laayega
            // Check if there is a building to the LEFT
            bool hasLeftBuilding = (itRow != rowBuildings[x].begin());
            // Check if there is a building to the RIGHT
            bool hasRightBuilding = (next(itRow) != rowBuildings[x].end());

            // ----- Up aur Down check karne ke liye -----
            auto itCol = colBuildings[y].lower_bound(x);
            // Lower_bound x wale point par iterator laayega
            // Check if there is a building ABOVE (upar)
            bool hasUpperBuilding = (itCol != colBuildings[y].begin());
            // Check if there is a building BELOW (neeche)
            bool hasLowerBuilding = (next(itCol) != colBuildings[y].end());

            // ----- Final check: Agar 4on direction mein koi building hai -----
            if (hasLeftBuilding && hasRightBuilding && hasUpperBuilding && hasLowerBuilding) {
                coveredCount++;
            }
        }

        return coveredCount;
    }
};
