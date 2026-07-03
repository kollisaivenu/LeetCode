impl Solution {
    pub fn min_number_operations(target: Vec<i32>) -> i32 {
        let mut ans = target[0];

        for idx in 1..target.len() {
            if target[idx] > target[idx-1] {
                ans += (target[idx] - target[idx-1]);
            }
        }

        return ans;
    }
}