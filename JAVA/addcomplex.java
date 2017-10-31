/*Experiment 5 - Write a program to perform addition of two 
complex numbers using constructor by passing and returning object.*/

import java.util.*;
class number
{
	int real,im;

	number ()
	{
		real=0; im=0;
	}

	number (int r,int i)
	{
		real=r; im=i;
	}

	void display ()
	{
		System.out.println(" Number is "+real+"+"+im+"i");
	}

	number add (number num)
	{
		number answer = new number();
		answer.real =real+num.real;
		answer.im =im+num.im;
		return answer;
	}
}

class addcomplex
{
	public static void main (String[] args) 
	{   
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter real part of 1st number ");
		int realnum = sc.nextInt();
		
		System.out.println("Enter imaginary part of 1st number ");
		int imaginary = sc.nextInt();
		number c1 = new number(realnum,imaginary);
		
		System.out.println("Enter real part of 2nd number ");
		int realnum1 = sc.nextInt();
		
		System.out.println("Enter imaginary part of 2nd number ");
		int imaginary1 = sc.nextInt();
        
		number c2 = new number(realnum1, imaginary1);
        number c3 = new number();
        c3 = c1.add(c2);

        c3.display(); 
	}
}