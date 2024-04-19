using Agency.Models;
namespace Agency
{
    partial class ToursForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.dataGridViewTours = new System.Windows.Forms.DataGridView();
            this.countryDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.cityDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.hotelDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.hotClassDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.priceDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.tourModelBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.buttonMakeOrder = new System.Windows.Forms.Button();
            this.labelCountry = new System.Windows.Forms.Label();
            this.labelStartDate = new System.Windows.Forms.Label();
            this.labelEndDate = new System.Windows.Forms.Label();
            this.textBoxCountry = new System.Windows.Forms.TextBox();
            this.textBoxCity = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.numericUpDownTourists = new System.Windows.Forms.NumericUpDown();
            this.labelTourists = new System.Windows.Forms.Label();
            this.buttonFilter = new System.Windows.Forms.Button();
            this.dateTimePickerEnd = new System.Windows.Forms.DateTimePicker();
            this.dateTimePickerStart = new System.Windows.Forms.DateTimePicker();
            this.labelCity = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewTours)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tourModelBindingSource)).BeginInit();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownTourists)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridViewTours
            // 
            this.dataGridViewTours.AutoGenerateColumns = false;
            this.dataGridViewTours.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewTours.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.countryDataGridViewTextBoxColumn,
            this.cityDataGridViewTextBoxColumn,
            this.hotelDataGridViewTextBoxColumn,
            this.hotClassDataGridViewTextBoxColumn,
            this.priceDataGridViewTextBoxColumn});
            this.dataGridViewTours.DataSource = this.tourModelBindingSource;
            this.dataGridViewTours.Location = new System.Drawing.Point(-3, 131);
            this.dataGridViewTours.Name = "dataGridViewTours";
            this.dataGridViewTours.RowHeadersWidth = 51;
            this.dataGridViewTours.RowTemplate.Height = 24;
            this.dataGridViewTours.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridViewTours.Size = new System.Drawing.Size(732, 372);
            this.dataGridViewTours.TabIndex = 0;
            // 
            // countryDataGridViewTextBoxColumn
            // 
            this.countryDataGridViewTextBoxColumn.DataPropertyName = "Country";
            this.countryDataGridViewTextBoxColumn.HeaderText = "Страна";
            this.countryDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.countryDataGridViewTextBoxColumn.Name = "countryDataGridViewTextBoxColumn";
            this.countryDataGridViewTextBoxColumn.Width = 125;
            // 
            // cityDataGridViewTextBoxColumn
            // 
            this.cityDataGridViewTextBoxColumn.DataPropertyName = "City";
            this.cityDataGridViewTextBoxColumn.HeaderText = "Город";
            this.cityDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.cityDataGridViewTextBoxColumn.Name = "cityDataGridViewTextBoxColumn";
            this.cityDataGridViewTextBoxColumn.Width = 125;
            // 
            // hotelDataGridViewTextBoxColumn
            // 
            this.hotelDataGridViewTextBoxColumn.DataPropertyName = "Hotel";
            this.hotelDataGridViewTextBoxColumn.HeaderText = "Отель";
            this.hotelDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.hotelDataGridViewTextBoxColumn.Name = "hotelDataGridViewTextBoxColumn";
            this.hotelDataGridViewTextBoxColumn.Width = 125;
            // 
            // hotClassDataGridViewTextBoxColumn
            // 
            this.hotClassDataGridViewTextBoxColumn.DataPropertyName = "HotClass";
            this.hotClassDataGridViewTextBoxColumn.HeaderText = "Класс";
            this.hotClassDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.hotClassDataGridViewTextBoxColumn.Name = "hotClassDataGridViewTextBoxColumn";
            this.hotClassDataGridViewTextBoxColumn.Width = 125;
            // 
            // priceDataGridViewTextBoxColumn
            // 
            this.priceDataGridViewTextBoxColumn.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.priceDataGridViewTextBoxColumn.DataPropertyName = "Price";
            this.priceDataGridViewTextBoxColumn.HeaderText = "Цена";
            this.priceDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.priceDataGridViewTextBoxColumn.Name = "priceDataGridViewTextBoxColumn";
            // 
            // tourModelBindingSource
            // 
            this.tourModelBindingSource.DataSource = typeof(TourModel);
            // 
            // buttonMakeOrder
            // 
            this.buttonMakeOrder.FlatAppearance.BorderSize = 0;
            this.buttonMakeOrder.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonMakeOrder.ForeColor = System.Drawing.Color.Gainsboro;
            this.buttonMakeOrder.Location = new System.Drawing.Point(522, 509);
            this.buttonMakeOrder.Name = "buttonMakeOrder";
            this.buttonMakeOrder.Size = new System.Drawing.Size(134, 32);
            this.buttonMakeOrder.TabIndex = 1;
            this.buttonMakeOrder.Text = "Оформить заказ";
            this.buttonMakeOrder.UseVisualStyleBackColor = true;
            this.buttonMakeOrder.Click += new System.EventHandler(this.buttonMakeOrder_Click);
            // 
            // labelCountry
            // 
            this.labelCountry.AutoSize = true;
            this.labelCountry.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelCountry.ForeColor = System.Drawing.Color.LightGray;
            this.labelCountry.Location = new System.Drawing.Point(6, 18);
            this.labelCountry.Name = "labelCountry";
            this.labelCountry.Size = new System.Drawing.Size(71, 20);
            this.labelCountry.TabIndex = 2;
            this.labelCountry.Text = "Страна";
            // 
            // labelStartDate
            // 
            this.labelStartDate.AutoSize = true;
            this.labelStartDate.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelStartDate.ForeColor = System.Drawing.Color.LightGray;
            this.labelStartDate.Location = new System.Drawing.Point(248, 18);
            this.labelStartDate.Name = "labelStartDate";
            this.labelStartDate.Size = new System.Drawing.Size(120, 20);
            this.labelStartDate.TabIndex = 4;
            this.labelStartDate.Text = "Дата Начала";
            // 
            // labelEndDate
            // 
            this.labelEndDate.AutoSize = true;
            this.labelEndDate.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelEndDate.ForeColor = System.Drawing.Color.LightGray;
            this.labelEndDate.Location = new System.Drawing.Point(389, 18);
            this.labelEndDate.Name = "labelEndDate";
            this.labelEndDate.Size = new System.Drawing.Size(108, 20);
            this.labelEndDate.TabIndex = 5;
            this.labelEndDate.Text = "Дата Конца";
            // 
            // textBoxCountry
            // 
            this.textBoxCountry.Location = new System.Drawing.Point(6, 41);
            this.textBoxCountry.Name = "textBoxCountry";
            this.textBoxCountry.Size = new System.Drawing.Size(100, 22);
            this.textBoxCountry.TabIndex = 6;
            // 
            // textBoxCity
            // 
            this.textBoxCity.Location = new System.Drawing.Point(128, 41);
            this.textBoxCity.Name = "textBoxCity";
            this.textBoxCity.Size = new System.Drawing.Size(100, 22);
            this.textBoxCity.TabIndex = 7;
            // 
            // groupBox1
            // 
            this.groupBox1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(22)))), ((int)(((byte)(8)))), ((int)(((byte)(47)))));
            this.groupBox1.Controls.Add(this.numericUpDownTourists);
            this.groupBox1.Controls.Add(this.labelTourists);
            this.groupBox1.Controls.Add(this.buttonFilter);
            this.groupBox1.Controls.Add(this.dateTimePickerEnd);
            this.groupBox1.Controls.Add(this.dateTimePickerStart);
            this.groupBox1.Controls.Add(this.labelCity);
            this.groupBox1.Controls.Add(this.labelCountry);
            this.groupBox1.Controls.Add(this.labelStartDate);
            this.groupBox1.Controls.Add(this.textBoxCity);
            this.groupBox1.Controls.Add(this.labelEndDate);
            this.groupBox1.Controls.Add(this.textBoxCountry);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Top;
            this.groupBox1.Location = new System.Drawing.Point(0, 0);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(732, 125);
            this.groupBox1.TabIndex = 10;
            this.groupBox1.TabStop = false;
            // 
            // numericUpDownTourists
            // 
            this.numericUpDownTourists.Location = new System.Drawing.Point(536, 41);
            this.numericUpDownTourists.Maximum = new decimal(new int[] {
            4,
            0,
            0,
            0});
            this.numericUpDownTourists.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownTourists.Name = "numericUpDownTourists";
            this.numericUpDownTourists.Size = new System.Drawing.Size(74, 22);
            this.numericUpDownTourists.TabIndex = 14;
            this.numericUpDownTourists.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownTourists.ValueChanged += new System.EventHandler(this.numericUpDownTourists_ValueChanged);
            // 
            // labelTourists
            // 
            this.labelTourists.AutoSize = true;
            this.labelTourists.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelTourists.ForeColor = System.Drawing.Color.LightGray;
            this.labelTourists.Location = new System.Drawing.Point(532, 18);
            this.labelTourists.Name = "labelTourists";
            this.labelTourists.Size = new System.Drawing.Size(78, 20);
            this.labelTourists.TabIndex = 13;
            this.labelTourists.Text = "Туристы";
            // 
            // buttonFilter
            // 
            this.buttonFilter.FlatAppearance.BorderSize = 0;
            this.buttonFilter.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonFilter.ForeColor = System.Drawing.Color.LightGray;
            this.buttonFilter.Location = new System.Drawing.Point(654, 12);
            this.buttonFilter.Name = "buttonFilter";
            this.buttonFilter.Size = new System.Drawing.Size(75, 110);
            this.buttonFilter.TabIndex = 12;
            this.buttonFilter.Text = "Фильтр";
            this.buttonFilter.UseVisualStyleBackColor = true;
            this.buttonFilter.Click += new System.EventHandler(this.buttonFilter_Click);
            // 
            // dateTimePickerEnd
            // 
            this.dateTimePickerEnd.Location = new System.Drawing.Point(393, 41);
            this.dateTimePickerEnd.MinDate = new System.DateTime(2023, 12, 15, 0, 0, 0, 0);
            this.dateTimePickerEnd.Name = "dateTimePickerEnd";
            this.dateTimePickerEnd.Size = new System.Drawing.Size(118, 22);
            this.dateTimePickerEnd.TabIndex = 11;
            this.dateTimePickerEnd.Value = new System.DateTime(2023, 12, 15, 20, 33, 11, 0);
            this.dateTimePickerEnd.ValueChanged += new System.EventHandler(this.dateTimePickerEnd_ValueChanged);
            // 
            // dateTimePickerStart
            // 
            this.dateTimePickerStart.CustomFormat = "";
            this.dateTimePickerStart.Location = new System.Drawing.Point(252, 41);
            this.dateTimePickerStart.MinDate = new System.DateTime(2023, 12, 15, 0, 0, 0, 0);
            this.dateTimePickerStart.Name = "dateTimePickerStart";
            this.dateTimePickerStart.Size = new System.Drawing.Size(116, 22);
            this.dateTimePickerStart.TabIndex = 10;
            this.dateTimePickerStart.Value = new System.DateTime(2023, 12, 15, 20, 32, 8, 0);
            this.dateTimePickerStart.ValueChanged += new System.EventHandler(this.dateTimePickerStart_ValueChanged);
            // 
            // labelCity
            // 
            this.labelCity.AutoSize = true;
            this.labelCity.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelCity.ForeColor = System.Drawing.Color.LightGray;
            this.labelCity.Location = new System.Drawing.Point(124, 18);
            this.labelCity.Name = "labelCity";
            this.labelCity.Size = new System.Drawing.Size(61, 20);
            this.labelCity.TabIndex = 3;
            this.labelCity.Text = "Город";
            // 
            // ToursForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(32)))), ((int)(((byte)(30)))), ((int)(((byte)(45)))));
            this.ClientSize = new System.Drawing.Size(732, 553);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.buttonMakeOrder);
            this.Controls.Add(this.dataGridViewTours);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "ToursForm";
            this.Text = "ToursForm";
            this.Load += new System.EventHandler(this.ToursForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewTours)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tourModelBindingSource)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownTourists)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.DataGridView dataGridViewTours;
        private System.Windows.Forms.Button buttonMakeOrder;
        private System.Windows.Forms.Label labelCountry;
        private System.Windows.Forms.Label labelStartDate;
        private System.Windows.Forms.Label labelEndDate;
        private System.Windows.Forms.TextBox textBoxCountry;
        private System.Windows.Forms.TextBox textBoxCity;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.DateTimePicker dateTimePickerEnd;
        private System.Windows.Forms.DateTimePicker dateTimePickerStart;
        private System.Windows.Forms.Button buttonFilter;
        private System.Windows.Forms.Label labelTourists;
        private System.Windows.Forms.Label labelCity;
        private System.Windows.Forms.NumericUpDown numericUpDownTourists;
        private System.Windows.Forms.DataGridViewTextBoxColumn countryDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn cityDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn hotelDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn hotClassDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn priceDataGridViewTextBoxColumn;
        private System.Windows.Forms.BindingSource tourModelBindingSource;
    }
}