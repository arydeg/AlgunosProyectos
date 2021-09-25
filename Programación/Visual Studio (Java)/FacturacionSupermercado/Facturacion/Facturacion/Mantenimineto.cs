using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Facturacion
{
    public partial class Mantenimineto : Form_Base
    {
        public Mantenimineto()
        {
            InitializeComponent();
        }

        private void Mantenimineto_Load(object sender, EventArgs e)
        {

        }

        private void Button1_Click(object sender, EventArgs e)
        {
            Consultar();
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            Guardar();
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            Eliminar();
        }

        private void Button4_Click(object sender, EventArgs e)
        {
            Nuevo();
        }
    }
}
