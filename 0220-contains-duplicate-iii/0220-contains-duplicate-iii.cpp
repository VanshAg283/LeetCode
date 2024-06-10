#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                       int valueDiff) {
        ordered_set s;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > indexDiff) {
                s.erase({nums[i - indexDiff - 1], i - indexDiff - 1});
            }
            s.insert({nums[i], i});
            auto it = s.lower_bound({nums[i] - valueDiff, -1});
            while (it != s.end() && it->first <= nums[i] + valueDiff) {
                if (abs(it->second - i) <= indexDiff && it->second != i) {
                    return true;
                }
                ++it;
            }
        }
        return false;
    }
};