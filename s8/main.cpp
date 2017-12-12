// Amat Martínez Vilà
// u1939654
// Sessió 8

#include <iostream>
#include "GrafEtiquetatVMap.h"

void escriure_graf_pintat(GrafEtiquetatVMap& g, const char *nomFitxerTGF)
{
    ofstream f_sort;
    f_sort.open(nomFitxerTGF, ofstream::out);
    if (f_sort.fail())
        cerr << "Ha fallat l'escriptura del fitxer:" << nomFitxerTGF;
    else
    {
        int n_vertexs = g.nVertexs();
        vector<string> taula_colors = {
                "",
                "indigo",
                "cyan",
                "darkred",
                "aquamarine",
                "lime",
                "rosybrown",
                "orangered",
                "olive",
                "gold",
                "sienna"
        };
        f_sort << "strict graph {" << endl << "\tnode [style=filled]" << endl;

        g.AfegirEtiqueta(1, 1);
        f_sort << "\t" << "1 [color=" << taula_colors[g.ObtenirEtiqueta(1)] << "]" << endl;
        for (int v_actual = 2; v_actual <= n_vertexs; v_actual++)
        {
            vector<bool> descartats(v_actual+1, false);
            for (int vei_actual = 1; vei_actual < v_actual; vei_actual++)
            {
                if (g.ExisteixAresta(v_actual, vei_actual))
                    descartats[g.ObtenirEtiqueta(vei_actual)] = true;
            }
            int color = 1;
            while (descartats[color])
                color++;
            g.AfegirEtiqueta(v_actual, color);
            f_sort << "\t" << v_actual << " [color=" << taula_colors[g.ObtenirEtiqueta(v_actual)] << "]" << endl;
        }
        for (int v_actual = 1; v_actual <= n_vertexs; v_actual++)
        {
            int veins_recorreguts = 0;
            for (int vei_actual = v_actual; vei_actual <= n_vertexs && veins_recorreguts <= g.n_veins(v_actual); ++vei_actual)
            {
                if (g.ExisteixAresta(v_actual, vei_actual))
                {
                    veins_recorreguts++;
                    f_sort << "\t" << v_actual << " -- " << vei_actual << endl;
                }
            }
        }
        f_sort << "}" << endl;
        f_sort.close();
    }
}

int main()
{
    char filename[50];
    cout << "Nom del fitxer:" << endl << "> ";
    cin >> filename;

    GrafEtiquetatVMap g(filename, false);
    cout << "Nom del fitxer de sortida (amb l'extensió .dot):" << endl << "> ";
    cin >> filename;
    escriure_graf_pintat(g, filename);
    return 0;
}