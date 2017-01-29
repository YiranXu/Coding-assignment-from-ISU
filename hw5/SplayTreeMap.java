package edu.iastate.cs228.hw5;

import java.util.Iterator;
import java.util.ArrayList;

/**
 *
 * An implementation of a map based on a splay tree.
 *
 * @author yiranxu
 */
public class SplayTreeMap<K extends Comparable<? super K>, V> {
	/**
	 *
	 * The key-value pairs in this Map.
	 *
	 */
	private SplayTreeSet<MapEntry<K, V>> entrySet = new SplayTreeSet<MapEntry<K, V>>();

	/**
	 * Default constructor. Creates a new, empty, SplayTreeMap
	 */
	public SplayTreeMap() {
		entrySet = new SplayTreeSet<MapEntry<K, V>>(null, 0);
	}

	/**
	 * Simple copy constructor used only for testing. This method is fully
	 * implemented and should not be modified.
	 */
	public SplayTreeMap(SplayTreeSet<MapEntry<K, V>> set) {
		entrySet = set;
	}

	/**
	 *
	 * @return the number of key-value mappings in this map.
	 */
	public int size() {
		return entrySet.size();
	}

	/**
	 *
	 * @return the value to which key is mapped, or null if this map contains no
	 *         mapping for key.
	 *
	 */
	public V get(K key) {

		Node<MapEntry<K, V>> n = entrySet.findEntry(new MapEntry<K, V>(key,
				null));
		if (n != null) {
			entrySet.contains(n.getData());
			return n.getData().value;
		} else {
			entrySet.contains(n.getData());
			return null;
		}
	}

	/**
	 *
	 * @return true if this map contains a mapping for key.
	 *
	 */
	public boolean containsKey(K key) {
		if (key == null) {
			return false;
		}
		;
		return entrySet.contains(new MapEntry<K, V>(key, null));
	}

	/**
	 *
	 * Associates value with key in this map.
	 *
	 * @return the previous value associated with key, or null if there was no
	 *         mapping for key.
	 *
	 */
	public V put(K key, V value) {
		if(key==null || value==null){
			throw new NullPointerException();
		}
		Node<MapEntry<K, V>> n = entrySet.findEntry(new MapEntry<K, V>(key,
				value));
		V ret = null;
		if (n != null) {
			ret = n.getData().value;
			n.getData().value = value;
			entrySet.contains(n.getData());
		} else {
			entrySet.add(new MapEntry<K, V>(key, value));
		}
		return ret;
	}

	/**
	 *
	 * Removes the mapping for key from this map if it is present.
	 *
	 * @return the previous value associated with key, or null if there was no
	 *         mapping for key.
	 *
	 */
	public V remove(K key) {
		Node<MapEntry<K, V>> n = entrySet.findEntry(new MapEntry<K, V>(key,
				null));
		V ret = null;
		if (n != null) {
			ret = n.getData().value;
			entrySet.remove(n.getData());
		} else {
			entrySet.remove(new MapEntry<K, V>(key, null));
		}
		return ret;
	}

	/**
	 *
	 * @return a SplayTreeSet storing the keys contained in this map.
	 *
	 */
	public SplayTreeSet<K> keySet() {
		SplayTreeSet<K> keyset = new SplayTreeSet<K>();
		for (MapEntry<K, V> element : entrySet) {
			keyset.add(element.key);
		}
		return keyset;
	}

	/**
	 *
	 * @return an ArrayList storing the values contained in this map. The values
	 *         in the ArrayList should be arranged in ascending order of the
	 *         corresponding keys.
	 *
	 */
	public ArrayList<V> values() {
		ArrayList<V> values = new ArrayList<V>();
		for (MapEntry<K, V> element : entrySet) {
			values.add(element.value);
		}
		return values;
	}

}
