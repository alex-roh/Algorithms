#include <iostream>

void perm(int k);
void swap(int k, int i);
static char data[] = { 'a', 'b', 'c', 'd' };
static int n = 4;

int main(void)
{
	perm(0);
	return 0;
}

// k is a barrier index between a prefix string and set S
// e.g., 0, 1, 2, ..., (k - 1) | k | (k + 1), (k + 2), ..., (n - 1)
// if k == 0, there is no prefix string

// however, this code has an error: it doesn't print the entire permuation correctly.
void perm(int k)
{
	if (k == n)
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
		return;
	}

	for (int i = k; i < n; i++)
	{
		swap(i, k);
		perm(k + 1);
	}
}

void swap(int k, int i)
{
	int temp = data[k];
	data[k] = data[i];
	data[i] = temp;
}

