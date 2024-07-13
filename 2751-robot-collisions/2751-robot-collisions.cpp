class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<tuple<int, int, char, int>> robots;
        
        for (int i = 0; i < n; ++i) {
            robots.emplace_back(positions[i], healths[i], directions[i], i);
        }
        sort(robots.begin(), robots.end());
        
        stack<int> st;
        
        for (int i = 0; i < n; ++i) {
            int position = get<0>(robots[i]);
            int health = get<1>(robots[i]);
            char direction = get<2>(robots[i]);
            
            if (st.empty() || direction == 'R') {
                st.push(i);
            } else {
                while (!st.empty() && get<2>(robots[st.top()]) == 'R' && health > 0) {
                    int j = st.top();
                    int other_health = get<1>(robots[j]);
                    if (health > other_health) {
                        health -= 1;
                        get<1>(robots[j]) = 0;
                        st.pop();
                    } else if (health < other_health) {
                        get<1>(robots[j]) -= 1;
                        health = 0;
                    } else {
                        get<1>(robots[j]) = 0;
                        health = 0;
                        st.pop();
                    }
                }
                
                if (health > 0) {
                    st.push(i);
                    get<1>(robots[i]) = health;
                } else {
                    get<1>(robots[i]) = 0;
                }
            }
        }
        
        vector<int> ans(n, 0);
        for (const auto& robot : robots) {
            int health = get<1>(robot);
            int original_index = get<3>(robot);
            ans[original_index] = health;
        }

        vector<int> survived_healths;
        for (int h : ans) {
            if (h > 0) {
                survived_healths.push_back(h);
            }
        }
        
        return survived_healths;
    }
};