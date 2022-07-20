/*

Assignment name  : ulstr
Expected files   : ulstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.

If the number of arguments is not 1, the program displays '\n'.

Examples :

$>./ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e
l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.$
$>./ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e
s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  $
$>./ulstr "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$
$>./ulstr | cat -e
$

*/
#include <unistd.h>

int	main(int ac, char *argv[])
{
	int	index;

	index = 0;

	if (ac == 2)
	{
		while (argv[1][index])
		{
			if ((argv[1][index] >= 'a' && argv[1][index] <= 'z'))
			{
				argv[1][index] -= 32;
				write (1, &argv[1][index++], 1);
			}
			else if ((argv[1][index] >= 'A' && argv[1][index] <= 'Z'))
			{
				argv[1][index] += 32;
				write (1, &argv[1][index++], 1);
			}
			else write (1, &argv[1][index++], 1);
		}
	}
	write (1, "\n", 1);
}
