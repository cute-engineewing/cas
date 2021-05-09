#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
process_file(FILE *in_fp, const char *dest)
{
	FILE *out_fp;

	(void)in_fp;
	(void)dest;
	out_fp = fopen(dest, "wb");
	if (!out_fp)
	{
		perror("cas");
		return (-1);
	}

	fclose(out_fp);
	return (0);
}

int
main(int argc, char *argv[])
{
	int idx;
	FILE *fp;
	char *dest_name;

	if (argc < 2)
	{
		return process_file(stdin, "out.o");
	}
	else
	{
		for (idx = 1; idx < argc; idx++)
		{
			fp = fopen(argv[idx], "r");
			if (!fp)
			{
				perror("cas");
				return (EXIT_FAILURE);
			}
			dest_name = (char *)malloc(sizeof(char) * (strlen(argv[idx] + 2)));
			strcat(dest_name, ".o");
			if (process_file(fp, dest_name) != 0)
			{
				fclose(fp);
				return (EXIT_FAILURE);
			}
			fclose(fp);
		}
	}

	return (EXIT_SUCCESS);
}
