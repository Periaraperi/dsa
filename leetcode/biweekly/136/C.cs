public class C {
    public int MinFlips(int[][] grid) {
        int n = grid.Length;
        int m = grid[0].Length;

        int makeAllZero = 0;
        foreach (var row in grid) {
            foreach (var col in row) {
                if (col == 1) {
                    ++makeAllZero;
                }
            }
        }
        
        for (int i=0; i<n/2; ++i) {
            for (int j=0; j<m/2; ++j) {
                
            }
        }


    }
}
