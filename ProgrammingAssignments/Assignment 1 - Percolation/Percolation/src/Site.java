import broberto.algorithms.Identifiable;

/**
 * 
 * @author broberto
 *
 */

public class Site implements Identifiable {
	
	/**
	 * Class Site provides a model of a single site in
	 * a percolation simulation. A site is either BLOCKED or
	 * UNBLOCKED.
	 */
	
	private enum Status {
		BLOCKED, UNBLOCKED
	}
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
	
	public void block() {
		_status = Status.BLOCKED;
	}
	
	public void unblock() {
		_status = Status.UNBLOCKED;
	}

	@Override
	public int id() {
		return _id;
	}
}
