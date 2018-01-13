using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Animation
{
    public partial class Form1 : Form
    {
        Image spider;      // image of spider
        float Angle = 0; 　// 擺盪的角度
        float Angle_D = 1; // 角度的遞增值
        int spider_y = 100; // 之豬的y軸高度	
        Pen myPen = new Pen(Color.DarkGray, 2); // 汁豬思
        int kukuIndex = 0;

        public Form1()
        {
            InitializeComponent();
            //this.ClientSize = new Size(1200, 800); // 設定視窗客戶區的寬高
            spider = new Bitmap(Properties.Resources.sp);            
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
			int x = this.ClientSize.Width/2;
			int y = this.ClientSize.Height/2;

            /*
            // Method 1
            e.Graphics.TranslateTransform(x, 0); // 平移畫布的原點
            e.Graphics.RotateTransform(Angle);　// 旋轉畫布

            // 化出汁豬的影像
            e.Graphics.DrawImage(spider, -spider.Width/2, spider_y);            
            // 化出汁豬思
            e.Graphics.DrawLine(myPen, 0, 0, 0, spider_y+32);
            //畫出歐噴哭哭
            e.Graphics.DrawImage(openkuku.Images[kukuIndex], 100, 400);
            */


            // Method 2
            Bitmap scr = new Bitmap(820, 640);  // whole screen image
            Graphics dr1 = Graphics.FromImage(scr);  // 圖層1
            Graphics dr2 = Graphics.FromImage(scr);  // 圖層2
            
            //平移畫布的原點
			dr1.TranslateTransform(x,0);
			//旋轉畫布
			dr1.RotateTransform(Angle);
			//化出汁豬的影像
			dr1.DrawImage(spider, -spider.Width/2, spider_y, spider.Width, spider.Height);
			//化出汁豬思
			dr1.DrawLine(myPen,0,0,0,spider_y+32);
								 
			//畫出歐噴哭哭
			dr2.DrawImage(openkuku.Images[kukuIndex],100,400);
            
            e.Graphics.DrawImage(scr,0,0);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Angle = Angle + Angle_D;　// 更新擺盪的角度
            if (Angle > 60 || Angle < -60)
                Angle_D = -Angle_D;
            this.Invalidate(); // 重畫
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            kukuIndex++;
            if (kukuIndex == openkuku.Images.Count)
                kukuIndex = 0;
            this.Invalidate();
        }
    }
}
