//
//  main.cpp
//  oving2
//
//  Created by Gjert Ingar Gjersund on 24.01.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include <iostream>
#include <cmath>

void inputAndPrintInteger() {
    /*
     Take whole number input and print
     */
    
    int i = 0;
    std::cout << "Vennligst skriv inn et heltall: " << std::endl;
    std::cin >> i;
    std::cout << "Du skrev inn: " << i << std::endl;
}

int inputInteger() {
    /*
     Take whole number input and return
     */
    
    int i = 0;
    std::cout << "Vennligst skriv inn et heltall: " << std::endl;
    std::cin >> i;
    return i;
}

double inputDouble() {
    /*
     Take double number input and return
     */
    double i = 0;
    std::cout << "Vennligst skriv inn et tall: " << std::endl;
    std::cin >> i;
    return i;
}

void inputIntegersAndPrintSum() {
    /*
     Output the sum of two given whole numbers
     Dependency: inputInteger()
     */
    
    int a = 0;
    int b = 0;
    std::cout << "Summering av heltall" << std::endl;
    a = inputInteger();
    b = inputInteger();
    
    std::cout << "Summen av heltallene er: " << a + b << std::endl;
}

bool isOdd(int i) {
    /*
     Get whole number and check if odd or even
     */
    bool isOdd = false;
    
    if ((i % 2) == 1) {
        isOdd = true;
    }
    
    return isOdd;
}

void printHumanReadableTime(int s) {
    /*
     Get seconds, convert to hours, minutes and seconds,
     and then output to screen
     */
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    
    hours = (s - (s % 3600)) / 3600;
    minutes = ((s % 3600) - ((s % 3600) % 60)) / 60;
    seconds = (s % 3600) % 60;
    
    std::cout << hours << "t " << minutes << "m " << seconds << "s" << std::endl;
}

void inputIntegersUsingLoopAndPrintSum() {
    /*
     Input any number of whole numbers to sum up.
     
     Oppgave 2b)
     Using infinite while statement and break out when 0 is selected.
     In my opinion its best to use while to allow "changing your mind"
     later in the summation.
     As of allocating correct amount of memory, deciding the size beforehand
     is beneficial.
     
     */
    int sum = 0;
    
    std::cout << "Summer heltall og skriv 0 når du vil avslutte" << std::endl;
    
    while (true) {
        int x = 0;
        std::cout << "Velg et heltall: " << std::endl;
        std::cin >> x;
        
        if (x > 0) {
            sum = sum + x;
        } else if (x == 0) {
            break;
        } else {
            std::cout << "Ugyldig heltall" << std::endl;
        }
    }
    
    std::cout << "Summen ble: " << sum << std::endl;
}

void convertNOKtoEURO() {
    /*
     Convert any amount NOK into EURO
     
     Oppgave 2e)
     Using inputDouble to allow "øre" in the conversion as well as to prevent
     collision between int and double when calculating the convertion.
     Return type is void because I only output to screen, and do not return a number.
     */
    double kurs = 9.64;
    double nok = 0;
    
    std::cout << "Velkommen til valutakonverteren, vennligst skriv inn hvor mange NOK du vil konvertere" << std::endl;
    
    while (true) {
        nok = inputDouble();
        
        if (nok >= 0) {
            break;
        } else {
            std::cout << "Tallet må være positivt" << std::endl;
        }
    }
    
    std::cout.precision(3);
    std::cout << nok << " NOK er det samme som " << (nok / kurs) << " EURO" << std::endl;
}

void writeMultiplicationTable() {
    int width = 0;
    int height = 0;
    
    std::cout << "Vennligst angi bredde i heltall: " << std::endl;
    std::cin >> width;
    
    std::cout << "Vennligst angi høyde i heltall: " << std::endl;
    std::cin >> height;
    
    std::cout << std::endl;
    for (int i = 1; i <= height; i++) {
        std::cout << "\t";
        for (int j = 1; j <= width; j++) {
            std::cout << i * j << "\t";
        }
        std::cout << "\n";
    }
}

double discriminant (double a, double b, double c) {
    return ((b*b) - (4 * a * c));
}

void printRealRoots (double a, double b, double c) {
    
    double disc = discriminant(a, b, c);
    
    if (disc > 0) {
        
        std::cout
            << "De to løsningene til ligningen er: "
            << ((-b + sqrt(disc)) / (2 * a))
            << " og "
            << ((-b - sqrt(disc)) / (2 * a))
        << std::endl;
        
    } else if (disc == 0) {
        
        std::cout
        << "Løsningen til ligningen er: "
        << (-b / (2 * a))
        << std::endl;
        
    } else {
        std::cout << "Ingen reelle løsninger" << std::endl;
    }
}

void solveQuadraticEquation () {
    
    std::cout << "Velkommen til annengradsløseren!" << std::endl;
    
    double a = 0, b = 0, c = 0;
    
    std::cout << "Vennligst skriv in din a: " << std::endl;
    std::cin >> a;
    std::cout << "Vennligst skriv in din b: " << std::endl;
    std::cin >> b;
    std::cout << "Vennligst skriv in din c: " << std::endl;
    std::cin >> c;
    
    printRealRoots(a, b, c);
}

void calculateLoanPayments () {
    std::cout << "Velkommen til avdragskalkulatoren!" << std::endl;
    
    double initialLoan = 0;
    double remainingLoan = 0;
    double interest = 0;
    
    std::cout << "Vennligst skriv størrelsen på lånet ditt:" << std::endl;
    std::cin >> initialLoan;
    
    std::cout << "Skriv inn renten på lånet:" << std::endl;
    std::cin >> interest;
    
    remainingLoan = initialLoan;
    std::cout.precision(2);
    
    std::cout << "År\t\tInnbetaling\t\tGjenstående lån" << std::endl;
    for (int i = 0; i < 10; i++) {
        double payment = (initialLoan / 10) + ((interest / 100) * remainingLoan);
        remainingLoan = remainingLoan - (initialLoan / 10);
        std::cout << std::fixed << (i + 1) << "\t\t" << payment << "\t\t\t" << remainingLoan << std::endl;
    }
}

int main() {
    /*
    // Oppgave 1a)
    inputAndPrintInteger();
    
    // Oppgave 1b)
    int number = inputInteger();
    std::cout << "Du skrev inn: " << number;
    
    // Oppgave 1c)
    inputIntegersAndPrintSum();
    
    // Oppgave 1e)
    for (int i = 10; i < 15; i++) {
        if (isOdd(i)) {
            std::cout << i << " er et oddetall." << std::endl;
        } else {
            std::cout << i << " er et partall." << std::endl;
        }
    }
     
    // Oppgave 1f)
    printHumanReadableTime(10000);
    // Oppgave 2a)
    inputIntegersUsingLoopAndPrintSum();
    
    // Oppgave 2c)
    double doubleNumber = inputDouble();
    std::cout << "Du skrev inn: " << doubleNumber;
    
    // Oppgave 2d)
    convertNOKtoEURO();
     
    // Oppgave 3a)
     
     */
    while (true) {
        int action = 0;
        std::cout << "\nVelg funksjon:\n"
            << "0) Avslutt\n"
            << "1) Summer to tall\n"
            << "2) Summer flere tall\n"
            << "3) Konverter NOK til EURO\n"
            << "4) Skriv ut gangetabell\n"
            << "5) Løs annengradsligning\n"
            << "6) Avdragskalkulator\n"
            << "Angi valg (0-6): "
            << std::endl;
        
        std::cin >> action;
        
        switch(action) {
            case 0:
                break;
            case 1:
                inputIntegersAndPrintSum();
                break;
            case 2:
                inputIntegersUsingLoopAndPrintSum();
                break;
            case 3:
                convertNOKtoEURO();
                break;
            case 4:
                writeMultiplicationTable();
                break;
            case 5:
                solveQuadraticEquation();
                break;
            case 6:
                calculateLoanPayments();
                break;
            default:
                std::cout << "Ugyldig menyvalg" << std::endl;
        }
        
        if (action == 0) {
            std::cout << "\nBye! Bye!" << std::endl;
            break;
        }
    }
}
