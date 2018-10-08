static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int lengthOfLongestSubstring(const string s) {
        unordered_map<char,int> hash_str;
        auto size = s.size();
        decltype(s.size()) len = 0;
        
        for  (decltype(s.size()) i = 0,j = 0; j < size; j++)
        {
            if(hash_str.count(s[j]) && hash_str[s[j]] >= i) 
                i = hash_str[s[j]] + 1;
            hash_str[s[j]] = j;
            len = max(j - i + 1,len);   
        }       
        return len;
    }
};

