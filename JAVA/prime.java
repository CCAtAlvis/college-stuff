//Experiment 3 - Write a program to display prime numbers between 1 to 1000.

class prime
{
	public static void main(String[] args)
	{
		int i,n,counter;
		boolean f;
		for(i=2;i<1000;i++)
		{
			n = i;
			f = true;
			counter = 1;

			while(counter*counter <= n)
			{
				if(counter != 1 && n%counter == 0)
				{
					f = false;
					break;
				}
				++counter;
			}

			if(f)
			{
				System.out.println(n + " is a prime");
			}
		}	
	}
}