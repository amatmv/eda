// Amat Martínez Vilà
// u1939654
// Practica d'algorísmica

#include <iostream>
#include <getopt.h>
#include <fstream>
#include <vector>
#include <chrono>
#include "SolucionadorNadal.h"

const char* HELP = "*** PREPARADOR DE SOPARS DE NADAL ***\n"
        "Utilització: ./nadal [--help,-h,-m x,-u,-g] fitxer\n"
        "\non\n\n"
        "-h, --help:\tmostra aquest missatge d’ajuda i surt\n"
        "-m x:\t\tcerca i mostra, si la troba, una solucio\n"
        "\t\ton grau aversió màxim tol·lerat és x\n"
        "-u:\t\tmostra una disposició que minimitzi el grau\n"
        "\t\tglobal d’aversió entre veïns de taula\n"
        "-g:\t\tutilitza una estrategia voraç (greedy)\n"
        "fitxer  ha de ser un fitxer de text que contingui\n"
        "la llista de convidats i els seus graus d’aversió (en format .txt).";
const char* ARG_MISSING = "Falten arguments (\"./nadal --help\" per ajuda)";
const char* UNKNOWN_OPT = "Opcio desconeguda: ";

bool isset(const char*c);

bool fitxerEsFormat(const std::string& filename, const std::string& format);

int main(int argc, char **argv)
{
    int do_help = 0, do_greedy = -1, do_optimum = -1, max_aversio = -1;
    char const *myfile = "";
    bool do_non_optimal = false;

    struct option longopts[] = {
            { "help", no_argument,          & do_help,  1},
    };
    int opt;
    while ((opt = getopt_long(argc, argv, ":hf:gum:", longopts, nullptr)) != -1)
    {
        switch (opt) {
            case 'm':
                do_non_optimal = true;
                max_aversio = atoi(optarg);
                break;
            case 'u':
                do_optimum = 1;
                break;
            case 'g':
                do_greedy = 1;
                break;
            case 'h':
                do_help = 1;
                break;
            case 0:
                break;
            case ':':
                std::cerr << ARG_MISSING << std::endl;
                return -1;
            case '?':
            default:
                std::cerr << UNKNOWN_OPT << (char)optopt << std::endl;
                return -1;
        }
    }
    if (fitxerEsFormat(std::string(argv[argc-1]), ".txt"))
        myfile = argv[argc-1];
    else
    {
        std::cerr << "Falta el nom del fitxer (en format .txt)" << std::endl;
        return -1;
    }
    if (do_help == 1)
    {
        std::cout << HELP << std::endl;
        return 0;
    }
    else if (isset(myfile) && do_non_optimal && max_aversio == -1)
    {
        std::cerr << "Falta el grau màxim d’aversió" << std::endl;
        return -1;
    }

    std::ifstream file;
    file.open(myfile, std::ifstream::in);
    if (file.fail())
        throw ("Fitxer no trobat");

    int n_convidats;
    file >> n_convidats;
    file.ignore(100, '\n');
    std::string convidats[n_convidats];
    for (int k = 0; k < n_convidats; k++)
        getline(file, convidats[k]);

    std::vector<std::vector<int>> aversions(n_convidats, std::vector<int>(n_convidats));
    for (int i = 0; i < n_convidats; i++)
        for (int j = 0; j < n_convidats; j++)
            file >> aversions[i][j];

    std::chrono::high_resolution_clock::time_point t1, t2;
    if (max_aversio != -1)
    {
        SolucionadorNadal solucionador(SolucioNadal(n_convidats, max_aversio, aversions, convidats));
        t1 = std::chrono::high_resolution_clock::now();
        solucionador.solucio_index_aversio();
        t2 = std::chrono::high_resolution_clock::now();
        if (solucionador.solucio_trobada())
        {
            std::cout << "TAULA DE " << n_convidats << " CONVIDATS AMB UN INDEX MÀXIM DE: " << max_aversio << std::endl;
            std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            solucionador.mostrar();
            std::cout << "Sol·lució trobada en " << time_span.count() << " segons." << std::endl;
        }
    }

    if (do_optimum != -1)
    {
        std::cout << "TAULA DE " << n_convidats << " CONVIDATS AMB UN INDEX ÒPTIM" << std::endl;
        SolucionadorNadal sol_optima(SolucioNadal(n_convidats, aversions, convidats));
        t1 = std::chrono::high_resolution_clock::now();
        sol_optima.solucio_minima_aversio();
        t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        sol_optima.mostrar();
        std::cout << "Sol·lució trobada en " << time_span.count() << " segons." << std::endl;
    }

    if (do_greedy != -1)
    {
        // ============================
        //      TODO: implementar
        // ============================
        std::cout << "TAULA DE " << n_convidats << " CONVIDATS OPTIMITZANT L'AVERSIÓ MITJANÇANT LA TÈCNICA VORAÇ" << std::endl;
        std::cout << "No implementada" << std::endl;
        SolucionadorNadal sol_optima(SolucioNadal(n_convidats, aversions, convidats));
        t1 = std::chrono::high_resolution_clock::now();
        //sol_optima.solucio_aproximada();
        t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        sol_optima.mostrar();
        std::cout << "Sol·lució trobada en " << time_span.count() << " segons." << std::endl;
    }
    return 0;
}

bool fitxerEsFormat(const std::string& filename, const std::string& format)
{
    if (filename.length() < format.length())
        return false;
    for (int i = 1; i <= format.length(); i++)
        if (filename[filename.length()-i] != format[format.length()-i])
            return false;
    return true;
}

bool isset(const char *c)
{
    return c && c[0];
}