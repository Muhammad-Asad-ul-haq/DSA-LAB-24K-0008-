#include <iostream>
using namespace std;

int main() {
    int arr[] = {2022, 2023, 2024, 2022, 2023, 2024};
    int n = 6, i;
    int count_2022 = 0, count_2023 = 0, count_2024 = 0;

    for(i = 0; i < n; i++) {
        if(arr[i] == 2022) count_2022++;
        else if(arr[i] == 2023) count_2023++;
        else if(arr[i] == 2024) count_2024++;
    }

    i = 0;
    while(count_2022--) arr[i++] = 2022;
    while(count_2023--) arr[i++] = 2023;
    while(count_2024--) arr[i++] = 2024;

    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
