import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;

//Texteditor class starts here  
class Texteditor extends Frame implements ActionListener
{
    TextArea ta = new TextArea();
    int i, len1, len, pos1;
    String str = "", s3 = "", s2 = "", s4 = "", s32 = "", s6 = "", s7 = "", s8 = "", s9 = "";
    CheckboxMenuItem chkb = new CheckboxMenuItem( "Word Wrap" );

    public Texteditor ()
    {
        MenuBar mb = new MenuBar();
        setLayout(new BorderLayout());
        add("Center", ta);
        setMenuBar(mb);

        Menu m1 = new Menu("File");
        Menu m2 = new Menu("Edit");
        Menu m3 = new Menu("Tools");
        Menu m4 = new Menu("Help");
        mb.add(m1);
        mb.add(m2);
        mb.add(m3);

        MenuItem mi1[] = { new MenuItem("New"),
        new MenuItem("Open"),
        new MenuItem("Save"),
        new MenuItem("Save As"),
        new MenuItem("Exit")};

        MenuItem mi2[] = { new MenuItem("Delete"),
        new MenuItem("Cut"),
        new MenuItem("Copy"),
        new MenuItem("Paste"),
        new MenuItem("Select All")};

        MenuItem mi3[] = { new MenuItem("Compile"),
        new MenuItem("Run")};

        for (int i = 0; i<mi1.length; i++)
        {
            m1.add(mi1[i]);
            mi1[i].addActionListener(this);
        }

        for (int i = 0; i<mi2.length; i++)
        {
            m2.add(mi2[i]);
            mi2[i].addActionListener(this);
        }

        m3.add(chkb);
        chkb.addActionListener(this);

        for (int i = 0; i<mi3.length; i++)
        {
            m3.add(mi3[i]);
            mi3[i].addActionListener(this);
        }

        MyWindowsAdapter mw = new MyWindowsAdapter(this);
        addWindowListener(mw);
        setSize(500,500);
        setTitle("untitled notepad");
        setVisible(true);
    }

    public void actionPerformed(ActionEvent ae)
    {
        String arg = (String)ae.getActionCommand();

        if (arg.equals("New"))
        {
            dispose();
            Texteditor t11=new Texteditor();
            t11.setSize(500,500);
            t11.setVisible(true);
        }

        try
        {  
            if (arg.equals("Open"))
            {
                FileDialog fd1 = new FileDialog(this,"Select File",FileDialog.LOAD);
                fd1.setVisible(true);

                String s4 = "";
                s2 = fd1.getFile();
                s3 = fd1.getDirectory();
                s32 = s3+s2;

                File f = new File(s32);
                FileInputStream fii = new FileInputStream(f);

                len = (int)f.length();
                for(int j = 0; j<len; j++)
                {
                    char s5=(char)fii.read();
                    s4=s4 + s5;
                }

                ta.setText(s4);
            }
        }
        catch (IOException e)
        {
        }

        try
        {
            if (arg.equals("Save As"))
            {
                FileDialog dialog1 = new FileDialog(this,"Save As",FileDialog.SAVE);
                dialog1.setVisible(true);
                s7 = dialog1.getDirectory();
                s8 = dialog1.getFile();
                s9 = s7+s8+".txt";
                s6 = ta.getText();
                len1 = s6.length();
                byte buf[] = s6.getBytes();
                File f1 = new File(s9);
                FileOutputStream fobj1 = new FileOutputStream(f1);

                for(int k = 0; k<len1; k++)
                    fobj1.write(buf[k]);

                fobj1.close();
            }

            this.setTitle(s8 + " Texteditor File");
        }
        catch (IOException e)
        {
        }

        if (arg.equals("Exit"))
            System.exit(0);

        if (arg.equals("Cut"))
        {
            str = ta.getSelectedText();
            i = ta.getText().indexOf(str);
            ta.replaceRange(" ", i, i+str.length());
        }

        if (arg.equals("Copy"))
            str = ta.getSelectedText();

        if (arg.equals("Paste"))
        {
            pos1 = ta.getCaretPosition();
            ta.insert(str, pos1);
        }

        if (arg.equals("Delete"))
        {
            String msg = ta.getSelectedText();
            i = ta.getText().indexOf(msg);
            ta.replaceRange(" ", i, i+msg.length());
            msg="";
        }

        if (arg.equals("Select All"))
            ta.select(0, ta.getText().length());

        try
        {
            if (arg.equals("Compile"))
            {
                s32 = s3+s2;
                String cmd = "javac " + s32;
                Runtime run = Runtime.getRuntime();
                Process pr = run.exec(cmd);
                System.out.println("Complie Command Successful!");
            }
        }
        catch (Exception e)
        {
            System.out.println("Complie Command Error!!!");
            System.out.println("cought e : " + e);
        }

        try
        {
            if (arg.equals("Run"))
            {
                String file = s2.substring(0, s2.length() - 5);
                String cmd = "java " + s3 + file;
                Runtime run = Runtime.getRuntime();
                Process pr = run.exec(cmd);
                System.out.println("Run Command Successful");
            }
        }
        catch (Exception e)
        {
            System.out.println("Run Command Error!!!");
            System.out.println("cought e : " + e);
        }

    }

    public class MyWindowsAdapter extends WindowAdapter
    {
        Texteditor tt;

        public MyWindowsAdapter(Texteditor ttt)
        {
            tt=ttt;
        }

        public void windowClosing(WindowEvent we)
        {
            tt.dispose();
        }
    }
}

public class project
{
    public static void main(String args[])
    {
        Texteditor to=new Texteditor();
    }
}
