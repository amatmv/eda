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
				afegirAs(lAs, nCred, *itAs);
				itAs++;
			}
			else
			{
				list<dni>::const_iterator itDni = find(itMat->second->begin(), itMat->second.end(), d);
				if (itDni != itMat->second.end())
				{
					afegirAs(lAs, nCred, *itAs);
				}
				itAs++;
				itMat++;
			}
		}
	}
}


void ex2017_2::afegirAs(list<codi_assignatura>& lAs, int & cred, const codi_assignatura &c) const
{
	list<codi_assignatura>::iterator itL = lAs.end();
	while (it != lAs.begin() and (itL-1)->second.obtenirQuadrimestre() > p.second.obtenirQuadrimestre())
		itL--;
	lAs.insert(itL, p);
	nCred += p.second.contCredits();
	while (nCred > 62)
	{
		nCred -= lAs.back().second.obtCredits();
		lAs.pop_back();
	}
}