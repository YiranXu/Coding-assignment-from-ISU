package edu.iastate.cs228.hw5;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

/**
 * 
 * @author David Montealegre
 *
 */


public class SPTSetTest {

	//Checks if add() splays every entry
	@Test
	public void AddTest() {
		SplayTreeSet<Integer> spl = new SplayTreeSet<Integer>();
		spl.add(5);
		spl.add(3);
		spl.add(4);
		Integer res = spl.getRoot().getData();
		Integer ans = 4;
		assertEquals(ans, res);
	}
	
	//Tries the getRoot() method
	@Test
	public void GetRootTest() {
		SplayTreeSet<Integer> spl = new SplayTreeSet<Integer>();
		spl.add(5);
		Integer res = spl.getRoot().getData();
		Integer ans = 5;
		assertEquals(ans, res);
	}
	
	//Tries to find the first entry
	@Test
	public void findEntryTest1() {
		SplayTreeSet<Integer> spl = new SplayTreeSet<Integer>();
		spl.add(5);
		spl.add(3);
		spl.add(4);
		Integer res = spl.findEntry((Integer)5).getData();
		Integer ans = 5;
		assertEquals(ans, res);
	}
	
	//Tries to find something that isn't there
	@Test
	public void findEntryTest2() {
		SplayTreeSet<Integer> spl = new SplayTreeSet<Integer>();
		spl.add(5);
		spl.add(3);
		spl.add(4);
		Node<Integer> res = spl.findEntry((Integer)6);
		Node<Integer> ans = null;
		assertEquals(ans, res);
	}
	
	//Looks for the entry
	@Test
	public void ContainsTest1() {
		SplayTreeSet<Integer> spl = new SplayTreeSet<Integer>();
		spl.add(5);
		Integer con = 5;
		boolean res = spl.contains(con);
		boolean ans = true;
		assertEquals(ans, res);
	}
	
	//looks for something that isn't there
	@Test
	public void ContainsTest2() {
		SplayTreeSet<Integer> spl = new SplayTreeSet<Integer>();
		spl.add(5);
		Integer con = 4;
		boolean res = spl.contains(con);
		boolean ans = false;
		assertEquals(ans, res);	
	}
	
	// Tries to find the successor of 4: which is 5
	@Test
	public void successorTest1() {
		SplayTreeSet<Integer> spl = new SplayTreeSet<Integer>();
		spl.add(5);
		Node<Integer> ans = spl.getRoot();
		spl.add(3);
		spl.add(4);
		Node<Integer> res = spl.successor(spl.getRoot());
		assertEquals(ans, res);
	}
	
	// Tries to find the successor of the largest value
	@Test
	public void successorTest2() {
		SplayTreeSet<Integer> spl = new SplayTreeSet<Integer>();
		spl.add(5);
		Node<Integer> test = spl.getRoot();
		spl.add(3);
		spl.add(4);
		Node<Integer> res = spl.successor(test);
		Node<Integer> ans = null;
		assertEquals(ans, res);
	}
	
	//Removes the root with two children
	@Test
	public void RemoveTest1() {
		SplayTreeSet<Integer> spl = new SplayTreeSet<Integer>();
		spl.add(5);
		spl.add(3);
		spl.add(4);
		Integer rem = 4;
		spl.remove(rem);
		Integer res = spl.getRoot().getData();
		Integer ans = 3;
		assertEquals(ans, res);
	}
	
	//Removes the root with one child
	@Test
	public void RemoveTest2() {
		SplayTreeSet<Integer> spl = new SplayTreeSet<Integer>();
		spl.add(5);
		spl.add(4);
		Integer rem = 4;
		spl.remove(rem);
		Integer res = spl.getRoot().getData();
		Integer ans = 5;
		assertEquals(ans, res);
	}
	
	//Removes a leaf
	@Test
	public void RemoveTest3() {
		SplayTreeSet<Integer> spl = new SplayTreeSet<Integer>();
		spl.add(5);
		spl.add(3);
		spl.add(4);
		Integer rem = 5;
		spl.remove(rem);
		Integer res = spl.getRoot().getData();
		Integer ans = 4;
		assertEquals(ans, res);
	}
	
	//This is while debugging, not an actual test
	@Test
	public void toStringTest() {
		SplayTreeSet<Integer> spl = new SplayTreeSet<Integer>();
		//spl.add(5);
		spl.add(3);
		spl.add(4);
		String res = spl.toString();
		String ans = res;
		assertEquals(ans, res);
	}
}
