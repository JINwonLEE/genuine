static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int rect_index;
    int len;
    vector<vector<int>> rect_list;
    vector<int> areas;
    int sum;
    Solution(vector<vector<int>>& rects) {
        rect_index = 0;
        sum = 0;
        len = rects.size();
        for (int i = 0; i < len; i++) {
            rect_list.push_back(rects[i]);
            sum += (rects[i][2] - rects[i][0] + 1 ) * (rects[i][3] - rects[i][1] + 1);
            areas.push_back(sum);
        }
    }
    
    vector<int> pick() {
        rect_index = getIndex();
        int x1 = rect_list[rect_index][0];
        int y1 = rect_list[rect_index][1];
        int x2 = rect_list[rect_index][2];
        int y2 = rect_list[rect_index][3];
        
        return(vector<int>{x1 + (rand() % (x2 - x1 + 1)), y1 + (rand() % (y2 - y1 + 1))});
    }
    
    int getIndex() {
        int tmp = rand() % sum + 1;
        int low = 0;
        int high = len - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (tmp > areas[mid]) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
