/**
 * Count of blocks that a robot can reach in a mxn grid.
 */
public class Q13 {
    public static int movingCount(int threshold, int rows, int cols) {
        if (threshold < 0 || rows < 0 || cols < 0) {
            throw new IllegalArgumentException("Input invalid");
        }

        boolean[][] visited = new boolean[rows][cols];
        return dfs(threshold, rows, cols, 0, 0, visited);
    }

    private static int dfs(int threshold, int rows, int cols, int row, int col, boolean[][] visited) {
        int count = 0;
        if (row < 0 || col < 0 || row >= rows || col >= cols || visited[row][col] || !isValid(threshold, row, col)) {
            return count;
        }

        visited[row][col] = true;
        count = 1 + dfs(threshold, rows, cols, row, col - 1, visited)
                + dfs(threshold, rows, cols, row + 1, col, visited)
                + dfs(threshold, rows, cols, row, col + 1, visited)
                + dfs(threshold, rows, cols, row - 1, col, visited);

        return count;
    }

    private static boolean isValid(int threshold, int row, int col) {
        int sum = 0;
        while (row > 0) {
            sum += row % 10;
            row /= 10;
        }
        while (col > 0) {
            sum += col % 10;
            col /= 10;
        }
        return sum <= threshold;
    }
}
