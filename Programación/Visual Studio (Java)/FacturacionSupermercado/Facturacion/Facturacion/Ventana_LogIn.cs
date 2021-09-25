using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Data;
using MiLibreria;

namespace Facturacion
{
    public partial class Ventana_LogIn : Form_Base
    {       
        public Ventana_LogIn()
        {
            InitializeComponent();
        }

        public static string Usuario;
        public static string AdmOrUser;

        private void BtnIniciar_Click(object sender, EventArgs e)
        {
            txtNombre.Focus();

            try
            {
                string CMD = string.Format("Select * FROM Usuarios WHERE account='{0}' AND password='{1}'", txtNombre.Text.Trim(), txtPass.Text.Trim());

                DataSet ds = Utilidades.Ejecutar(CMD);
                string cuenta = ds.Tables[0].Rows[0]["account"].ToString().Trim();
                string pass = ds.Tables[0].Rows[0]["password"].ToString().Trim();

                if ((cuenta == txtNombre.Text.Trim())&&(pass == txtPass.Text.Trim()))
                {
                    Usuario = ds.Tables[0].Rows[0]["id_usuario"].ToString().Trim();

                    if (Convert.ToBoolean(ds.Tables[0].Rows[0]["Status_admin"]) == true)
                    {    
                        Ventana_Admin ventanaAdmin = new Ventana_Admin();
                        this.Hide();
                        ventanaAdmin.Show();
                        AdmOrUser = "Adm";
                    }
                    else {
                        AdmOrUser = "User";
                        Ventana_User ventanaUser = new Ventana_User();
                        this.Hide();
                        ventanaUser.Show();
                    }
                }

            }
            catch (Exception error) {
                MessageBox.Show("El usuario y/o la contraseña estan incorrectos");
                //MessageBox.Show("UPS!. Se ha producido un error " + error.Message);
            }    

        }

        private void Ventana_LogIn_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }
    }
}
