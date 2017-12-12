bool SolucioPintar::Acceptable(const iteratorPintar& iCan)
{
	int color = iCan.actual();
	int paisAct = niv+1, i = 1;
	bool esAdj = false;
	while(i < paisAct and not esAdj)
	{
		if (matAdj[pasiAct][i] and colors[i] == color)
		{
			esAdj = true;
		}
		i++;
	}
	return not esAdj;
}

void SolucioPintar::Anotar(const iteradorPintar& iCan)
{
	niv++;
	colors[niv] = iCan.actual();
	if (colors[niv] > nColors)
	{
		nColors++;
	}
} 

void SolucioPintar::Desanotar(const iteradorPintar& iCan)
{
	if (nColors > iCan.maxim())
	{
		nColors--;
	}
	colors[niv] = 0;
	niv--;
}