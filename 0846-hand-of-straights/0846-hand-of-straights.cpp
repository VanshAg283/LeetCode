class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        sort(hand.begin(), hand.end());
        map<int,int> m;
        int div = hand.size() / groupSize;
        for (int i = 0; i < hand.size(); ++i) {
            m[hand[i]]++;
            if (m[hand[i]] > div) {
                return false;
            }
        }

        // vector<int> unique;
        // for (auto& i : m) {
        //     unique.push_back(i.first)
        // }
        auto it = m.begin();
        for (int i = 0; i < div; ++i) {
            if (it != m.end()) {
                if (it->second > 0) {
                    it->second--;
                    int ct = 1;
                    auto it2 = next(it);
                    auto prev = it;
                    while (ct < groupSize) {
                        if (it2 != m.end()) {
                            if (it2->first == prev->first + 1 && it2->second > 0) {
                                it2->second--;
                                prev = it2;
                                it2 = next(it2);
                                ct++;
                            } else {
                                return false;
                            }
                        } else {
                            return false;
                        }
                    }
                } else {
                    it = next(it);
                    i--;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};