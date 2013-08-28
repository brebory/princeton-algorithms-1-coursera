/**
 * @author Brendon Roberto
 *
 */
public class Percolation {
	
	private interface Identifiable {
		int id();
	}

	
	private enum Status {
		BLOCKED, UNBLOCKED
	}
	
	private class Site implements Identifiable {
		
		/**
		 * Class Site provides a model of a single site in
		 * a percolation simulation. A site is either BLOCKED or
		 * UNBLOCKED.
		 */
		
		private Status 	_status;
		private int 	_id;
		
		public Site(int x, int y, int n) {
			// Check for valid arguments
			if (n > 0 && n > x && n > y) {
				_status = Status.BLOCKED;
				_id = (x * n) + y;	
			} else {
				throw new IllegalArgumentException(
						String.format("Cannot construct Site at index [%d][%d] in grid of size %d.",
									  x, y, n));
			}	
		}
		
		public boolean isBlocked() {
			return _status == Status.BLOCKED;
		}
		
		public void unblock() {
			_status = Status.UNBLOCKED;
		}

		@Override
		public int id() {
			return _id;
		}
	}
	
	/**
	 * Class Percolation provides a simulation interface for running 
	 * percolation simulators. 
	 */

	private Site[][] 	_grid;
	private WeightedQuickUnionUF _paths;
	private int _size;
	
	/**
	 * Default Constructor
	 * Creates an N X N Percolation grid with all sites blocked
	 * @param N	The size of square percolation grid
	 */
	public Percolation(int N) {
		_size = N;
		_grid = new Site[_size][_size];
		for (int i = 0; i < _size; i++) {
			for (int j = 0; j < _size; j++) {
				_grid[i][j] = new Site(i, j, _size);
			}
		}
		_paths = new WeightedQuickUnionUF(_size * _size);
	}
	
	/**
	 * Method open changes the status of the site at 
	 * _grid[i][j] to unblocked. It also updates _paths
	 * to connect the site to its neighbors as well as
	 * updating blockedSites by removing the entry at i, j
	 * 
	 * @param i row index to open
	 * @param j column index to open
	 */
	public void open(int i, int j) {
		// Check for valid input
		if (i < 0 || i > _size || j < 0 || j > _size) {
			throw new IndexOutOfBoundsException("Invalid indices for open method.");
		}
		Site current = _grid[i][j];
		if (current.isBlocked()) {
			current.unblock();
			Site left = this.getLeftNeighbor(i, j);
			Site right = this.getRightNeighbor(i, j);
			Site top = this.getTopNeighbor(i, j);
			Site bottom = this.getBottomNeighbor(i, j);
			
			if (left != null && !left.isBlocked()) {
				_paths.union(current.id(), left.id());
			}
			if (right != null && !right.isBlocked()) {
				_paths.union(current.id(), right.id());
			}
			if (top != null) {
				_paths.union(current.id(), top.id());
			}
			if (bottom != null) {
				_paths.union(current.id(), bottom.id());
			}		
		}
	}
	
	/**
	 * Method isOpen returns true if the site at
	 * grid[i][j] is open, and false otherwise.
	 * 
	 * @param i row index to check
	 * @param j column index to check
	 * @return true if open, false if blocked
	 */
	public boolean isOpen(int i, int j) {
		return !_grid[i][j].isBlocked();
	}
	
	/**
	 * Method isFull returns true if the site at
	 * grid[i][j] is full (connected to the top row), 
	 * and false otherwise.
	 * 
	 * @param i row index to check
	 * @param j column index to check
	 * @return true if full, false if blocked
	 */
	public boolean isFull(int i, int j) {
		if (_grid[i][j].isBlocked()) {
			return false;
		}
		
		_paths.find(_grid[i][j].id());
		for (int idx = 0; idx < _size; idx++) {
			if (!_grid[0][idx].isBlocked()) {
				if (_paths.connected(_grid[i][j].id(), _grid[0][idx].id())) {
					return true;
				}
			}	
		}
		return false;
	}
	
	/**
	 * Method percolates returns true if the system
	 * percolates, that is, has at least one site at the
	 * bottom that is full.
	 * 
	 * @return true if the system percolates, false otherwise
	 */
	public boolean percolates() {
		for (int idx = 0; idx < _size; idx++) {
			if (isFull(_size-1, idx)) {
				return true;
			}
		}
		return false;
	}
	
	/**
	 * Method getLeftNeighbor returns the Site to the left
	 * of the site at _grid[i][j], or null (if i,j is at the
	 * left edge of _grid)
	 * @param i row index to check
	 * @param j column index to check
	 * @return the site at _grid[i][j-1] or null
	 */

	private Site getLeftNeighbor(int i, int j) {
		if (j - 1 < 0) {
			return null;
		} else {
			return _grid[i][j-1];
		}
	}
	
	/**
	 * Method getRightNeighbor returns the Site to the right
	 * of the site at _grid[i][j], or null (if i,j is at the
	 * right edge of _grid)
	 * @param i row index to check
	 * @param j column index to check
	 * @return the site at _grid[i][j+1] or null
	 */
	private Site getRightNeighbor(int i, int j) {
		if (j + 1 >= _size) {
			return null;
		} else {
			return _grid[i][j+1];
		}
	}
	
	/**
	 * Method getTopNeighbor returns the Site above
	 * the site at _grid[i][j], or null (if i,j is at the
	 * top edge of _grid)
	 * @param i row index to check
	 * @param j column index to check
	 * @return the site at _grid[i-1][j] or null
	 */
	private Site getTopNeighbor(int i, int j) {
		if (i - 1 < 0) {
			return null;
		} else {
			return _grid[i-1][j];
		}
	}
	
	/**
	 * Method getBottomNeighbor returns the Site below
	 * the site at _grid[i][j], or null (if i,j is at the
	 * bottom edge of _grid)
	 * @param i row index to check
	 * @param j column index to check
	 * @return the site at _grid[i+1][j] or null
	 */
	private Site getBottomNeighbor(int i, int j) {
		if (i + 1 >= _size) {
			return null;
		} else {
			return _grid[i+1][j];
		}
	}
}
