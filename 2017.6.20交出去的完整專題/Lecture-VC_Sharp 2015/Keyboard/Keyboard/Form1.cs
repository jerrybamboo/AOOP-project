using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Keyboard
{
    public partial class Form1 : Form
    {
        Label[] labelList = new Label[41]; // A ~ Z和空白鍵值

        /*
        // Multi-Dimensional Array in C# 
        // https://msdn.microsoft.com/zh-tw/library/2yd9wwz4.aspx
        // Two-dimensional array.
        int[,] array2D = new int[,] { { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } };
        // The same array with dimensions specified.
        int[,] array2Da = new int[4, 2] { { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } };
        // A similar array with string elements.
        string[,] array2Db = new string[3, 2] { { "one", "two" }, { "three", "four" },{ "five", "six" } };
        */

        public Form1()
        {
            InitializeComponent();

            // 在41個按鍵的 Tag 放入 代表的 KeyCode
			label1.Tag = Keys.Q; label2.Tag = Keys.W; label3.Tag = Keys.E;
			label4.Tag = Keys.R; label5.Tag = Keys.T; label6.Tag = Keys.Y;
			label7.Tag = Keys.U; label8.Tag = Keys.I; label9.Tag = Keys.O;
			label10.Tag = Keys.P; label11.Tag = Keys.A; label12.Tag = Keys.S;
			label13.Tag = Keys.D; label14.Tag = Keys.F; label15.Tag = Keys.G;
			label16.Tag = Keys.H; label17.Tag = Keys.J; label18.Tag = Keys.K;
			label19.Tag = Keys.L; label20.Tag = Keys.Z; label21.Tag = Keys.X;
			label22.Tag = Keys.C; label23.Tag = Keys.V; label24.Tag = Keys.B;
			label25.Tag = Keys.N; label26.Tag = Keys.M; label27.Tag = Keys.Alt;
			label28.Tag = Keys.Control; label29.Tag = Keys.Shift; label30.Tag = Keys.Space;
			label31.Tag = Keys.F1; label32.Tag = Keys.F2; label33.Tag = Keys.F3; label34.Tag = Keys.F4;
			label35.Tag = Keys.F5; label36.Tag = Keys.F6; label37.Tag = Keys.F7; label38.Tag = Keys.F8;
			label39.Tag = Keys.F9; label40.Tag = Keys.F10; label41.Tag = Keys.F11;

			// 以陣列 取代 在41個 label 元件
			labelList[0] = label1; labelList[1] = label2; labelList[2] = label3;
			labelList[3] = label4; labelList[4] = label5; labelList[5] = label6;
			labelList[6] = label7; labelList[7] = label8; labelList[8] = label9;
			labelList[9] = label10; labelList[10] = label11; labelList[11] = label12;
			labelList[12] = label13; labelList[13] = label14; labelList[14] = label15;
			labelList[15] = label16; labelList[16] = label17; labelList[17] = label18;
			labelList[18] = label19; labelList[19] = label20; labelList[20] = label21;
			labelList[21] = label22; labelList[22] = label23; labelList[23] = label24;
			labelList[24] = label25; labelList[25] = label26; labelList[26] = label27;
			labelList[27] = label28; labelList[28] = label29; labelList[29] = label30;
			labelList[30] = label31; labelList[31] = label32; labelList[32] = label33;
			labelList[33] = label34; labelList[34] = label35; labelList[35] = label36;
			labelList[36] = label37; labelList[37] = label38; labelList[38] = label39;
			labelList[39] = label40; labelList[40] = label41;
        }

        // 有鍵盤按鍵被按下
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Alt || e.Control || e.Shift)
			{
			    if (e.Alt) 
                    labelList[26].BackColor = Color.LawnGreen;
				if (e.Control) 
                    labelList[27].BackColor = Color.LawnGreen;
				if (e.Shift) 
                    labelList[28].BackColor = Color.LawnGreen;

				for (int i = 0; i < labelList.Length; i++)
				{
				    if (e.KeyCode == (Keys)labelList[i].Tag)
					    labelList[i].BackColor = Color.LawnGreen; // 將被按下的按鍵 變為綠色
			    }		 
			}
			else
			{
                for (int i = 0; i < labelList.Length; i++)
                {
                    if (e.KeyCode == (Keys)labelList[i].Tag)
                        labelList[i].BackColor = Color.Red; // 將被按下的按鍵 變為紅色
                }		 
			}
        }

        // 有鍵盤按鍵被放開
        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            
            // not including in KeyCode
            labelList[26].BackColor = Color.CornflowerBlue;
			labelList[27].BackColor = Color.CornflowerBlue;
			labelList[28].BackColor = Color.CornflowerBlue;
			
			for (int i = 0; i < labelList.Length; i++)
			{
			    if (e.KeyCode == (Keys)labelList[i].Tag)
				    labelList[i].BackColor = Color.CornflowerBlue; // 將被放開的按鍵 變為藍色
			}
        }
    }
}
