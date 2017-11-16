struct node
{
	element dada;
	int ant, seg;
};

node *dades;
int maxDades, buits, actual;


void Llista2Taula::Inserir(const element &e)
{
	if (esPlena())
		throw("Elol");
	else
	{
		int ant = dades[act].ant;
		int nova = buits; //cim
		buits = dades[buids].seg; //desempila
		dades[nova].dada = e;
		dades[nova].seg = act;
		dades[nova].ant = ant;
		dades[ant].seg = nova;
		dades[act].ant = nova;
	}
}