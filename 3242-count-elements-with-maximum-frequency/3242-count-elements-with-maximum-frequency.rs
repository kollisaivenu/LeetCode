impl Solution {
    pub fn max_frequency_elements(nums: Vec<i32>) -> i32 {
        let mut freq = [0; 100];

        for i in nums {
            freq[(i-1) as usize] += 1;
        }

        let mut most_freq = freq[0];
        let mut sum = 0;

        for i in 1..100 {
            if freq[i] > most_freq {
                most_freq = freq[i];
            }
        }

        for i in 0..100 {
            if freq[i] == most_freq {
                sum += most_freq;
            }
        }

        sum
    }
}