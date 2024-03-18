# MALLOC
## Double Pointer malloc

```c
	char **ptr = (char **)malloc(10);

	for (int i = 0; i < 10; i++) {
		ptr[i] = (char *)malloc(20);
	}
```

It should take spaces perfectly and should seg forbidden accesses like ```ptr[2][25] = 'c';```
