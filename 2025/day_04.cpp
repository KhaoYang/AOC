#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
static const int dirs[8][2] = {{1,0}, {0,1},
                               {-1,0}, {0,-1},
                               {1,1}, {1,-1},
                               {-1, -1}, {-1, 1}};
int main() {
	vector<vector<char>> grid;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        vector<char> row;
        row.reserve(line.size());
        for (char c : line) {
            row.push_back(c);  
        }
        grid.push_back(row);
    }
    int result = 0;
    bool removed = true;
    while(removed){
        int change = 0;
        for(size_t i = 0; i < grid.size(); i++){
            for(size_t j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '@'){
                    int count = 0;
                    for(size_t k = 0; k < 8; k++){
                        size_t ix = i + dirs[k][0];
                        size_t jx = j + dirs[k][1];
                        if(ix >= 0 && jx >= 0 && ix < grid.size() && jx < grid[i].size() && grid[ix][jx] == '@'){
                            count++;
                        }
                    }
                    if(count < 4) {
                        change++;
                        grid[i][j] = '.';
                    }
                }
            }
        }
        if(change == 0) break;
        else result += change;
    }
    cout << result;
    return 0;
}
