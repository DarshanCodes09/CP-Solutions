class Solution {
public:
    const long long MOD1 = 1000000007;
    const long long MOD2 = 1000000009;
    const long long BASE1 = 100019;
    const long long BASE2 = 100043;

    bool check(vector<int>& nums, int len) {
        int n = nums.size();

        long long pow1 = 1, pow2 = 1;
        for (int i = 0; i < len; i++) {
            pow1 = (pow1 * BASE1) % MOD1;
            pow2 = (pow2 * BASE2) % MOD2;
        }

        long long h1 = 0, h2 = 0;

        for (int i = 0; i < len; i++) {
            h1 = (h1 * BASE1 + nums[i]) % MOD1;
            h2 = (h2 * BASE2 + nums[i]) % MOD2;
        }

        unordered_map<long long, int> freq;

        long long key = h1 * MOD2 + h2;
        freq[key]++;

        for (int i = len; i < n; i++) {
            h1 = (h1 * BASE1 + nums[i]
                  - (pow1 * nums[i - len]) % MOD1 + MOD1) % MOD1;

            h2 = (h2 * BASE2 + nums[i]
                  - (pow2 * nums[i - len]) % MOD2 + MOD2) % MOD2;

            key = h1 * MOD2 + h2;
            freq[key]++;
        }

        for (auto it : freq) {
            if (it.second == 1) return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int low = 1;
        int high = nums.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(nums, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
