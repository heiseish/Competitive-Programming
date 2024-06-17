impl Solution {
	pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
		if nums1.len() > nums2.len() {
			Solution::find_median_sorted_arrays_impl(&nums2[..], &nums1[..])
		} else {
			Solution::find_median_sorted_arrays_impl(&nums1[..], &nums2[..])
		}

	}

	pub fn find_median_sorted_arrays_impl(nums1: &[i32], nums2: &[i32]) -> f64 {
		let n = nums1.len();
		let m = nums2.len();

		let mut start = 0;
		let mut end = n;
		let mut hi = (n + m + 1) / 2;

		while start <= end {
			let mid = (start + end) / 2;
			let las = mid;
			let lbs = hi - mid;
			let la = {
				if las > 0 {
					nums1[las - 1]
				} else {
					i32::MIN
				}
			};
			let lb = {
				if lbs > 0 {
					nums2[lbs - 1]
				} else {
					i32::MIN
				}
			}

			let ra = {
				if las < n {
					nums1[las]
				} else {
					i32::MAX
				}
			};
			let rb = {
				if lbs < m {
					nums2[lbs]
				} else {
					i32::MAX
				}
			}

			if la <= rb && rb <= ra {
				if (m + n) % 2 == 0 {
					return (la.max(lb) + ra.min(rb)) as f64 / 2.0;
				}
				return la.max(lb) as f64;
			} else if la > rb {
				end = mid - 1;
			} else {
				start = mid + 1;
			}

		}
		0.0
	}
}
