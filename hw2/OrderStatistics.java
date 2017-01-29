package edu.iastate.cs228.hw2;

import java.util.Random;

/**
 * A class used to generate order statistics of datasets
 * 
 * @author jennyxu
 */
public class OrderStatistics {

	/**
	 * Returns the minimum element (first order statistic) in array arr. This
	 * method must run in worst-case O(n) time, where n = arr.length, using a
	 * linear scan of the input array.
	 * 
	 * @param arr
	 *            - The data to search
	 * @return - the minimum element of arr
	 */
	public static int findMinimum(int[] arr) {
		int minIndex = 0;
		for (int j = 1; j < arr.length; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		return arr[minIndex];
	}

	/**
	 * Returns the maximum element (first order statistic) in array arr. This
	 * method must run in worst-case O(n) time, where n = arr.length, using a
	 * linear scan of the input array.
	 * 
	 * @param arr
	 *            - The data to search
	 * @return - the maximum element of arr
	 */
	public static int findMaximum(int[] arr) {
		int maxIndex = 0;
		for (int j = 1; j < arr.length; j++) {
			if (arr[j] > arr[maxIndex]) {
				maxIndex = j;
			}
		}
		return arr[maxIndex];
	}

	/**
	 * An implementation of the SELECT algorithm of Figure 1 of the project
	 * specification. Returns the ith order statistic in the subarray
	 * arr[first], ..., arr[last]. The method must run in O(n) expected time,
	 * where n = (last - first + 1).
	 * 
	 * @param arr
	 *            - The data to search in
	 * @param first
	 *            - The leftmost boundary of the subarray (inclusive)
	 * @param last
	 *            - The rightmost boundary of the subarray (inclusive)
	 * @param i
	 *            - The requested order statistic to find
	 * @return - The ith order statistic in the subarray
	 * 
	 * @throws IllegalArgumentException
	 *             - If i < 1 or i > n
	 */
	public static int select(int[] arr, int first, int last, int i) {
		if (i < 1 || i > arr.length) {
			throw new IllegalArgumentException();
		}
		if (first == last) {
			return arr[first];
		}
		int p = partition(arr, first, last);
		int k = p - first + 1; // computes the number k of elements in
								// arr[first],...,arr[p]
		// check if the pivot arr[p] is the ith order statistics.If so, it
		// returns arr[p]. Otherwise, check the conditions to determine which of
		// the two sub-arrays contains the ith order statistic
		if (i == k) {
			return arr[p];
		} else if (i < k) { // the ith smallest element must be the ith order
							// statistic among arr[first],...,arr[p-1]
			return select(arr, first, p - 1, i);
		} else { // the element we are looking for is in sub-array
					// arr[p+1],...,arr[last]
			return select(arr, p + 1, last, i - k);
		}
	}

	/**
	 * Helper Method of partition the array arr into two (possibly
	 * empty)sub-arrays arr[first],...,arr[p-1] and arr[p+1],...,arr[last] such
	 * that each element in arr[first],...,arr[p-1] is less than or equal to
	 * arr[p] and each element in arr[p+1],...,arr[last] is greater than or
	 * equal to arr[p]. arr[p] is the pivot
	 * 
	 * @param arr
	 *            - The data to search in
	 * @param first
	 *            - The leftmost boundary of the subarray (inclusive)
	 * @param last
	 *            - The rightmost boundary of the subarray (inclusive)
	 * @return -the pivot number
	 */
	private static int partition(int[] arr, int first, int last) {
		// Randomly select a pivot 
		Random rand=new Random();
		int position=rand.nextInt(last-first+1)+first;
		int pivot = arr[position];
		swap(arr,position,last);
		int i = first - 1;
		for (int j = first; j <= last-1 ; j++) {
			if (arr[j] <= pivot) {
				i++;
				swap(arr, i, j); // Move the element less than pivot to the
									// block where number are less than pivot
			}
		}
		// Put the pivot into the position i+1
		swap(arr, i + 1, last);
		return i + 1; // return the position where the pivot number is such that
						// every number before the pivot is less than the pivot,
						// every number after the pivot is larger than the pivot

	}

	/**
	 * Helper method to swap two elemnets in the array
	 * 
	 * @param array
	 * @param i
	 *            -position of the first element
	 * @param j
	 *            -position of the second element
	 */
	private static void swap(int[] array, int i, int j) {
		int tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}

	/**
	 * Returns the ith order statistic of array arr in O(n) expected time, where
	 * n = arr.length.
	 * 
	 * @param arr
	 *            - The data to search through
	 * @param i
	 *            - The requested order statistic to find in arr
	 * @return - The ith order statistic in arr
	 * 
	 * @throws IllegalArgumentException
	 *             - If i < 1 or i > n
	 */
	public static int findOrderStatistic(int[] arr, int i) {
		if (i < 1 || i > arr.length) {
			throw new IllegalArgumentException();
		}
		return select(arr, 0, arr.length - 1, i);
	}

	/**
	 * Returns the median (n/2th order statistic rounding up) in array arr in
	 * O(n) expected time, where n = arr.length.
	 * 
	 * @param arr
	 *            - The array to find the median of
	 * @return - The median value of arr
	 */
	public static int findMedian(int[] arr) {
		int n = arr.length;
		//return ceiling of n/2
		if (n % 2 == 0) { 
			int median = n / 2;
			return select(arr, 0, arr.length - 1, median);
		} else {
			int median = (n + 1) / 2;
			return select(arr, 0, arr.length - 1, median);
		}

	}
}

