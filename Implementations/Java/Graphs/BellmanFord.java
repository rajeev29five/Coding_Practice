import java.util.*;

class Graph
{
    int src;
    int des;
    int weight;
}

public class BellmanFord
{

    public static void bellmanFord(Graph graph[], int edges, int vertices, int sourceVertex)
    {
        int distance[] = new int[vertices+1];

        for(int i = 1; i<=vertices; i++)
        {
            distance[i] = Integer.MAX_VALUE;
        }
        distance[sourceVertex] = 0;
        for(int i = 1; i<vertices-1; i++)
        {
            for(int j = 1; j<=edges; j++)
            {
                int u = graph[j].src;
                int v = graph[j].des;
                int w = graph[j].weight;
                if(distance[u] != Integer.MAX_VALUE && distance[u] + w < distance[v])
                {
                    distance[v] = distance[u] + w;
                }
            }
        }

        for(int j = 1; j<=edges; j++)
        {
            int u = graph[j].src;
            int v = graph[j].des;
            int w = graph[j].weight;
            if(distance[u] != Integer.MAX_VALUE && distance[u] + w < distance[v])
            {
                System.out.println("-ve cycle detected");
                return;
            }   
        }

        System.out.println("*******OUTPUT******");
        for(int i = 1; i<distance.length; i++) 
        {
            System.out.println(i + " " + distance[i]);
        }
    }


    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int vertices = sc.nextInt();
        int edges = sc.nextInt();
        Graph graph[] = new Graph[edges+1];
        for(int i = 0; i<=edges; i++) graph[i] = null;

        for(int i = 1; i<=edges; i++)
        {
            Graph node = new Graph();
            node.src = sc.nextInt();
            node.des = sc.nextInt();
            node.weight = sc.nextInt();
            graph[i] = node;
        }
        bellmanFord(graph, edges, vertices, 1);
    }
}