void monticleEntrers::mostrarPreordre()
{
	iMostrarPreordre(1);
}

void monticleEntrers::iMostrarPreordre(int i)
{
	if (i <= nDades)
	{
		cout << dades[i];
		iMostrarPreordre(2*i);
		iMostrarPreordre(2*i+1);
	}
}