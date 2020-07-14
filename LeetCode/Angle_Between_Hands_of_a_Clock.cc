class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_angle = hour * 30 + minutes * 0.5;
        double minutes_angle = 6 * minutes;
        double angle = minutes_angle - hour_angle > 0 ? minutes_angle - hour_angle : hour_angle - minutes_angle; 
        return min(angle, 360 - angle);
    }
};
