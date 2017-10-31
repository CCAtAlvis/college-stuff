/*Experiment 1 - Write a program to demonstrate different methods (Using Scanner  class,  
BufferedReader class and Command line)to take input for different data types in Java.
Also shift a number three bits right and display the result. */

import java.io.*;
import java.util.*;
class input
{
	static void scanner_input ()
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter a string(using Scanner)");
		String s = sc.nextLine();
		System.out.println("Entered String is : "+s);
		System.out.println("Enter a number(using Scanner)");
		double n = sc.nextDouble();
		System.out.println("Entered number is : "+n);
	}

	static void buffered_input () throws IOException
	{ 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		System.out.println("Enter a string(using BufferedReader)");
		String s = br.readLine();
		System.out.println("Entered number is : "+s);
		System.out.println("Enter a number(using BufferedReader)");
		double n = Double.parseDouble(br.readLine());
		System.out.println("Entered number is : "+n);	
	}

	static void right_shift ()
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a number");
		int num = sc.nextInt();
		System.out.println("After shifting :"+(num>>3));
	}

	public static void main (String[] args) 
	{
		String s = args[0];
		double d = Double.parseDouble(args[1]);
		System.out.println("String entered via command line : " + s);
		System.out.println("Number entered via command line : " + d);
		
		scanner_input();
		right_shift();

		try
		{
			buffered_input();
		}
		catch (Exception e)
		{
			System.out.println(e);
		}
	}
}