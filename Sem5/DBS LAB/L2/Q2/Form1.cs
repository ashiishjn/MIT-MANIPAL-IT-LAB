using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace L2Q2
{
    public partial class Form1 : Form
    {
        public String[] usernames = { "Ram", "Shyam", "Hari" };
        public String[] passwords = { "ram", "shyam", "hari" };
        public int index;
        public Form1()
        {
            InitializeComponent();
        }

        private void usernametextBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < 3; i++)
            {
                if (String.Equals(usernametextBox.Text, usernames[i]))
                {
                    index = i;
                    if (String.Equals(passwordtextBox.Text, passwords[i]))
                    {
                        Details details = new Details();
                        this.Hide();
                        details.Show();
                        break;
                    }
                    else
                    {
                        MessageBox.Show("Wrong Password");
                        break;
                    }
                }
                else
                {
                    MessageBox.Show("User Not Registered");
                    break;
                }

            }
        }
    }
}
