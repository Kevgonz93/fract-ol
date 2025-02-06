# FRACT-OL

## ¿Qué es un fractol?

Es una figura matemática que presenta una estructura similar a diferentes escalas. Esto significa que **si te acercas a una parte del fractal, podrías encontrar una forma similar a la original**, y esto se repite a medida que haces zoom. Los fractales son autosimilares, y tienen una dimensión fractal que no es necesariamente un número entero.

### Fractorial de Julia

#### ¿Cómo funciona?

El conjunto de Julia se genera tomando un número complejo fijo (C), y aplicándolo una fórmula iterativa a cada punto complejo z en el plano complejo. La fórmula es:

    z_{n+1} = z_n^2 + c

-   z_n es el valor de z en la n-ésima iteración.
-   c es un número complejo fijo para toda la generación del conjunto.

Es decir: 

    z_1 = (z_0)^2 + c
    z_2 = (z_1)^2 + c
    z_3 = (z_2)^2 + c

El proceso comienza con un valor inicial z₀, que es un punto en el plano complejo, y luego se aplica la fórmula iterativamente. Si el valor absoluto de z sigue creciendo indefinidamente (es decir, si |z| se hace más grande que un cierto umbral), el punto z₀ se considera fuera del conjunto de Julia. Si z sigue dentro de un rango limitado, el punto z₀ se considera parte del conjunto.

#### Características

-	Autosimilitud: 

Significa que al hacer zoom en el fractal, puedes ver patrones similares a diferentes escalas.

-	Dinámica compleja: 

La dinámica de los fractales de Julia puede ser muy compleja, con comportamientos como “atractores”, que son regiones en el plano donde los puntos de z tienden a irse a medida que las iteraciones progresan.