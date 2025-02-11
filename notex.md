# FRACT-OL

## ¿Qué es un fractol?

Es una figura matemática que presenta una estructura similar a diferentes escalas. Esto significa que **si te acercas a una parte del fractal, podrías encontrar una forma similar a la original**, y esto se repite a medida que haces zoom. Los fractales son autosimilares, y tienen una dimensión fractal que no es necesariamente un número entero.

### Fractal de Julia

El conjunto de Julia se genera tomando un número complejo fijo (C), y aplicándolo una fórmula iterativa a cada punto complejo z en el plano complejo. La fórmula es:

    z_{n+1} = z_n^2 + c

- z_n es el valor de z en la n-ésima iteración.
- c es un número complejo fijo para toda la generación del conjunto.

Es decir:

    z_0 = 0
    z_1 = (z_0)^2 + c
    z_2 = (z_1)^2 + c
    z_3 = (z_2)^2 + c

El proceso comienza con un valor inicial z₀, que es un punto en el plano complejo, y luego se aplica la fórmula iterativamente. Si el valor absoluto de z sigue creciendo indefinidamente (es decir, si |z| se hace más grande que un cierto umbral), el punto z₀ se considera fuera del conjunto de Julia. Si z sigue dentro de un rango limitado, el punto z₀ se considera parte del conjunto.

### Fractal de Mandelbrot

El conjunto de Mandelbrot se define mediante la iteración de una función compleja, en la que se toma un número complejo (c) y se iteran las ecuaciones del tipo:

z\_{n+1} = z_n^2 + c

Utiliza la misma fórmula de Julia y empieza la iteracción de la misma manera(con valor 0). Básicamente comprueba si los puntos (c) pertenecen al conjunto (no se desbordan), pintándolos de un color distinto a los puntos que no pertenecen al conjunto (se desbordan). Estos últimos, suelen pintarse según la "rapidez" (interacción) con la que se desbordan.

### Diferencias

1. Fijación del parámetro:

   - Mandelbrot : C varía según se evalúan diferentes puntos en el plano complejo.
   - Julia : C es fijo y elegido al principio. Lo que varía es el punto Z_n sobre el plano complejo.

2. Estrategia de iteración

   - Mandelbrot : Se empieza con "z_0 = 0", y se evalúan disintos valores de "c". Se dice que "c" pertenece al conjunto si no "escapa" al infinito antes de un número determinado de iteraciones.
   - Julia : Con el valor fijo de "c", se evalúa si "Z_n" escapa del conjunto después d eun número de iteraciones.

3. Conjunto Conexo o Disconexo

   - Mandelbrot : Este conjunto es conexo, es decir que sus puntos forman una figura continua, sin fragmentos.
   - Julia : El conjunto puede ser ambos, dependerá del valor de "c".

4. Generación de fractales

   - Mandelbrot : Se representa visualmente como un conjunto de putnos que no escapan, generando un solo fractal para el conjunto.
   - Julia : El fractal cambiará según el valor de "c".

5. Patrón y simetría:

   - Mandelbrot : El conjunto tiene una forma central parecida a un corazón, con ramas que se extienden hacia afuera. Al hacer zoom en cualquier parte del contorno, verás patrones similares en diferentes escalas (autosimilitud).
   - Julia : La forma del fractal de Julia depende de "c"￼y puede ser mucho más variada. Algunos fractales de Julia tienen formas con simetría rotacional, mientras que otros pueden parecer más caóticos o como fragmentos dispersos.

6. Comportamiento ante el zoom:

   - Mandelbrot : A medida que haces zoom en el borde del conjunto los detalles se repiten de manera autosimilar, mostrando estructuras cada vez más complejas pero siempre del mismo patrón.
   - Julia : En el fractal de Julia, el comportamiento cambia dependiendo de "c". Algunas partes pueden mostrar patrones similares al hacer zoom, pero en general, no se mantiene la misma estructura de zoom que el conjunto de Mandelbrot.

7. Relación entre ambos fractales:

   - Mandelbrot : El conjunto de Mandelbrot se puede considerar una “semilla” para los fractales de Julia. Cada valor de ￼ dentro del conjunto de Mandelbrot genera un fractal de Julia específico. Si el valor de "c"￼ está fuera del conjunto de Mandelbrot, el fractal de Julia correspondiente será disconexo.
   - Julia : Los fractales de Julia pueden considerarse una serie de variaciones de Mandelbrot. Cada valor de "c" en el conjunto de Mandelbrot corresponde a un fractal de Julia.

8. Uso artístico y visual:
   - Mandelbrot : Su forma característica y la manera en que se repiten los patrones al hacer zoom lo hacen muy popular para exploración visual.
   - Julia : Los fractales de Julia también tienen un atractivo visual, pero su diversidad de formas según el valor de "c" permite una variedad aún mayor de diseños visuales.

Resumen:

| Característica             | Conjunto de **Mandelbrot**               | Conjunto de **Julia**                      |
| -------------------------- | ---------------------------------------- | ------------------------------------------ |
| **Valor de \( c \)**       | Varía para cada punto del plano complejo | Fijo para todo el conjunto                 |
| **Punto de inicio**        | \( z_0 = 0 \)                            | \( z_0 \) varía según el punto en el plano |
| **Conjunto**               | Siempre conexo                           | Puede ser conexo o disconexo               |
| **Generación**             | Representación de los valores de \( c \) | Depende del valor de \( c \)               |
| **Patrón y simetría**      | Forma característicamente conectada      | Diversidad de formas según \( c \)         |
| **Comportamiento al zoom** | Autosimilitud en el borde                | Varía dependiendo de \( c \)               |
