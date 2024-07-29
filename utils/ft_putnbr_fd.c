void	ft_putnbr_fd(int n, int fd)
{
	int		a;
	char	b;
	int		c;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n == -2147483648)
		ft_putstr_fd("2147483648", fd);
	else if (n >= 10)
	{
		c = n;
		a = c % 10;
		ft_putnbr_fd(c / 10, fd);
		b = a + '0';
		ft_putchar_fd(b, fd);
	}
	if (n < 10 && n >= 0)
	{
		b = n + '0';
		ft_putchar_fd(b, fd);
	}
}