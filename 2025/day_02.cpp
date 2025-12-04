#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string input;
    getline(cin, input); 

    vector<pair<long long, long long>> ranges;
    vector<vector<int>> blocks = {{}, {}, {1}, {1}, {1,2}, {1}, {1,2,3}, {1}, {1,2,4}, {1,3}, {1,2,5}};
    stringstream ss(input);
    string token;

    while (getline(ss, token, ',')) {
        long long L, R;
        sscanf(token.c_str(), "%lld-%lld", &L, &R);
        ranges.emplace_back(L, R);
    }
    long long total = 0;
    
    /*  PART 1 */
    // for(size_t i = 0; i < ranges.size(); i++){
    //     long long start = ranges[i].first;
    //     long long end = ranges[i].second;
    //     for(long long j = start; j <= end; j++){
    //         string num = to_string(j);
    //         if(num.size() % 2 == 0){
    //             if(num.substr(0, num.size() / 2) == num.substr(num.size()/2)){
    //                 total += j;
    //             }
    //         }
    //     }
    // }
    
    /* PART 2 */
    for(size_t i = 0; i < ranges.size(); i++){
        long long start = ranges[i].first;
        long long end = ranges[i].second;
        for(long long j = start; j <= end; j++){
            string num = to_string(j);
            for(int k = 0; k < blocks[num.size()].size(); k++){
                bool valid = true;
                int index = 0;
                while(index < num.size()){
                    if(num.substr(0, blocks[num.size()][k]) != num.substr(index, blocks[num.size()][k])){
                        valid = false;
                        break;
                    }
                    index += blocks[num.size()][k];
                }
                if(valid){
                    total += j;
                    break;
                }
            }
        }
    }
    cout << total;
    return 0;
}
