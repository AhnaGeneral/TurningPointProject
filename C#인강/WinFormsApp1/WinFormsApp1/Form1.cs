using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            AgressCheck.Checked = true;
            AgressCheck.ThreeState = true; 
            Event2.Checked = false;
            Event1.Checked = true;
            SNSAgress.CheckState = CheckState.Indeterminate;

            checkedListBox1.Items.Add("대한민국");
            checkedListBox1.Items.Add("미국");
            
        }
    }
}
//unchecked, checked, indeterminate