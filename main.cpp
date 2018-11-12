#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int **Mass;
    int **Mass2;
    int Lines;
    int Columns;


    srand(time(0));


    cout << endl << " > Type variety of Lines : ";
    cin >> Lines;
    cout << endl << " > Type variety of Columns : ";
    cin >> Columns;


    cout << endl << endl;

    Mass = new int *[Lines];

    for(int i = 0 ; i < Lines ; i++){ Mass[i] = new int[Columns]; }



    for(int i = 0 ; i < Lines ; i++){
         for(int j = 0 ; j < Columns ; j++){

            Mass[i][j] = rand() % 20;

         }
    }



    for(int i = 0 ; i < Lines ; i++){
         for(int j = 0 ; j < Columns ; j++){

            if(j == 0) cout << endl;
           cout << "  " << Mass[i][j] << "  ";

         }
    }

    cout << endl << endl;



        Mass2 = new int *[Lines];

    for(int i = 0 ; i < Lines ; i++){ Mass2[i] = new int[Columns]; }



    for(int i = 0 ; i < Lines ; i++){
         for(int j = 0 ; j < Columns ; j++){

            Mass2[i][j] = 0;

         }
    }

    float a;
    float n,d;

    for(int i = 0 ; i < Lines ; i++){
         for(int j = 0 ; j < Columns ; j++){

            a = sqrt(Mass[i][j]);
            n = modf(a,&d);

            if(n == 0) Mass2[i][j] = Mass[i][j];


         }
    }



    for(int i = 0 ; i < Lines ; i++){
         for(int j = 0 ; j < Columns ; j++){

            if(j == 0) cout << endl;
           cout << "  " << Mass2[i][j] << "  ";

         }
    }

    for(int i = 0 ; i < Lines ; i++){
         for(int j = 0 ; j < Columns ; j++){

            Mass[i][j] = Mass2[i][j];

         }
    }






    int counter = 0;
    int counter1 = 0;
    int tmp = 0;
    int number = 0;
    int maxi;

    cout << endl << endl;

    for(int i = 0 ; i < Lines ; i++){
         for(int j = 0 ; j < Columns ; j++){

             if(Mass[i][j] != 0){

             cout << Mass[i][j] << " ";

                for(int n = 0 ; n < Lines ; n++){
                   for(int m = 0 ; m < Columns ; m++){

                           if(Mass[i][j] == Mass[n][m]){
                               counter++;

                           }
                   }
                }
             }

             if(counter >= counter1 && Mass[i][j] != 0){
           //  cout << endl<<" Count " << counter;

                  if(Mass[i][j] > number || counter > counter1)
                    number = Mass[i][j];
                 //    cout << endl <<" Numb " << number;
                    counter1 = counter;
                    tmp++;
             }

             counter = 0;
         }
    }

    if(counter1 == 0){

    maxi = Mass[0][0];

      for(int i = 0 ; i < Lines ; i++){
         for(int j = 0 ; j < Columns ; j++){

             if(Mass[i][j] != 0){

                    if(maxi < Mass[i][j]) maxi = Mass[i][j];

             }
         }
      }

      number = maxi;
    }



    cout << endl << endl << " The biggest Number, that repeated more often : " << number << endl << endl;

return 0;
}
