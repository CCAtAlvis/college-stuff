//Experiment 6 - Write a program to implement method overloading to calculate area of rectangle, square and circle.

import java.util.*;
class MO
{
	static float area(int l,int b)
	{
		return (l*b);
	}

	static float area(int a)
	{
		return a*a;
	}

	static float area(float r)
	{
		return r*r*3.14159f;
	}

	public static void main(String[] args) 
	{
		double ar = 0;
		Scanner sc = new Scanner(System.in);
		System.out.println("1. Area of rectangle\n2.Area of square\n3.Area of circle\nEnter your choice");
		int choice = sc.nextInt();

		switch(choice)
		{
			case 1:	System.out.println("Enter length and breath");
					int l = sc.nextInt();
					int b = sc.nextInt();
					ar = area(l,b);
					break;

			case 2:	System.out.println("Enter side");
					int a = sc.nextInt();
					ar = area(a);
					break;

			case 3:	System.out.println("Enter radius");
					float r = sc.nextFloat();
					ar = area(r);
					break;

			default:System.out.println("Invalid input");
					System.exit(0);
		}	
		System.out.println("Area = " +ar);
	}
}