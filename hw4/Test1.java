package edu.iastate.cs228.hw4;

import java.io.FileNotFoundException;
import java.util.InputMismatchException;
/**
 * For test
 * @author yiranxu
 *
 */
public class Test1 {

	public static void main(String[] args) throws InputMismatchException, FileNotFoundException {
		ConvexHull cc=new ConvexHull(20);
		ConvexHull cc1=new ConvexHull("coordinates.txt");
		cc.lowestPoint();
		cc1.lowestPoint();
		cc.quickSort();
		cc.setUpScan();
		cc.GrahamScan();
		cc.hullToFile();
		cc.pointsToFile();
		cc1.quickSort();
		cc1.setUpScan();
		cc1.GrahamScan();
		//cc1.hullToFile();
		//cc1.pointsToFile();
		System.out.println(cc.toString());
		System.out.println(cc1.toString());
	}

}
