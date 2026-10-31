#include "monty.h"
#include <string.h>

/**
 * name_of_file - extract the exact the name monty file
 * @path: the path to the monty file
 *
 * Return: the filename
 */
char *name_of_file(char *path)
{
	char *dir;
	char *filename = NULL;

	dir = strtok(path, "/");
	while (dir != NULL)
	{
		filename = dir;
		dir = strtok(NULL, "/");
	}
	return (filename);
}
