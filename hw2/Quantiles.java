package edu.iastate.cs228.hw2;

import java.util.Arrays;

/**
 * A class for generating and analyzing q-quantiles of datasets
 * 
 * @author jennyxu
 */
public class Quantiles {

	/* Variables to store the quantiles, size of the data, totals, etc */

	/* NOTE: Do not store the original data */
	private int n;// the length of the original data array
	private int q;// the number of quantiles
	private int[] quantiles;// stores the q-1 q-quantiles
	private int topTotal; // Total sum of the elements in the top quartile
							// groups
	private int bottomTotal; // Total sum of the elements in the bottom quartile
								// groups

	/**
	 * A constructor that creates a new Quantiles object, whose quantiles array
	 * has length q - 1, and contains the q-quantiles of the data array. The
	 * expected time complexity of this method must be O(n 閿燂拷 q), or better,
	 * where n = data.length.
	 * 
	 * @param data
	 *            - The integers to split into q-quantiles
	 * @param q
	 *            - The number of q-quantiles to create
	 * 
	 * @throws IllegalArgumentException
	 *             - If q < 1 or if q > n
	 */
	public Quantiles(int[] data, int q) {
		n = data.length;
		if (q <= 1 || q > n) {
			throw new IllegalArgumentException();
		}
		this.q = q;
		quantiles = new int[q - 1];
		for (int i = 1; i <= q - 1; i++) {
			int order = (int) Math.ceil((i * n * 1.0) / (q * 1.0));
			quantiles[i - 1] = OrderStatistics.select(data, 0, n - 1, order);
		}
		for (int i = 0; i < n; i++) {
			if (data[i] > quantiles[q - 2]) {
				topTotal += data[i];
			}
		}
		for(int i=0;i<n;i++){
			if(data[i]<=quantiles[0]){
				bottomTotal+=data[i];
			}
		}
	}

	/**
	 * A constructor that creates a new Quantiles object, whose quantiles array,
	 * has length three, and is initialized to contain the three quantiles of
	 * data. The expected time complexity of this method must be O(n), where n =
	 * data.length.
	 * 
	 * @param data
	 *            - The integers to split into q-quantiles
	 * @throws IllegalArgumentException
	 *             - If n < 4
	 */
	public Quantiles(int[] data) {
		n = data.length;
		q = 4;
		if (n < 4) {
			throw new IllegalArgumentException();
		}

		quantiles = new int[3];
		for (int i = 1; i <= 3; i++) {
			int order = (int) Math.ceil((i * n * 1.0) / (4 * 1.0));
			quantiles[i - 1] = OrderStatistics.select(data, 0, n - 1, order);
		}
		for (int i = 0; i < n; i++) {
			if (data[i] > quantiles[2]) {
				topTotal += data[i];
			}
		}
		for(int i=0;i<n;i++){
			if(data[i]<=quantiles[0]){
				bottomTotal+=data[i];
			}
		}
	}

	/**
	 * An optional constructor that creates a new Quantiles object, whose
	 * quantiles array has length q - 1, and is initialized to contain the
	 * q-quantiles of the data array.
	 * 
	 * If fast is true, then the expected time complexity of this method must be
	 * O(n log q), where n = data.length, where n = data.length (for this, you
	 * must implement the method such as the one outlined in Section 2.2.
	 * 
	 * If fast is false, then the expected time complexity of this method is
	 * only required to be O(n 閿燂拷 q), but may be faster
	 * 
	 * @param data
	 *            - The integers to split into q-quantiles
	 * @param q
	 *            - The number of q-quantiles to create
	 * @param fast
	 *            - Flag to request a O(n log q) construction
	 * 
	 * @throws IllegalArgumentException
	 *             - If q < 1 or if q > n
	 */
	public Quantiles(int[] data, int q, boolean fast) {
		if(q>=1 ||q>n){
			throw new IllegalArgumentException();
		}
		n = data.length;
		this.q = q;
		quantiles = new int[q - 1];
		int first=1;
		int last=n-1;
		help(data,first,last);
		
	}
	/**
	 * Helper method for the third constructor
	 * @param data
	 * @param first
	 * @param last
	 */

	private void help(int[] data,int first, int last){
		if(first>=last){
			return ;
		}
		int k=(int) Math.ceil((q-1)/ 2.0);
		int mid=OrderStatistics.select(data, first, last, k);
		
		quantiles[k]=mid;
		
		help(data,first,k-1);
		help(data,k+1,last);
	}
	/**
	 * Returns the k-th q-quantile of this object. This method must take O(1)
	 * time in the worst case.
	 * 
	 * @param k
	 *            - Specifies which q-quantile to return
	 * @return - The k-th q-quantile
	 * 
	 * @throws IllegalArgumentException
	 *             - If k < 1 or k is greater than the number of quantiles of
	 *             this object
	 */
	public int getQuantile(int k) {
		if (k < 1 || k > q - 1) {
			throw new IllegalArgumentException();
		}
		return quantiles[k - 1];

	}

	/**
	 * Returns the number of quantiles in this object. This method must take
	 * O(1) time in the worst case.
	 * 
	 * @return - The number of quantiles in this object
	 */
	public int getQ() {
		return q - 1;
	}

	/**
	 * Returns the index of the quantile group that contains x:
	 * 
	 * - If x is less than or equal to the first quantile, then return 1.
	 * 
	 * - If x is strictly greater than the last quantile (quantile q - 1), then
	 * return q.
	 * 
	 * - Otherwise, return the smallest index k such that x is less than or
	 * equal to the k-th q- quantile.
	 * 
	 * This method must take O(log k) time in the worst case.
	 * 
	 * @param x
	 *            - The item to find the quantile of
	 * @return - The quantile containing x as described above
	 */
	public int quantileQuery(int x) {
		if (x <= quantiles[0]) {
			return 1;
		} else if (x > quantiles[q - 2]) {
			return q;
		} else {
			int left = 1;
			int right = q - 1;
			while (left <= right) {
				int mid = (int) Math.ceil((left + right) / 2.0);
				if (quantiles[mid - 1] >= x) {
					if (quantiles[mid - 2] < x) {
						return mid;
					}
					right = mid - 1;
				}
				if (quantiles[mid - 1] < x) {
					if (quantiles[mid] >= x) {
						return mid + 1;
					}
					left = mid + 1;
				}
			}
			return right;
		}
	}

	/**
	 * Returns the sum of all values that are strictly higher than the (q - 1)th
	 * q-quantile in the original data array. This method must take O(1) time in
	 * the worst case.
	 * 
	 * @return - sum of all values that are strictly higher than the (q - 1)th
	 *         q-quantile
	 */
	public int getTopTotal() {
		return topTotal;
	}

	/**
	 * Returns the sum of all vales that are smaller than or equal to the first
	 * quantile in the original data array. This method must take O(1) time in
	 * the worst case.
	 * 
	 * @return - the sum of all vales that are smaller than or equal to the
	 *         first quantile
	 */
	public int getBottomTotal() {
		return bottomTotal;
	}

	/**
	 * Returns the ratio of getTopTotal() to getBottomTotal() for this object.
	 * This method must take O(1) time in the worst case.
	 * 
	 * @return - the ratio
	 */
	public float ineqRatio() {
		return (float)topTotal/bottomTotal;
	}

	/**
	 * Returns the length of the original data array. This method must take O(1)
	 * time in the worst case.
	 * 
	 * @return - the size of the original data array
	 */
	public int size() {
		return n;
	}

	/**
	 * Overrides the toString() method, returning a String in the format given
	 * on page 6 of the project specifications.
	 * 
	 * @return - the String representation of this object
	 */
	@Override
	public String toString() {
		return n+", "+q+", "+Arrays.toString(quantiles)+", "+topTotal+", "+bottomTotal+'\n';
	}
}
