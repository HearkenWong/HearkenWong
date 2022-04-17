class Solution {
public:
    int guessNumber(int n) {
        return (size_t)partition_point((bool*)1, (bool*)n, [] (const bool& i) {
            return guess(size_t(&i)) == 1;
        });
    }
};
