import java.net.*;
import java.io.*;
import java.util.*;

class DataClient
{
    public static void main(String[] args) {
	try {
	    //make connection to server socket
	    while(true)
		{
		    Socket sock= new Socket("127.0.0.1",6013);
	    
		    System.out.print("Client:");
		    Scanner sc = new Scanner(System.in);
		    String s = sc.nextLine();  
    
		    PrintWriter pout = new
			PrintWriter(sock.getOutputStream(), true);
		    pout.println("Client:"+s);

		    

		    InputStream in= sock.getInputStream();
		    BufferedReader bin = new
			BufferedReader(new InputStreamReader(in));
		    String sline=bin.readLine();
		    System.out.println(sline);
	    
		    sock. close() ;
		}
	}
	catch (IOException ioe) {
	    System.err.println(ioe);
	}
    }
}
