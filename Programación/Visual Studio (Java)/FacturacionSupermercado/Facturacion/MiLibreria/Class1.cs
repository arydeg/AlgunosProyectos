using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace MiLibreria
{
    public class Utilidades
    {
        public static DataSet Ejecutar(string cmd) {
            SqlConnection connection = new SqlConnection("Data Source=.;Initial Catalog=Administracion;Integrated Security=True");
            connection.Open();
            DataSet DS = new DataSet();
            SqlDataAdapter DA = new SqlDataAdapter(cmd,connection);
            DA.Fill(DS);
            connection.Close();

            return DS;
        }

        public static Boolean Errortxt(string txt) {
            if (txt == "")
            {
                return true;
            }
            else {
                if (txt == " ")
                {
                    return true;
                }
                else {
                    return false;
                }
            }

        }

    }
}
