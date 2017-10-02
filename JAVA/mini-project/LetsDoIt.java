import java.io.*;
import java.util.concurrent.TimeUnit;
import java.util.ArrayList;
// import java.util.Vector;

class Encrypt
{
    protected FileInputStream fin = null;
    protected FileOutputStream fout = null;
    protected byte key = 1;

    public Encrypt ()
    {
        //wow, the default constructor
    }

    public Encrypt ( byte key )
    {
        //now lets set the key if sent by the user
        if ( key == 0 )
            this.key = (byte) ( Math.random() * 51 + 50 );
        else
            this.key = key;
    }

    public void set ( String fin )
    {
        try
        {
            this.fin = new FileInputStream( fin );
        }
        catch ( FileNotFoundException e )
        {
            System.out.println("OOPS!!! Looks like the file you want to encrypt does not exist.");
            return;
        }

        String fout = fin + ".ecnrypt";
        File file = new File( fout );
        file.delete();
        file = null;

        try
        {
            this.fout = new FileOutputStream( fout , true );
        }
        catch ( FileNotFoundException e )
        {
            System.out.println("OOPS!!! Looks like the file you want to encrypt does not exist.");
            return;
        }
    }

    // public void set ( FileOutputStream fout )
    // {
    //     this.fout = fout;
    // }

    public void set ( byte key )
    {
        if ( key == 0 )
            this.key = (byte) ( Math.random() * 51 + 50 );
        else
            this.key = key;
    }

    // this is the function that encrypts the file
    protected void LetsEncrypt ()
    {
        // function flow
        // 
        // old (inefficient) algo
        // 1: get the whole file and store it in fileArray
        // 2: ecnrypt is using : steps to encrypt (1)
        // 
        // new (efficient) algo
        // 1: get the file char by char
        // 2: encrypt it on the fly using : steps to encrypt (2)

        int i;
        // ArrayList fileArray = new ArrayList();
        // String fileString = "";
        ArrayList binaryChars = new ArrayList();
        String temp = "";
        //char binary = '\0';
        byte decimal;
        System.out.println("\nWow. The program now is encrypting your file!!!");

        // try to read from the file
        try {
            do
            {
                temp = "";
                i = fin.read();
                if ( i == -1 )
                    break;

                // System.out.print((char) i);
                // fileString = fileString + (char) i; 
                // fileArray.add( (char) i );

                temp = getBinary( (char) i );
                if ( i == 32 )
                    temp = "0" + temp;
                
                for ( i = 0; i < 7; i++ )
                    binaryChars.add( temp.substring( i, i + 1 ) );

                while ( binaryChars.size() > 3 )
                {
                    temp = "";
                    for ( i = 0; i < 4; i++ )
                        temp = temp + binaryChars.get( i );

                    decimal = getDecimal( temp );
                    fout.write( key + decimal );

                    binaryChars.remove( 0 );
                }
            }
            while ( i != -1 );

            for ( i = 0; i < binaryChars.size(); i++ )
                temp = temp + binaryChars.get( i );

            while ( 4 != temp.length() )
            {
                temp = "0" + temp;
            }

            decimal = getDecimal( temp );
            fout.write( key + decimal );

        }
        // catch the IOException if there is any error in reading the file
        catch ( Exception e )
        {
            System.out.println("OOPS!!! The file you want to encrypt does not want to get encrypted. Bad luck there.");
        }
        // and finaly *try and* close the file
        finally
        {
            // trying to close the file here
            try
            {
                fin.close();
                fout.close();
                System.out.println("YES!!! Your file is now encrypted.");                
            }
            // and catch Exception if we *the program actually* are no able to close the file
            catch ( Exception e )
            {
                System.out.println("OOPS!!! The file hit the fan and we were not able to Save it. Please try again and later if you want.");
            }
        }

        // thought (1) : it is easer to work with array than String directly so instead of using String fileString
        // thought of using 1: toCharArray()
        // then 2: use a char array instead of fileString and then toCharArray()
        // then 3: my mind clicked for vectors, aaj hi to skiha tha isliye
        // thoda search kiya to ArrayList bhi milgaya
        // then 4: searched difference between ArrayList and Vectors
        // here https://stackoverflow.com/questions/2986296/what-are-the-differences-between-arraylist-and-vector
        // it states "Use ArrayLists if there is no specific requirement to use Vectors."
        // so using ArrayList  
        // then 5: why do i even need to store the file in an ArrayList, i can simply do it on the fly as in thought (2)
        // now i am thinking fo using an ArrayList, see steps to encrypt (2)

        // Its time to encrypt the file. Fianlly
        // 
        // steps to encrypt (1)
        // 1: get 4 chars from the fileString
        // here the chars are not in blocks but continuous i.e. i->i+4, i+1->i+5 etc
        // 2: convert that char string to binary string use getBinary function
        // 3: convert that binary string to integer
        // 4: do operations over integer to get the encrypeted code
        // 5: merge the codes together to get the encrypeted file String 
        // now i think steps should have been started from 0, just a thought
        // 
        // steps to encrypt (2)
        // note : steps to encrypt (1) is kinda wrong and more importantly an inefficient algo
        // see function flow LetsEncrypt for proper difference between old (inefficient) and new (more efficient) algo
        // 1: get the char from file
        // 2: convert it to binary String
        // 3: convert that binary String to char array or better an ArrayList
        // 4: now get the 4 bits -> convert them to integer
        // 5: add that integer to the key
        // 6: type cast that key + integer to char and get whatever it is
        // 7: store (append) that into the output file
        // 8: remove the first the first (zeroth) element from the ArrayList or char array whatever it is
        // 9: repeat these steps from 4: to 8: till there are 4 bits left in the ArrayList or char array
        // 10: when we have less than 4 bits left convert the next char from file to binary and append in the array
        // 11: once there are no more chars in the file and only 3 chars in array append 0 at the end
        // 12: now convert these last 4 bits
        // 13: And Finally end of encryption
        // 
        // see the first try inside this function to see how goes.

        // if ( fileArray.size() < 3 )
        // {
        //     //        
        //     // for ( i = 0; i < 4; i++ )
        //     //     temp += fileArray.get(i);

        //     // temp = getBinary( temp );
        //     // binary = (char) Integer.parseInt( temp );

        //     // temp = "";
        // }
        // else
        // {
        //     for ( i = 0; i < fileArray.size() - 3 ; i++ )
        //     {
        //         // for ( int j = i; j < 4; j++ )
        //         //     temp += fileArray.get(j);

        //         // temp = getBinary( temp );
        //         // temp = fileArray.get( i );

        //         // thought (2) : first i thought of storing the whole file in binary in an string and then encrypt
        //         // now i am thinking that as the algo uses only 4 bits at a time, so as to reduce the memory consumption
        //         // encrypt on the go as and when we have less than 4 bits left convert the next char from file to binary

        //         temp = getBinary( ( char ) fileArray.get( i ) );
        //         // System.out.print( temp + "  " );
                

        //         // binary = (char) Integer.parseInt( temp );
        //         // System.out.print( binary + "  " );

        //         temp = "";
        //     }
        // }
    }

    protected String getBinary ( char in )
    {
        String bin = "";
        int num = ( int ) in ;

        // get the reversed binary string of the input 
        if ( num == 0 )
            bin = "0";

        while ( num > 0 )
        {
            bin = bin + num%2;
            num /= 2;
        }

        // reverse the string to get the binary string
        bin = reverseString( bin );

        // lets send it now to the function
        return bin;
    }

    protected String reverseString ( String str )
    {  
        StringBuilder sb = new StringBuilder(str);  
        sb.reverse();  
        return sb.toString();  
    }

    protected byte getDecimal ( String str )
    {
        byte num = 0;
        short inp = Short.parseShort( str );
        byte i = 0;

        while ( inp > 0 )
        {
            num += inp%10 * Math.pow( 2, i );
            inp /= 10;
            i++;
        }

        return num;
    }
}

class Program
{
    public static void main (String[] args) throws Exception
    {
        // Encrypt enc = new Encrypt();
        System.out.println("hello world, lets Encrypt");
        BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
        byte inp;
        do
        {
            System.out.println("Enter the encryption key. \nRemember key should be something from 50 to 100\nAnd only integers please, no floating pts");
            System.out.println("Enter 0 to genetrate a random key, w'll make sure its strong enough :)");
            inp = Byte.parseByte( br.readLine() );
        }
        while ( inp != 0 && ( inp < 50 || inp > 100 ));

        Encrypt enc = new Encrypt( inp );
        enc.set( "sampleInput.txt" );
        enc.LetsEncrypt();

        // System.out.println(enc.fin);
        // for (; ; )
        // {
        //     System.out.print("a");
        //     try {                
        //         TimeUnit.MILLISECONDS.sleep(10);
        //     }
        //     catch ( Exception e )
        //     {

        //     }

        //     System.out.print("\b");
        //     try {                
        //         TimeUnit.MILLISECONDS.sleep(10);
        //     }
        //     catch ( Exception e )
        //     {

        //     }

        // }
    }
}