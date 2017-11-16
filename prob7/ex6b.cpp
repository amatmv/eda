list<codi_assignatura> ex2017_2::propostaMatrcula(const dni& d const 
{
	map<dni, alumne>::const_terator itAl = alumnes.find(d);
	if (itAl == alumnes.end())
	{
		throw("");
	}
	else
	{
		map<codi_assignatura, assignatura>::const_iterator itAs = assignatures.begin();
		map<codi_assignatura, list<dni>>::const_iterator itMat = mat_assignatures.begin();
		while (itAs != mat_assignatures.end())
		{
			if (itAs->first != itMat->first)
			{
				Afegir
				itAs++;
			}
			else
			{
				list<dni>::const_iterator itDni = find(itMat->second->begin(), itMat->second.end(), d);
				if (itDni != itMat->second.end())
				{
					Afegir
				}
				itAs++;
				itMat++;
			}
		}
	}
}