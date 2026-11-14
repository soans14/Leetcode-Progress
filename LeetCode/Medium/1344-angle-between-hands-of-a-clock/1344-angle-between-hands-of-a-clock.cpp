class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ha,ma;
        ha=(hour%12)*30+minutes*0.5;
        ma=minutes*6.0;
        return abs(ha-ma)<=180?abs(ha-ma):360-abs(ha-ma);
    }
};