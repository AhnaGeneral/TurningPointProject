
namespace WinFormsApp1
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
            this.AgressCheck = new System.Windows.Forms.CheckBox();
            this.SNSAgress = new System.Windows.Forms.CheckBox();
            this.Event1 = new System.Windows.Forms.CheckBox();
            this.Event2 = new System.Windows.Forms.CheckBox();
            this.checkedListBox1 = new System.Windows.Forms.CheckedListBox();
            this.SuspendLayout();
            // 
            // AgressCheck
            // 
            this.AgressCheck.AutoSize = true;
            this.AgressCheck.Location = new System.Drawing.Point(12, 178);
            this.AgressCheck.Name = "AgressCheck";
            this.AgressCheck.Size = new System.Drawing.Size(102, 19);
            this.AgressCheck.TabIndex = 0;
            this.AgressCheck.Text = "이용약관 동의";
            this.AgressCheck.UseVisualStyleBackColor = true;
            this.AgressCheck.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // SNSAgress
            // 
            this.SNSAgress.AutoSize = true;
            this.SNSAgress.Checked = true;
            this.SNSAgress.CheckState = System.Windows.Forms.CheckState.Indeterminate;
            this.SNSAgress.Location = new System.Drawing.Point(12, 253);
            this.SNSAgress.Name = "SNSAgress";
            this.SNSAgress.Size = new System.Drawing.Size(97, 19);
            this.SNSAgress.TabIndex = 1;
            this.SNSAgress.Text = "SNS수신동의";
            this.SNSAgress.UseVisualStyleBackColor = true;
            // 
            // Event1
            // 
            this.Event1.AutoSize = true;
            this.Event1.Location = new System.Drawing.Point(12, 228);
            this.Event1.Name = "Event1";
            this.Event1.Size = new System.Drawing.Size(62, 19);
            this.Event1.TabIndex = 2;
            this.Event1.Text = "이벤트";
            this.Event1.UseVisualStyleBackColor = true;
            // 
            // Event2
            // 
            this.Event2.AutoSize = true;
            this.Event2.Location = new System.Drawing.Point(12, 203);
            this.Event2.Name = "Event2";
            this.Event2.Size = new System.Drawing.Size(69, 19);
            this.Event2.TabIndex = 3;
            this.Event2.Text = "이벤트2";
            this.Event2.UseVisualStyleBackColor = true;
            // 
            // checkedListBox1
            // 
            this.checkedListBox1.FormattingEnabled = true;
            this.checkedListBox1.Items.AddRange(new object[] {
            "서울특별시",
            "경기도",
            "세종특별자치시",
            "인천광역시",
            "대구특별시",
            "부산광역시",
            "광주광역시",
            "대전광역시 ",
            "울산광역시",
            "강원도",
            "충청북도",
            "충청남도 ",
            "전라북도",
            "전라남도",
            "경상북도",
            "경상남도",
            "",
            ""});
            this.checkedListBox1.Location = new System.Drawing.Point(12, 278);
            this.checkedListBox1.Name = "checkedListBox1";
            this.checkedListBox1.Size = new System.Drawing.Size(167, 220);
            this.checkedListBox1.TabIndex = 4;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(551, 510);
            this.Controls.Add(this.checkedListBox1);
            this.Controls.Add(this.Event2);
            this.Controls.Add(this.Event1);
            this.Controls.Add(this.SNSAgress);
            this.Controls.Add(this.AgressCheck);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox AgressCheck;
        private System.Windows.Forms.CheckBox SNSAgress;
        private System.Windows.Forms.CheckBox Event1;
        private System.Windows.Forms.CheckBox Event2;
        private System.Windows.Forms.CheckedListBox checkedListBox1;
    }
}

