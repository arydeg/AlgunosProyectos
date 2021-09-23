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
    public partial class Consultas : Form_Base
    {
        public Consultas()
        {
            InitializeComponent();
        }

        public DataSet LlenarDataGrill(string tabla) {
            DataSet ds;
            string cmd = string.Format("SELECT * FROM " + tabla);
            ds = Utilidades.Ejecutar(cmd);
            return ds;
        }

        private void BtnSelect_Click(object sender, EventArgs e)
        {
            if (dataGridView1.Rows.Count == 0)
            {
                return;
            }
            else
            {
                DialogResult = DialogResult.OK;
                Close();
            }
        }

    }
}
