/* Exercise
 * Compute $\pi$ by numerical integration .
 * We use the fact that $\pi$ is the area of the unit circle,
 * and we approximate this by computing the area of a quarter circle using Riemann sums .
 *
 * Let $f(x)=\sqrt{1-x^2}$ be the function that describes the quarter circle for $x=0… 1$;
 * Then we compute \[ \pi/4\approx\sum_{i=0}^{N-1} \Delta x f(x_i) \qquad \hbox{where $x_i=i\Delta x$ and $\Delta x=1/N$} \]
 * Write a program for this, and parallelize it using OpenMP parallel for directives.
 *
 * 1. Put a parallel directive around your loop. Does it still compute the right result?
 * Does the time go down with the number of threads? (The answers should be no and no.)
 * 2. Change the parallel to parallel for (or \n{parallel do}). Now is the result correct?
 * Does execution speed up? (The answers should now be no and yes.)
 * 3. Put a critical directive in front of the update. (Yes and very much no.)
 * 4. Remove the critical and add a clause reduction (+:quarterpi) to the for directive.
 * Now it should be correct and efficient.
 */

//
// Created by elsey on 2021/9/25.
//

#include <valarray>
#include <iostream>

double f(double x){
    return sqrt(1 - pow(x, 2));
}

double integral(double(*f)(double x), double a, double b, int n)
{
    double step = (b - a)/n;   // width of rectangle
    double area = 0.0;
    double y = 0;  // height of rectangle

    for(int i = 0; i < n; ++i)
    {
        y = step * f((i + 0.5) * step);
        printf("area(%f) += y(%f) * step(%f)\n", area, y, step);
        area += y * step;
    }

    return area;
}

int main() {
    int x = 3;
    int low_end = 0;
    int high_end = 1;
    int steps = 100;
    std::cout << integral(f, low_end, high_end, steps);
    return 0;
}