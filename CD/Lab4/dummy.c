struct peace{
	int f;
	int j;
};
int sum(int a, int b)
{
	int s = a / b;
	return s;
}

bool search(int *arr, int key)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		if (arr[i] == key)
			return 1;
		else
			return 0;
	}
}

void main()
{
	int a[11], i, res;
	bool status;
	struct peace p;
	//printf("Size of struct peace: %d", sizeof(struct peace));
	printf("Enter array elements:");
	for (i = 0; i < 10; ++i)
		scanf("%d", &a[i]);
	res = sum(a[0], a[4]);
	status = search(a, res);
	printf("%d", status);
}
