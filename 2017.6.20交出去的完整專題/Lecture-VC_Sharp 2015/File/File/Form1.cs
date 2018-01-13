using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO; // 檔案相關 for BinaryWriter BinaryReader


namespace Filedemo
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // 檔案設定
            FileStream outFile = new FileStream("..//..//..//Resources//mynewfile.txt", FileMode.Create, FileAccess.Write);

            // 建立檔案流
            StreamWriter streamOut = new StreamWriter(outFile);

            // 寫檔
            streamOut.WriteLine(textBox1.Text);
            streamOut.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            // 先確定檔案存在
            if (!File.Exists("..//..//..//Resources//mynewfile.txt")) 
					 return; 
				
				 // 檔案設定
                 FileStream fileInput = new FileStream("..//..//..//Resources//mynewfile.txt", FileMode.OpenOrCreate, FileAccess.ReadWrite);
				 // 開啟檔案
				 StreamReader streamIn = new StreamReader(fileInput);
				 
				 // 讀檔
				 while(!streamIn.EndOfStream)
				 {
					 textBox2.Text = textBox2.Text + streamIn.ReadLine();	
					 textBox2.Text = textBox2.Text + Environment.NewLine;
				 }
				 streamIn.Close();
        }        

        private void button3_Click(object sender, EventArgs e)
        {
             String a_string = "Openkuku";  // 字串
			 float a_float = 3.1415926f;     // 四位元組浮點數
			 int an_int = 99;                // 整數
			 bool a_bool = true;             // 一位元組的 Boolean 值
			 
			 // 開啟檔案
             BinaryWriter outFile = new BinaryWriter(File.Open("..//..//..//Resources//myFile.dat", FileMode.Create)); 
             
			 outFile.Write(a_string); // 寫入 字串
			 outFile.Write(a_float);  // 寫入 四位元組浮點數
			 outFile.Write(an_int);   // 寫入 整數
			 outFile.Write(a_bool);   // 寫入 一位元組的 Boolean 值

			 outFile.Close(); // 關閉檔案
        }

        private void button4_Click(object sender, EventArgs e)
        {
            // 先確定檔案存在
            if (!File.Exists("..//..//..//Resources//myFile.dat")) 
				 return; 
			 // 開啟檔案
             BinaryReader inFile = new BinaryReader(File.Open("..//..//..//Resources//myFile.dat", FileMode.Open)); 

			 String my_string;
			 float my_float;
			 int my_int;
			 bool my_bool;

			 textBox2.Text = ""; // 文字方塊 先清空
			 while (inFile.PeekChar() != -1) // 傳回下一個可供使用的字元，但不消耗它
			 {
				 my_string = inFile.ReadString(); // 讀出 字串
				 my_float = inFile.ReadSingle();  // 讀出 四位元組浮點數
				 my_int = inFile.ReadInt32();     // 讀出 整數
				 my_bool = inFile.ReadBoolean();  // 讀出 一位元組的 Boolean 值

				 textBox2.Text = textBox2.Text + my_string + Environment.NewLine;
				 textBox2.Text = textBox2.Text + my_float.ToString() + Environment.NewLine;
				 textBox2.Text = textBox2.Text + my_int.ToString() + "\n";
				 textBox2.Text = textBox2.Text + my_bool.ToString() + Environment.NewLine;
			 }

			 inFile.Close(); // 關閉檔案
        }

        private void button5_Click(object sender, EventArgs e)
        {
            String myfile = "";

            // 由 Open File Dialog 得到檔案名字
            saveFileDialog1.ShowDialog();
            myfile = saveFileDialog1.FileName;
            // 設定檔案
            FileStream outFile = new FileStream(myfile, FileMode.Create, FileAccess.Write);
            // 開檔
            StreamWriter streamOut = new StreamWriter(outFile);
            // 寫檔
            streamOut.WriteLine(textBox1.Text);
            streamOut.Close();
        }        

        private void button6_Click(object sender, EventArgs e)
        {
             String myfile = "";
			 
			 // 由 Open File Dialog 得到檔案名字
			 openFileDialog1.ShowDialog() ;
			 myfile = openFileDialog1.FileName;
			 
			 // 設定檔案
			 FileStream fileInput = new FileStream(myfile, FileMode.OpenOrCreate, FileAccess.ReadWrite);
			 // 開檔
			 StreamReader streamIn = new StreamReader(fileInput);
			 // 讀檔
			 while(!streamIn.EndOfStream)
			 {
				 textBox2.Text = textBox2.Text + streamIn.ReadLine();
			 }
			 streamIn.Close();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
