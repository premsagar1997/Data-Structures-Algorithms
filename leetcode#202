class Solution {
public:
    bool isHappy(int n) {
       unordered_set<int> st;
        while (n != 1) {
            int res = 0;
            while (n != 0) {
                res += (n % 10 ) * (n % 10);
                n /= 10;
            }
            
            if (st.find(res) != st.end())
                return false;
            
            st.insert(res);
            n = res;
        }
        return true;
    }
};
