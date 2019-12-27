/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:46:20 by szakaria          #+#    #+#             */
/*   Updated: 2019/12/18 16:47:52 by szakaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		signal_ctrl_z(void)
{
	struct termios	tr;
	char			sig[2];

	tcgetattr(2, &tr);
	tr.c_lflag |= (ECHO | ICANON);
	ft_putstr_fd(tgetstr("te", NULL), 2);
	ft_putstr_fd(tgetstr("ve", NULL), 2);
	sig[0] = tr.c_cc[VSUSP];
	sig[1] = '\0';
	signal(SIGTSTP, SIG_DFL);
	ioctl(2, TIOCSTI, sig);
	tcsetattr(2, 0, &tr);
}

void		signal_fg(void)
{
	struct termios	config;
	char			**av;

	ft_putstr_fd(tgetstr("ti", NULL), 2);
	ft_putstr_fd(tgetstr("vi", NULL), 2);
	av = argv_historique(NULL);
	if (tcgetattr(2, &config) < 0)
		ft_putstr_fd("error", 2);
	config.c_lflag &= ~(ECHO | ICANON);
	if (tcsetattr(2, 0, &config) < 0)
		ft_putstr_fd("error", 2);
	signal(SIGTSTP, lance_signal);
	affichage_win(mode_historique(NULL), key_historique(NULL),
			av, big_name(av));
}

void		lance_signal(int signal)
{
	if (signal == SIGTSTP)
		signal_ctrl_z();
	else if (signal == SIGCONT)
		signal_fg();
	else if (signal)
	{
		free(key_historique(NULL));
		free(mode_historique(NULL));
		ft_putstr_fd(tgetstr("te", NULL), 2);
		ft_putstr_fd(tgetstr("ve", NULL), 2);
		exit(0);
	}
}

void		check_signal2(void)
{
	signal(SIGURG, lance_signal);
	signal(SIGSTOP, lance_signal);
	signal(SIGTSTP, lance_signal);
	signal(SIGCONT, lance_signal);
	signal(SIGCHLD, lance_signal);
	signal(SIGTTIN, lance_signal);
	signal(SIGTTOU, lance_signal);
	signal(SIGIO, lance_signal);
	signal(SIGXCPU, lance_signal);
	signal(SIGXFSZ, lance_signal);
	signal(SIGVTALRM, lance_signal);
	signal(SIGPROF, lance_signal);
	signal(SIGWINCH, signal_size);
	signal(SIGINFO, lance_signal);
	signal(SIGUSR1, lance_signal);
	signal(SIGUSR2, lance_signal);
}

void		check_signal(void)
{
	signal(SIGHUP, lance_signal);
	signal(SIGINT, lance_signal);
	signal(SIGQUIT, lance_signal);
	signal(SIGILL, lance_signal);
	signal(SIGTRAP, lance_signal);
	signal(SIGABRT, lance_signal);
	signal(SIGEMT, lance_signal);
	signal(SIGFPE, lance_signal);
	signal(SIGKILL, lance_signal);
	signal(SIGBUS, lance_signal);
	signal(SIGSEGV, lance_signal);
	signal(SIGSYS, lance_signal);
	signal(SIGPIPE, lance_signal);
	signal(SIGALRM, lance_signal);
	signal(SIGTERM, lance_signal);
	check_signal2();
}
