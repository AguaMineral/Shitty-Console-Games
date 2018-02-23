
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

#define COLUMNS 10
#define ROWS 10

using namespace std;


//Las coordenadas del tablero, meramente visual
char index [10] = {'A','B','C','D','E','F','G','H','I','J'};

class Table
{
private:
    char _arr[ROWS][COLUMNS];
public:
    Table()
    {
        for(int i = 0; i < ROWS; i++)
            for (int k = 0; k < COLUMNS; k++)
                _arr[i][k] = 'O';
    }

    //Función que actualiza el tablero con las tiradas de cada turno
    void SetTable(Table& table, int x, int y, const string& s, char rotation)
    {
        //Rotación horizontal
        if (rotation == 'H')
        {
            //bucle para introducir el barco en el tablero
            for ( int i = 0; i < 1; i++)
            {
                for ( int j = 0; j < s.size(); j++)
                    table._arr[x+i][y+j] = s[i];
            }

        }//Rotación vertical
        else if(rotation == 'V')
        {
            //bucle para introducir el barco en el tablero
            for ( int i = 0; i < s.size(); i++)
                table._arr[x+i][y] = s[i];
        }
        else
            cout << "Error, formato de rotación no válido" << endl;
    }
    //Función que imprime el tablero con sus coordenadas
    void PrintTable()
    {
        cout << "\t  ";
        for(int i = 0; i < ROWS; i++)
            cout <<  i+1 << " ";
        for(int i = 0; i < ROWS; i++)
        {

            cout << endl;
            cout << "\t" << index[i] << " ";
            for(int j = 0; j < COLUMNS; j++)
                cout << _arr[i][j] << " ";
        }
        cout << endl;
    }
};

int main()
{
    ///////////////////////// SHIPS //////////////////////////////

    string destructor ("XXXXX");
    string fragata("XXX");
    string lancha("X");

    ////////////////////// LOGIC GAME STUFF //////////////////////

    bool ganador = false;
    //Contador de Turnos
    int Turno = 0;

    //Pruebas con el generador aleatorio de numeros

    int i = 15;
    srand(time(NULL));
    while(i > 0)
    {
        cout << rand() % 100 << " ";
        i--;
    }
    cout << endl;

    ////////////////////// MENÚ ///////////////////////////////////

    cout << "Bienvenido a Aqua_Battles" << endl;
    cout << "Pon los barcos en el tablero" << endl;

    ///////////////////// GAME LOOP ///////////////////////////////////////////

    Table a;

    while(!ganador)
    {
        char rot = 'H';
        //se le pasa la instancia del tablero, las coordenadas donde quiere situarse el barco, el tipo de barco y la posición de este
        a.SetTable(a, 5, 5, fragata, rot);
        a.PrintTable();
        cin.get();
    }
    return 0;
}


