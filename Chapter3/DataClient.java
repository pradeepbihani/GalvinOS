import java.net.*;
import java.io.*;
import java.util.*;

public class DataClient
{
    public static void main(String[] args) {
	try {
	    //make connection to server socket
	    Socket sock= new Socket("127.0.0.1",6013);
	    InputStream in= sock.getInputStream();
	    BufferedReader bin = new
		BufferedReader(new InputStreamReader(in));
	    
	    String line;
	    while ( (line = bin.readLine()) !=null)
		System.out.println(line);
	    
	    sock. close() ;
	}
	catch (IOException ioe) {
	    System.err.println(ioe);
	}
    }
}
