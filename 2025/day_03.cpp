#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

int main() {
	vector<vector<int>> grid;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        vector<int> row;
        row.reserve(line.size());
        for (char c : line) {
            if (isdigit(c)) {
                row.push_back(c - '0');  
            }
        }
        grid.push_back(row);
    }
    long long total = 0;

    /* PART 1 */
    // for(size_t i = 0; i < grid.size(); i++){
    //     size_t n = grid[i].size();
    //     int largest = grid[i][n - 2]; 
    //     int second = grid[i][n - 1];
    //     for(int j = n - 3; j >= 0; j--){
    //         if(grid[i][j] >= largest){
    //             second = max(second, largest);
    //             largest = grid[i][j];
    //         }
    //     }
    //     total += largest * 10 + second;
    // }

    /* PART 2 */
    for(size_t i = 0; i < grid.size(); i++){
        size_t n = grid[i].size();
        int totalNums = 1;
        stack<long long> st;
        st.push(grid[i][0]);
        for(size_t j = 1; j < n; j++){
            if(grid[i][j] > st.top()){
                int k = (int)st.size();
                while(!st.empty() && grid[i][j] > st.top() && j + 12 - k < n){
                    st.pop();
                    k--;
                }
                st.push(grid[i][j]);
                totalNums = (int)st.size();
            } else {
                if(totalNums < 12){
                    st.push(grid[i][j]);
                    totalNums++;
                }
            }
        }
        long long factor = 1;
        while(!st.empty()){
            total += factor * st.top();
            st.pop();
            factor *= 10;
        }
    }
    cout << total;
    return 0;

}
