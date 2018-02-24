
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

#define COLUMNS 11
#define ROWS 11

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
            {
                if(i == 0 || i == 10){_arr[i][k] = '#';}
                else if(k==0 || k == 10){_arr[i][k] == '#';}
                _arr[i][k] = 'O';
            }

    }
    //Funcion que resetea el tablero
    void ResetTable()
    {
        Table();
    }

    //Función que actualiza el tablero con las tiradas de cada turno
    void SetTable(Table& table, int x, int y, const string& ship, char rotation)
    {
        //Rotación horizontal
        if (rotation == 'H')
        {
            CheckPos(table, x, y, ship, rotation);
            //bucle para introducir el barco en el tablero
            for ( int i = 0; i < 1; i++)
            {
                for ( int j = 0; j < ship.size(); j++){

                    table._arr[x+i][y+j] = ship[i];
                }
            }

        }//Rotación vertical
        else if(rotation == 'V')
        {
            CheckPos(table, x, y, ship, rotation);
            //bucle para introducir el barco en el tablero
            for ( int i = 0; i < ship.size(); i++)
                table._arr[x+i][y] = ship[i];
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

    /////////////////// REGLAS DE POSICIONAMIENTO DE BARCOS /////////////////////

    bool CheckPos(Table& table, int x, int y, const string& ship, char rot)
    {
        if ( rot == 'H')
        {
            cout << "h" << endl;
            for ( int i = y; i < ship.size()+y; i++ )
            {
                    //Comprobar si se superponen- Comprueba si hay barco contiguo
                if ( table._arr[x][i] == 'X' || table._arr[x-1][i] == 'X'|| table._arr[x+1][i] == 'X'|| table._arr[x][y-1] == 'X'|| table._arr[x][y+ship.size()] == 'X'
                    || (ship.size()+y) > COLUMNS || (ship.size() - y) < 0)//->comprueba si se sale del tablero
                {cout << "Posicion erronea, ya hay un barco" << endl; return false;}
            }
            cout << "Posicion correcta" << endl;
            return true;
        }
        else if( rot == 'V')
        {
            //Comprobar si se superponen
            cout << "v" << endl;
            for ( int i = x; i < ship.size()+ x; i++)
            {
                if ( table._arr[i][y] == 'X' || table._arr[i+1][y+1] == 'X'|| table._arr[i+1][y-1] == 'X'|| table._arr[i-1][y] == 'X'|| table._arr[i+ship.size()][y] == 'X'
                    || table._arr[x+ship.size()][y] != 'X' && table._arr[x+ship.size()][y] != 'O' )
                {cout << "Posicion erronea, ya hay un barco" << endl; return false;}
            }
            cout << "Posicion correcta" << endl;
            return true;
        }
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

    //Table a;

    while(!ganador)
    {
        Table a;
        char rot = 'H';
        char rot2 = 'V';
        int x = rand() % 10;
        int y = rand() % 10;
        int x2 = rand() % 10;
        int y2 = rand() % 10;
        //se le pasa la instancia del tablero, las coordenadas donde quiere situarse el barco, el tipo de barco y la posición de este
  //      a.SetTable(a, 6, 7, fragata, rot);
  //      a.SetTable(a, 7, 0, fragata, rot2);
        a.PrintTable();
        a.ResetTable();
        cin.get();
    }
    return 0;
}


