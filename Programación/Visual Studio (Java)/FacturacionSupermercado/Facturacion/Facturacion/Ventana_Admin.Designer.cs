namespace Facturacion
{
    partial class Ventana_Admin
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
            this.btnContPrincipal = new System.Windows.Forms.Button();
            this.btnAdminUsuarios = new System.Windows.Forms.Button();
            this.btnCamContraseña = new System.Windows.Forms.Button();
            this.btnCerrarSesion = new System.Windows.Forms.Button();
            this.lbl1 = new System.Windows.Forms.Label();
            this.lbl2 = new System.Windows.Forms.Label();
            this.lbl3 = new System.Windows.Forms.Label();
            this.lblAdmin = new System.Windows.Forms.Label();
            this.lblUsu = new System.Windows.Forms.Label();
            this.lblDni = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btnSalir
            // 
            this.btnSalir.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSalir.Location = new System.Drawing.Point(343, 309);
            this.btnSalir.Size = new System.Drawing.Size(160, 30);
            this.btnSalir.TabIndex = 20;
            // 
            // btnContPrincipal
            // 
            this.btnContPrincipal.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnContPrincipal.Location = new System.Drawing.Point(343, 70);
            this.btnContPrincipal.Name = "btnContPrincipal";
            this.btnContPrincipal.Size = new System.Drawing.Size(160, 30);
            this.btnContPrincipal.TabIndex = 0;
            this.btnContPrincipal.Text = "Contenedor Principal";
            this.btnContPrincipal.UseVisualStyleBackColor = true;
            this.btnContPrincipal.Click += new System.EventHandler(this.BtnContPrincipal_Click);
            // 
            // btnAdminUsuarios
            // 
            this.btnAdminUsuarios.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnAdminUsuarios.Location = new System.Drawing.Point(343, 126);
            this.btnAdminUsuarios.Name = "btnAdminUsuarios";
            this.btnAdminUsuarios.Size = new System.Drawing.Size(160, 30);
            this.btnAdminUsuarios.TabIndex = 1;
            this.btnAdminUsuarios.Text = "Administrar Usuarios";
            this.btnAdminUsuarios.UseVisualStyleBackColor = true;
            // 
            // btnCamContraseña
            // 
            this.btnCamContraseña.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnCamContraseña.Location = new System.Drawing.Point(343, 186);
            this.btnCamContraseña.Name = "btnCamContraseña";
            this.btnCamContraseña.Size = new System.Drawing.Size(160, 30);
            this.btnCamContraseña.TabIndex = 2;
            this.btnCamContraseña.Text = "Cambiar Contraseña";
            this.btnCamContraseña.UseVisualStyleBackColor = true;
            this.btnCamContraseña.Click += new System.EventHandler(this.BtnCamContraseña_Click);
            // 
            // btnCerrarSesion
            // 
            this.btnCerrarSesion.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnCerrarSesion.Location = new System.Drawing.Point(343, 246);
            this.btnCerrarSesion.Name = "btnCerrarSesion";
            this.btnCerrarSesion.Size = new System.Drawing.Size(160, 30);
            this.btnCerrarSesion.TabIndex = 3;
            this.btnCerrarSesion.Text = "Cerrar Sesion";
            this.btnCerrarSesion.UseVisualStyleBackColor = true;
            this.btnCerrarSesion.Click += new System.EventHandler(this.BtnCerrarSesion_Click);
            // 
            // lbl1
            // 
            this.lbl1.AutoSize = true;
            this.lbl1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl1.Location = new System.Drawing.Point(49, 138);
            this.lbl1.Name = "lbl1";
            this.lbl1.Size = new System.Drawing.Size(64, 20);
            this.lbl1.TabIndex = 5;
            this.lbl1.Text = "Admin:";
            // 
            // lbl2
            // 
            this.lbl2.AutoSize = true;
            this.lbl2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl2.Location = new System.Drawing.Point(49, 186);
            this.lbl2.Name = "lbl2";
            this.lbl2.Size = new System.Drawing.Size(76, 20);
            this.lbl2.TabIndex = 6;
            this.lbl2.Text = "Usuario:";
            // 
            // lbl3
            // 
            this.lbl3.AutoSize = true;
            this.lbl3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl3.Location = new System.Drawing.Point(49, 234);
            this.lbl3.Name = "lbl3";
            this.lbl3.Size = new System.Drawing.Size(33, 20);
            this.lbl3.TabIndex = 7;
            this.lbl3.Text = "ID:";
            // 
            // lblAdmin
            // 
            this.lblAdmin.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.lblAdmin.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lblAdmin.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAdmin.Location = new System.Drawing.Point(165, 132);
            this.lblAdmin.Name = "lblAdmin";
            this.lblAdmin.Size = new System.Drawing.Size(98, 28);
            this.lblAdmin.TabIndex = 8;
            this.lblAdmin.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblUsu
            // 
            this.lblUsu.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.lblUsu.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lblUsu.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblUsu.Location = new System.Drawing.Point(165, 181);
            this.lblUsu.Name = "lblUsu";
            this.lblUsu.Size = new System.Drawing.Size(98, 28);
            this.lblUsu.TabIndex = 9;
            this.lblUsu.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblDni
            // 
            this.lblDni.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.lblDni.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lblDni.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblDni.Location = new System.Drawing.Point(165, 232);
            this.lblDni.Name = "lblDni";
            this.lblDni.Size = new System.Drawing.Size(98, 28);
            this.lblDni.TabIndex = 10;
            this.lblDni.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Ventana_Admin
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(564, 405);
            this.Controls.Add(this.lblDni);
            this.Controls.Add(this.lblUsu);
            this.Controls.Add(this.lblAdmin);
            this.Controls.Add(this.lbl3);
            this.Controls.Add(this.lbl2);
            this.Controls.Add(this.lbl1);
            this.Controls.Add(this.btnCerrarSesion);
            this.Controls.Add(this.btnCamContraseña);
            this.Controls.Add(this.btnAdminUsuarios);
            this.Controls.Add(this.btnContPrincipal);
            this.Name = "Ventana_Admin";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Ventana_Admin";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Ventana_Admin_FormClosed);
            this.Load += new System.EventHandler(this.Ventana_Admin_Load);
            this.Controls.SetChildIndex(this.btnContPrincipal, 0);
            this.Controls.SetChildIndex(this.btnAdminUsuarios, 0);
            this.Controls.SetChildIndex(this.btnCamContraseña, 0);
            this.Controls.SetChildIndex(this.btnCerrarSesion, 0);
            this.Controls.SetChildIndex(this.lbl1, 0);
            this.Controls.SetChildIndex(this.lbl2, 0);
            this.Controls.SetChildIndex(this.lbl3, 0);
            this.Controls.SetChildIndex(this.lblAdmin, 0);
            this.Controls.SetChildIndex(this.lblUsu, 0);
            this.Controls.SetChildIndex(this.lblDni, 0);
            this.Controls.SetChildIndex(this.btnSalir, 0);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnContPrincipal;
        private System.Windows.Forms.Button btnAdminUsuarios;
        private System.Windows.Forms.Button btnCamContraseña;
        private System.Windows.Forms.Button btnCerrarSesion;
        private System.Windows.Forms.Label lbl1;
        private System.Windows.Forms.Label lbl2;
        private System.Windows.Forms.Label lbl3;
        private System.Windows.Forms.Label lblAdmin;
        private System.Windows.Forms.Label lblUsu;
        private System.Windows.Forms.Label lblDni;
    }
}