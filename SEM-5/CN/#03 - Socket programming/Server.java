import java.net.*;
import java.io.*;

public class Server
{
    //initialize socket and input stream
    private Socket           socket   = null;
    private ServerSocket     server   = null;
    private DataInputStream  in       = null;
    private DataInputStream serverRead = null;
    private DataOutputStream out      = null;

    // constructor with port
    public Server(int port)
    {
        // starts server and waits for a connection
        try
        {
            server = new ServerSocket(port);
            System.out.println("Server started");

            System.out.println("Waiting for a client ...");

            socket = server.accept();
            System.out.println("Client accepted");

            // takes input from the client socket
            in = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
            serverRead = new DataInputStream(System.in);
            out = new DataOutputStream(socket.getOutputStream());

            String inLine = "";
            String serverWrite = "";

            while (!inLine.equals("Disconnect") || !serverWrite.equals("Disconnect"))
            {
                // reads message from client until "Over" is sent
                while (!inLine.equals("Over") || !inLine.equals("Disconnect"))
                {
                    try
                    {
                        inLine = in.readUTF();
                        System.out.println(inLine);
                    }
                    catch(IOException e)
                    {
                        System.out.println(e);
                    }
                }

                if (!inLine.equals("Disconnect"))
                    break;

                while (!serverWrite.equals("Disconnect") || !serverWrite.equals("Over"))
                {
                    try
                    {
                        serverWrite = serverRead.readLine();
                        out.writeUTF(serverWrite);
                    }
                    catch(IOException e)
                    {
                        System.out.println(e);
                    }
                }
	    }

            System.out.println("Closing connection");

            // close connection
            socket.close();
            in.close();
        }
        catch(IOException e)
        {
            System.out.println(e);
        }
    }

    public static void main(String args[])
    {
        Server server = new Server(5000);
    }
}
