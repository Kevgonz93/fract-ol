# 📢 Fract-ol - 42 Project

## 📜 Descripción

Fract-ol es un proyecto de la escuela 42 cuyo objetivo es generar y visualizar fractales matemáticos utilizando la biblioteca gráfica MiniLibX.
El propósito de este proyecto es profundizar en el uso de gráficos en C mediante la representación de fractales, específicamente **Mandelbrot** y **Julia**. Se requiere implementar la interacción con el usuario y optimizar el rendimiento de los cálculos.

---

## 📋 Requisitos

Para compilar y ejecutar este proyecto, necesitas:

- Un sistema UNIX (macOS o Linux)
- Make y un compilador compatible con C (gcc o clang)
- En macOS: Los frameworks OpenGL y AppKit (incluidos por defecto en el sistema)
- En Linux: Las bibliotecas X11 y Xext

---

## 🛠️ Cómo Compilar y Ejecutar

1. Clonar el repositorio

```bash
$ git clone https://github.com/Kevgonz93/fract-ol
$ cd fract-ol
```

2. Compilar el proyecto

```bash
$ make
```

3. Ejecutar el programa

```bash
$ ./fractol <nombre_del_fractal> [parámetros opcionales]
```

Ejemplo:

```bash
$ ./fractol mandelbrot
$ ./fractol julia -0.7 0.27015
```

---

## 🚀 Características

### Makefile

El Makefile de este proyecto está hecho para poder compilar tanto en MacOS y Linux, según corresponda.

### Parámetros

```bash
$ ./fractol
	usage: ./fractol [fractal]
		mandelbrot
		julia [c_real] [c_imaginary]
		tricorn

- Mandelbrot	: el fractal se generará con valores predeterminados.
- Julia			: el fractal se basará según los parámetros introducidos, que corresponden al valor de C.
- Tricorn		: el fractal se generará con valores predeterminados.
```

### Movimientos

- **Flechas**: Mover la vista
- **Rueda del mouse**: Zoom in / Zoom out
- **Teclas +/-**: Ajustar el zoom.
- **Teclas 0-9**: Cambio de colores (predeterminados).
- **Click izquierdo**: Cambia al siguiente color.
- **Espacio**: Reinicio a la imagen inicial.
- **Esc o 'X' de la ventana**: Salir del programa.

---

## 📂 Estructura del Proyectop

```

📦 fract-ol
├── 📂 aux 				# Funcines extraídas de libft.
├── 📂 minilibx		 	# miniLibX descomprimida y compilada.
├── 📂 printf		 	# Función ft_printf realizada previamente.
├── 📂 src 				# Funciones útiles para la la app (handles, hooks, dibujo de los fractales,...) y cabecera con las estructuras utilizadas.
├── fractol.c 			# Funcion main y función iniciadora de la estructura de datos.
├── fractol.h 			# Cabecera del programa.
├── Makefile 			# Makefile para compilar el proyecto.
├── minilibx-linux.tgz	# MiniLibx comprimida.
├── notex.md 			# Notas teóricas de los fractales a tratar.
├── README.md 			# Este documento.
└── subject.pdf 		# Subjeact del proyecto en español.

```

---

## 📝 Bonus

✅ Implementación de un fractal adicional: Tricorn

✅ Manejo de zoom con referencia a la posición del mouse

✅ Movimientos con flechas

✅ Rango de color variable

## 🧑‍💻 Autor

[Kevin Gonzales](https://github.com/Kevgonz93)
