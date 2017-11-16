EstructuraCircular::EstructuraCircular()
{
	actual = new node;
	actual->seguent = actual;
}

void EstructuraCircular::EliminarElement(int n)
{
	node *p = actual;
	node *ant = NULL;
	int i = 1;
	if(n == 1)
		if(mida > 1)
			actual = NULL;
		else
		{
			ant = actual;
			while(i <= mida)
				ant = ant->seguent;
		}
	else
		while(i < n)
		{
			ant = p;
			p = p->seguent;
			i++;
		}
	ant->seguent = p->seguent;
	actual = p->seguent;
	delete p;
}