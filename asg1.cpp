#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int N;
    cout << "Nhap so phan tu cua mang: ";
    cin >> N;

    int* arr = new int[N];
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long sum = 0;

    // S? d?ng OpenMP ?? tính t?ng song song
#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }

    double average = static_cast<double>(sum) / N;
    cout << "Gia tri trung binh cua mang: " << average << endl;

    delete[] arr;
    return 0;
}
