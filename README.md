### int	mini_regexec(const char *text, const char *pattern)
#### RETURN VALUE
		NULL parameter: -1
		text matches the pattern : 1
		text don't matches the pattern : 1
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

#### USAGE
		if (mini_regexec(text, "^[0-1]^"))
			return (EXIT_SUCCESS);

/

/

/

/

/

/

/

/

/

### ./stable_ver
#### RETURN VALUE
		NULL parameter: -1
		text matches the pattern : 1
		text don't matches the pattern : 1
#### PATTERNS SUPPORTED
		[0-1]
		[0-9]
		[a-f]
		[a-f0-1]
		[0-9a-f] / [a-f0-9]
		0x[0-9] / 0X[0-9]
		0b[0-9] / 0B[0-9]
		0[0-9]

- [ ] dangerous if not [a-z] / [a-Z0-9] / [A-Z0-9a-Z] etc


![output](https://github.com/user-attachments/assets/21aca329-7ab1-49b0-8e41-531934633ec9)

| Base    | Range                | Prefix         | Example                |
|---------|----------------------|----------------|------------------------|
|      2  | `0, 1`               | `0b`/`0B`      | `0b1101 = 13`          |
|      8  | `0-7`                | `0`            | `052 = 42`             |
|      10 | `0-9`                |                | `123 = 123`            |
|      12 | `0-9 A,B`            |                | `A6 = 126`             |
|      16 | `0-9 A-F`            | `0x`/`0X`      | `0xFF = 255`           |
|      20 | `0-9 A-J`            |                | `1A = 30`              |
|      60 | `0-59`               | `:`            | `1:30 = 90`            |
