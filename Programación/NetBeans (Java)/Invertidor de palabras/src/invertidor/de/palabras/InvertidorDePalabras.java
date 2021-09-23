package invertidor.de.palabras;
import java.util.*;

public class InvertidorDePalabras {

    public static void main(String[] args) {
        System.out.println("Ingresa tu palabra o texto sin mayusculas:");
        
        Scanner sc = new Scanner(System.in);
        String[] a = sc.nextLine().split(" ");
        char arr[]= new char [50];
        
        try{
            for(int i=0; i<a.length; i++){
                for(int z=0; z<a[i].length(); z++){
                    arr[z]=a[i].charAt(z);
                }

                Arrays.sort(arr);
                System.out.print(arr);
                System.out.print(" ");

                for(int x=0; x<arr.length; x++){
                    arr[x]='\u0000';
                }
            }
        }catch(Exception e){
            System.out.println("A ocurrido un error. Porfavor intentelo de nuevo");
        }
    }
    
}