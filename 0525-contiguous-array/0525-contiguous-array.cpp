class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int max_length = 0;
    int count = 0;
    unordered_map<int, int> count_map; // Using unordered_map for O(1) lookup time

    count_map[0] = -1; // Initialize the hashmap with count 0 at index -1

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) {
            count -= 1;
        } else {
            count += 1;
        }

        if (count_map.find(count) != count_map.end()) { // If the count is already in the map
            max_length = max(max_length, i - count_map[count]);
        } else {
            count_map[count] = i; // If the count is not in the map, add it to the map with its index
        }
    }

    return max_length;
    }
};