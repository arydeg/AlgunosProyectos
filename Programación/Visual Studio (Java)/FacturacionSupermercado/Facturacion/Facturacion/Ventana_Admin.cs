using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MiLibreria;

namespace Facturacion
{
    public partial class Ventana_Admin : Form_Base
    {
        public Ventana_Admin()
        {
            InitializeComponent();
        }

        private void Ventana_Admin_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }

        private void BtnContPrincipal_Click(object sender, EventArgs e)
        {
            ContenedorMDI contedorPrincipal = new ContenedorMDI();
            this.Hide();
            contedorPrincipal.Show();
        }

        private void Ventana_Admin_Load(object sender, EventArgs e)
        {
            DataSet ds;
            string cmd = string.Format("Select * FROM Usuarios WHERE id_usuario = " + Ventana_LogIn.Usuario);
            ds = Utilidades.Ejecutar(cmd);

            lblAdmin.Text = ds.Tables[0].Rows[0]["account"].ToString().Trim();
            lblUsu.Text = ds.Tables[0].Rows[0]["Nom_usu"].ToString().Trim();
            lblDni.Text = ds.Tables[0].Rows[0]["id_usuario"].ToString().Trim();
        }

        private void BtnCerrarSesion_Click(object sender, EventArgs e)
        {
            Ventana_LogIn vl = new Ventana_LogIn();
            this.Hide();
            vl.Show();
        }

        private void BtnCamContraseña_Click(object sender, EventArgs e)
        {
            CambiarPass cp = new CambiarPass();
            this.Hide();
            cp.Show();
        }



    }
}
