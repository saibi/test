#include <stdio.h>

int main(void)
{
	int ret ;
	char buf[4];
	char test[128];

	ret = sprintf(test, "hello %s", "world");
	printf("ret = %d, [%s]\n", ret, test);

	ret = snprintf(buf, sizeof(buf), "hello %.2f world !!!", 18.18);

	printf("ret = %d\n", ret);
	printf("[1234567890]\n");
	printf("[%s]\n", buf);

	return 0;
}

