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
    public partial class CambiarPass : Form
    {
        public CambiarPass()
        {
            InitializeComponent();
        }

        private void BtnVolver_Click(object sender, EventArgs e)
        {
            if (Ventana_LogIn.AdmOrUser == "Adm")
            {
                Ventana_Admin va = new Ventana_Admin();
                this.Hide();
                va.Show();
            }
            else
            {
                Ventana_User vu = new Ventana_User();
                this.Hide();
                vu.Show();
            }
        }

        private void BtnSig_Click(object sender, EventArgs e)
        {
            if (Utilidades.Errortxt(txtPass.Text.Trim()) == true | Utilidades.Errortxt(txtRepetir.Text.Trim()) == true)
            {
                MessageBox.Show("Hay campos vacios");
            }
            else
            {
                if (txtPass.Text == txtRepetir.Text)
                {
                    DataSet ds;
                    string cmd = string.Format("EXEC ActualizaPass '{0}','{1}'", txtPass.Text.Trim(),Ventana_LogIn.Usuario);
                    ds = Utilidades.Ejecutar(cmd);
                    MessageBox.Show("Se ha cambiado con exito");
                    Ventana_LogIn vl = new Ventana_LogIn();
                    this.Hide();
                    vl.Show();
                }
                else {
                    MessageBox.Show("Las contraseñas no coinciden");
                }
            }
        }

        private void CambiarPass_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }
    }
}
