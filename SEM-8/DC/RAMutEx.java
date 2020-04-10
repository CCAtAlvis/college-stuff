import java.util.*;

public class RAMutEx {
  public static void main(String args[]) {
    String temp;
    int k;
    Scanner in = new Scanner(System.in);

    System.out.print("Enter the number of processes: ");
    int n = in.nextInt();

    int[][] process = new int[n][3];
    for (int i = 0; i < n; i++) {
      process[i][0] = i;
      process[i][2] = 0;

      System.out.print("Enter state of process " +i+ ": ");
      temp = in.next();
      if (temp.equals("none")) {
        process[i][1] = 0;
      } else if (temp.equals("wanted")) {
        process[i][1] = 1;
      } else if (temp.equals("held")) {
        process[i][1] = 2;
      }
    }

    for (int i = 0; i < n; i++) {
      if (process[i][1] == 1) {
        for (int j = 0; j < n; j++) {
          if (i == j) continue;

          System.out.println("Process "+process[i][0] +" sends request to process "+process[j][0]);
          if (process[j][1] == 2) {
            System.out.println("Process "+process[j][0] +" is in CS. process "+process[i][0] +" is queued");
          } else if (process[j][1] == 0) {
            System.out.println("Process "+process[j][0] +" sends OK message to process "+process[i][0]);
            process[i][2] = process[i][2] + 1;
          } else if (process[j][1] == 1) {
            System.out.println("Its a conflict");
            if (process[j][0] > process[i][0]) {
              System.out.println("Process "+process[j][0] +" doesn't send OK message to process "+process[i][0] +" as it's ID is greater. It is queued");
            } else {
              System.out.println("Process "+process[j][0] +" sends OK message to process "+process[i][0] +" as it's ID is lesser");
            }
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      if (process[i][2] == n - 1) {
        System.out.println("Process "+process[i][0] +" enters CS.");
      }
    }
  }
}