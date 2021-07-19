
namespace WinFormApp01
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.gb_size = new System.Windows.Forms.GroupBox();
            this.rb_large = new System.Windows.Forms.RadioButton();
            this.rb_medium = new System.Windows.Forms.RadioButton();
            this.rb_small = new System.Windows.Forms.RadioButton();
            this.gb_payment = new System.Windows.Forms.GroupBox();
            this.rb_card = new System.Windows.Forms.RadioButton();
            this.rb_cash = new System.Windows.Forms.RadioButton();
            this.gb_side = new System.Windows.Forms.GroupBox();
            this.cb_chicken = new System.Windows.Forms.CheckBox();
            this.cb_frenchFries = new System.Windows.Forms.CheckBox();
            this.cb_spaghetti = new System.Windows.Forms.CheckBox();
            this.cb_fanta = new System.Windows.Forms.CheckBox();
            this.cb_cider = new System.Windows.Forms.CheckBox();
            this.cb_cola = new System.Windows.Forms.CheckBox();
            this.button1 = new System.Windows.Forms.Button();
            this.cb_sidevisible = new System.Windows.Forms.CheckBox();
            this.label1 = new System.Windows.Forms.Label();
            this.tb_total = new System.Windows.Forms.TextBox();
            this.gb_size.SuspendLayout();
            this.gb_payment.SuspendLayout();
            this.gb_side.SuspendLayout();
            this.SuspendLayout();
            // 
            // gb_size
            // 
            this.gb_size.Controls.Add(this.rb_large);
            this.gb_size.Controls.Add(this.rb_medium);
            this.gb_size.Controls.Add(this.rb_small);
            this.gb_size.Location = new System.Drawing.Point(12, 29);
            this.gb_size.Name = "gb_size";
            this.gb_size.Size = new System.Drawing.Size(173, 124);
            this.gb_size.TabIndex = 0;
            this.gb_size.TabStop = false;
            this.gb_size.Text = "피자사이즈";
            // 
            // rb_large
            // 
            this.rb_large.AutoSize = true;
            this.rb_large.Location = new System.Drawing.Point(7, 88);
            this.rb_large.Name = "rb_large";
            this.rb_large.Size = new System.Drawing.Size(67, 24);
            this.rb_large.TabIndex = 2;
            this.rb_large.TabStop = true;
            this.rb_large.Text = "Large";
            this.rb_large.UseVisualStyleBackColor = true;
            // 
            // rb_medium
            // 
            this.rb_medium.AutoSize = true;
            this.rb_medium.Location = new System.Drawing.Point(7, 58);
            this.rb_medium.Name = "rb_medium";
            this.rb_medium.Size = new System.Drawing.Size(87, 24);
            this.rb_medium.TabIndex = 1;
            this.rb_medium.TabStop = true;
            this.rb_medium.Text = "Medium";
            this.rb_medium.UseVisualStyleBackColor = true;
            // 
            // rb_small
            // 
            this.rb_small.AllowDrop = true;
            this.rb_small.AutoSize = true;
            this.rb_small.Location = new System.Drawing.Point(7, 27);
            this.rb_small.Name = "rb_small";
            this.rb_small.Size = new System.Drawing.Size(67, 24);
            this.rb_small.TabIndex = 0;
            this.rb_small.TabStop = true;
            this.rb_small.Text = "Small";
            this.rb_small.UseVisualStyleBackColor = true;
            // 
            // gb_payment
            // 
            this.gb_payment.Controls.Add(this.rb_card);
            this.gb_payment.Controls.Add(this.rb_cash);
            this.gb_payment.Location = new System.Drawing.Point(12, 173);
            this.gb_payment.Name = "gb_payment";
            this.gb_payment.Size = new System.Drawing.Size(173, 100);
            this.gb_payment.TabIndex = 1;
            this.gb_payment.TabStop = false;
            this.gb_payment.Text = "결제 방식";
            // 
            // rb_card
            // 
            this.rb_card.AutoSize = true;
            this.rb_card.Location = new System.Drawing.Point(7, 58);
            this.rb_card.Name = "rb_card";
            this.rb_card.Size = new System.Drawing.Size(90, 24);
            this.rb_card.TabIndex = 1;
            this.rb_card.TabStop = true;
            this.rb_card.Text = "신용카드";
            this.rb_card.UseVisualStyleBackColor = true;
            // 
            // rb_cash
            // 
            this.rb_cash.AutoSize = true;
            this.rb_cash.Location = new System.Drawing.Point(7, 27);
            this.rb_cash.Name = "rb_cash";
            this.rb_cash.Size = new System.Drawing.Size(60, 24);
            this.rb_cash.TabIndex = 0;
            this.rb_cash.TabStop = true;
            this.rb_cash.Text = "현금";
            this.rb_cash.UseVisualStyleBackColor = true;
            // 
            // gb_side
            // 
            this.gb_side.Controls.Add(this.cb_chicken);
            this.gb_side.Controls.Add(this.cb_frenchFries);
            this.gb_side.Controls.Add(this.cb_spaghetti);
            this.gb_side.Controls.Add(this.cb_fanta);
            this.gb_side.Controls.Add(this.cb_cider);
            this.gb_side.Controls.Add(this.cb_cola);
            this.gb_side.Location = new System.Drawing.Point(203, 29);
            this.gb_side.Name = "gb_side";
            this.gb_side.Size = new System.Drawing.Size(155, 212);
            this.gb_side.TabIndex = 2;
            this.gb_side.TabStop = false;
            this.gb_side.Text = "사이드 메뉴";
            // 
            // cb_chicken
            // 
            this.cb_chicken.AutoSize = true;
            this.cb_chicken.Location = new System.Drawing.Point(7, 175);
            this.cb_chicken.Name = "cb_chicken";
            this.cb_chicken.Size = new System.Drawing.Size(76, 24);
            this.cb_chicken.TabIndex = 5;
            this.cb_chicken.Text = "닭튀김";
            this.cb_chicken.UseVisualStyleBackColor = true;
            // 
            // cb_frenchFries
            // 
            this.cb_frenchFries.AutoSize = true;
            this.cb_frenchFries.Location = new System.Drawing.Point(7, 144);
            this.cb_frenchFries.Name = "cb_frenchFries";
            this.cb_frenchFries.Size = new System.Drawing.Size(91, 24);
            this.cb_frenchFries.TabIndex = 4;
            this.cb_frenchFries.Text = "감자튀김";
            this.cb_frenchFries.UseVisualStyleBackColor = true;
            // 
            // cb_spaghetti
            // 
            this.cb_spaghetti.AutoSize = true;
            this.cb_spaghetti.Location = new System.Drawing.Point(7, 113);
            this.cb_spaghetti.Name = "cb_spaghetti";
            this.cb_spaghetti.Size = new System.Drawing.Size(91, 24);
            this.cb_spaghetti.TabIndex = 3;
            this.cb_spaghetti.Text = "스파게티";
            this.cb_spaghetti.UseVisualStyleBackColor = true;
            // 
            // cb_fanta
            // 
            this.cb_fanta.AutoSize = true;
            this.cb_fanta.Location = new System.Drawing.Point(7, 82);
            this.cb_fanta.Name = "cb_fanta";
            this.cb_fanta.Size = new System.Drawing.Size(61, 24);
            this.cb_fanta.TabIndex = 2;
            this.cb_fanta.Text = "환타";
            this.cb_fanta.UseVisualStyleBackColor = true;
            // 
            // cb_cider
            // 
            this.cb_cider.AutoSize = true;
            this.cb_cider.Location = new System.Drawing.Point(7, 51);
            this.cb_cider.Name = "cb_cider";
            this.cb_cider.Size = new System.Drawing.Size(76, 24);
            this.cb_cider.TabIndex = 1;
            this.cb_cider.Text = "사이다";
            this.cb_cider.UseVisualStyleBackColor = true;
            // 
            // cb_cola
            // 
            this.cb_cola.AutoSize = true;
            this.cb_cola.Location = new System.Drawing.Point(7, 20);
            this.cb_cola.Name = "cb_cola";
            this.cb_cola.Size = new System.Drawing.Size(61, 24);
            this.cb_cola.TabIndex = 0;
            this.cb_cola.Text = "콜라";
            this.cb_cola.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(264, 299);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(94, 29);
            this.button1.TabIndex = 3;
            this.button1.Text = "계산하기";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // cb_sidevisible
            // 
            this.cb_sidevisible.AutoSize = true;
            this.cb_sidevisible.Location = new System.Drawing.Point(203, 248);
            this.cb_sidevisible.Name = "cb_sidevisible";
            this.cb_sidevisible.Size = new System.Drawing.Size(161, 24);
            this.cb_sidevisible.TabIndex = 4;
            this.cb_sidevisible.Text = "사이드 메뉴 활성화";
            this.cb_sidevisible.UseVisualStyleBackColor = true;
            this.cb_sidevisible.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(19, 303);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(74, 20);
            this.label1.TabIndex = 5;
            this.label1.Text = "주문 가격";
            // 
            // tb_total
            // 
            this.tb_total.Location = new System.Drawing.Point(100, 300);
            this.tb_total.Name = "tb_total";
            this.tb_total.Size = new System.Drawing.Size(144, 27);
            this.tb_total.TabIndex = 6;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(405, 364);
            this.Controls.Add(this.tb_total);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cb_sidevisible);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.gb_side);
            this.Controls.Add(this.gb_payment);
            this.Controls.Add(this.gb_size);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.gb_size.ResumeLayout(false);
            this.gb_size.PerformLayout();
            this.gb_payment.ResumeLayout(false);
            this.gb_payment.PerformLayout();
            this.gb_side.ResumeLayout(false);
            this.gb_side.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox gb_size;
        private System.Windows.Forms.RadioButton rb_large;
        private System.Windows.Forms.RadioButton rb_medium;
        private System.Windows.Forms.RadioButton rb_small;
        private System.Windows.Forms.GroupBox gb_payment;
        private System.Windows.Forms.RadioButton rb_card;
        private System.Windows.Forms.RadioButton rb_cash;
        private System.Windows.Forms.GroupBox gb_side;
        private System.Windows.Forms.CheckBox cb_chicken;
        private System.Windows.Forms.CheckBox cb_frenchFries;
        private System.Windows.Forms.CheckBox cb_spaghetti;
        private System.Windows.Forms.CheckBox cb_fanta;
        private System.Windows.Forms.CheckBox cb_cider;
        private System.Windows.Forms.CheckBox cb_cola;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.CheckBox cb_sidevisible;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tb_total;
    }
}

