package edu.iastate.cs228.hw5;

import java.util.AbstractSet;
import java.util.Iterator;
import java.util.NoSuchElementException;



/**
 *
 * Splay tree implementation of the Set interface. The contains() and remove()
 * methods of AbstractSet are overridden to search the tree without using the
 * iterator.
 * 
 * @author yiranxu
 *
 */
public class SplayTreeSet<E extends Comparable<? super E>> extends
		AbstractSet<E> {
	// The root of the tree containing this set's items
	Node<E> root;

	// The total number of elements stored in this set
	int size;

	/**
	 * Default constructor. Creates a new, empty, SplayTreeSet
	 */
	public SplayTreeSet() {
		root = null;
		size = 0;
	}

	/**
	 * Shallow copy constructor. This method is fully implemented and should not
	 * be modified.
	 */
	public SplayTreeSet(Node<E> root, int size) {
		this.root = root;
		this.size = size;
	}

	/**
	 * Gets the root of this tree. Used only for testing. This method is fully
	 * implemented and should not be modified.
	 * 
	 * @return the root of this tree.
	 */
	public Node<E> getRoot() {
		return root;
	}

	/**
	 * Determines whether the set contains an element. Splays at the node that
	 * stores the element. If the element is not found, splays at the last node
	 * on the search path.
	 * 
	 * @param obj
	 *            element to be determined whether to exist in the tree
	 * @return true if the element is contained in the tree and false otherwise
	 */
	@Override
	public boolean contains(Object obj) {
		if(obj==null ){
			throw new NullPointerException();
		}
		
		E key = (E) obj;

		Node<E> n = findEntry(key);
		if (n == null) {
			Node<E> current = root;
			while (true) {
				int comp = current.getData().compareTo(key);
				if (comp == 0) {
					root=current;
					splay(current);
					
					return true;
				} else if (comp > 0) {
					if (current.getLeft() != null) {
						current = current.getLeft();
					} else {
						root=current;
						splay(current);
					
						return false;
					}
				} else if (comp < 0) {
					if (current.getRight() != null) {
						current = current.getRight();
					} else {
						root=current;
						splay(current);
						
						return false;
					}
				}
			}

		} else {
			root=n;
			splay(n);
		
			return true;
		}

	}

	/**
	 * Inserts an element into the splay tree. In case the element was not
	 * contained, this creates a new node and splays the tree at the new node.
	 * If the element exists in the tree already, it splays at the node
	 * containing the element.
	 * 
	 * @param key
	 *            element to be inserted
	 * @return true if insertion is successful and false otherwise
	 */
	@Override
	public boolean add(E key) {
		if(key==null){
			throw new NullPointerException();
		}
		if (root == null) {
			root = new Node<E>(key, null, null);
			++size;
			return true;
		}
		Node<E> current = root;
		while (true) {
			int comp = current.getData().compareTo(key);
			if (comp == 0) {
				root=current;
				splay(current);
		
				return false;
			} else if (comp > 0) {
				if (current.getLeft() != null) {
					current = current.getLeft();
				} else {
					Node<E> n = current.getLeft();
					n = new Node<E>(key, null, null);
					n.setParent(current);
					current.setLeft(n);
					++size;
					root=n;
					splay(n);
				
					return true;
				}
			} else {
				if (current.getRight() != null) {
					current = current.getRight();
				} else {
					Node<E> n = current.getRight();
					n = new Node<E>(key, null, null);
					n.setParent(current);
					current.setRight(n);
					++size;
					root=n;
					splay(n);
					
					return true;
				}
			}
		}

	}

	/**
	 * Removes the node that stores an element. Splays at its parent node after
	 * removal (No splay if the removed node was the root.) If the node was not
	 * found, the last node encountered on the search path is splayed to the
	 * root.
	 * 
	 * @param obj
	 *            element to be removed from the tree
	 * @return true if the object is removed and false if it was not contained
	 *         in the tree.
	 */
	@Override
	public boolean remove(Object obj) {
		
		E key = (E) obj;
		Node<E> n = findEntry(key);
		if (n == null) {
			return contains(key);
		}
		unlinkNode(n);
		--size;
		return true;
	}

	/**
	 * Returns the node containing key, or null if the key is not found in the
	 * tree. Called by contains().
	 * 
	 * @param key
	 * @return the node containing key, or null if not found
	 */
	protected Node<E> findEntry(E key) {
		if(key==null){
			throw new NullPointerException();
		}
		Node<E> current = root;
		while (current != null) {
			int comp = current.getData().compareTo(key);
			if (comp == 0) {
				return current;
			} else if (comp > 0) {
				current = current.getLeft();
			} else {
				current = current.getRight();
			}
		}
		return null;
	}

	/**
	 * Returns the successor of the given node.
	 * 
	 * @param n
	 * @return the successor of the given node in this tree, or null if there is
	 *         no successor
	 */
	protected Node<E> successor(Node<E> n) {
		
		if(n==null){
			return null;
		}
		else if(n.getRight()!=null){
			//leftmost entry in right subtree
			Node<E> current=n.getRight();
			while(current.getLeft()!=null){
				current=current.getLeft();
			}
			return current;
		}
		else{
			//We need to go up the tree to the closest ancestor that is a left child;its parent must be the successor
			Node<E> current=n.getParent();
			Node<E> child=n;
			while(current !=null && current.getRight()==child){
				child=current;
				current=current.getParent();
			}
			//either current is null, or child is left child of current
			return current;
		}
		
	}

	/**
	 * Removes the given node, preserving the binary search tree property of the
	 * tree.
	 * 
	 * @param n
	 *            node to be removed
	 */
	protected void unlinkNode(Node<E> n) {
		if(n==null){
			throw new NullPointerException();
		}
		// n has two children; replace n by the join of left and right subtrees
		// of x.
		// splay at n's parent
		if (n.getLeft() != null && n.getRight() != null) {
			Node<E> x = n.getLeft();
			x.setParent(null);
			while (x.getRight() != null) {
				x = x.getRight();
			}
			splay(x);
			Node<E> y = n.getRight();
			x.setRight(y);
			y.setParent(x);
			x.setParent(n.getParent());
			if (n.getParent() == null) {
				root = x;
				n.setLeft(null);
				n.setRight(null);
			} else {
				if (n.isLeftChild()) {
					n.getParent().setLeft(x);
				} else if (n.isRightChild()) {
					n.getParent().setRight(x);
				}
				//splay parental node to the root
				root=x.getParent();
				splay(x.getParent());
				
			}

		}
		// n has at most one children
		else {
			Node<E> replacement = null;
			if (n.getLeft() != null) {
				replacement = n.getLeft();
			} else if (n.getRight() != null) {
				replacement = n.getRight();
			}
			// n is root
			if (n.getParent() == null) {
				root = replacement;

			} else {
				if (n.isLeftChild()) {
					n.getParent().setLeft(replacement);
				} else if (n.isRightChild()) {
					n.getParent().setRight(replacement);
				}
				if (replacement != null) {
					replacement.setParent(n.getParent());
					root=replacement.getParent();
					splay(replacement.getParent());
				
				} else if (replacement == null) {
					root=n.getParent();
					splay(n.getParent());
				
					n.setParent(null);
				}
			}

		}

	}

	@Override
	public Iterator<E> iterator() {
		return new SplayTreeIterator();
	}

	@Override
	public int size() {
		return size;
	}

	/**
	 * Returns a representation of this tree as a multi-line string as explained
	 * in the project description.
	 */
	@Override
	public String toString() {
		StringBuilder sb=new StringBuilder();
		toStringRec(root,sb,0);
		return sb.toString(); 
	}
	/**
	 * Preorder traversal of the tree that builds a string representation
	 * @param n root of subtree to be traversed
	 * @param sb StringBuilder in which to create a string representation
	 * @param depth depth of the given node in the tree
	 */
	private void toStringRec(Node<E> n, StringBuilder sb,int depth){
		for(int i=0;i<4*depth;++i){
			sb.append(" ");
		}
		sb.append(n.getData().toString());
		sb.append("\n");
		
		if(n.getLeft()!=null && n.getRight()==null){
			toStringRec(n.getLeft(),sb,depth+1);
			for(int i=0;i<4*depth+4;++i){
				sb.append(" ");
			}
			sb.append("null\n");
		}
		else if(n.getRight()!=null && n.getLeft()==null){
			for(int i=0;i<4*depth+4;++i){
				sb.append(" ");
			}
			sb.append("null\n");
			toStringRec(n.getRight(),sb,depth+1);
		}
		else if(n.getLeft()==null && n.getRight()==null){
		
			return;
		}
		else if(n.getLeft()!=null && n.getRight()!=null){
			toStringRec(n.getLeft(),sb,depth+1);
			toStringRec(n.getRight(),sb,depth+1);
		}
		
	}

	/**
	 * Splay at the current node. This consists of a sequence of zig, zigZig, or
	 * zigZag operations until the current node is moved to the root of the
	 * tree.
	 * 
	 * @param current
	 *            node at which to splay.
	 */
	protected void splay(Node<E> current) {
		if (current == null) {
			return;
		}
		if (current.getParent() == null) {
			return;
		}
		while (current.getParent() != null) {
			if (current.getParent().getParent() == null) {
				zig(current);
				
			} else if (current.getParent().getParent() != null
					&& current.isLeftChild()
					&& current.getParent().isLeftChild()) {
				zigZig(current);
			} else if (current.getParent().getParent() != null
					&& current.isRightChild()
					&& current.getParent().isRightChild()) {
				zigZig(current);
			} else if (current.getParent().getParent() != null
					&& current.isRightChild()
					&& current.getParent().isLeftChild()) {
				zigZag(current);
			} else if (current.getParent().getParent() != null
					&& current.isLeftChild()
					&& current.getParent().isRightChild()) {
				zigZag(current);
			}

		}
		
	}

	/**
	 * Performs the zig operation on a node.
	 * 
	 * @param current
	 *            node at which to perform the zig operation.
	 */
	protected void zig(Node<E> current) {
		if (current.isLeftChild()) {
			rotateRight(current.getParent());
		} else if (current.isRightChild()) {
			rotateLeft(current.getParent());
		}
	}

	/**
	 * Performs the zig-zig operation on a node.
	 * 
	 * @param current
	 *            node at which to perform the zig-zig operation.
	 */
	protected void zigZig(Node<E> current) {
		if (current.isLeftChild() && current.getParent().isLeftChild()) {
			rotateRight(current.getParent().getParent());
			rotateRight(current.getParent());
		} else if (current.isRightChild() && current.getParent().isRightChild()) {
			rotateLeft(current.getParent().getParent());
			rotateLeft(current.getParent());
		}
	}

	/**
	 * Performs the zig-zag operation on a node.
	 * 
	 * @param current
	 *            node to perform the zig-zag operation on
	 */
	protected void zigZag(Node<E> current) {
		if (current.isRightChild() && current.getParent().isLeftChild()) {
			rotateLeft(current.getParent());
			rotateRight(current.getParent());
		} else if (current.isLeftChild() && current.getParent().isRightChild()) {
			rotateRight(current.getParent());
			rotateLeft(current.getParent());
		}
	}

	// Helper method
	/**
	 * Right rotate
	 * 
	 * @param h
	 * @return
	 */
	private void rotateRight(Node<E> h) {
		Node<E> x = h.getLeft();
		h.setLeft(x.getRight());
		if (x.getRight() != null) {
			x.getRight().setParent(h);
		}
		x.setRight(h);
		if (x.getParent().getParent() != null) {
			if (x.getParent().isLeftChild()) {
				x.getParent().getParent().setLeft(x);
			} else if (x.getParent().isRightChild()) {
				x.getParent().getParent().setRight(x);
			}
		}
		x.setParent(x.getParent().getParent());
		h.setParent(x);
	}

	/**
	 * Left rotate
	 * 
	 * @param h
	 * @return
	 */
	private void rotateLeft(Node<E> h) {
		Node<E> x = h.getRight();
		h.setRight(x.getLeft());
		if (x.getLeft() != null) {
			x.getLeft().setParent(h);
		}
		x.setLeft(h);
		if (x.getParent().getParent() != null) {
			if (x.getParent().isLeftChild()) {
				x.getParent().getParent().setLeft(x);
			} else if (x.getParent().isRightChild()) {
				x.getParent().getParent().setRight(x);
			}
		}
		x.setParent(x.getParent().getParent());
		h.setParent(x);

	}

	/**
	 *
	 * Iterator implementation for this splay tree. The elements are returned in
	 * ascending order according to their natural ordering.
	 *
	 */
	private class SplayTreeIterator implements Iterator<E> {
		/**
		 * Node to be returned by next call to next().
		 */
		Node<E> cursor;
		/**
		 * Node returned by last call to next() and available for removal. This
		 * field is null when no node is available to be removed.
		 */
		Node<E> pending;

		public SplayTreeIterator() {
			// start out at smallest value
			cursor = root;
			if (cursor != null) {
				while (cursor.getLeft() != null) {
					cursor = cursor.getLeft();
				}
			}

		}

		@Override
		public boolean hasNext() {
			
			return cursor!=null;
		}

		@Override
		public E next() {
			if(!hasNext()) throw new NoSuchElementException();
			pending=cursor;
			cursor=successor(cursor);
			return pending.getData();
		}

		@Override
		public void remove() {
			if(pending==null){
				throw new IllegalStateException();
			}
			unlinkNode(pending);
			pending=null;
		}
	}
}
