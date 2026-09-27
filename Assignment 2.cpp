/*
  C++ Programming - Week 2 Assignment & Mini Project
  Topics: Functions (User Defined & Recursive), Arrays & Multi-Dimensional Arrays, String Handling
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// ==========================================
// 1. Create function to find factorial (Recursive)
// ==========================================
long long findFactorial(int n) {
    if (n <= 1) return 1;
    return n * findFactorial(n - 1);
}

void assignment1() {
    cout << "\n--- 1. Factorial using Function ---" << endl;
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;
    if (num < 0) {
        cout << "Factorial of a negative number doesn't exist." << endl;
    } else {
        cout << "Factorial of " << num << " = " << findFactorial(num) << endl;
    }
}

// ==========================================
// 2. Reverse array elements using function
// ==========================================
void reverseArray(int arr[], int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void assignment2() {
    cout << "\n--- 2. Reverse Array Elements ---" << endl;
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    reverseArray(arr, n);

    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// ==========================================
// 3. Count vowels in a string
// ==========================================
int countVowels(const string& str) {
    int count = 0;
    for (char ch : str) {
        char lowerCh = tolower(ch);
        if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
            count++;
        }
    }
    return count;
}

void assignment3() {
    cout << "\n--- 3. Count Vowels in String ---" << endl;
    cin.ignore(); // Clear input buffer
    string text;
    cout << "Enter a string: ";
    getline(cin, text);

    cout << "Total number of vowels: " << countVowels(text) << endl;
}

// ==========================================
// 4. Sort array using Bubble Sort
// ==========================================
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void assignment4() {
    cout << "\n--- 4. Bubble Sort ---" << endl;
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    bubbleSort(arr, n);

    cout << "Sorted Array (Ascending): ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// ==========================================
// Mini Project: Student Report Generator
// ==========================================
void studentReportGenerator() {
    cout << "\n=== MINI PROJECT: Student Report Generator ===" << endl;
    int numStudents, numSubjects;
    
    cout << "Enter number of students: ";
    cin >> numStudents;
    cout << "Enter number of subjects: ";
    cin >> numSubjects;

    string studentNames[numStudents];
    double marks[numStudents][100]; // 2D array representation
    double totalMarks[numStudents] = {0};
    double percentage[numStudents];

    for (int i = 0; i < numStudents; i++) {
        cout << "\nEnter name of Student " << i + 1 << ": ";
        cin >> studentNames[i];
        cout << "Enter marks for " << numSubjects << " subjects:\n";
        for (int j = 0; j < numSubjects; j++) {
            cout << "  Subject " << j + 1 << ": ";
            cin >> marks[i][j];
            totalMarks[i] += marks[i][j];
        }
        percentage[i] = totalMarks[i] / numSubjects;
    }

    cout << "\n---------------- STUDENT REPORT CARD ----------------\n";
    for (int i = 0; i < numStudents; i++) {
        cout << "Name: " << studentNames[i] << endl;
        cout << "Total Marks: " << totalMarks[i] << " / " << (numSubjects * 100) << endl;
        cout << "Percentage: " << percentage[i] << "%" << endl;
        
        cout << "Grade: ";
        if (percentage[i] >= 90) cout << "A+";
        else if (percentage[i] >= 75) cout << "A";
        else if (percentage[i] >= 60) cout << "B";
        else if (percentage[i] >= 40) cout << "C";
        else cout << "Fail";
        cout << "\n-----------------------------------------------------\n";
    }
}

int main() {
    cout << "C++ Week 2 Assignment & Mini Project Solutions\n";
    assignment1();
    assignment2();
    assignment3();
    assignment4();
    studentReportGenerator();

    return 0;
}
