bool esEuleria(const GrafDispers &g)
{
	if (g.esDirigit())
	{
		throw("El graf es dirigit");
	}
	else 
	{
		int imparells = 0;
		int i = 1;
		while (i < g.nVertexs() and imparells <= 2)
		{
			if (g.nVeins(i) % 2 != 0)
			{
				imparells++;
			}
			i++;
		}
		return imparells == 0 or imparells == 2;
	}
}