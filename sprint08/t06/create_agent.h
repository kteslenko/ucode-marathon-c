#include "agent.h"

int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);
char *mx_strcpy(char *dst, const char *src);

t_agent *mx_create_agent(char *name, int power, int strength);
