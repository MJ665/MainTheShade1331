import java.util.ArrayList;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Collections;  // Add this import statement

public class FifteenPuzzleSolver {

    private static final int[][] GOAL_STATE = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 0}
    };

    private static final int[][] MOVES = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    public static void main(String[] args) {
        int[][] initialBoard = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 0, 12},
            {13, 14, 11, 15}
        };

        ArrayList<int[][]> solutionPath = solvePuzzle(initialBoard);

        if (solutionPath != null) {
            for (int i = 0; i < solutionPath.size(); i++) {
                System.out.println("Step " + i + ":");
                printBoard(solutionPath.get(i));
                System.out.println();
            }
        } else {
            System.out.println("No solution found.");
        }
    }

    private static ArrayList<int[][]> solvePuzzle(int[][] initialBoard) {
        PriorityQueue<Node> openList = new PriorityQueue<>();
        HashSet<String> closedSet = new HashSet<>();

        int[][] goalState = GOAL_STATE;
        Node initialNode = new Node(initialBoard, 0, null);

        openList.add(initialNode);

        while (!openList.isEmpty()) {
            Node currentNode = openList.poll();
            int[][] currentState = currentNode.board;

            if (isEqual(currentState, goalState)) {
                ArrayList<int[][]> solutionPath = new ArrayList<>();
                while (currentNode != null) {
                    solutionPath.add(currentNode.board);
                    currentNode = currentNode.parent;
                }
                Collections.reverse(solutionPath);
                return solutionPath;
            }

            closedSet.add(boardToString(currentState));

            int blankX = 0, blankY = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (currentState[i][j] == 0) {
                        blankX = i;
                        blankY = j;
                        break;
                    }
                }
            }

            for (int[] move : MOVES) {
                int newX = blankX + move[0];
                int newY = blankY + move[1];

                if (isValidMove(newX, newY)) {
                    int[][] newBoard = copyBoard(currentState);
                    newBoard[blankX][blankY] = currentState[newX][newY];
                    newBoard[newX][newY] = 0;

                    if (!closedSet.contains(boardToString(newBoard))) {
                        Node newNode = new Node(newBoard, currentNode.depth + 1, currentNode);
                        openList.add(newNode);
                    }
                }
            }
        }

        return null;
    }

    private static boolean isEqual(int[][] board1, int[][] board2) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board1[i][j] != board2[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    private static boolean isValidMove(int x, int y) {
        return x >= 0 && x < 4 && y >= 0 && y < 4;
    }

    private static int[][] copyBoard(int[][] board) {
        int[][] copy = new int[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                copy[i][j] = board[i][j];
            }
        }
        return copy;
    }

    private static String boardToString(int[][] board) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                sb.append(board[i][j]);
            }
        }
        return sb.toString();
    }

    private static void printBoard(int[][] board) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    private static class Node implements Comparable<Node> {
        int[][] board;
        int depth;
        Node parent;

        Node(int[][] board, int depth, Node parent) {
            this.board = board;
            this.depth = depth;
            this.parent = parent;
        }

        @Override
        public int compareTo(Node other) {
            int thisPriority = this.depth + manhattanDistance(this.board);
            int otherPriority = other.depth + manhattanDistance(other.board);
            return Integer.compare(thisPriority, otherPriority);
        }
    }

    private static int manhattanDistance(int[][] board) {
        int distance = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int tile = board[i][j];
                if (tile != 0) {
                    int goalX = (tile - 1) / 4;
                    int goalY = (tile - 1) % 4;
                    distance += Math.abs(i - goalX) + Math.abs(j - goalY);
                }
            }
        }
        return distance;
    }
}
