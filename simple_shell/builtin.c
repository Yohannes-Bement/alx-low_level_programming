#include "shell.h"

/**
 * _johnjesus - exits the shell
 * @yohanes: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int _johnjesus(info_t *yohanes)
{
	int kak;

	if (yohanes->argv[1]) /* If there is an exit arguement */
	{
		kak = _erratoi(yohanes->argv[1]);
		if (kak == -1)
		{
			yohanes->status = 2;
			print_error(yohanes, "Illegal number: ");
			_eputs(yohanes->argv[1]);
			_eputchar('\n');
			return (1);
		}
		yohanes->err_num = _erratoi(yohanes->argv[1]);
		return (-2);
	}
	yohanes->err_num = -1;
	return (-2);
}

/**
 * _tom - changes the current directory of the process
 * @abint: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _tom(info_t *abint)
{
	char *sony, *dog, buf[1024];
	int chdir_rat;

	sony = getcwd(buf, 1024);
	if (!sony)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!abint->argv[1])
	{
		dog = _getenv(abint, "HOME=");
		if (!dog)
			chdir_rat = /* TODO: what should this be? */
				chdir((dog = _getenv(abint, "PWD=")) ? dog : "/");
		else
			chdir_rat = chdir(dog);
	}
	else if (_strcmp(abint->argv[1], "-") == 0)
	{
		if (!_getenv(abint, "OLDPWD="))
		{
			_puts(sony);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(abint, "OLDPWD=")), _putchar('\n');
		chdir_rat = /* TODO: what should this be? */
			chdir((dog = _getenv(abint, "OLDPWD=")) ? dog : "/");
	}
	else
		chdir_rat = chdir(abint->argv[1]);
	if (chdir_rat == -1)
	{
		print_error(abint, "can't cd to ");
		_eputs(abint->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(abint, "OLDPWD", _getenv(abint, "PWD="));
		_setenv(abint, "PWD", getcwd(buf, 1024));
	}
	return (0);
}

/**
 * _lord - changes the current directory of the process
 * @GOD: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _lord(info_t *GOD)
{
	char **JESUS_LORD;

	JESUS_LORD = GOD->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*JESUS_LORD); /* temp att_unused workaround */
	return (0);
}

