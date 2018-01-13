using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

// 使用Visual Basic
// Project上按右鍵->Add Reference->.Net->Microsoft.VisualBasic
using Microsoft.VisualBasic;
using Microsoft.VisualBasic.Devices;

// 使用 SystemSound 和 SoundPlayer
using System.Media;

// 用Windows Media Player
// 首先，在Toolbox裡面，右键->Choose Items->選擇“COM Components”，選“Windows Media Player”->OK   
// 然後，將“Windows Media Player”從工具箱拖放到你的Design Form中，AxWMPLib和WMPLib的引用就會自動添加進來


namespace Sound
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        // 要加入 參考 -> Microsoft.VisualBasic
		Computer myComputer = new Computer();

        // 播放在 Windows 音效配置中事件相關的音效
        private void button1_Click(object sender, EventArgs e)
        {
            myComputer.Audio.PlaySystemSound(SystemSounds.Asterisk);
			//myComputer.Audio.PlaySystemSound(System.Media.SystemSounds.Beep);
			//myComputer.Audio.PlaySystemSound(System.Media.SystemSounds.Exclamation);
			//myComputer.Audio.PlaySystemSound(System.Media.SystemSounds.Hand);
			//myComputer.Audio.PlaySystemSound(System.Media.SystemSounds.Question);
        }

        // 播放外部的聲音檔
        private void button2_Click(object sender, EventArgs e)
        {
            //myComputer.Audio.Play("..//..//..//Resources//PLANE04.WAV");

			//等候播放完成後再繼續執行程式碼
			//myComputer.Audio.Play("..//..//..//Resources//PLANE04.WAV", AudioPlayMode.WaitToComplete);
			//在背景中撥放聲音，程式碼會繼續執行
			//myComputer.Audio.Play("..//..//..//Resources//PLANE04.WAV", AudioPlayMode.Background);
			//在背景中撥放聲音，直到乎叫Stop()方法。程式碼會繼續執行
			myComputer.Audio.Play("..//..//..//Resources//PLANE04.WAV", AudioPlayMode.BackgroundLoop);		
        }

        // 停止播放
        private void button3_Click(object sender, EventArgs e)
        {
            myComputer.Audio.Stop();
        }

        // 使用 SystemSound 和 SoundPlayer
        // 播放 Windows 作業系統音效事件類型關聯的音效
        private void button4_Click(object sender, EventArgs e)
        {
            SystemSounds.Asterisk.Play();
			//SystemSounds.Beep.Play();
			//SystemSounds.Exclamation.Play();
			//SystemSounds.Hand.Play();
			//SystemSounds.Question.Play();
        }

        // 播放外部的聲音檔
		 SoundPlayer sound1 = new SoundPlayer("..//..//..//Resources//weapon05.wav");
		 // 新增一個SoundPlayer物件
		 SoundPlayer sound2 = new SoundPlayer();

        private void button5_Click(object sender, EventArgs e)
        {
            //sound1.Play();  // 播放
            sound2.SoundLocation = "..//..//..//Resources//weapon05.wav"; // 設定聲音檔案的路徑和名稱
            sound2.Play();
            //sound1.PlayLooping(); // 重複循環播放
            //sound1.PlaySync(); // 播放 -- 等候播放完成後，再繼續執行程式碼
        }

        // 停止播放
        private void button6_Click(object sender, EventArgs e)
        {
            //sound1.Stop(); 
            sound2.Stop();
        }

        // 用 Media Player 播放
        // 播放外部的聲音檔
        private void button7_Click(object sender, EventArgs e)
        {
            //axWindowsMediaPlayer1.settings.autoStart = false; // 不自動播放
            //axWindowsMediaPlayer1.settings.mute = true;       // 無聲
            axWindowsMediaPlayer1.URL = "Fx13112_30_cal1.mp3"; // 載入 mp3
            axWindowsMediaPlayer1.settings.volume = 90;       // 音量 0 ~ 100
            axWindowsMediaPlayer1.Ctlcontrols.play();
        }

        // 停止播放
        private void button8_Click(object sender, EventArgs e)
        {
            axWindowsMediaPlayer1.Ctlcontrols.stop();
        }

        
    }
}
