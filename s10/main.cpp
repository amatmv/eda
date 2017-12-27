// Amat Martínez Vilà
// u1939654
// Sessió 9
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <getopt.h>
#include "SolucioSalts.h"
#include "SolucionadorSalts.h"

std::vector<std::vector<int>> generar_tauler_aleatori(int tamany, int v_maxim);

std::vector<std::vector<int>> llegir_matriu_de_fitxer(char *filename);

void mostrar_matriu(const std::vector<std::vector<int>> &matriu, const std::vector<int>& digits);

int main(int argn, char ** argv)
{
    std::vector<std::vector<int>> matriu;
    int opt;
    while ( (opt = getopt(argn, argv, "rf")) != -1 )
    {
        switch ( opt )
        {
            case 'r':
                if (argn < 4)
                    throw ("Falten paràmetres per a l'opció: -r");
                matriu = generar_tauler_aleatori(atoi(argv[2]), atoi(argv[3]));
                break;
            case 'f':
                if (argn < 3)
                    throw ("Falten paràmetres per a l'opció: -f");
                matriu = llegir_matriu_de_fitxer(argv[2]);
                break;
            case '?':
                std::cerr << "Unknown option: '" << char(optopt) << "'!" << std::endl;
                break;
            default:
                break;
        }
    }

    time_t t1,t2;
    auto n = matriu.size();
    SolucioSalts sol(matriu);
    SolucionadorSalts solucionador(sol);
    t1 = time(NULL);
    solucionador.trobar_una_solucio();
    t2 = time(NULL);
    std::list<SolucioSalts::posicio> cami = solucionador.cami();

    if (!cami.empty())
    {
        std::vector<std::vector<int>> matriu_cami(n+1, std::vector<int>(n+1));
        std::vector<int> digits(n+1, 0);

        int salts = 1;
        matriu_cami[1][1] = salts++;

        std::cout << "Sol·lució trobada en " << difftime(t2,t1) << " segons." << std::endl;
        int n_actual;
        for (auto &it_salts : cami)
        {
            std::cout << "(" << it_salts.x << "," << it_salts.y << ")";
            matriu_cami[it_salts.x][it_salts.y] = salts++;

            n_actual = matriu_cami[it_salts.x][it_salts.y];
            for(; n_actual > 0; n_actual/=10, digits[it_salts.x]++);
        }
        std::cout << std::endl << std::endl;
        mostrar_matriu(matriu_cami, digits);
    }
    return 0;
}

std::vector<std::vector<int>> llegir_matriu_de_fitxer(char *filename)
{
    std::ifstream file;
    file.open(filename, std::ifstream::in);
    if (file.fail())
        throw ("Fitxer no trobat");
    int n;
    file >> n;

    std::vector<std::vector<int>> v(n+1, std::vector<int>(n+1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            file >> v[i][j];
    return v;
}

std::vector<std::vector<int>> generar_tauler_aleatori(int tamany, int v_maxim)
{
    std::vector<std::vector<int>> v(tamany+1, std::vector<int>(tamany+1));
    for (int i = 1; i <= tamany; i++)
        for (int j = 1; j <= tamany; j++)
            v[i][j] = rand() % (v_maxim-1) + 1;
    return v;
}

void mostrar_matriu(const std::vector<std::vector<int>> &matriu, const std::vector<int> &digits)
{
    auto tamany = matriu.size();
    for (int i = 1; i <= tamany; ++i)
    {
        for (int j = 1; j <= tamany; ++j)
        {
            if (matriu[i][j] != 0)
                std::cout << matriu[i][j];
            else
            {
                std::cout << "·";
                for (int k = 0; i < digits[j]; k++)
                    std::cout << " ";
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
