using System;

namespace ConsoleApp1
{
    class AppDomain
    {
        static void Main(string[] args)
        {
            int cont = 0;
            int vocales = 0;

            string texto;
            string contienevocal;
            string[] palabra = new string[20];

            Console.WriteLine("Ingrese alguna palabra:");
            texto = Convert.ToString(Console.ReadLine());

            foreach (char letra in texto) {
                contienevocal = Convert.ToString(letra);
                switch (contienevocal) {
                    case "a": palabra[cont] = contienevocal; cont++; break;
                    case "e": palabra[cont] = contienevocal; cont++; break;
                    case "i": palabra[cont] = contienevocal; cont++; break;
                    case "o": palabra[cont] = contienevocal; cont++; break;
                    case "u": palabra[cont] = contienevocal; cont++; break;
                }
            }

            Console.WriteLine();
            contienevocal = "";

            for (int i = cont; i >= 0; i--) {
                for (int z = cont; z >= 0; z--) {
                    if (z == i) {
                    } else {
                        if (palabra[i] == palabra[z]) {
                            palabra[z] = "";
                        }

                    }
                }
                contienevocal = palabra[i] + contienevocal;
            }

            Convert.ToString(contienevocal);

            foreach (char letra in contienevocal)
            {
                contienevocal = Convert.ToString(letra);
                switch (contienevocal)
                {
                    case "a": Console.WriteLine("contiene vocal " + letra); vocales++; break;
                    case "e": Console.WriteLine("contiene vocal " + letra); vocales++; break;
                    case "i": Console.WriteLine("contiene vocal " + letra); vocales++; break;
                    case "o": Console.WriteLine("contiene vocal " + letra); vocales++; break;
                    case "u": Console.WriteLine("contiene vocal " + letra); vocales++; break;
                }
            } 

            Console.WriteLine();

            if (vocales == 5) {
                Console.WriteLine("Contiene TODAS las vocales");
            }
            else {
                Console.WriteLine("Contiene " + vocales + " vocales");
            }
            
            Console.WriteLine("-----------------------------");
            Console.WriteLine();
            Main(args);

        }
    }
}
