impl Solution {
    pub fn minimum_distance(nums: Vec<i32>) -> i32 {
        let mut min_dist = usize::MAX;
        for i in 0..nums.len() {
            for j in i+1..nums.len() {
                for k in j+1..nums.len() {
                    if nums[i] == nums[j] && nums[j] == nums[k] {
                        min_dist = min_dist.min(2*k - 2*i);
                    }
                }
            }
        }

        min_dist as i32
    }
}