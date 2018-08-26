//
// Code Contributor(s): Rajeev Ranjan
//

import java.util.Scanner;
import java.lang.*;
import java.io.*;

class KMP
{
	public static int[] computePrefix(String pattern)
	{
		int l = pattern.length();
		int prefix[] = new int[l];
		prefix[0] = 0;
		for(int i = 1, j = 0; i < l; i++)
		{
			while(j > 0 && pattern.charAt(i) != pattern.charAt(j))
			{
				j = prefix[j-1];
			}
			if(pattern.charAt(i) == pattern.charAt(j))
			{
				prefix[i] = ++j;
			}
			else
			{
				prefix[i] = j;
			}
		}
		return prefix;
	}

	public static void KMP(String s, String pattern)
	{
		int lenOfOrg = s.length();
		int lenOfPat = pattern.length();
		int prefixArray[] = computePrefix(pattern);
		for(int i = 0, j = 0; i<lenOfOrg; i++)
		{
			while(j > 0 && s.charAt(i) != pattern.charAt(j))
			{
				j = prefixArray[j-1];
			}
			if(s.charAt(i) == pattern.charAt(j))
			{
				j++;
			}
			if(j == lenOfPat)
			{
				System.out.println("Patten starts at " + (i-lenOfPat+1) + " ends at " + i);
				j = prefixArray[j-1];
			}
		}
	}


	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0)
		{
			String s = sc.next();
			String pattern = sc.next();
			KMP(s, pattern);
		}
	}
}
