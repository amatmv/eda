int GrafDispers::nVers(int v) const
{
	int res = 0;
	if (v <= 0 or v > nVers)
	{
		throw ("Fora de rang");
	}
	else
	{
		nodeAresta *act = Arestes[v];
		while (act != NULL)
		{
			res++;
			act = act->seg;
		}
		if (!dirigit)
		{
			for (int i = 0; i < nVers; ++i)
			{
				if (i != v)
				{
					act = Arestes[i];
					while (act != NULL and act->desti!=v)
					{
						act = act->seg;
					}
					if (act != NULL)
						res++;
				}
			}
		}
	}
	return res;
}