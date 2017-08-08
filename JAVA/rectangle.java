/*Experiment 4 - Write a program to create a Rectangle class, objects and implement
methods to read dimensions, calculate area of rectangle and display dimensions and area.*/

import java.util.*;
class rectangle
{
	double length, width, area;

	void accept(double l, double w)
	{
		length = l;
		width = w;
	}

	void area()
	{
		area = length*width;
	}

	void displayArea()
	{
		System.out.println("area of the box is: " + area);
	}

	void displayDimensions()
	{
		System.out.println("dimensions of the box are: length = " + length + " width = " + width);
	}

}

class rectMain
{
	public static void main(String args[])
	{
		double length, width;
		Scanner s = new Scanner(System.in);
		System.out.println("enter length and width of the rectangle ");
		length = s.nextDouble();
		width = s.nextDouble();

		rectangle r = new rectangle();
		r.accept(length, width);
		r.area();
		r.displayDimensions();
		r.displayArea();
	}
}