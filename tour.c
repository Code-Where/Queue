#include <stdio.h>

int printTour(int arr[][2], int n)
{
	int start = 0;
	int end = 1;

	int curr_petrol = arr[start][0] - arr[start][1];

	while (end != start || curr_petrol < 0)
	{
		while (curr_petrol < 0 && start != end)
		{
			curr_petrol -= arr[start][0] - arr[start][1];
			start = (start + 1)%n;

			if (start == 0)
			return -1;
		}

		curr_petrol += arr[end][0] - arr[end][1];

		end = (end + 1)%n;
	}

	return start;
}

int main()
{
	int arr[3][2] = {{5, 4}, {2, 4}, {5, 3}};

	int start = printTour(arr, 3);

	if(start == -1){
        printf("No solution");
    } 
    else{
        printf("Start = %d", start);
    }    

	return 0;
}
