// Amat Martínez Vilà
// u1939654
// Sessió 7

#include <iostream>
#include "GrafVList.h"

int vertexs_senars(const GrafVList &g)
// pre: cert
// post: retorna el nombre de vèrtexs del graf que té un pès senar.
{
    int n_arestes, vertexs_senars = 0;
    for (int i = 1; i < g.nVertexs(); ++i)
    {
        n_arestes = g.n_veins(i);
        if (n_arestes % 2 != 0)
            ++vertexs_senars;
    }
    return vertexs_senars;
}

void esEuleria(const GrafVList &g)
// pre: cert
// post: mostra per pantalla si té camí eulerià, circuit eulerià o no és eulerià.
{
    int v_senars = vertexs_senars(g);
    int n_arestes = g.nArestes();

    if (n_arestes > 0 && v_senars == 2)
        cout << "Té camí Eulerià." << endl;
    else if (n_arestes > 0 && v_senars == 0)
        cout << "Té circuit Eulerià." << endl;
    else
        cout << "No té camí ni circuit Eulerià." << endl;
}

int main()
{
    char filename[50];
    cout << "Nom del fitxer:" << endl << "> ";
    cin >> filename;

    GrafVList g(filename, false);
//    g.EscriureGraf("test.tgf");
    esEuleria(g);
    return 0;
}