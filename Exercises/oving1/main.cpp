//
// ØVING 1 - TDT4102
// Gjert Ingar Gjersund
//

#include <iostream>
using namespace std;
// Oppgave a)
double max(double a, double b) {
    if (a > b) {
        std::cout << "A is greater than B" << std::endl;
        return a;
    } else {
        std::cout << "B is greater than A" << std::endl;
        return b;
    }
}

// Oppgave c)
int fibonacci(int n) {
    int a = 0;
    int b = 1;
    
    std::cout << "Fibonacci numbers:" << std::endl;
    
    for (int x = 1; x < (n + 1); x++) {
        std::cout << x << ": " << b << std::endl;
        int temp = b;
        b += a;
        a = temp;
    }
    
    std::cout << "----" << std::endl;
    
    return b;
}

// Oppave d)
int squareNumberSum(int n) {

    int totalSum = 0;
    
    for (int i = 0; i < n; i++) {
        totalSum += (i * i);
        std::cout << (i * i) << std::endl;
    }
    
    std::cout << totalSum << std::endl;
    
    return totalSum;
}

// Oppgave e)
void triangleNumbersBelow(int n) {
    int acc = 1;
    int num = 2;
    
    std::cout << "Triangle numbers below " << n << ":" << std::endl;
    
    while (acc < n) {
        std::cout << acc << std::endl;
        acc += num++;
    }
    
    std::cout << std::endl;
}

bool isTriangleNumber(int number) {
    int acc = 1;
    while (number > 0) {
        number -= acc++;
    }
    
    return number == 0;
}

// Oppgave f)
bool isPrime(int n) {
    bool primeness = true;
    
    for (int j = 2; j < n; j++) {
        if ((n % j) == 0) {
            primeness = false;
            break;
        }
    }
    
    return primeness;
}

// Oppgave g)
void naivePrimeNumberSearch(int n) {
    for (int number = 2; number < n; number++) {
        if (isPrime(number)) {
            std::cout << number << " is a prime" << std::endl;
        }
    }
}

// Oppgave h)
int findGreatestDivisor(int n) {
    for (int divisor = (n - 1); divisor > 0; divisor--) {
        if ((n % divisor) == 0) {
            return divisor;
        }
    }
    
    return 1;
}


int main() {
    // Oppgave a)
    std::cout << "Oppgave a)" << std::endl;
    std::cout << max(5, 6) << std::endl;
    
    // Oppgave c)
    std::cout << "Oppgave c)" << std::endl;
    std::cout << fibonacci(10) << std::endl;
    
    // Oppgave d)
    std::cout << "Oppgave d)" << std::endl;
    std::cout << squareNumberSum(3) << std::endl;
    
    // Oppgave e)
    std::cout << "Oppgave e)" << std::endl;
    triangleNumbersBelow(20);
    std::cout << isTriangleNumber(2) << std::endl;
    std::cout << isTriangleNumber(6) << std::endl;
    
    // Oppgave f)
    std::cout << "Oppgave f)" << std::endl;
    std::cout << isPrime(3) << std::endl;
    
    // Oppgave g)
    std::cout << "Oppgave g)" << std::endl;
    naivePrimeNumberSearch(3);
    
    // Oppgave h)
    std::cout << "Oppgave h)" << std::endl;
    std::cout << findGreatestDivisor(11) << std::endl;
    
    // Return 0
    return 0;
}
