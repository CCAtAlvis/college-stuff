/*Experiment 2 -  Write a program to print grade of the
student according to given range using switch statement.*/ 

import java.util.*;
class grade
{
	public static void main (String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter marks of student");
		int marks = sc.nextInt();

		if (marks > 100)
			marks = -1;
		else
			marks = marks/10;

		switch (marks)
		{
			case 10:
			case 9:	System.out.println("Grade : A");
					break;

			case 8:
			case 7:	System.out.println("Grade : B");
					break;

			case 6:
			case 5:	System.out.println("Grade : C");
					break;

			case 4:
			case 3:	System.out.println("Grade : D");
					break;

			case 2:
			case 1:
			case 0:	System.out.println("FAIL");
					break;

			default:System.out.println("Invalid input");
		}
	}
}