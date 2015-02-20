#include "lib.h"
#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>


 char opcao_menu;//opção menu



//----------------------------função principal---------------------------------
int main()
{

    do{

        system("cls");
        printf("%s","------------------------------\n ");
        printf("%s"," [1] - soma \n ");
        printf("%s"," [2] - subtracao \n");
        printf("%s","  [3] - multiplicacao \n");
        printf("%s","  [4] - divisao \n");
        printf("%s","  [5] - Sair \n");


        printf("%s","Informe a opcao desejada\n");
        scanf("%c", &opcao_menu); //menu principal


//-------------------------- soma ------------------------------------
       if (opcao_menu == '1'){
            sub_menu('1'); //
       }

//--------------------------subtração ------------------------------------

       if (opcao_menu == '2'){
            sub_menu('2');
       }

//-------------------------multiplicação ---------------------------------


       if (opcao_menu == '3'){
            sub_menu('3');
       }


//-------------------------divisão ---------------------------------


       if (opcao_menu == '4'){
            sub_menu('4');
       }




    }while(opcao_menu !='5');

  return 0;
}
