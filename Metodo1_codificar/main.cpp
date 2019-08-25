#include <iostream>
#include <fstream> //clase fstream


using namespace std;

int main()
{
    string contenido;

    //***********************************************************
    //leer archivo

    ifstream ficheroEntrada;
    string nombre;
    string frase;

    cout << "Dime el nombre del fichero: ";
    getline(cin,nombre);

    ficheroEntrada.open ( nombre.c_str() , ios::in);
    if (ficheroEntrada.is_open()) {

        while (! ficheroEntrada.eof() ) {
            getline (ficheroEntrada,frase);
            contenido+=frase; // almacenar en un string
        }

        ficheroEntrada.close();
    }

    else {cout << "Fichero inexistente o faltan permisos para abrirlo" << endl;
          exit(1); //terminar programa
    }

    cout << contenido << "\n\n";

    //***********************************************************



    //***********************************************************

    int semilla;
    cout << "Ingrese la semilla: ";
    cin >>semilla;



//    int longitud1=contenido.length();
//    int longitud2=contenido.size();

//    cout << longitud1 << endl;
//    cout << longitud2 << endl;


    //***********************************************************
    //palabra a binario
    string binario;
    int longitud=contenido.length();


    for (int i=0,contador=128,posicion=0;i<longitud;i++) {
        for (int j=0;j<8;j++) {

            if(contenido[i]>=contador)
            {
                binario+=49; //ascii del 1 es 49
                posicion ++;
                contenido[i]-=contador;
                contador/=2;
            }

            else
            {
                binario+=48; //ascii del 0 es 48
                posicion ++;
                contador/=2;
            }
        }

        contador=128;
    }

    cout << binario << "\n\n";
    //***********************************************************
    //Codificacion


    int n0=0,n1=0; //numero de ceros y numero de unos
    int length_b = binario.length();
    string binariocod;
    bool inicial=false;




    for (int i=0;i<length_b;) {

        //Si hay igual cantidad de 1s y 0s se invierte cada bit del grupo.
        if(n0 == n1)
        {
            n0=0;n1=0;//reiniciar contadores de 1s y 0s

            for (int j=0;j<semilla&&i<length_b;j++,i++) {

                if (binario[i]==49)
                {
                    binariocod+=48;
                    n1+=1;
                }
                else{

                    binariocod+=49;
                    n0+=1;
                }
            }
        }

        //Si hay mayor cantidad de 0s se invierte cada 2 bits.
        else if (n0 > n1)
        {
            n0=0;n1=0;//reiniciar contadores de 1s y 0s
            int con=0;

            for (int j=0;j<semilla&&i<length_b;j++,i++) {

                //contar 0s y 1s
                if (binario[i]==49)
                {
                    n1+=1;
                }
                else{
                    n0+=1;
                }

                //invertir cada 2 bits
                if (con == 1)
                {
                   con=0;
                   if (binario[i]==49)
                   {
                       binariocod+=48;
                   }
                   else{
                       binariocod+=49;
                   }

                }
                else
                {
                    binariocod+=binario[i];
                    con++;
                }
            }
        }

        //Si hay mayor cantidad de 1s se invierte cada 3 bits.
        else
        {
            n0=0;n1=0;//reiniciar contadores de 1s y 0s
            int con=0;

            for (int j=0;j<semilla&&i<length_b;j++,i++) {

                //contar 0s y 1s
                if (binario[i]==49)
                {
                    n1+=1;
                }
                else{
                    n0+=1;
                }

                //invertir cada 3 bits
                if (con == 2)
                {
                   con=0;
                   if (binario[i]==49)
                   {
                       binariocod+=48;
                   }
                   else{
                       binariocod+=49;
                   }

                }
                else
                {
                    binariocod+=binario[i];
                    con++;
                }
            }
        }

        //cout << binariocod;
    }


    cout << binariocod << "\n\n";


    //***********************************************************
    //crear archivo

    ofstream resultado;
    resultado.open("binario_codificado.txt",ios::out);

    if(resultado.fail())
        {
         cout<<"no se pudo guardar el archivo codificado en un archivo";
         exit(1);
        }


    resultado<<binariocod;


    resultado.close();
    cout<<"su archivo se a creado \n\n";



     //***********************************************************

    return 0;
}

