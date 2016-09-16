package edu.iastate.cs228.hw2;

public class QuantilesTest2 {

	public static void main(String[] args) {
		int[] arr={15,17,9,35,23,2,11,18,5,6};
		Quantiles q1=new Quantiles(arr,3);
		System.out.println(q1.getQuantile(1));
	}

}
