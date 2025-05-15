#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    inline bool exists(std::string& s, std::string& sub) {
    return s.substr(0,sub.size()) == sub;
}
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        std::vector<std::vector<std::string>> ans;
    for (int i = 1; i <= searchWord.size(); i++) {
        std::vector<std::string> v;
        std::string sub = searchWord.substr(0,i);
        for (auto word : products) {
            if (exists(word,sub)) {
                v.push_back(word);
            }
        }
        if (v.size() >= 3) {
            //sort lexicographically
            std::vector<std::string> d;
            std::sort(v.begin(),v.end());
           // std::vector<std::string> d;
            for (int i = 0; i < 3; i++) {
                d.push_back(v[i]);
            }
            ans.push_back(d);
        } else {
            std::sort(v.begin(),v.end());
            ans.push_back(v);
        }
    }
    return ans;
    }
};