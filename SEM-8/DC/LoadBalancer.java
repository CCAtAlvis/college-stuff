import java.util.*;  

public class LoadBalancer {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter number of processes: ");
		int p = sc.nextInt();
		System.out.print("Enter number of servers: ");
		int sCount = sc.nextInt();

		int s = 0;
		for (int i=0; i<p; ++i) {
			System.out.println("process " + (i+1) + " is assigned to server " + (s+1));
			s++;
			s %= sCount;
		}
	}
}