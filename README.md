# int	mini_regex(const char *text, const char *pattern)

**NAME**  
          *mini_regex* - look alike regex functions

**SYNOPSIS**  
       #include "mini_regex.h"  
       int mini_regex(const char *text, const char *pattern)

**DESCRIPTION**  
       *mini_regex()* is used to match a null-terminated string against a null-terminated pattern.

**RETURN VALUE**  
       *mini_regex()* returns zero for a successful match or 0 for failure.

**CAVEATS**  
       can be very dangerous if pattern is poorly written.  
       Segfault if parameters is NULL.  

**EXAMPLES**  

       #include <stdio.h>
       #include "mini_regex.h"

       int main(void)
       {
              size_t       t;
              size_t       p;
              const char *pattern[] = 
              {
                     "[^^^][0-9]\0",
                     "[0-9]\0",
                     NULL
              };
              const char *text[] =
              {
                     "   1234\0",
                     "1232222\0",
                     NULL
              };
              p = 0;
              while (pattern[p])
              {
                     t = 0;
                            printf("%s\n", pattern[p]);
                     while (text[t])
                     {
                            if (mini_regex(text[t], pattern[p]))
                                   printf("OK:\t%s\n", text[t]);
                            else
                                   printf("NOK:\t%s\n", text[t]);
                            t++;
                     }
                     p++;
              }
              return (0);
       }

## SPECIFIC PATTERNS SUPPORTED

| Desc.                 | Pattern | Example      |
|-----------------------|---------|--------------|
| Binary                | `[0-1]` | `1101`       |
| Octal                 | `[0-7]` | `052`        |
| Decimal               | `[0-9]` | `123`        |
| Lowercase             | `[a-z]` | `test`       |
| Uppercase             | `[A-Z]` | `TEST`       |
| Alpha                 | `[a-Z]` | `Test`       |
| Alpha & Num           | `[a0Z]` | `T3st`       |
| Filename              | `[./t]` | `./T3st.txt` |
| MAP_border            | `[^1^]` | ` 111 `      |
| MAP_inside            | `[0N1]` | `100E001`    |
| whitespace            | `[^^^]` | `      `     |
| Optional whitespace   | `^`     | ` `          |

| Example                      | Pattern                       |
|------------------------------|-------------------------------|
| `  NO  ./xpm/north.xpm`      | `^NO[^^^][./t]`               |
| `  F 101,  21,  97    `      | `"^F^[0-9]^,^[0-9]^,^[0-9]^"` |
| `  us3r.n4mE@d0m41n.com    ` | `"[a0Z].[a0Z]@[a0Z].[a-z]"`   |

**TODO**  
- [ ] NULL PARAMETERS PROTECTION  
- [x] pattern with differents length :shipit:  
- [ ] make a step-by-step implementation  
- [ ] explain how to implement extra patterns  
