package edu.iastate.cs228.hw2;

import static org.junit.Assert.*;

import org.junit.Test;

public class OrderStatisticsTest {
	int[] arr={15,17,9,35,23,2,11,18,5,6};
	@Test
	public void testFindMinimum() {
		assertEquals(2,OrderStatistics.findMinimum(arr));
	}
	@Test
	public void testFindMaximum(){
		assertEquals(35,OrderStatistics.findMaximum(arr));
	}
	@Test
	public void testSelect2order(){
		assertEquals(18,OrderStatistics.select(arr, 3, 7, 3 ));
	}
	@Test
	public void testSelect2order2(){
		assertEquals(9,OrderStatistics.select(arr, 2, 6, 2));
	}
	@Test
	public void testFindOrderStatistics1(){
		assertEquals(2,OrderStatistics.findOrderStatistic(arr,1));
	}
	@Test
	public void testFindOrderStatistics2(){
		assertEquals(5,OrderStatistics.findOrderStatistic(arr, 2));
	}
	@Test
	public void testFindOrderStatistics3(){
		assertEquals(6 ,OrderStatistics.findOrderStatistic(arr, 3));
	}
	@Test
	public void testFindOrderStatistics4(){
		assertEquals(9 ,OrderStatistics.findOrderStatistic(arr, 4));
	}
	@Test
	public void testFindMedian(){
		assertEquals(11,OrderStatistics.findMedian(arr));
	}
	
}