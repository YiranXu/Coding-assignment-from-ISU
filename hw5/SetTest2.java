package edu.iastate.cs228.hw5;

public class SetTest2 {

	public static void main(String[] args) {
		SplayTreeSet<Integer> spl = new SplayTreeSet<Integer>();
		//spl.add(5);
		spl.add(31);
		spl.add(37);
		spl.add(25);
		spl.add(10);
		spl.add(20);
		spl.add(35);
		spl.add(53);
		spl.add(60);
		spl.add(62);
		spl.add(30);
		spl.add(55);
		spl.add(50);
		spl.contains(31);
		String res = spl.toString();
		//System.out.println(res);
		SplayTreeMap<Integer, String> s = new SplayTreeMap<>();

		s.put(30,"Carol");
		s.put(21,"Sam");
		s.put(22,"Jenny");
		s.put(50,"Amy");
		s.put(10,"Kaitlyn");
		s.put(60,"John");
		s.put(53,"Shelby");
		s.put(55,"Keke");
		s.put(25,"Luna");
		System.out.println(s.keySet().toString());
		System.out.println(s.values().toString());
	}
	

}
