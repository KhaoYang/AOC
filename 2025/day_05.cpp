// Source: https://usaco.guide/general/io

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<long long, long long>> ranges;
    vector<long long> nums;
    string line;

    while (getline(cin, line)) {
        if (line.empty() || line.find('-') == string::npos) {
            break;
        }
        
        size_t dash_pos = line.find('-');
        long long start = stoll(line.substr(0, dash_pos));
        long long end = stoll(line.substr(dash_pos + 1));
        ranges.push_back({start, end});
    }
    while (getline(cin, line)) {
        if (!line.empty()) {
            long long num = stoll(line);
            nums.push_back(num);
        }
    }
    sort(ranges.begin(), ranges.end());
    vector<pair<long long, long long>> merged;
    merged.push_back(ranges[0]);
    for(size_t i = 0; i < ranges.size(); i++){
        if(merged.back().second >= ranges[i].first){
            merged.back().second = max(merged.back().second, ranges[i].second);
        } else {
            merged.push_back(ranges[i]);
        }
    }
    long long count = 0;
    
    /* PART 1 */
    // for(size_t i = 0; i < nums.size(); i++){
    //     for(size_t j = 0; j < merged.size(); j++){
    //         if(nums[i] >= merged[j].first && nums[i] <= merged[j].second){
    //             count++;
    //             break;
    //         }
    //     }
    // }

    /* PART 2*/
    for(size_t i = 0; i < merged.size(); i++){
        count += merged[i].second - merged[i].first + 1;
    }
    cout << count;
    return 0;

}
