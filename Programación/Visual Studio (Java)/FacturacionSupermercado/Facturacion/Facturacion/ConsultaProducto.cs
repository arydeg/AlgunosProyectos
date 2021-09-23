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
    public partial class ConsultaProducto : Consultas
    {
        public ConsultaProducto()
        {
            InitializeComponent();
        }

        private void ConsultaProducto_Load(object sender, EventArgs e)
        {
            dataGridView1.DataSource = LlenarDataGrill("Articulo").Tables[0];
        }

        private void BtnBuscar_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(txtNom.Text.Trim()) == true)
            {
                dataGridView1.DataSource = LlenarDataGrill("Articulo").Tables[0];
            }
            else
            {
                DataSet ds;
                string cmd = "Select * FROM Articulo WHERE Nom_pro LIKE ('%" + txtNom.Text.Trim() + "%') ";
                ds = Utilidades.Ejecutar(cmd);

                dataGridView1.DataSource = ds.Tables[0];
            }
  
        }


    }
}
