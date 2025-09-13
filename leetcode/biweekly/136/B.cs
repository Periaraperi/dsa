public class B {
    public int MinFlips(int[][] grid) {
        int n = grid.Length;
        int m = grid[0].Length;

        int rows = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m/2; ++j) {
                if (grid[i][j] != grid[i][m-j-1]) {
                    ++rows;
                }
            }
        }

        int cols = 0;
        for (int j=0; j<m; ++j) {
            for (int i=0; i<n/2; ++i) {
                if (grid[i][j] != grid[n-i-1][j]) {
                    ++cols;
                }
            }
        }

        return Math.Min(rows, cols);
    }
}
