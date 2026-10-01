class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {

        bool seen[1001] = {false};
        std::vector<int> result;

        for (int num : nums1) {
            seen[num] = true;
        }

        for (int num : nums2) {
            if (seen[num] == true) {
                result.push_back(num);
                seen[num] = false; 
            }
        }
        
        return result;
    }
};
