/**
3.2 Mittelwert und Varianz (21%)
Implementieren Sie ein Programm, welches Mittelwert und die Varianz der Elemente eines Integer-Arrays ausgibt. Der Benutzer soll zuerst mittels scanf eingeben wie viele Elemente das Array enthalten soll. Anschließend soll ebenfalls mit scanf jedes einzelne Array-Element eingelesen werden. Sobald alle Elemente eingelesen wurden, soll das Array an eine Funktion übergeben werden, welche den Mittelwert und die Varianz aller Elemente berechnet. Der Mittelwert und die Varianz sollen dabei von dieser Funktion mittels Call-by-Reference in Form von sog. Out-Arguments zurückgegeben werden. Im Hauptprogramm soll dann der Mittelwert und die Varianz ausgegeben werden (mit jeweils genau einer Nachkommastelle).

Ein Out-Argument ist ein Funktionsargument, dass anders als "normale" Funktionsargumente (die auch In-Argumente genannt werden) dazu dient, einen Wert von einer Funktion zurück zu bekommen. Ein einzelner Wert wird normalerweise in Form eines Rückgabewerts zurückgegeben. Aber bei mehreren Werten (in unseren Fall zwei: Den Mittelwert und die Varianz) geht das über den Rückgabewert nicht so einfach. Eine Möglichkeit ist die Verwendung von Out-Argumenten. Out-Argumente werden einer Funktion mittels Call-by-Reference übergeben und die Werte, die zurückgegeben werden sollen, werden diesen Argumenten zugewiesen. Hier ein Beispiel für eine Funktion mit einem Out-Argument:

// The function argument arg is an out-argument that is passed as a pointer (call-by-reference)
void foo(int* arg) {
   *arg = 42; // Store 42 into arg
}

int var1 = 0;

// We pass var1 to function foo()
// Since we use call-by-reference we actually need to pass a pointer to var1
foo(&var1);

printf("var1 = %d\n", var1); // Output is "var1 = 42"
Die Varianz  𝜎2
  berechnet sich über die Formel  𝜎2=∑𝑛𝑖=0(𝑥𝑖−𝑥̃ )2𝑛
 . Dabei ist  𝑛
  die Anzahl der Elemente,  𝑥̃
  der Mittelwert und  𝑥𝑖
  das Array-Element mit dem Index  𝑖
 .

Hier eine Beispielausgabe:

> Geben Sie die Anzahl der Elemente Ihres Arrays an:
3
> Element #1:
4
> Element #2:
2
> Element #3:
0
> Der Mittelwert Ihres Arrays ist: 2.0 > Der Varianz Ihres Arrays ist: 2.6666666

Wichtig für die Auswertung ist, dass zuerst die Arraygröße n eingelesen wird und dann genau n Elemente des Arrays. Halten Sie sich bitte exakt an diese Vorgehensweise!

*/

#include <stdio.h>

void calculate_stats(int* arr, int n, double* mean, double* variance) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    *mean = sum / n;

    double variance_sum = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = arr[i] - *mean;
        variance_sum += diff * diff;
    }
    *variance = variance_sum / n;
}

int main() {
    int n;
    printf("Geben Sie die Anzahl der Elemente Ihres Arrays an:\n");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Element #%d:\n", i + 1);
        scanf("%d", &arr[i]);
    }

    double mean, variance;
    calculate_stats(arr, n, &mean, &variance);

    printf("Der Mittelwert Ihres Arrays ist: %.1f\n", mean);
    printf("Der Varianz Ihres Arrays ist: %.1f\n", variance);

    return 0;
}
