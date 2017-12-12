void Solucionador::Solucionar(const solucio& sol)
{
	actual = sol;
	TrobarTotes();
}

void Solucionador::TrobarTotes()
{
	Candidats iCan = actual.inicialitzarCandidats();
	while(!iCan.esFi())
	{
		if (actual.Acceptable(iCan))
		{
			actual.AnotarCandidat(iCan);
			if (!actual.esCompleta())
			{
				TrobarTotes();
			}
			else
			{
				actual.mostrar();
			}
			actual.Desanotar();
		}
		iCan.Seguent():
	}
}



solucio::solucio(const vector<int>& A, const int& n, const int& S)
{
	_S = S;
	_A = A;
	_nivell = 0;
	_n = n;
	_solucio = vector<int>(n);
}

bool solucio::esCompleta()
{
	return _suma == _S;
}

bool solucio::Acceptable(const Candidats& iCan)
{
	int actual = iCan.Actual();
	return _suma + _A[actual] <= _S;
}

void solucio::AnotarCandidat(const Candidats& iCan)
{
	_suma += _A[iCan.Actual()];
	_solucio[_nivell] = iCan.Actual();
	_nivell++;
}

void solucio::DesanotarCandidat(const Candidats& iCan)
{
	_nivell--;
	_solucio[_nivell] = 0;
	_suma -= _A[iCan.Actual()];
}

