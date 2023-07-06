/**
* binary_to_uint - converts a binary number to an unsigned int
* @b: pointer to a string containing the binary number
* Return: the converted number, or 0 if b is NULL or contains characters
* that are not 0 or 1
*/
unsigned int binary_to_uint(const char *b)
{
unsigned int dec_num = 0;

if (!b)
return (0);

while (*b)
{
if (*b < '0' || *b > '1')
return (0);
dec_num = (dec_num << 1) | (*b - '0');
b++;
}

return (dec_num);
}
