using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormApp01
{
    public partial class Form1 : Form
    {
        private int price = 0;
        private string size = "미선택";
        private string pay = ""; 
       
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // 사이즈
            if (rb_small.Checked == true) {
                price = 10000;
                size = "Small";
            }
            else if (rb_medium.Checked == true) {
                price = 15000;
                size = "Medium";
            }
            else if (rb_large.Checked == true) {
                price = 20000;
                size = "Large";
            }
            // 사이드
            if (cb_cola.Checked || cb_fanta.Checked || cb_cider.Checked ) price += 1000;
            if (cb_frenchFries.Checked || cb_spaghetti.Checked || cb_chicken.Checked) price += 6000;
            
            // 지불방식
            if(rb_cash.Checked) { pay = rb_cash.Text; }
            else if (rb_card.Checked) { pay = rb_card.Text; }

            tb_total.Text = string.Format("{0:0,0}",price) + "원"; 

            MessageBox.Show($"결제 해주셔서 감사합니다.\n주문하신 정보 확인 부탁드립니다." +
                $"\n피자 사이즈:{size}" +
                $"\n사이드 메뉴 가격:{price}" +
                $"\n지불 방식:{pay}"); 
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            rb_small.Checked = true;
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (cb_sidevisible.Checked) gb_side.Enabled = true;
            else gb_side.Enabled = false; 
        }
    }
}
