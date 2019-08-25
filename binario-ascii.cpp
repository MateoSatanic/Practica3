#include <iostream>

using namespace std;

int main()
{


    //***********************************************************
    //palabra a binario
    string palabra;
    string binario;

    cout << "ingrese palabra: ";
    getline(cin,palabra);


    int longitud=palabra.length();


    for (int i=0,contador=128,posicion=0;i<longitud;i++) {
        for (int j=0;j<8;j++) {

            if(palabra[i]>=contador)
            {
                binario+=49;
                posicion ++;
                palabra[i]-=contador;
                contador/=2;
            }

            else
            {
                binario+=48;
                posicion ++;
                contador/=2;
            }
        }

        contador=128;
    }

    cout << binario << "\n\n";

    //***********************************************************
    //binario a  palabra

    binario= "0100110101100001011101000110010101101111";
    int longitud1=binario.length();

    string frase;

    for (int i=0,contador=128,suma=0;i<longitud1;) {
        for (int j=0;j<8;i++,j++) {

            if(binario[i]==49)
            {
               suma+=contador;
               contador/=2;
            }

            else
            {
               contador/=2;
            }
        }

        contador=128;
        frase+=suma;
        suma=0;
    }

    cout << frase << "\n\n";

    return 0;
}
