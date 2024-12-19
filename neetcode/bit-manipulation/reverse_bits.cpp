/*
runtime: O(32)
space: O(32)
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<bool> bits(32);
        for (int i = 0; i < 32; i++) {
            // Extract bit at each index.
            int mask = 1 << i;
            bits[i] = n & mask;
        }

        int ans = 0;
        for (int i = 0; i < 32; i++) {
            // Place bit at reversed index.
            int mask = bits[i] << (32 - 1 - i);
            ans |= mask;
        }
        return ans;
    }
};
