/**
 * _strcmp - compares two strings, ending at the first byte that is different.
 * @s1: string to be compared
 * @s2: string to compare by
 * main - check the code
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++)
		;
	return (s1[i] - s2[i]);
}
