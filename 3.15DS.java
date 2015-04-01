import java.net.*;
import java.io.*;
 class  DataServer
{
    public static void main(String[] args) {
	try {
	    ServerSocket sock= new ServerSocket(6013);
	    
	    while (true) {
		Socket client= sock.accept();
		PrintWriter pout = new
		    PrintWriter(client.getOutputStream(), true);
		StringBuffer sb = new StringBuffer("Joke of the day : \nHAHA\nwhat a joke i can not stop Laughing");
		
		pout.println(sb);		
		client. close() ;
	    }
	}
	catch (IOException ioe) {
	    System.err.println(ioe);
	}
    }
}
