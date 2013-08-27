package broberto.algorithms;

import java.util.ArrayList;
import java.util.List;

public class QuickUnion<T extends Identifiable> {
	private List<QuickUnionNode<T>> ids;
	
	public QuickUnion(T[] source) {
		ids = new ArrayList<QuickUnionNode<T>>();
		for (T item : source) {
		}
	}
	
	public QuickUnion(T[][] source) {
		
	}
	
}
