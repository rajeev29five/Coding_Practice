//
// Code Contributor(s): Rajeev Ranjan
//

import java.util.Scanner;
import java.util.Arrays;

class Adj{
    int data;
    Adj next;
}

public class DFS{

    public static Adj headInsert(Adj adjList, int vertex){
        Adj newNode = new Adj();
        newNode.data = vertex;
        newNode.next = adjList;

        return newNode;
    }

    public static void display(Adj adjList[], int vertices){
        for(int i = 0; i<=vertices; i++){
            Adj temp = adjList[i];
            System.out.print("adj["+i+"]->");
            while(temp != null){
                System.out.print(temp.data + "->");
                temp = temp.next;
            }
            System.out.println("null");
        }
    }

    public static void dfs(Adj adjList[], int i, boolean visited[], int parent[]){
        visited[i] = true;
        Adj temp = adjList[i];
        while(temp != null){
            if(!visited[temp.data]){
                parent[temp.data] = i;
                dfs(adjList, temp.data, visited, parent);
            }
            temp = temp.next;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int vertices = sc.nextInt();
        int edges = sc.nextInt();
        Adj adjList[] = new Adj[vertices+1];
        for(int i = 0; i<=vertices; i++) {
            adjList[i] = null;
        }
        for(int i = 1; i<=edges; i++){
            int start = sc.nextInt();
            int end = sc.nextInt();
            adjList[start] = headInsert(adjList[start], end);
        }
        display(adjList, vertices);
        boolean visited[] = new boolean[vertices+1];
        Arrays.fill(visited, false);
        int parent[] = new int[vertices+1];
        Arrays.fill(parent, -1);
        parent[1] = 0;
        for(int i = 1; i<=vertices; i++){
            if (!visited[i]) {
                dfs(adjList, i, visited, parent);
            }
        }
        for(int i = 1; i<=vertices; i++){
            System.out.println("parent[" + i + "]->" + parent[i]);
        }
    }
}
