package edu.iastate.cs228.hw5;

import static org.junit.Assert.*;

import org.junit.Test;
/**
 * Tests
 * @author yiranxu
 *
 */
public class SplayTreeMapTests {

	@Test
	public void testGet() {
		SplayTreeMap<Integer,String> s = new SplayTreeMap<Integer,String>();
		s.put(30,"Carol");
		s.put(21,"Sam");
		s.put(22,"Jenny");
		s.put(50,"Amy");
		s.put(10,"Kaitlyn");
		s.put(60,"John");
		s.put(53,"Shelby");
		s.put(55,"Keke");
		s.put(25,"Luna");
		String res=s.get(55);
		String ans = "Keke";
		assertEquals(ans, res);
	}
	@Test
	public void testContains(){
		SplayTreeMap<Integer,String> s = new SplayTreeMap<Integer,String>();
		s.put(30,"Carol");
		s.put(21,"Sam");
		s.put(22,"Jenny");
		s.put(50,"Amy");
		s.put(10,"Kaitlyn");
		s.put(60,"John");
		s.put(53,"Shelby");
		s.put(55,"Keke");
		s.put(25,"Luna");
			boolean ans = true;
			boolean res = s.containsKey(55);
			
			assertEquals(ans, res);
		
	}
	@Test
	public void testPutExist(){
		SplayTreeMap<Integer,String> s = new SplayTreeMap<Integer,String>();
		s.put(30,"Carol");
		s.put(21,"Sam");
		s.put(22,"Jenny");
		s.put(50,"Amy");
		s.put(10,"Kaitlyn");
		s.put(60,"John");
		s.put(53,"Shelby");
		s.put(55,"Keke");
		s.put(25,"Luna");
			String ans = "Shelby";
			String res = s.put(53,"Shelby");
			
			assertEquals(ans, res);
		
	}
	@Test
	public void testPutNotExist(){
		SplayTreeMap<Integer,String> s = new SplayTreeMap<Integer,String>();
		s.put(30,"Carol");
		s.put(21,"Sam");
		s.put(22,"Jenny");
		s.put(50,"Amy");
		s.put(10,"Kaitlyn");
		s.put(60,"John");
		s.put(53,"Shelby");
		s.put(55,"Keke");
		s.put(25,"Luna");
			//String ans = "Shelby";
			String res = s.put(57,"Traci");
			//String res1=s.get(53);
			//String ans1="Traci";
			assertEquals(null, res);
			//assertEquals(ans1, res1);
	}
	@Test
	public void testRemoveExist(){
		SplayTreeMap<Integer,String> s = new SplayTreeMap<Integer,String>();
		s.put(30,"Carol");
		s.put(21,"Sam");
		s.put(22,"Jenny");
		s.put(50,"Amy");
		s.put(10,"Kaitlyn");
		s.put(60,"John");
		s.put(53,"Shelby");
		s.put(55,"Keke");
		s.put(25,"Luna");
		
			//String ans = "Shelby";
			String res =s.remove(50);
			//String res1=s.get(53);
			//String ans1="Traci";
			assertEquals("Amy", res);
			//assertEquals(ans1, res1);
	}
	@Test
	public void testRemoveNotExist(){
		SplayTreeMap<Integer,String> s = new SplayTreeMap<Integer,String>();
		s.put(30,"Carol");
		s.put(21,"Sam");
		s.put(22,"Jenny");
		s.put(50,"Amy");
		s.put(10,"Kaitlyn");
		s.put(60,"John");
		s.put(53,"Shelby");
		s.put(55,"Keke");
		s.put(25,"Luna");
		
			//String ans = "Shelby";
			String res =s.remove(57);
			//String res1=s.get(53);
			//String ans1="Traci";
			assertEquals(null, res);
			//assertEquals(ans1, res1);
	}
	
}
