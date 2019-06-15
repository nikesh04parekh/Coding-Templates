int n;
int lps[200005];
string str;

void KMP()
{
	int len = 0;
	int c = 0;
	int i = 1;
	while(i < n)
	{
		while (i < n && str[i] == str[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		if (len != 0)
			len = lps[len - 1];
		else
		{
			lps[i] = 0;
			i++;
		}
	}
}