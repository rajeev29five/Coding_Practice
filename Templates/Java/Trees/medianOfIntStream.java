//
// Code Contributor(s) : Rajeev Ranjan
//even better i like it

import java.util.Scanner;
import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.Iterator;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class CustomComparator implements Comparator<Integer>
{
    public int compare(Integer a, Integer b)
    {
        return b - a;
    }
}

public class medianStream
{
    public static void main(String[] args)throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>(new CustomComparator());
        double median = 0.0;
        int curr;
        while(sc.hasNext())
        {
            curr = sc.nextInt();
            if(minHeap.size() == maxHeap.size())
            {
                if(curr < median)
                {

                    maxHeap.add(curr);
                    median = maxHeap.peek();
                    System.out.println("Median : " + (int)median);
                }
                else
                {
                    minHeap.add(curr);
                    median = minHeap.peek();
                    System.out.println("Median : " + (int)median);
                }
            }
            else if ( minHeap.size() < maxHeap.size())
            {
                if(curr < median)
                {
                    minHeap.add(maxHeap.poll());
                    maxHeap.add(curr);
                }
                else
                {
                    minHeap.add(curr);
                }
                median = (maxHeap.peek() + minHeap.peek())/2.0;
                System.out.println("Median : " + median);
            }
            else
            {
                if(curr < median)
                {
                    maxHeap.add(curr);
                }
                else
                {
                    maxHeap.add(minHeap.poll());
                    minHeap.add(curr);
                }
                median = (maxHeap.peek() + minHeap.peek())/2.0;
                System.out.println("Median : " + median);
            }
        }
        // minHeap.add(1);
        // minHeap.add(2);
        // minHeap.add(5);
        // minHeap.add(-1);
        // while(!minHeap.isEmpty())
        // {
        //     System.out.print(minHeap.poll() + " ");
        // }
    }
}
