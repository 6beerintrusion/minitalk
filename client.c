#include "minitalk.h"

extern int g_total;

void	ft_send_null(int pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		kill(pid, SIGUSR1);
		bit--;
		while (!g_total)
			usleep(10);
		g_total = 0;
	}
}
void	ft_send(int	pid, int i)
{
	if (i == 1)
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("Mauvais PID");
			exit(1);
		}
	if ( i == 0)
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("Mauvais PID");
			exit(1);
		}
}
void	send_str(int pid, char *str)
{
	int		bit;
	int		i;

	i = 0;
	bit = 7;
	while (bit >= 0)
	{
		if (str[i] & (1 << bit))
			ft_send(pid, 1);
		else
			ft_send(pid, 0);
		bit--;
		if(bit < 0 && str[++i])
			bit = 7;
		while (!g_total)
			usleep(10);
		g_total = 0;
		if (bit < 0 && !str[i])
		{
			ft_send_null(pid);
			//printf("Message, recu !");
		}
	}
}

void	ft_error(void)
{
	ft_printf("bad arguments");
	exit(1);
}

int	ft_number(char c)
{
	if ((c >= '0' && c <= '9') || c == '\0')
		return (1);
	return (0);
}

void	ft_check(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = 1;
	while(i < argc)
	{
		if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 4194304)
		{
			ft_printf("Mauvais PID");
			exit(1);
		}
		if (!argv[i] || !*argv[i])
			ft_error();
		j = 0;
		while(argv[1][j])
		{
			if(!ft_number(argv[1][j]) || ft_atoi(argv[1]) < 0)
				ft_error();
			j++;
		}
		i++;
	}
}

void	handler(int signum, siginfo_t *client, void *null)
{
	(void)null;
	(void)client;
	if (signum == SIGUSR2)
		g_total = 1;
	else if (signum == SIGUSR1)
	{
		ft_printf("Message recu\n");
		exit(0);
	}
}


#ifdef COMPILE_CLIENT

int	main(int argc, char **argv)
{
	//
struct sigaction	s_sigaction;
	ft_memset(&s_sigaction, 0, sizeof(s_sigaction));
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = handler;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	if (argc == 3)
	{
		ft_check(argc,argv);
		send_str(ft_atoi(argv[1]), argv[2]);
	}
	return (0);
}
#endif
