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
    public partial class MantenimientoProducto : Mantenimineto
    {
        public MantenimientoProducto()
        {
            InitializeComponent();
        }

        public override Boolean Guardar()
        {
            if (Utilidades.Errortxt(txtIdProd.Text.Trim()) == true | Utilidades.Errortxt(txtNomProd.Text.Trim()) == true | Utilidades.Errortxt(txtPrecio.Text.Trim()) == true)
            {
                MessageBox.Show("Hay campos vacios");
                return false;
            }
            else
            {
                try
                {

                    string cmd = String.Format("EXEC ActualizaArticulos '{0}','{1}','{2}'", txtIdProd.Text.Trim(), txtNomProd.Text.Trim(), txtPrecio.Text.Trim());
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
            if (Utilidades.Errortxt(txtIdProd.Text.Trim()) == true)
            {
                MessageBox.Show("Hay campos vacios");
            }
            else
            {
                try
                {

                    string cmd = String.Format("EXEC EliminarArticulos '{0}'", txtIdProd.Text.Trim());
                    Utilidades.Ejecutar(cmd);

                    MessageBox.Show("Se ha eliminado correctamente");

                }
                catch (Exception error)
                {
                    MessageBox.Show("Se ha producido un error " + error.Message);
                }
            }
        }

        public override void Nuevo()
        {
            txtIdProd.Text = "";
            txtNomProd.Text = "";
            txtPrecio.Text = "";
        }


    }
}
