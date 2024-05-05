#include "simple_shell.h"
/**
 * _getenv - gets the path
 * @path_name: a pointer to the struct of data
 *
 * Return: (Success) a positive number
 * ------- (Fail) a negative number
 */
char *_getenv(char *path_name)
{
	char **environ_cursor, *env_ptr, *name_ptr;

	environ_cursor = environ;
	while (*environ_cursor)
	{
		env_ptr = *environ_cursor;
		name_ptr = path_name;
		while (*env_ptr == *name_ptr)
		{
			if (*env_ptr == '=')
				break;
			env_ptr++;
			name_ptr++;
		}
		if ((*env_ptr == '=') && (*name_ptr == '\0'))
			return (env_ptr + 1);
		environ_cursor++;
	}
	return (NULL);
}
/**
 * signal_handler - handle the process interrept signal
 * @signo: the signal identifier
 *
 * Return: void
 */
void signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		PRINT("\n");
		PRINT(PROMPT);
	}
}
/**
 * fill_an_array - fill an array with elements
 * @a: the given array
 * @el: the given element
 * @len: the length of the array
 *
 * Return: pointer to filled array
 */
void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}

/**
 * array_rev - reverse array
 * @arr: the given array
 * @len: the array length
 *
 * Return: void
 */
void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}
/**
 * index_cmd - indexed command
 * @data: a pointer to the data structure
 *
 * Return: void
 */
void index_cmd(sh_t *data)
{
	data->index += 1;
}

/**
 * _itoa - convert integer to array
 * @n: the given number
 *
 * Return: a pointer to the null terminated string
 */
char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';
	return (s);
}
/**
 * _atoi - converts character to integer
 * @c: the given character
 *
 * Return: An integer
 */
int _atoi(char *c)
{
	unsigned int val = 0;
	int sign = 1;

	if (c == NULL)
		return (0);
	while (*c)
	{
		if (*c == '-')
			sign *= (-1);
		else
			val = (val * 10) + (*c - '0');
		c++;
	}
	return (sign * val);
}

/**
 * intlen - Determine the number of digit int integer
 * @num: the given number
 *
 * Return: the length of the integer
 */
int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}
/**
 * print_error - prints error
 * @data: the data structure pointer
 *
 * Return: (Success) a positive number
 * ------- (Fail) a negative number
 */
int print_error(sh_t *data)
{
	char *idx = _itoa(data->index);

	PRINT("hsh: ");
	PRINT(idx);
	PRINT(": ");
	PRINT(data->args[0]);
	PRINT(": ");
	PRINT(data->error_msg);
	free(idx);
	return (0);
}

/**
 * write_history - prints error
 * @data: the data structure pointer
 *
 * Return: (Success) a positive number
 * ------- (Fail) a negative number
 */
int write_history(sh_t *data __attribute__((unused)))
{
	char *filename = "history";
	char *line_of_history = "this is a line of history";
	ssize_t fd, w;
	int len;

	if (!filename)
		return (-1);
	fd = open(filename, O_RDWR | O_APPEND);
	if (fd < 0)
		return (-1);
	if (line_of_history)
	{
		while (line_of_history[len])
			len++;
		w = write(fd, line_of_history, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}

