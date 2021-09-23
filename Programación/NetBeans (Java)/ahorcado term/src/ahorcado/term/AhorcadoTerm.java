/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ahorcado.term;
import java.util.Scanner;
/**
 *
 * @author ary
 */
public class AhorcadoTerm {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        String[] Palabras = new String[]{
            "ary",
            "ary intenta",
            "ahorcado",
            "marto pierde",
            };
        
     
        String palabra = Palabras[numero(Palabras.length)];
        
        boolean Terminado = false;
        boolean[] letra = new boolean[palabra.length()];
        
        for(int i=0; i<letra.length; i++) 
            letra[i] = (palabra.charAt(i) == ' ');
        
        Scanner scanner = new Scanner(System.in);
        
        int vidas = 10;
        
        while(!Terminado) 
        {
            System.out.print("palabra");
            
            for(int i=0; i<palabra.length(); i++)
            {
                if(letra[i]){
                    System.out.print(palabra.charAt(i)); 
                }else{ 
                    System.out.print('_'); 
                }
            }
            
            System.out.print(vidas + " vidas");
            
            char entrada = scanner.next().charAt(0);
            
            boolean acertado = false;
            
            for(int i=0; i<palabra.length(); i++)
                if(palabra.charAt(i) == entrada){
                    letra[i] = true;
                    acertado = true;
                }
           
            if(acertado){
                if(ganaste(letra)){ 
                    Terminado = true; 
                    System.out.println("Muy bien! Adivinaste! Era " + palabra + "!");
                }
                
            }else{ 
                vidas--; 
                if(vidas == 0){ 
                    Terminado = true;
                    System.out.println("Wep, te quedaste tikero. 0 vidas.");
                }
                
        }}
    }
    
    static int numero(int max){
        return (int)(Math.random() * max);
    }
    
    static boolean ganaste(boolean[] array){
        for(int i=0; i<array.length; i++) 
            if(!array[i]) 
                return false;
        return true;
    }
    
    
}
