bool **matArestes;
bool dirigit;
int nVers; 
int nArs;


CuaEnter q;
vector<bool> visitats(nVers+1, false);
int nVisitats = 0;
while (nVisitats < nVers)
{
	if (q.buida())
	{
		int j = 1;
		while (visitats[j] == true /*and j<nVers*/)
			j++;
		cout << j;
		q.encuar(j);
		visitats[j] = true;
		nVisitats++;
	}
	else 
	{
		int j = q.primer();
		for (int i = 1; i <= nVers; ++i)
		{
			if (matArestes[j][i] and !visitats[i])
			{
				cout << i;
				q.encuar(i);
				visitats[i] = true;
				nVisitats++;
			}
		}
		q.desencuar();
	}
}
