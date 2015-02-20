#include "lib.h"
#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>


 char opcao_soma;//op��o menu soma
 char opcao_multiplica; //opc�o submenu
 char opcao_subtrai;//opcao menu subtrai
 char opcao_divide; //opcao menu divide



//-------------------------fun��o submenu------------------------------------------------
void sub_menu(char op){

    TLista *primeiro = inicializa();
    TLista *segundo = inicializa();

    char first[MAX];
    char second[MAX];

    TLista * p = inicializa();
    TLista * s = inicializa();

//---------------------------------------opera��o soma-----------------------------------------
  if(op =='1'){ //opera��o soma

   do{
            system("cls");
            //system("clear");
            printf("%s","------------------------------\n ");
            printf("%s"," [1] - somar \n ");
            printf("%s"," [2] - sair \n");

            printf("%s","Informe a opcao desejada >>>_");
            scanf("%c", &opcao_soma); //recebe a op�ao menu

            //chama a fun��o soma
         if (opcao_soma == '1'){

           system("cls");
           printf("Entre com o primeiro numero: ");
           scanf("%s",&first);


            printf("Entre com o segundo numero: ");
            scanf("%s",&second);

            int i;
            int numeroCorrente;

            for (i=0; i < strlen(first); i++) {
                numeroCorrente = first[i] - 48;
                primeiro = ins_ini(primeiro,numeroCorrente);
            }

            for (i=0; i < strlen(second); i++) {
                numeroCorrente = second[i] - 48;
                segundo = ins_ini(segundo,numeroCorrente);
            }

            TLista *resultado = adicao(primeiro, segundo);//chama a fun��o
            imprime(resultado); //imprime o resultado


            first[MAX] = "";
            second[MAX] = "";
            primeiro = inicializa();
            segundo = inicializa();

            printf("%s","\n\n ");
            //system("pause");

         }


         }while(opcao_soma != '2'); //sai do menu soma

    }




//---------------------------------------opera��o subtracao-----------------------------------------
  if(op =='2'){ //opera��o subtracao

   do{
            //system("cls");
            system("clear");
            printf("%s","------------------------------\n ");
            printf("%s"," [1] - subtrair \n ");
            printf("%s"," [2] - sair \n");

            printf("%s","Informe a opcao desejada >>>_");
            scanf("%c", &opcao_subtrai); //recebe a op�ao menu

            //chama a fun��o soma
         if (opcao_subtrai == '1'){

           //system("cls");
           system("clear");
           printf("Entre com o primeiro numero: ");
           scanf("%s",&first);

            printf("Entre com o segundo numero: ");
            scanf("%s",&second);

            int i;
            int numeroCorrente;

            for (i=0; i < strlen(first); i++) {
                numeroCorrente = first[i] - 48;
                primeiro = ins_ini(primeiro,numeroCorrente);
            }

            for (i=0; i < strlen(second); i++) {
                numeroCorrente = second[i] - 48;
                segundo = ins_ini(segundo,numeroCorrente);
            }

            if (compara(primeiro, segundo) == -1) {
                   s = primeiro;
                   p = segundo;
            } else {
                   p = primeiro;
                   s = segundo;
            }

            TLista *resultado = subtracao(p, s);//chama a fun��o
            imprime(resultado); //imprime o resultado


            first[MAX] = "";
            second[MAX] = "";
            primeiro = inicializa();
            segundo = inicializa();

            printf("%s","\n\n ");
            //system("pause");

         }


         }while(opcao_subtrai != '2'); //sai do menu soma

    }



// ------------------opera��o multiplicacao-----------------------------------------
  if(op =='3'){ //opera��o multiplica

   do{
            //system("cls");
            system("clear");
            printf("%s","------------------------------\n ");
            printf("%s"," [1] - multiplicar \n ");
            printf("%s"," [2] - sair \n");

            printf("%s","Informe a opcao desejada >>>_");
            scanf("%c", &opcao_multiplica); //recebe a op�ao menu

            //chama a fun��o soma
         if (opcao_multiplica == '1'){

           //system("cls");
           system("clear");
           printf("Entre com o primeiro numero: ");
           scanf("%s",&first);

           printf("Entre com o segundo numero: ");
            scanf("%s",&second);

            int i;
            int numeroCorrente;

            for (i=0; i < strlen(first); i++) {
                numeroCorrente = first[i] - 48;
                primeiro = ins_ini(primeiro,numeroCorrente);
            }

            for (i=0; i < strlen(second); i++) {
                numeroCorrente = second[i] - 48;
                segundo = ins_ini(segundo,numeroCorrente);
            }

            TLista *resultado = multiplicacao(primeiro, segundo);
            imprime(resultado);


            first[MAX] = "";
            second[MAX] = "";
            primeiro = inicializa();
            segundo = inicializa();

            printf("%s","\n\n ");
            //system("pause");

         }


         }while(opcao_multiplica != '2'); //sai do menu multiplica

    }



//----------------------------opera��o divisao----------------------------------
    if(op =='4'){ //opera��o divisao

     do{
            system("cls");
            printf("%s","------------------------------\n ");
            printf("%s"," [1] - dividir \n ");
            printf("%s"," [2] - sair \n");

            printf("%s","Informe a opcao desejada >>>_");
            scanf("%c", &opcao_divide); //recebe a op�ao menu

            //chama a fun��o soma
         if (opcao_divide == '1'){


             TLista *dividendo = inicializa(); //dividendo

             long int segundo;

             //system("cls");
             system("clear");
             printf("Entre com o primeiro numero: ");
             scanf("%s",&first);

             printf("Entre com o segundo numero: ");
             scanf("%lld",&segundo);


                int i;
                int numeroCorrente;

                for (i=0; i < strlen(first); i++) {
                    numeroCorrente = first[i] - 48;
                    dividendo = ins_ult(dividendo,numeroCorrente);
                }

                if (segundo!=0){
                    TLista *quociente = divisao(dividendo,segundo);
                    imprime(quociente);
                }else{
                    printf("\n\n");
                    printf("%s\n","Nao e possivel realizar divisao por zero(0)");
                }

                first[MAX] = "";
                printf("%s","\n\n ");
                //system("pause");
         }


        }while(opcao_divide != '2');
    }





} //-------------------------------------fim fun��o submenu---------------------------------



