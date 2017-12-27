// Amat Martínez Vilà
// u1939654
// Sessió 9
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "SolucioSalts.h"
#include "SolucionadorSalts.h"

int main()
{
    auto filename = new char[50];
    std::cout << "Nom del fitxer:" << std::endl << "> ";
    std::cin >> filename;
    std::ifstream file;
    file.open(filename, std::ifstream::in);
    delete [] filename;

    if (file.fail())
        throw ("Fitxer no trobat");
    int n;
    file >> n;
    std::vector<std::vector<int>> v (n+1, std::vector<int>(n+1));
    std::cout << "Matriu del fitxer:" << std::endl;
    int v_actual;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            file >> v_actual;
            std::cout << v_actual << " ";
            v[i][j] = v_actual;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    SolucioSalts sol (v);
    SolucionadorSalts solucionador (sol);
    solucionador.trobar_una_solucio();
    std::list<SolucioSalts::posicio> cami = solucionador.cami();

    std::vector<std::vector<bool>> matriu_cami(n+1, std::vector<bool>(n+1));

    if (!cami.empty())
    {
        std::cout << "Sol·lució trobada:" << std::endl;
        matriu_cami[1][1] = true;
        for (auto &it_salts : cami)
        {
            std::cout << "(" << it_salts.x << "," << it_salts.y << ")";
            matriu_cami[it_salts.y][it_salts.x] = true;
        }
        std::cout << std::endl << std::endl;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (matriu_cami[i][j])
                    std::cout << "#";
                else
                    std::cout << "·";
                std::cout << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}