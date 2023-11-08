# Experiment-1: Searching and Sorting Algorithms

## 1. Selection Sort

```java
public class SelectionSort {
    public static void selectionSort(int[] arr) {
        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    public static void main(String[] args) {
        int[] arr = {22, 13, 64, 12, 33};
        selectionSort(arr);

        System.out.println("Sorted array:");
        for (int value : arr) {
            System.out.print(value + " ");
        }
    }
}
```

## 2. Insertion Sort

```java
public class InsertionSort {
    public static void insertionSort(int[] arr) {
        int n = arr.length;

        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }
    }

    public static void main(String[] args) {
        int[] arr = {64, 25, 12, 22, 11};
        insertionSort(arr);

        System.out.println("Sorted array:");
        for (int value : arr) {
            System.out.print(value + " ");
        }
    }
}
```

## 3. Merge Sort

```java
public class MergeSort {
    public static void merge(int[] arr, int left, int middle, int right) {
        int n1 = middle - left + 1;
        int n2 = right - middle;

        int[] leftArray = new int[n1];
        int[] rightArray = new int[n2];

        for (int i = 0; i < n1; i++) {
            leftArray[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            rightArray[j] = arr[middle + 1 + j];
        }

        int i = 0, j = 0;
        int k = left;

        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                arr[k] = leftArray[i];
                i++;
            } else {
                arr[k] = rightArray[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = leftArray[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = rightArray[j];
            j++;
            k++;
        }
    }

    public static void mergeSort(int[] arr, int left, int right) {
        if (left < right) {
            int middle = left + (right - left) / 2;

            mergeSort(arr, left, middle);
            mergeSort(arr, middle + 1, right);

            merge(arr, left, middle, right);
        }
    }

    public static void main(String[] args) {
        int[] arr = {64, 25, 12, 22, 11};
        int n = arr.length;

        mergeSort(arr, 0, n - 1);

        System.out.println("Sorted array:");
        for (int value : arr) {
            System.out.print(value + " ");
        }
    }
}
```

## 4. Linear Search

```java
public class LinearSearch {
    public static int linearSearch(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i; // Element found at index 'i'.
            }
        }
        return -1; // Element not found in the list.
    }

    public static void main(String[] args) {
        int[] arr = {64, 25, 12, 22, 11};
        int target = 22;

        int result = linearSearch(arr, target);

        if (result != -1) {
            System.out.println("Element found at index " + result);
        } else {
            System.out.println("Element not found in the list.");
        }
    }
}
```

## 5. Binary Search

```java
public class BinarySearch {
    public static int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid; // Element found at index 'mid'.
            }

            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1; // Element not found in the list.
    }

    public static void main(String[] args) {
        int[] arr = {11, 12, 22, 25, 64};
        int target = 22;

        int result = binarySearch(arr, target);

        if (result != -1) {
            System.out.println("Element found at index " + result);
        } else {
            System.out.println("Element not found in the list.");
        }
    }
}
```

# Experiment-2: Stack, Queue & Linked List

## 1. Stack

```java
import java.util.EmptyStackException;

public class Stack {
    private int[] stackArray;
    private int top;
    private int maxSize;

    public Stack(int maxSize) {
        this.maxSize = maxSize;
        stackArray = new int[maxSize];
        top = -1;
    }

    public void push(int value) {
        if (top == maxSize - 1) {
            throw new StackOverflowError("Stack is full");
        }
        top++;
        stackArray[top] = value;
    }

    public int pop() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        int value = stackArray[top];
        top--;
        return value;
    }

    public int peek() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return stackArray[top];
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean isFull() {
        return top == maxSize - 1;
    }

    public static void main(String[] args) {
        Stack stack = new Stack(5);
        stack.push(10);
        stack.push(20);
        stack.push(30);

        System.out.println("Top element: " + stack.peek());

        int poppedElement = stack.pop();
        System.out.println("Popped element: " + poppedElement);

        System.out.println("Is stack empty? " + stack.isEmpty());
        System.out.println("Is stack full? " + stack.isFull());
    }
}
```

## 2. Queue

```java
public class queue {
    private int maxSize;
    private int front;
    private int rear;
    private int currentSize;
    private int array[];

    public queue(int size) {
        this.maxSize = size;
        front = 0;
        rear = -1;
        currentSize = 0;
        array = new int[maxSize];
    }

    public boolean isFull() {
        return (currentSize == maxSize);
    }

    public boolean isEmpty() {
        return (currentSize == 0);
    }

    public void enqueue(int item) {
        if (isFull()) {
            System.out.println("Queue is full!");
            return;
        }
        rear = (rear + 1) % maxSize;
        array[rear] = item;
        currentSize++;
        System.out.println("Added to queue" + item);
    }

    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty!");
            return -1;
        }
        int temp = front;
        front = (front + 1) % maxSize;
        currentSize--;
        System.out.println("Removed from queue" + array[temp]);
        return array[temp];
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("Queue is empty!");
            return;
        }
        int temp = front;
        while (temp != rear) {
            System.out.println(array[temp]);
            temp = (temp + 1) % maxSize;
        }
        System.out.println(array[rear]);
    }

    public static void main(String[] args) {
        queue queue = new queue(5);
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        queue.dequeue();
        queue.enqueue(5);
        queue.display();
    }
}
```

## 3. Linked-List

```java
public class linkedlist {
    Node head;
    static class Node {
        int data;
        Node next;
        Node(int d) {
            data = d;
            next = null;
        }
    }
    public static linkedlist insert(linkedlist list, int data) {
        Node new_node = new Node(data);
        new_node.next = null;
        if (list.head == null) {
            list.head = new_node;
        } else {
            Node last = list.head;
            while (last.next != null) {
                last = last.next;
            }
            last.next = new_node;
        }
        return list;
    }
    public static void printList(linkedlist list) {
        Node currNode = list.head;
        System.out.print("\nLinkedList: ");
        while (currNode != null) {
            System.out.print(currNode.data + " ");
            currNode = currNode.next;
        }
        System.out.println("\n");
    }
    public static linkedlist deleteByKey(linkedlist list, int key) {
        Node currNode = list.head, prev = null;
        if (currNode != null && currNode.data == key) {
            list.head = currNode.next;
            System.out.println(key + " found and deleted");
            return list;
        }
        while (currNode != null && currNode.data != key) {
            prev = currNode;
            currNode = currNode.next;
        }
        if (currNode != null) {
            prev.next = currNode.next;
            System.out.println(key + " found and deleted");
        }
        if (currNode == null) {
            System.out.println(key + " not found");
        }
        return list;
    }
    public static linkedlist deleteAtPosition(linkedlist list, int index) {
        Node currNode = list.head, prev = null;
        if (index == 0 && currNode != null) {
            list.head = currNode.next;
            System.out.println(index + " position element deleted");
            return list;
        }
        int counter = 0;
        while (currNode != null) {
            if (counter == index) {
                prev.next = currNode.next;
                System.out.println(index + " position element deleted");
                break;
            } else {
                prev = currNode;
                currNode = currNode.next;
                counter++;
            }
        }
        if (currNode == null) {
            System.out.println(index + " position element not found");
        }
        return list;
    }
    public static void main(String[] args) {
        linkedlist list = new linkedlist();
        list = insert(list, 1);
        list = insert(list, 2);
        list = insert(list, 3);
        list = insert(list, 4);
        list = insert(list, 5);
        list = insert(list, 6);
        list = insert(list, 7);
        list = insert(list, 8);
        printList(list);
        deleteByKey(list, 1);
        printList(list);
        deleteByKey(list, 4);
        printList(list);
        deleteByKey(list, 10);
        printList(list);
        deleteAtPosition(list, 0);
        printList(list);
        deleteAtPosition(list, 2);
        printList(list);
        deleteAtPosition(list, 10);
        printList(list);
    }
}
```

# Experiment-3: Minimum Spanning Tree

## Prim's Algorithm

```java
// A Java program for Prim's Minimum Spanning Tree (MST)
// algorithm. The program is for adjacency matrix
// representation of the graph

import java.io.*;
import java.lang.*;
import java.util.*;

class MST {
    private static final int V = 5;

    int minKey(int key[], Boolean mstSet[])
    {
        int min = Integer.MAX_VALUE, min_index = -1;

        for (int v = 0; v < V; v++)
            if (mstSet[v] == false && key[v] < min) {
                min = key[v];
                min_index = v;
            }

        return min_index;
    }

    void printMST(int parent[], int graph[][])
    {
        System.out.println("Edge \tWeight");
        for (int i = 1; i < V; i++)
            System.out.println(parent[i] + " - " + i + "\t"
                               + graph[i][parent[i]]);
    }

    void primMST(int graph[][])
    {
        int parent[] = new int[V];
        int key[] = new int[V];

        Boolean mstSet[] = new Boolean[V];

        for (int i = 0; i < V; i++) {
            key[i] = Integer.MAX_VALUE;
            mstSet[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, mstSet);

            mstSet[u] = true;

            for (int v = 0; v < V; v++)
                if (graph[u][v] != 0 && mstSet[v] == false
                        && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
        }

        printMST(parent, graph);
    }

    public static void main(String[] args)
    {
        MST t = new MST();
        int graph[][] = new int[][] { { 0, 2, 0, 6, 0 },
            { 2, 0, 3, 8, 5 },
            { 0, 3, 0, 0, 7 },
            { 6, 8, 0, 0, 9 },
            { 0, 5, 7, 9, 0 }
        };

        t.primMST(graph);
    }
}
```

## Kruskal's Algorithm

```java
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class KruskalsMST {

    static class Edge {
        int src, dest, weight;

        public Edge(int src, int dest, int weight)
        {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }
    }

    static class Subset {
        int parent, rank;

        public Subset(int parent, int rank)
        {
            this.parent = parent;
            this.rank = rank;
        }
    }

    public static void main(String[] args)
    {
        int V = 4;
        List<Edge> graphEdges = new ArrayList<Edge>(
            List.of(new Edge(0, 1, 10), new Edge(0, 2, 6),
                    new Edge(0, 3, 5), new Edge(1, 3, 15),
                    new Edge(2, 3, 4)));

        graphEdges.sort(new Comparator<Edge>() {
            @Override public int compare(Edge o1, Edge o2)
            {
                return o1.weight - o2.weight;
            }
        });

        kruskals(V, graphEdges);
    }

    private static void kruskals(int V, List<Edge> edges)
    {
        int j = 0;
        int noOfEdges = 0;

        Subset subsets[] = new Subset[V];

        Edge results[] = new Edge[V];

        for (int i = 0; i < V; i++) {
            subsets[i] = new Subset(i, 0);
        }

        while (noOfEdges < V - 1) {

            Edge nextEdge = edges.get(j);
            int x = findRoot(subsets, nextEdge.src);
            int y = findRoot(subsets, nextEdge.dest);

            if (x != y) {
                results[noOfEdges] = nextEdge;
                union(subsets, x, y);
                noOfEdges++;
            }

            j++;
        }

        System.out.println(
                  "Following are the edges of the constructed MST:");
        int minCost = 0;
        for (int i = 0; i < noOfEdges; i++) {
            System.out.println(results[i].src + " -- "
                               + results[i].dest + " == "
                               + results[i].weight);
            minCost += results[i].weight;
        }
        System.out.println("Total cost of MST: " + minCost);
    }

    // Function to unite two disjoint sets
    private static void union(Subset[] subsets, int x,
                                  int y)
    {
        int rootX = findRoot(subsets, x);
        int rootY = findRoot(subsets, y);

        if (subsets[rootY].rank < subsets[rootX].rank) {
            subsets[rootY].parent = rootX;
        }
        else if (subsets[rootX].rank
                 < subsets[rootY].rank) {
            subsets[rootX].parent = rootY;
        }
        else {
            subsets[rootY].parent = rootX;
            subsets[rootX].rank++;
        }
    }

    // Function to find parent of a set
    private static int findRoot(Subset[] subsets, int i)
    {
        if (subsets[i].parent == i)
            return subsets[i].parent;

        subsets[i].parent
            = findRoot(subsets, subsets[i].parent);
        return subsets[i].parent;
    }
}
```

# Experiment-4: All Pair Shortest Path

## Floyd Warshall Algorithm

```java
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
```

# Experiment-5: Longest Common Subsequence using Dynamic Programming

```java
public class LongestCommonSubsequence {
    public static String findLCS(String str1, String str2) {
        int m = str1.length();
        int n = str2.length();

        int[][] dp = new int[m + 1][n + 1];

        // Fill the dp array using a bottom-up approach
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int length = dp[m][n];
        char[] lcs = new char[length];
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                lcs[length - 1] = str1.charAt(i - 1);
                i--;
                j--;
                length--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        return new String(lcs);
    }

    public static void main(String[] args) {
        String str1 = "AGGTAB";
        String str2 = "GXTXAYB";
        String lcs = findLCS(str1, str2);
        System.out.println("Longest Common Subsequence: " + lcs);
    }
}
```

# Experiment-6: 8 Queen’s Problem

```java
import java.util.Arrays;

class EightQP {
    static final int N = 8;

    static boolean isSafe(int[][] board, int row, int col) {
        for (int x = 0; x < col; x++)
            if (board[row][x] == 1)
                return false;

        for (int x = row, y = col; x >= 0 && y >= 0; x--, y--)
            if (board[x][y] == 1)
                return false;

        for (int x = row, y = col; x < N && y >= 0; x++, y--)
            if (board[x][y] == 1)
                return false;

        return true;
    }

    static boolean solveNQueens(int[][] board, int col) {
        if (col == N) {
            for (int[] row : board)
                System.out.println(Arrays.toString(row));
            System.out.println();
            return true;
        }

        for (int i = 0; i < N; i++) {
            if (isSafe(board, i, col)) {
                board[i][col] = 1;
                if (solveNQueens(board, col + 1))
                    return true;
                board[i][col] = 0;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int[][] board = new int[N][N];
        if (!solveNQueens(board, 0))
            System.out.println("No solution found");
    }
}
```

# Experiment-7: 15 Puzzle Problem

```java
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


```

---

# Experiment-8: Naïve String-Matching

```java
public class NaiveStringMatching {
    public static void search(String text, String pattern) {
        int n = text.length();
        int m = pattern.length();

        for (int i = 0; i <= n - m; i++) {
            int j;

            for (j = 0; j < m; j++) {
                if (text.charAt(i + j) != pattern.charAt(j))
                    break;
            }

            if (j == m) {
                System.out.println("Pattern found at index " + i);
            }
        }
    }

    public static void main(String[] args) {
        String text = "AABAACAADAABAAABAA";
        String pattern = "AABA";
        search(text, pattern);
    }
}
```

---

# Experiment-9: Palindromic Tree

```java
// import java.util.*;

class Node {
    int start, end;
    int length;
    int[] insertEdg = new int[26];
    int suffixEdg;
}

public class PalindromicSubstrings {
    static final int MAXN = 1000;
    static Node root1 = new Node();
    static Node root2 = new Node();
    static Node[] tree = new Node[MAXN];
    static int currNode;
    static String s;
    static int ptr;

    static void insert(int idx) {
        int tmp = currNode;
        while (true) {
            int curLength = tree[tmp].length;
            if (idx - curLength >= 1 && s.charAt(idx) == s.charAt(idx - curLength - 1))
                break;
            tmp = tree[tmp].suffixEdg;
        }
        if (tree[tmp].insertEdg[s.charAt(idx) - 'a'] != 0) {
            currNode = tree[tmp].insertEdg[s.charAt(idx) - 'a'];
            return;
        }
        ptr++;
        tree[tmp].insertEdg[s.charAt(idx) - 'a'] = ptr;
        tree[ptr] = new Node();
        tree[ptr].length = tree[tmp].length + 2;
        tree[ptr].end = idx;
        tree[ptr].start = idx - tree[ptr].length + 1;
        tmp = tree[tmp].suffixEdg;
        currNode = ptr;
        if (tree[currNode].length == 1) {
            tree[currNode].suffixEdg = 2;
            return;
        }
        while (true) {
            int curLength = tree[tmp].length;
            if (idx - curLength >= 1 && s.charAt(idx) == s.charAt(idx - curLength - 1))
                break;
            tmp = tree[tmp].suffixEdg;
        }
        tree[currNode].suffixEdg = tree[tmp].insertEdg[s.charAt(idx) - 'a'];
    }

    public static void main(String[] args) {
        root1.length = -1;
        root1.suffixEdg = 1;
        root2.length = 0;
        root2.suffixEdg = 1;
        tree[1] = root1;
        tree[2] = root2;
        ptr = 2;
        currNode = 1;
        s = "abcbab";
        int l = s.length();
        for (int i = 0; i < l; i++)
            insert(i);
        System.out.println("All distinct palindromic substrings for " + s + " :");
        for (int i = 3; i <= ptr; i++) {
            System.out.print((i - 2) + ") ");
            for (int j = tree[i].start; j <= tree[i].end; j++)
                System.out.print(s.charAt(j));
            System.out.println();
        }
    }
}
```