class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> m;
    for (auto i : nums) {
        if (m.count(i)) {
            m[i] = m[i] + 1;
        } else {
            m[i] = 1;
        }
    }

    std::vector<std::vector<int>> vec;
    for (auto p : m) {
        std::vector<int> v;
        for (int i = 0; i < p.second; i++) {
            v.push_back(p.first);
        }
        vec.push_back(v);
    }
    std::sort(vec.begin(),vec.end(),[](const std::vector<int>& a, const std::vector<int>& b) -> int {
        return a.size() < b.size();
    });
    int i = 0;
    std::vector<int> ans;
    for (int j = vec.size() - 1; j >= 0 && i < k; j--) {
        ans.push_back(vec[j][0]);
        i++;
    }
    return ans;    
    }
};