#include "shell.h"

/**
 * mainj - entry point
 * @acj: arg count
 * @avj: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int mainj(int acj, char **avj)
{
	info_t info[] = { INFO_INIT };
	int fdj = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fdj)
			: "r" (fdj));

	if (acj == 2)
	{
		fdj = open(avj[1], O_RDONLY);
		if (fdj == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(avj[0]);
				_eputs(": 0: Can't open ");
				_eputs(avj[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fdj;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, avj);
	return (EXIT_SUCCESS);
}

