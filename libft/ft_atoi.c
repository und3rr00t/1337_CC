int atoi(const char *nptr)
{
	int i;
	int s;
	int o;

	i = 0;
	s = 1;
	o = 0;

	while ((nptr[i] == 32) || (nptr[i] >= 9 && nptr <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (nptr[i] =)
