void EDFDispersioIndirecte2::Afegir(const clau& c, const Element &e)
{
	node2 *act = dades[c.h() & maxDades];
	node2 *ant = NULL;
	bool trobat = false;
	while (act != NULL and !trobat)
	{
		if (c.esMenor(act->id))
		{
			ant = act;
			act = act->fe;
		}
		else if (act->id.esMenor(c))
		{
			ant = act;
			act = act->fd;
		}
		else
			trobat = true;
	}
	if (trobat)
	{
		act->valor = e;
	}
	else 
	{
		node2 *nou = new node2;
		nou->id = c;
		nou->valor = e;
		nou->fe = nou->fd = NULL;
		if (ant == NULL)
		{
			dades[c.h() % maxDades] = nou;
		}
		else if (c.esMenor(ant->id))
		{
			ant->fe = nou;
		}
		else
		{
			ant->fd = nou;
		}
		nDades++;
	}

}