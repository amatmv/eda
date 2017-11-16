EDFDispersioIndirecte::EDFDispersioIndirecte(const EDFDispersioIndirecte& e)
{
	nDades = e.nDades;
	maxDades = o.maxDades;
	dades = new node*[maxDades];
	for (int i = 0; i < maxDades; ++i)
	{
		node* p = o.dades[i];
		dades[i] = NULL;
		while (p != NULL)
		{
			node* q = new node;
			q->id = p->id;
			q->valor = p->valor;
			q->seg = dades[i];
			dades[i] = q;
			p = p->seg;
		}
	}
}