class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int pos_x = 0;
        int pos_y = height.size() - 1;
        
        int sum = 0;
        
        while (pos_x < pos_y) {
            int height_x = height[pos_x];
            int height_y = height[pos_y];
            
            int wid = pos_y - pos_x;
            int hei = height_x < height_y ? height_x : height_y;
            if (sum < wid * hei) {
                sum = wid * hei;
            }
            
            if (height_x < height_y) {
                pos_x++;
            } else {
                pos_y--;
            }
        }
        
        return sum;
    }
};
