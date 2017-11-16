void mostrarSucc(ArbreBinariEqPersones *a)
{
	ArbreBinariEqPersones *t = a;
	while (!t->esBuit())
	{
		if (t->Contingut().esHome())	
		{
			t->Contingut().EscriuNom();
			mostrarSucc(t->FillEsquerre());
		}
		t = t->FillDret();
	}
	t = a;
	while (!t->esBuit())
	{
		if (!t->Contingut().esHome())
		{
			t->Contingut().EscriuNom();
			mostrarSucc(t->FillEsquerre())
		}
		t = t->FillDret();
	}
}