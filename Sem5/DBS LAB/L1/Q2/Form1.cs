using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Q2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string msg = string.Empty;
            msg = "";
            string error = "";
            if (textBox1.Text == "")
                error += "Enter Name\n";
            else
                msg += "Name: " + textBox1.Text;
            DateTime iDate;
            iDate = dateTimePicker1.Value;
            msg += "\nDOB: " + iDate;


            if (radioButton1.Checked == true)
                msg += "\nGender: Male";
            else if (radioButton2.Checked == true)
                msg += "\nGender: Female";
            else if (radioButton3.Checked == true)
                msg += "\nGender: Others";
            else
                error += "Select Gender\n";
            if ((textBox2.Text).Length != 10)
                error += "Incorrect Phone no.\n";
            else
                msg += "\nPhone no.: " + textBox2.Text;
            if (textBox3.Text == "")
                error += "Enter Email ID\n";
            else
                msg += "\nEmail ID: " + textBox3.Text;
            if (comboBox1.SelectedItem == null)
                error += "Enter Semester\n";
            else
                msg += "\nSemester: " + comboBox1.SelectedItem;
            if (comboBox2.SelectedItem == null)
                error += "Enter Semester\n";
            else
                msg += "\nBranch: " + comboBox2.SelectedItem;
            msg += "\n--Interests--\n";
            if (JAVA.Checked == true)
                msg += "  JAVA\n";
            if (checkBox2.Checked == true)
                msg += "  C#\n";
            if (checkBox1.Checked == true)
                msg += "  C++\n";
            if (checkBox3.Checked == true)
                msg += "  C\n";
            if (checkBox4.Checked == true)
                msg += "  PYTHON\n";
            if (checkBox5.Checked == true)
                msg += "  DBS\n";
            
            if (error != "")
            {
                MessageBox.Show(error);
            }
            else
                MessageBox.Show(msg);
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            dateTimePicker1.Format = DateTimePickerFormat.Short;
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox5_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox1_CheckedChanged_1(object sender, EventArgs e)
        {

        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {

        }
    }
}
