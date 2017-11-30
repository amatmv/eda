vector<int> obtSubconjuntMinim() const
{
        vector<vector<bool>> adjacencies (nVers+1, vector<bool> (nVers+1));
        vector<int> nombre_arestes_per_vertex(nVers+1, 0);
        vector<int> subconjunt();
        int arestes_restants = nArs;

        for (int i = 1; i <= nVers; ++i)
        {
                for (int j = 1; j <= i; ++j)
                {
                        if (matArestes[i][j])
                        {
                                adjacencies[i][j] = adjacencies[j][i] = true;
                                nombre_arestes_per_vertex[i]++;
                                nombre_arestes_per_vertex[j]++;
                        }
                }
        }
        while(arestes_restants > 0)
        {
                int prometedor = 1;
                for (int i = 2; i <= nVers; ++i)
                        if (nombre_arestes_per_vertex[i] > nombre_arestes_per_vertex[prometedor])
                                prometedor = i;

                subconjunt.push_back(prometedor);
                for (int i = 1; i <= prometedor; ++i)
                {
                        if (adjacencies[prometedor][i])
                        {
                                nombre_arestes_per_vertex[prometedor]--;
                                nombre_arestes_per_vertex[i]--;
                                adjacencies[prometedor][i] = adjacencies[i][prometedor] = false;
                                arestes_restants--;
                        }
                }
        }
        return subconjunt;
}