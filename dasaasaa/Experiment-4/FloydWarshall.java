class FloydWarshall {
    final static int INF = 9999;
    final static int nV = 4;

    void floydWarshall(int graph[][]) {
        int matrix[][] = new int[nV][nV];

        for (int i = 0; i < nV; i++) {
            for (int j = 0; j < nV; j++) {
                matrix[i][j] = graph[i][j];
            }
        }

        for (int k = 0; k < nV; k++) {
            for (int i = 0; i < nV; i++) {
                for (int j = 0; j < nV; j++) {
                    if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }

        printMatrix(matrix);
    }

    void printMatrix(int matrix[][]) {
        for (int i = 0; i < nV; i++) {
            for (int j = 0; j < nV; j++) {
                if (matrix[i][j] == INF) {
                    System.out.print("INF ");
                } else {
                    System.out.print(matrix[i][j] + " ");
                }
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int graph[][] = {
            { 0, 3, INF, 5 },
            { 2, 0, INF, 4 },
            { INF, 1, 0, INF },
            { INF, INF, 2, 0 }
        };

        FloydWarshall a = new FloydWarshall();
        a.floydWarshall(graph);
    }
}