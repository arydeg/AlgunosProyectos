namespace Facturacion
{
    partial class Ventana_User
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
            this.lblDni = new System.Windows.Forms.Label();
            this.lblUsu = new System.Windows.Forms.Label();
            this.lblNombre = new System.Windows.Forms.Label();
            this.lb3 = new System.Windows.Forms.Label();
            this.lbl1 = new System.Windows.Forms.Label();
            this.lbl2 = new System.Windows.Forms.Label();
            this.btnCerrarSesion = new System.Windows.Forms.Button();
            this.btnCamContraseña = new System.Windows.Forms.Button();
            this.btnContPrincipal = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnSalir
            // 
            this.btnSalir.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSalir.Location = new System.Drawing.Point(338, 262);
            this.btnSalir.Size = new System.Drawing.Size(160, 30);
            this.btnSalir.TabIndex = 20;
            // 
            // lblDni
            // 
            this.lblDni.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.lblDni.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lblDni.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblDni.Location = new System.Drawing.Point(171, 211);
            this.lblDni.Name = "lblDni";
            this.lblDni.Size = new System.Drawing.Size(98, 28);
            this.lblDni.TabIndex = 22;
            this.lblDni.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblUsu
            // 
            this.lblUsu.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.lblUsu.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lblUsu.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblUsu.Location = new System.Drawing.Point(171, 160);
            this.lblUsu.Name = "lblUsu";
            this.lblUsu.Size = new System.Drawing.Size(98, 28);
            this.lblUsu.TabIndex = 21;
            this.lblUsu.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblNombre
            // 
            this.lblNombre.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.lblNombre.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lblNombre.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblNombre.Location = new System.Drawing.Point(171, 111);
            this.lblNombre.Name = "lblNombre";
            this.lblNombre.Size = new System.Drawing.Size(98, 28);
            this.lblNombre.TabIndex = 20;
            this.lblNombre.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lb3
            // 
            this.lb3.AutoSize = true;
            this.lb3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lb3.Location = new System.Drawing.Point(55, 213);
            this.lb3.Name = "lb3";
            this.lb3.Size = new System.Drawing.Size(33, 20);
            this.lb3.TabIndex = 19;
            this.lb3.Text = "ID:";
            // 
            // lbl1
            // 
            this.lbl1.AutoSize = true;
            this.lbl1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl1.Location = new System.Drawing.Point(55, 115);
            this.lbl1.Name = "lbl1";
            this.lbl1.Size = new System.Drawing.Size(76, 20);
            this.lbl1.TabIndex = 18;
            this.lbl1.Text = "Nombre:";
            // 
            // lbl2
            // 
            this.lbl2.AutoSize = true;
            this.lbl2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl2.Location = new System.Drawing.Point(55, 164);
            this.lbl2.Name = "lbl2";
            this.lbl2.Size = new System.Drawing.Size(76, 20);
            this.lbl2.TabIndex = 17;
            this.lbl2.Text = "Usuario:";
            // 
            // btnCerrarSesion
            // 
            this.btnCerrarSesion.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnCerrarSesion.Location = new System.Drawing.Point(338, 203);
            this.btnCerrarSesion.Name = "btnCerrarSesion";
            this.btnCerrarSesion.Size = new System.Drawing.Size(160, 30);
            this.btnCerrarSesion.TabIndex = 2;
            this.btnCerrarSesion.Text = "Cerrar Sesion";
            this.btnCerrarSesion.UseVisualStyleBackColor = true;
            this.btnCerrarSesion.Click += new System.EventHandler(this.BtnCerrarSesion_Click);
            // 
            // btnCamContraseña
            // 
            this.btnCamContraseña.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnCamContraseña.Location = new System.Drawing.Point(338, 142);
            this.btnCamContraseña.Name = "btnCamContraseña";
            this.btnCamContraseña.Size = new System.Drawing.Size(160, 30);
            this.btnCamContraseña.TabIndex = 1;
            this.btnCamContraseña.Text = "Cambiar Contraseña";
            this.btnCamContraseña.UseVisualStyleBackColor = true;
            this.btnCamContraseña.Click += new System.EventHandler(this.BtnCamContraseña_Click);
            // 
            // btnContPrincipal
            // 
            this.btnContPrincipal.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnContPrincipal.Location = new System.Drawing.Point(338, 80);
            this.btnContPrincipal.Name = "btnContPrincipal";
            this.btnContPrincipal.Size = new System.Drawing.Size(160, 30);
            this.btnContPrincipal.TabIndex = 0;
            this.btnContPrincipal.Text = "Contenedor Principal";
            this.btnContPrincipal.UseVisualStyleBackColor = true;
            this.btnContPrincipal.Click += new System.EventHandler(this.BtnContPrincipal_Click);
            // 
            // Ventana_User
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(575, 391);
            this.Controls.Add(this.lblDni);
            this.Controls.Add(this.lblUsu);
            this.Controls.Add(this.lblNombre);
            this.Controls.Add(this.lb3);
            this.Controls.Add(this.lbl1);
            this.Controls.Add(this.lbl2);
            this.Controls.Add(this.btnCerrarSesion);
            this.Controls.Add(this.btnCamContraseña);
            this.Controls.Add(this.btnContPrincipal);
            this.Name = "Ventana_User";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Ventana_User";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Ventana_User_FormClosed);
            this.Load += new System.EventHandler(this.Ventana_User_Load);
            this.Controls.SetChildIndex(this.btnContPrincipal, 0);
            this.Controls.SetChildIndex(this.btnCamContraseña, 0);
            this.Controls.SetChildIndex(this.btnCerrarSesion, 0);
            this.Controls.SetChildIndex(this.lbl2, 0);
            this.Controls.SetChildIndex(this.lbl1, 0);
            this.Controls.SetChildIndex(this.lb3, 0);
            this.Controls.SetChildIndex(this.lblNombre, 0);
            this.Controls.SetChildIndex(this.lblUsu, 0);
            this.Controls.SetChildIndex(this.lblDni, 0);
            this.Controls.SetChildIndex(this.btnSalir, 0);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label lblDni;
        private System.Windows.Forms.Label lblUsu;
        private System.Windows.Forms.Label lblNombre;
        private System.Windows.Forms.Label lb3;
        private System.Windows.Forms.Label lbl1;
        private System.Windows.Forms.Label lbl2;
        private System.Windows.Forms.Button btnCerrarSesion;
        private System.Windows.Forms.Button btnCamContraseña;
        private System.Windows.Forms.Button btnContPrincipal;
    }
}