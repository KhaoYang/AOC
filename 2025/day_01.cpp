#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	vector<string> v;
    string s;
    while (cin >> s) { 
        v.push_back(s);
    }
    int count = 0;
    int num = 50;
    for(size_t i = 0; i < v.size(); i++){
        int rot = stoi(v[i].substr(1));
        if(v[i][0] == 'R'){
            count += rot / 100;
            rot = rot % 100;
            int prevNum = num;
            num = num + rot;
            if(prevNum < 100 && num > 100) count++;
            num = num % 100;
        } else if(v[i][0] == 'L'){
            count += rot / 100;
            rot = rot % 100;
            int prevNum = num;
            num -= rot;
            if(prevNum > 0 && num < 0) count++;
            if(num < 0){
                num += 100;
            }
        }
        if(num == 0) count++;
    }
    cout << count;
    return 0;
}
