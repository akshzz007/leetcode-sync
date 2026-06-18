class Solution {
public:
    double angleClock(int hour, int minutes) {

        // 12 ko 0 treat karo
        if (hour == 12)
            hour = 0;

        // Minute hand angle
        double minuteAngle = minutes * 6;

        // Hour hand angle
        double hourAngle = (hour * 30) + (minutes * 0.5);

        // Difference between both hands
        double angle = abs(hourAngle - minuteAngle);

        // Smaller angle return karo
        return min(angle, 360 - angle);
    }
};