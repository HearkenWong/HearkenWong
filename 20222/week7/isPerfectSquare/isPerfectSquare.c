class Solution {
public:
    bool isPerfectSquare(int num) {
        long x = 1, square = 1;
        while (square <= num) {
            if (square == num) {
                return true;
            }
            ++x;
            square = x * x;
        }
        return false;
    }
};

