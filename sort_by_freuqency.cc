class Solution {
public:
    string frequencySort(string s) {
        std::unordered_map<char,int> m;
    for (auto c : s) {
        if (m.count(c)) {
            m[c] = m[c] + 1;
        } else {
            m[c] = 1;
        }
    }
    std::vector<std::vector<char>> v;
    for (auto p : m) {
        std::vector<char> vec;
        for (int i = 0; i < p.second; i++) {
            vec.push_back(p.first);
        }
        v.push_back(vec);
    }
    std::sort(v.begin(), v.end(), [](std::vector<char>& a, std::vector<char>& b) -> bool {
        return a.size() > b.size();
    });
    std::string ans;
    for (auto i : v) {
        for (auto character : i) {
            ans += character;
        }
    }
    return ans;        
    }
};