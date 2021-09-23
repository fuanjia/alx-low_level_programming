#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * string_nconcat - concatenate two strings up to n bytes.
 * @s1: source string
 * @s2: string to truncate up to n bytes
 * @n: number of bytes to truncate by
 * Return: pointer to new buffer
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *string = NULL;
	char *ptr = NULL;
	unsigned int len1, len2, len;

	if (s1 == NULL)
		s1 = "";
	if (!s2)
		s2 = "";
	for (len1 = 0; s1[len1]; len1++)
		;
	for (len2 = 0; s2[len2]; len2++)
		;
	if (len2 > n)
		len2 = n;
	len = len1 + len2 + 1;
	string = malloc(sizeof(*string) * len);
	ptr = string;
	if (string == NULL)
		return (NULL);
	while (*s1)
	{
		*string++ = *s1++;
	}
	while (n-- && *s2 != '\0')
	{
		*string++ = *s2++;
	}
	*string = '\0';
	return (ptr);
}
