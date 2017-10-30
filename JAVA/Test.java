import java.sql.*;
class Test
{
public static void main(String args[])
{
try{
//String url="jdbc:odbc:logingdsn";
Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
Connection c=DriverManager.getConnection("jdbc.ucanaccess:c://Desktop//jdbc//login.accdb");
Statement st1=c.createStatement();
int n=st1.executeUpdate("Insert into logindatabase values('Sayali')");
Statement st=c.createStatement();
ResultSet rs=st.executeQuery("Select * from logindatabase");

while(rs.next()){
System.out.println("rs.getInt(1)+rs.getString(2)");
}
}catch(Exception ee)
{
System.out.println(ee);
}
}
}