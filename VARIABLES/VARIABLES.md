# VARIABLES
[Go Back to main page](../README.md)
### Format Specifiers 

syntax:
%[flags][width][.precision][length]specifier
### Specifier

| Specifier | Output                                     | Example      |
|-----------|--------------------------------------------|--------------|
| d or i    | Signed decimal integer                     | 392          |
| u         | Unsigned decimal integer                   | 7235         |
| o         | Unsigned octal                             | 610          |
| x         | Unsigned hexadecimal integer               | 7fa          |
| X         | Unsigned hexadecimal integer (uppercase)   | 7FA          |
| f         | Decimal floating point, lowercase          | 392.65       |
| F         | Decimal floating point, uppercase          | 392.65       |
| e         | Scientific notation (mantissa/exponent), lowercase | 3.9265e+2 |
| E         | Scientific notation (mantissa/exponent), uppercase | 3.9265E+2 |
| g         | Use the shortest representation: %e or %f  | 392.65       |
| G         | Use the shortest representation: %E or %F  | 392.65       |
| a         | Hexadecimal floating point, lowercase      | -0xc.90fep-2 |
| A         | Hexadecimal floating point, uppercase      | -0XC.90FEP-2 |
| c         | Character                                  | a            |
| s         | String of characters                       | sample       |
| p         | Pointer address                            | b8000000     |
| n         | Nothing printed. The corresponding argument must be a pointer to a signed int. The number of characters written so far is stored in the pointed location. |              |
| %         | A % followed by another % character will write a single % to the stream. | %            |

### Flag

| Flag      | Description                                               |
|-----------|-----------------------------------------------------------|
|  -        | 	Left-justify within the given field width; Right justification is the default (see width sub-specifier). |
|   +       | Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.|
|   (space) |If no sign is going to be written, a blank space is inserted before the value.|
|   #       |Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written.|
|   0      | 	Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).|

### Width

| Width     | Description                                               |
|-----------|-----------------------------------------------------------|
|  (number) |Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.|
|*          |The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.|

### .precision

| .precision| Description                                                                                   |
|-----------|-----------------------------------------------------------------------------------------------|
|  .number  |For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0.For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6).For g and G specifiers: This is the maximum number of significant digits to be printed.For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered.If the period is specified without an explicit value for precision, 0 is assumed.|
|.*         |The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.|

![alt text](image.png)


important! 
 - ‘%d’ and ‘%i’ behave similarly with printf() There is no difference between the %i and %d format specifiers when used with printf. but %d and %i behavior is different with scanf()
%d assume base 10 while %i auto detects the base.Therefore, both specifiers behave differently when they are used with an input function. So, the value of 012 would be 10 with %i but 12 with %d.
    - %d takes an integer value as a signed decimal integer i.e. it takes negative values along with positive values but values should be in decimal otherwise it will print garbage value.
(Note: If the input is in the octal format like 012 then %d will ignore 0 and take input as 12).
 
    - %i takes an integer value as an integer value with decimal, hexadecimal, or octal type.
To enter a value in hexadecimal format, the value should be provided by preceding “0x” and to enter a value in value in octal format, the value should be provided by preceding “0”.