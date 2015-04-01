import java.net.*;
import java.io.*;
import java.util.*;
 class  DataServer
{
    public static void main(String[] args) {
	try {
	    ServerSocket sock= new ServerSocket(6013);
	    
	    while (true) {
		Socket client= sock.accept();		
		
		InputStream in= client.getInputStream();
		BufferedReader bin = new
		    BufferedReader(new InputStreamReader(in));
		String cline =bin.readLine();
		System.out.print(cline+"\nServer:");
	       

		Scanner sc = new Scanner(System.in);
		String sline = sc.nextLine();
		/*while ( (line = bin.readLine()) !=null)
		  {  System.out.println(line);}*/
		
		
		PrintWriter pout = new
		    PrintWriter(client.getOutputStream(), true);
		pout.println("server:"+sline);

		client. close() ;
	    }
	}
	catch (IOException ioe) {
	    System.err.println(ioe);
	}
    }
}
