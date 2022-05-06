/**
 * Check whether there exists a path in a given matrix.
 */
public class Q12 {
    public static boolean hasPath(char[][] matrix, char[] path) {
        if (matrix == null || path == null || matrix.length == 0 || matrix[0].length == 0) {
            throw new IllegalArgumentException("Input invalid");
        }

        int m = matrix.length, n = matrix[0].length;
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(matrix, path, i, j, 0, visited))
                    return true;
            }
        }
        return false;
    }

    private static boolean dfs(char[][] matrix, char[] path, int row, int col, int len, boolean[][] visited) {

        // recursion terminal condition
        if (path.length - 1 == len) {
            return true;
        }

        // backtrack condition
        if (row < 0 || col < 0 || row >= matrix.length || col >= matrix.length || visited[row][col]) {
            return false;
        }

        boolean flag = false;
        visited[row][col] = true;
        flag = dfs(matrix, path, row - 1, col, len + 1, visited)
                || dfs(matrix, path, row + 1, col, len + 1, visited)
                || dfs(matrix, path, row, col - 1, len + 1, visited)
                || dfs(matrix, path, row, col + 1, len + 1, visited);

        if (!flag) { // backtracking
            len--;
            visited[row][col] = false;
        }
        return flag;
    }

    public static void main(String[] args) {
        char[][] matrix = new char[][] { { 'a', 'b', 'c', 'e' }, { 's', 'f', 'c', 's' }, { 'a', 'd', 'e', 'e' } };
        char[] path = new char[] { 'b', 'f', 'c', 'e' };
        System.out.println(hasPath(matrix, path));
    }
}
