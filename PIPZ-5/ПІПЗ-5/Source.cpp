#include <iostream>

using namespace System;

void RunTask1() {
    Console::WriteLine(L"--- ВИКОНАННЯ ЗАВДАННЯ 1 ---\n");

    int M;
    Console::Write(L"Введіть кількість водіїв: ");
    M = Int32::Parse(Console::ReadLine());

    double C;
    Console::Write(L"Введіть вартість перевезення однієї тонно-кілометра: ");
    C = Double::Parse(Console::ReadLine());

    array<int>^ driverIds = gcnew array<int>(M);
    array<double>^ weights = gcnew array<double>(M);
    array<double>^ distances = gcnew array<double>(M);

    for (int i = 0; i < M; i++) {
        Console::WriteLine(L"\n--- Введення даних ---");
        Console::WriteLine(L"Водій № {0}", i + 1);

        Console::Write(L"  Табельний номер: ");
        driverIds[i] = Int32::Parse(Console::ReadLine());

        Console::Write(L"  Вага вантажу (т): ");
        weights[i] = Double::Parse(Console::ReadLine());

        Console::Write(L"  Відстань (км): ");
        distances[i] = Double::Parse(Console::ReadLine());
    }

    Console::WriteLine(L"\n\n----------------------------------------");
    Console::WriteLine(L"       ВІДОМІСТЬ ВИПЛАТИ ЗАРПЛАТИ       ");
    Console::WriteLine(L"----------------------------------------");
    Console::WriteLine(L"Табельний №    | Заробітна платня");
    Console::WriteLine(L"----------------------------------------");

    for (int i = 0; i < M; i++) {
        double salary = weights[i] * distances[i] * C;
        Console::WriteLine(L"{0, -14} | {1, 10:F2} грн", driverIds[i], salary);
    }
    Console::WriteLine(L"----------------------------------------");

    Console::Write(L"\nНатисніть будь-яку клавішу, щоб повернутися в меню...");
    Console::ReadKey();
}

void RunTask2() {
    Console::WriteLine(L"--- ВИКОНАННЯ ЗАВДАННЯ 2 ---\n");
    int N;
    Console::Write(L"Введіть кількість рядків: ");
    N = Int32::Parse(Console::ReadLine());

    int M;
    Console::Write(L"Введіть кількість стовпців: ");
    M = Int32::Parse(Console::ReadLine());

	if (N <= 0 || M <= 0) {
		Console::WriteLine(L"\nПомилка: Кількість рядків і стовпців повинна бути додатною.");
		Console::Write(L"\nНатисніть будь-яку клавішу, щоб повернутися в меню...");
		Console::ReadKey();
		return;
	}

    array<double, 2>^ matrix = gcnew array<double, 2>(N, M);

    Console::WriteLine(L"\nОберіть спосіб заповнення матриці:");
    Console::WriteLine(L"1. Ввести елементи вручну");
    Console::WriteLine(L"2. Заповнити випадковими числами");

    int fillChoice = Int32::Parse(Console::ReadLine());

    if (fillChoice == 2) {
        Random^ rand = gcnew Random();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i, j] = rand->Next(-50, 51);
            }
        }
    }

    else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                Console::Write(L"Введіть елемент [{0}, {1}]: ", i + 1, j + 1);
                matrix[i, j] = Double::Parse(Console::ReadLine());
            }
        }
    }

    Console::WriteLine(L"\nВведена матриця:");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            Console::Write(L"{0, 10:F2} ", matrix[i, j]);
        }
        Console::WriteLine();
    }

    double maxElement = Math::Abs(matrix[0, 0]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Math::Abs(matrix[i, j]) > maxElement) {
                maxElement = Math::Abs(matrix[i, j]);
            }
        }
    }

    Console::WriteLine(L"\nНайбільший за модулем елемент: {0:F2}", maxElement);

    if (maxElement == 0) {
        Console::WriteLine(L"\nНеможливо поділити на нуль. Всі елементи матриці дорівнюють нулю.");
    }
    else {
        Console::WriteLine(L"\nМатриця після ділення на найбільший за модулем елемент:");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                double newVal = matrix[i, j] / maxElement;
                Console::Write(L"{0, 10:F2} ", newVal);
            }
            Console::WriteLine();
        }
    }

    Console::Write(L"\nНатисніть будь-яку клавішу, щоб повернутися в меню...");
    Console::ReadKey();
}

int main() {
    system("chcp 65001 > nul");

    int choose = 0;

    while (choose != 3) {

        Console::Clear();
        Console::WriteLine(L"========================================");
        Console::WriteLine(L"          ГОЛОВНЕ МЕНЮ ПРОГРАМИ         ");
        Console::WriteLine(L"========================================");
        Console::WriteLine(L"1. Виконати Завдання 1");
        Console::WriteLine(L"2. Виконати Завдання 2");
        Console::WriteLine(L"3. Вихід з програми");
        Console::WriteLine(L"========================================");
        Console::Write(L"Оберіть потрібний пункт (1-3): ");

        try {
            choose = Int32::Parse(Console::ReadLine());
        }
        catch (Exception^) {
            choose = 0;
        }

        Console::Clear();

        switch (choose) {
        case 1: {
            RunTask1();
            break;
        }

        case 2: 
			RunTask2();
            break;


        case 3:
            Console::WriteLine(L"Вихід з програми. До побачення!");
            break;

        default:
            Console::WriteLine(L"Невірний вибір. Будь ласка, оберіть пункт від 1 до 3.");
            Console::Write(L"\nНатисніть будь-яку клавішу, щоб продовжити...");
            Console::ReadKey();
            break;
        }
    }

    return 0;
}