//BAI 1: Chuyển đổi số tự nhiên từ hệ cơ số 10 sang hệ cơ số b bất kỳ (2 ≤ b ≤ 24).
#include <stdio.h>

void exercise1() {
    int number, base;
    char result[32];
    int index = 0;

    printf("Enter a number in base 10: ");
    scanf("%d", &number);
    printf("Enter the target base (2-24): ");
    scanf("%d", &base);

    if (base < 2 || base > 24) {
        printf("Invalid base!\n");
        return;
    }

    while (number > 0) {
        int remainder = number % base;
        result[index++] = (remainder < 10) ? '0' + remainder : 'A' + (remainder - 10);
        number /= base;
    }

    printf("Converted number: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    printf("\n");
}
//BAI 2: Tính tổng các chữ số của một số nguyên bất kỳ.
#include <stdio.h>

void exercise2() {
    int number, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }

    printf("Sum of digits: %d\n", sum);
}
// BAI 3: Phân tích một số nguyên thành các thừa số nguyên tố.
#include <stdio.h>

void exercise3() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Prime factorization: ");
    for (int i = 2; i <= number; ++i) {
        while (number % i == 0) {
            printf("%d ", i);
            number /= i;
        }
    }
    printf("\n");
}
// BAI 4: Liệt kê tất cả các số nguyên tố nhỏ hơn n.
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int number) {
    if (number < 2) return false;
    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0) return false;
    }
    return true;
}

void exercise4() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Primes less than %d: ", n);
    for (int i = 2; i < n; ++i) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
// BAI 5: Liệt kê tất cả các số thuận nghịch có 6 chữ số.
#include <stdio.h>

void exercise5() {
    printf("6-digit palindromes: ");
    for (int i = 100000; i <= 999999; ++i) {
        int reversed = 0, original = i;
        while (original > 0) {
            reversed = reversed * 10 + original % 10;
            original /= 10;
        }
        if (reversed == i) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
// BAI 6: Nhập dãy số thực và liệt kê các phần tử xuất hiện đúng một lần.
#include <stdio.h>

void exercise6() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float arr[n];
    int count[n];

    printf("Enter %d real numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count[i]++;
            }
        }
    }

    printf("Elements that appear exactly once: ");
    for (int i = 0; i < n; i++) {
        if (count[i] == 1) {
            printf("%.2f ", arr[i]);
        }
    }
    printf("\n");
}
// BAI 7: Nhập dãy số thực và liệt kê các phần tử xuất hiện đúng hai lần.
#include <stdio.h>

void exercise7() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float arr[n];
    int count[n];

    printf("Enter %d real numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count[i]++;
            }
        }
    }

    printf("Elements that appear exactly twice: ");
    for (int i = 0; i < n; i++) {
        if (count[i] == 2) {
            printf("%.2f ", arr[i]);
            count[i] = 0; // Avoid duplicate printing
        }
    }
    printf("\n");
}
// BAI 8: Đếm số lần xuất hiện của các phần tử trong một dãy số thực.
#include <stdio.h>

void exercise8() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float arr[n];
    int count[n];

    printf("Enter %d real numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        count[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        if (count[i] != -1) continue;

        int frequency = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                frequency++;
                count[j] = 0;
            }
        }
        count[i] = frequency;
    }

    printf("Frequency of elements:\n");
    for (int i = 0; i < n; i++) {
        if (count[i] > 0) {
            printf("%.2f: %d times\n", arr[i], count[i]);
        }
    }
}
// BAI 9: Nhập một chuỗi và đếm số từ trong chuỗi đó.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void exercise9() {
    char str[100];
    printf("Enter a string: ");
    getchar(); // Consume newline
    fgets(str, 100, stdin);

    int count = 0, inWord = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isspace(str[i])) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            count++;
        }
    }

    printf("The string contains %d word(s).\n", count);
}
// BAI 10: Liệt kê tất cả các số nguyên tố có 5 chữ số sao cho tổng các chữ số bằng S.
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number) {
    if (number < 2) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

int sumOfDigits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

void exercise10() {
    int S;
    printf("Enter the value of S: ");
    scanf("%d", &S);

    printf("5-digit primes with digit sum equal to %d:\n", S);
    for (int i = 10000; i <= 99999; i++) {
        if (isPrime(i) && sumOfDigits(i) == S) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
// BAI 11: Liệt kê các số Fibonacci nhỏ hơn n và là số nguyên tố.
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number) {
    if (number < 2) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

void exercise11() {
    int n;
    printf("Enter the limit n: ");
    scanf("%d", &n);

    int a = 0, b = 1;
    printf("Fibonacci primes less than %d:\n", n);

    while (a < n) {
        if (isPrime(a)) {
            printf("%d ", a);
        }
        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}
// BAI 12: Thực hiện các chức năng: tính tổng chữ số và phân tích số nguyên thành thừa số nguyên tố.
#include <stdio.h>

int sumOfDigits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

void primeFactorization(int number) {
    printf("Prime factorization: ");
    for (int i = 2; i <= number; i++) {
        while (number % i == 0) {
            printf("%d ", i);
            number /= i;
        }
    }
    printf("\n");
}

void exercise12() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Sum of digits: %d\n", sumOfDigits(n));
    primeFactorization(n);
}

// BAI 13: Thực hiện các chức năng: liệt kê ước số, đếm số ước, và liệt kê ước số là nguyên tố.
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number) {
    if (number < 2) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

void exercise13() {
    int n, count = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Divisors of %d: ", n);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nNumber of divisors: %d\n", count);

    printf("Prime divisors of %d: ", n);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0 && isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// BAI 14: Liệt kê n số nguyên tố đầu tiên và n số Fibonacci đầu tiên.
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number) {
    if (number < 2) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

void listPrimes(int n) {
    printf("First %d primes: ", n);
    for (int i = 2, count = 0; count < n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n");
}

void listFibonacci(int n) {
    printf("First %d Fibonacci numbers: ", n);
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

void exercise14() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    listPrimes(n);
    listFibonacci(n);
}

// BAI 15: Thực hiện các chức năng trên ma trận A.
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number) {
    if (number < 2) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

void exercise15() {
    int n, m;
    printf("Enter rows and columns (n m): ");
    scanf("%d %d", &n, &m);

    int A[n][m];
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Find max element
    int max = A[0][0], maxRow = 0, maxCol = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] > max) {
                max = A[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
    printf("Max element: %d at position (%d, %d)\n", max, maxRow, maxCol);

    // Replace non-prime elements with 0
    printf("Matrix with non-prime elements replaced by 0:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!isPrime(A[i][j])) {
                A[i][j] = 0;
            }
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    // Sort columns in ascending order
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n - 1; i++) {
            for (int k = i + 1; k < n; k++) {
                if (A[i][j] > A[k][j]) {
                    int temp = A[i][j];
                    A[i][j] = A[k][j];
                    A[k][j] = temp;
                }
            }
        }
    }
    printf("Matrix after sorting columns:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}
//BAI 16:  Thực hiện các chức năng trên mảng A.
#include <stdio.h>

void findTwoLargest(int arr[], int n) {
    int max1 = -1, max2 = -1, idx1 = -1, idx2 = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            idx2 = idx1;
            max1 = arr[i];
            idx1 = i;
        } else if (arr[i] > max2) {
            max2 = arr[i];
            idx2 = i;
        }
    }
    printf("Largest element: %d at index %d\n", max1, idx1);
    printf("Second largest element: %d at index %d\n", max2, idx2);
}

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void insertDescending(int arr[], int *n, int x) {
    int i;
    for (i = *n - 1; i >= 0 && arr[i] < x; i--) {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = x;
    (*n)++;
}

void exercise16() {
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int arr[100];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findTwoLargest(arr, n);

    printf("Array sorted in descending order: ");
    sortDescending(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int x;
    printf("Enter a number to insert: ");
    scanf("%d", &x);
    insertDescending(arr, &n, x);

    printf("Array after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//BAI 17: Chuẩn hóa chuỗi ký tự.
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void normalizeString(char str[]) {
    int len = strlen(str);
    int j = 0;

    // Remove extra spaces
    for (int i = 0; i < len; i++) {
        if (!(str[i] == ' ' && (j == 0 || str[j - 1] == ' '))) {
            str[j++] = str[i];
        }
    }
    if (j > 0 && str[j - 1] == ' ') j--; // Remove trailing space
    str[j] = '\0';

    // Capitalize first character of each word
    for (int i = 0; str[i]; i++) {
        if (i == 0 || str[i - 1] == ' ') {
            str[i] = toupper(str[i]);
        } else {
            str[i] = tolower(str[i]);
        }
    }
}

void exercise17() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    normalizeString(str);
    printf("Normalized string: \"%s\"\n", str);
}

//BAI 18:  Tìm từ dài nhất trong chuỗi.
#include <stdio.h>
#include <string.h>

void findLongestWord(char str[]) {
    char longest[100] = "";
    char word[100] = "";
    int maxLength = 0, startIdx = 0;

    for (int i = 0, j = 0; i <= strlen(str); i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            word[j++] = str[i];
        } else {
            word[j] = '\0';
            if (strlen(word) > maxLength) {
                maxLength = strlen(word);
                strcpy(longest, word);
                startIdx = i - maxLength;
            }
            j = 0;
        }
    }
    printf("Longest word: \"%s\"\n", longest);
    printf("Start position: %d\n", startIdx);
}

void exercise18() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    findLongestWord(str);
}

//BAI 19: Chuyển đổi chuỗi họ tên từ định dạng "họ đệm tên" sang "tên họ đệm".
#include <stdio.h>
#include <string.h>

void rearrangeName(char str[]) {
    char firstName[100] = "", remaining[100] = "";
    int i, j = 0;

    // Find the last space
    for (i = strlen(str) - 1; i >= 0 && str[i] != ' '; i--);

    if (i >= 0) {
        strncpy(firstName, &str[i + 1], strlen(str) - i);
        firstName[strlen(str) - i] = '\0';

        strncpy(remaining, str, i);
        remaining[i] = '\0';

        printf("Reformatted name: \"%s %s\"\n", firstName, remaining);
    } else {
        printf("Invalid input. Please enter a full name.\n");
    }
}

void exercise19() {
    char str[100];
    printf("Enter a full name: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    rearrangeName(str);
}

//BAI 20:Liệt kê tất cả các hoán vị của các số từ 1 đến n.
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int arr[], int l, int r) {
    if (l == r) {
        for (int i = 0; i <= r; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = l; i <= r; i++) {
            swap(&arr[l], &arr[i]);
            permute(arr, l + 1, r);
            swap(&arr[l], &arr[i]); // Backtrack
        }
    }
}

void exercise20() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    printf("Permutations of numbers from 1 to %d:\n", n);
    permute(arr, 0, n - 1);
}




