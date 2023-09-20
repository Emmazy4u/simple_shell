#include "shell.h"

/**
 * hsh_loop - command loop
 */
void hsh_loop(void)
{
	char *cmd_buff = NULL;
	int status = 0;
	char **line;

	while(!(0))
	{
		print_prompt("cisfun$ ");
		status = read_line(&cmd_buff);
		/*End-of-file condition*/
		if (status == -1)
		{
			free(cmd_buff);
			break;
		/*Ctrl+d was pressed*/
		}
		if (*cmd_buff == '\0')
			continue; /*No input condition*/
		line = parse_line(cmd_buff);
	  	cmd_exec(line);
	}
	_putchar('\n');
}

