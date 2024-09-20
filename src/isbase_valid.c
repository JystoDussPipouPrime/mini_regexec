int	isbase_binary(int c)
{
	return (c == '0' || c == '1');
}

int	isbase_hex(int c)
{
	return ((c >= 'a' && c <= 'f') || (c >= '0' && c <= '9'));
}

int	isbase_oct(int c)
{
	return (c >= '0' && c <= '7');
}

int	isbase_digit(int c)
{
	return (c >= '0' && c <= '9');
}
