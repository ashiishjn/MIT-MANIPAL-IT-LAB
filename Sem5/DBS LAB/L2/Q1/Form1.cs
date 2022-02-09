using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace L2Q1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveFileDialog1.ShowDialog();
            string fName = saveFileDialog1.FileName;
            StreamWriter sw = new StreamWriter(fName);
            sw.Write(richTextBox1.Text);
            sw.Flush();
            sw.Close();
        }

        private void fontToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FontDialog fd = new FontDialog();
            fd.Font = richTextBox1.SelectionFont;
            if (fd.ShowDialog() == DialogResult.OK)
            {
                richTextBox1.SelectionFont = fd.Font;   
            }
        }

        private void colorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ColorDialog fd = new ColorDialog();
            fd.Color = richTextBox1.SelectionColor;
            if (fd.ShowDialog() == DialogResult.OK)
            {
                richTextBox1.SelectionColor = fd.Color;
            }
        }


        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();
            dlg.Title = "Open";
            dlg.ShowDialog();
            string fName = dlg.FileName;
            StreamReader sr = new StreamReader(fName);
            richTextBox1.Text = sr.ReadToEnd();
            sr.Close();
        }
        
        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {

        }

        private void saveFileDialog1_FileOk_1(object sender, CancelEventArgs e)
        {

        }

        private void aboutUsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Hello\n");
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }



        /*private void cutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Clipboard.SetText(txt.SelectedText);
            txt.SelectedText = string.Empty;
        }

        private void copyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Clipboard.SetText(txt.SelectedText);
        }

        private void pasteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string xx = Clipboard.GetText();
            txt.Text = txt.Text.Insert(txt.SelectionStart, xx);
        }*/



      
    }
}

