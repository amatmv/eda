int ExprAlgebraica::calcular(int operacio, int e, int d)
{
	if (char(operacio) == '+')
		return e+d;
	else if(char(operacio) == '-')
		return e-d;
	else if(char(operacio) == '*')
		return e*d;
	else if(char(operacio) == '/')
		if (d == 0)
			throw("L'operand dret no pot ser 0!");
}

int ExprAlgebraica::Operar() const
{
	if (arrel != NULL)
		return iOperar(arrel);
	return 0;
	
}

int ExprAlgebraica::iOperar(node* n) const
{
	if (esFulla(n))
		return n->dada;
	else 
	{
		int op_esquerre = iOperar(n->fe);
		int op_dret = iOperar(n->fd);
		return calcular(n->dada, op_esquerre, op_dret);
	}

}