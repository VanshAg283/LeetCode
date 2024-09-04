class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> obs;
        for (auto& i : obstacles) {
            pair<int,int> p;
            p.first = i[0];
            p.second = i[1];
            obs.insert(p);
        }
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int curr = 0;
        int x = 0;
        int y = 0;
        int dist = 0;
        for (int i = 0; i < commands.size(); ++i) {
            if (commands[i] == -1) {
                curr = (curr + 1) % 4;
            } else if (commands[i] == -2) {
                curr = (curr + 3) % 4;
            } else {
                for (int j = 0; j < commands[i]; ++j) {
                    if (obs.find({x + dir[curr][0], y + dir[curr][1]}) != obs.end()) {
                        break;
                    }
                    x = x + dir[curr][0];
                    y = y + dir[curr][1];
                }
                cout << "(" << x << ", " << y << ")" << endl; 
                dist = max(dist, x*x + y*y);
            }
        }
        return dist;
    }
};