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
    public partial class ManteniminetoCliente : Mantenimineto
    {
        public ManteniminetoCliente()
        {
            InitializeComponent();
        }

        public override bool Guardar()
        {
            if (Utilidades.Errortxt(txtIdCli.Text.Trim()) == true | Utilidades.Errortxt(txtNomCli.Text.Trim()) == true | Utilidades.Errortxt(txtApe.Text.Trim()) == true)
            {
                MessageBox.Show("Hay campos vacios");
                return false;
            }
            else
            {
                try
                {

                    string cmd = String.Format("EXEC ActualizaClientes '{0}','{1}','{2}'", txtIdCli.Text.Trim(), txtNomCli.Text.Trim(), txtApe.Text.Trim());
                    Utilidades.Ejecutar(cmd);

                    MessageBox.Show("Se ha guardado correctamente");

                    return true;
                }
                catch (Exception error)
                {
                    MessageBox.Show("Se ha producido un error " + error.Message);
                    return false;
                }
            }
        }

        public override void Eliminar()
        {
            if (Utilidades.Errortxt(txtIdCli.Text.Trim()) == true)
            {
                MessageBox.Show("Hay campos vacios");
            }
            else
            {
                try
                {
                    string cmd = String.Format("EXEC EliminarClientes '{0}'", txtIdCli.Text.Trim());
                    Utilidades.Ejecutar(cmd);

                    MessageBox.Show("Se ha eliminado correctamente");
                }
                catch (Exception error)
                {
                    MessageBox.Show("Se ha producido un error " + error);
                }
            }
        }
        public override void Nuevo()
        {
            txtApe.Text = "";
            txtNomCli.Text = "";
            txtIdCli.Text = "";
        }

    }
}
