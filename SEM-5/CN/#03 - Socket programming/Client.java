// A Java program for a Client
import java.net.*;
import java.io.*;

public class Client
{
    // initialize socket and input output streams
    private Socket socket            = null;
    private DataInputStream  input   = null;
    private DataOutputStream out     = null;
    private DataInputStream serverRead = null;

    // constructor to put ip address and port
    public Client(String address, int port)
    {
        // establish a connection
        try
        {
            socket = new Socket(address, port);
            System.out.println("Connected");

            // takes input from terminal
            input  = new DataInputStream(System.in);

            // sends output to the socket
            out    = new DataOutputStream(socket.getOutputStream());

            serverRead = new DataInputStream(socket.getInputStream());
        }
        catch(UnknownHostException u)
        {
            System.out.println(u);
        }
        catch(IOException i)
        {
            System.out.println(i);
        }

        // string to read message from input
        String line = "";
        String serverWrite = "";

        // keep reading until "Over" is input
        while (!line.equals("Disconnect") || !serverWrite.equals("Disconnect"))
        {
            // reads message from client until "Over" is sent
            while (!line.equals("Over") || !line.equals("Disconnect"))
            {
                try
                {
                    line = input.readLine();
                    System.out.println(line);
                    out.writeUTF(line);
                }
                catch(IOException e)
                {
                    System.out.println(e);
                }
            }

            if (!line.equals("Disconnect"))
                break;

            while (!serverWrite.equals("Disconnect") || !serverWrite.equals("Over"))
            {
                try
                {
                    serverWrite = serverRead.readUTF();
                    System.out.println(serverWrite);
                }
                catch(IOException e)
                {
                    System.out.println(e);
                }
            }
        }


        // close the connection
        try
        {
            input.close();
            out.close();
            socket.close();
        }
        catch(IOException i)
        {
            System.out.println(i);
        }
    }

    public static void main(String args[])
    {
        Client client = new Client("localhost", 5000);
    }
}
