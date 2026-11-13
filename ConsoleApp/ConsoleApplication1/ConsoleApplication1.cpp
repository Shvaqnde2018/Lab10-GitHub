#include "pch.h"

using namespace System;

void RunTask1()
{
    Console::WriteLine(L"--- Task 1");
    double L = 24, W = 19;

    Console::Write(L"Enter variant number: ");
    double C = Double::Parse(Console::ReadLine());

    double S = L * W;
    double cost = S * C;

    Console::WriteLine(L"Room size: {0:F2} m by {1:F2} m", L, W);
    Console::WriteLine(L"Room area: {0:F2} square meters", S);
    Console::WriteLine(L"Carpet covering price: {0:F2}$", cost);
}

void RunTask2()
{
    Console::WriteLine(L"\n--- Task 2");
    Console::Write(L"Enter first word: ");
    String^ firstWord = Console::ReadLine();

    Console::Write(L"Enter second word: ");
    String^ secondWord = Console::ReadLine();

    String^ phrase = firstWord + L" and " + secondWord;
    Console::WriteLine(L"Result: {0}", phrase);
}

void RunTask3()
{
    Console::WriteLine(L"\n--- Task 3");
    Console::Write(L"Enter first word: ");
    String^ firstWord = Console::ReadLine();

    Console::Write(L"Enter second word: ");
    String^ secondWord = Console::ReadLine();

    int result = String::Compare(firstWord, secondWord);

    if (result < 0) {
        Console::WriteLine(L"{0} is less than {1}", firstWord, secondWord);
    }
    else if (result > 0) {
        Console::WriteLine(L"{0} is greater than {1}", firstWord, secondWord);
    }
    else {
        Console::WriteLine(L"{0} is equal to {1}", firstWord, secondWord);
    }
}

void RunTask4()
{
    Console::WriteLine(L"\n--- Task 4");
    Console::Write(L"Enter phrase: ");
    String^ phrase = Console::ReadLine();

    String^ result = L"begin " + phrase + L" end";

    Console::WriteLine(L"Result string: {0}", result);
    Console::WriteLine(L"String length: {0}", result->Length);
}

void RunTask5()
{
    Console::WriteLine(L"\n--- Task 5");
    Console::Write(L"Enter string to reverse: ");
    String^ phrase = Console::ReadLine();

    String^ result = L"";
    for (int i = phrase->Length - 1; i >= 0; i--)
    {
        result += phrase[i];
    }

    Console::WriteLine(L"Reversed string: {0}", result);
}

void RunTask6()
{
    Console::WriteLine(L"\n--- Task 6");
    Console::Write(L"Enter first string: ");
    String^ name1 = Console::ReadLine();

    Console::Write(L"Enter second string: ");
    String^ name2 = Console::ReadLine();

    if (name1->Length > name2->Length)
    {
        Console::WriteLine(L"'{0}' is longer than '{1}'", name1, name2);
    }
    else if (name1->Length < name2->Length)
    {
        Console::WriteLine(L"'{0}' is shorter than '{1}'", name1, name2);
    }
    else
    {
        Console::WriteLine(L"'{0}' is equal in length to '{1}'", name1, name2);
    }
}

int main(array<System::String^>^ args)
{
    RunTask1();
    RunTask2();
    RunTask3();
    RunTask4();
    RunTask5();
    RunTask6();

    Console::WriteLine(L"\nAll tasks completed. Press Enter to exit.");
    Console::ReadLine();

    return 0;
}