
/**
 * 
 * @author Brendon Roberto
 *
 */

public class PercolationStats {
	
	private double[] _results;
	private int 	 _number_of_tests;
	private int		 _percolation_size;
	private int		 _sites_count;
	
	public PercolationStats(int N, int T) {
		_number_of_tests = T;
		_percolation_size = N;
		_sites_count = N*N;
		
		_results = new double[_number_of_tests];
		
		for (int idx = 0; idx < _number_of_tests; idx++) {
			Percolation prc = new Percolation(_percolation_size);
			int iterations = 0;
			while (!prc.percolates()) {
				int x = StdRandom.uniform(_percolation_size);
				int y = StdRandom.uniform(_percolation_size);
				prc.open(x, y);
				iterations++;
			}
			_results[idx] = (double) iterations / _sites_count;
		}
	}
	
	public double mean() {
		return StdStats.mean(_results);
	}
	
	public double stddev() {
		return StdStats.stddev(_results);
	}
	
	public double confidenceLo() {
		return mean() - (1.96 * stddev()) / _number_of_tests;
	}
	
	public double confidenceHi() {
		return mean() + (1.96 * stddev()) / _number_of_tests;
	}
	
	public static void main(String[] args) {
		if (args.length != 2) {
			throw new IllegalArgumentException("Invalid arguments for PercolationStats.main");
		}
		int N = Integer.parseInt(args[0]);
		int T = Integer.parseInt(args[1]);
		
		if (N <= 0 || T <= 0) {
			throw new IllegalArgumentException("Invalid arguments for PercolationStats.main");
		}
		
		PercolationStats test = new PercolationStats(N, T);
		System.out.println(String.format("mean\t\t\t\t= %f", test.mean()));
		System.out.println(String.format("stddev\t\t\t\t= %f", test.stddev()));
		System.out.println(String.format("95%% confidence interval\t\t= %f %f", test.confidenceLo(), test.confidenceHi()));
	}
}
