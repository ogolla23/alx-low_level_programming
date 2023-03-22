/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
    int _isalpha(int c);
    
    c = _isalpha('H');
    _putchar(c + '0');
    c = _isalpha('o');
    _putchar(c + '0');
    c = _isalpha(108);
    _putchar(c + '0');
    c = _isalpha(';');
    _putchar(c + '0');
    _putchar('\n');
    return (0);
}
