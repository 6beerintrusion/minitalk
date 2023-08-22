#include "minitalk.h"

extern int g_total;

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	if (size == 0)
	{
		free (ptr);
		return (NULL);
	}
	new_ptr = ft_calloc(sizeof(char), size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, ft_strlen(ptr));
	free(ptr);
	return (new_ptr);
}

void	ft_build_msg(char c , siginfo_t *siginfo)
{
	static char *str = NULL;

	size_t size;

	size = ft_strlen(str);
	//if (!str)
	//	str = ft_calloc(sizeof(char), 1);
	str = ft_realloc(str, size + 2);
	if (c == '\0')
	{
		ft_printf("[%s]\n", str);
		kill(siginfo->si_pid, SIGUSR1);
		free(str);
		str = NULL;
		return ;
	}
	str[size] = c;
	size++;
	str[size] = '\0';
}

void	bit_to_char(int signal, siginfo_t *siginfo, void *null)
{
	static int		i = 7;
	static int		result = 0;
	static int		tab_bit[8] = {1,2,4,8,16,32,64,128};
	
	if (i < 0)
		i = 7;
	(void)null;
	if (signal == SIGUSR2)
	{
		g_total = 1;
		result = result + tab_bit[i];
		i--;
	}
	if (signal == SIGUSR1)
	{	i--;
		g_total = 1;
	}
	if (i < 0 && result == 0)
	{
		ft_build_msg('\0', siginfo);
	}
	else if (i < 0)
	{
		ft_build_msg((char)result, siginfo);
		result = 0;
	}
	kill(siginfo->si_pid, SIGUSR2);
}
#ifdef COMPILE_SERVER
int main() {

struct sigaction	s_sigaction;

	ft_printf("%d\n",getpid());
	s_sigaction.sa_sigaction = bit_to_char;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
#endif

