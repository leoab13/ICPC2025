#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s; // Lectura de la cadena completa (puede contener espacios)

    int score = 0;

    // Función lambda auxiliar para contar ocurrencias de un patrón dado
    auto countOccurrences = [&](const string &pattern) {
        int count = 0;
        size_t pos = s.find(pattern);
        while (pos != string::npos) {
            count++;
            pos = s.find(pattern, pos + 1); // Continuar después de la coincidencia actual
        }
        return count;
    };

    // Cálculo de ocurrencias
    int countHa = countOccurrences("ha");
    int countBooooo = countOccurrences("booooo");
    int countBravo = countOccurrences("bravo");

    // Cálculo del puntaje total
    score += countHa * 1;
    score -= countBooooo * 1;
    score += countBravo * 3;

    cout << score << endl;
    return 0;
}