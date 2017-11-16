int ConjuntEnters::Minim() const
{
	if (arrel == NULL)
	{
		throw("Es buit");
	}
	node* ant = arrel;
	node* act = arrel->fe;
	while (act != NULL)
	{
		ant = act;
		act = act->fe;
	}
	return ant->codi;
}