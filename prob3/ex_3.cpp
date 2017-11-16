ArbreBinari::ArbreBinari(const char *s)
{
	i = 0;
	arrel = ArbreBinari::iArbreBinari(s, i)
}

ArbreBinari::node * ArbreBinari::iArbreBinari(const char *s, int &i)
{
	char c = s[i];
	node *aux1, *aux2, *res;
	i++;
	if (s[i] != '(')
		res = new node();
	else
	{
		i++; //'('
		aux1 = iArbreBinari(s, i);
		if (s[i] == ' ')		
		{
			i++; //' '
			aux2 = iArbreBinari(s, i);
			i++;
		} else
		{
			aux2 = NULL;
			i++;
		}
		res = new node(c, aux1, aux2); 
	}
	return res;
}