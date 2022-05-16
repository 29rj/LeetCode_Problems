class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        if(grid[0][0] == 1) // check if starting cell itself is blocked -> -1
            return -1;
        
        int m = grid.length, n = grid[0].length; // m = n = N 
        Queue<int[]> q = new LinkedList<>();
        boolean[][] visited = new boolean[m][n];
		
		// dx dy 8 directional vector
        int[] dx = new int[]{1, 1, 0, -1, -1, -1, 0, 1};
        int[] dy = new int[]{0, 1, 1, 1, 0, -1, -1, -1};
        
		// initialize from source top left cell
        q.add(new int[]{0, 0});
        visited[0][0] = true;
        int level = 1;
        
        while(q.size() > 0) {
            for(int i = q.size(); i > 0; i--) { // iterate all cells in next level
                int[] xy = q.poll();
                if(xy[0] == m - 1 && xy[1] == n - 1) // check if reached bottom right most cell
                    return level;
                for(int j = 0; j < 8; j++) { // loop 8 directiona cells 
                    int nx = xy[0] + dx[j];
                    int ny = xy[1] + dy[j];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] == 0) { // check if next cell coordinates valid
                        visited[nx][ny] = true;
                        q.add(new int[]{nx, ny});
                    }
                }
            }
            
            level++; // update level after processing level
        }
        
        return -1;
    }
}