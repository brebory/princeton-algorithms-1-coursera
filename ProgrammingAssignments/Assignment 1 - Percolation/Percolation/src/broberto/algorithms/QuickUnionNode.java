package broberto.algorithms;

public class QuickUnionNode<T extends Identifiable> {
	private int 	_root;
	private T 		_data;
	
	public QuickUnionNode(T source) {
		_root = source.id();
		_data = source;
	}
	
	public int getRoot() {
		return _root;
	}
	
	public void setRoot(int newRoot) {
		_root = newRoot;
	}
	
	public T getData() {
		return _data;
	}
}
