#include "main.h"

/**
 * just_flags - Calculates active flags based on the given format string.
 *
 * @format: The formatted string in which to search for flags.
 * @index: The current index in the format string.
 *
 * Return: The calculated flags.
 */
int just_flags(const char *format, int *index)
{
	int currentIndex;
	int calculatedFlags = 0;
	const char FLAG_CHARACTERS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO,
		F_HASH, F_SPACE, 0};

	for (currentIndex = *index + 1; format[currentIndex] != '\0';
			currentIndex++)
	{
	char currentChar = format[currentIndex];
	int flagIndex = 0;

	while (FLAG_CHARACTERS[flagIndex] != '\0')
	{
		if (currentChar == FLAG_CHARACTERS[flagIndex])
		{
		calculatedFlags |= FLAG_ARRAY[flagIndex];
		break;
		}
		flagIndex++;
	}

	if (FLAG_CHARACTERS[flagIndex] == '\0')
	{
		break;
	}
	}

	*index = currentIndex - 1;

	return (calculatedFlags);
}
