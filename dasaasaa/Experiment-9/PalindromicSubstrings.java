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