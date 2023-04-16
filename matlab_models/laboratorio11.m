% Laboratorio 11
% Variante 2
% Enunciado:
% Crear figuras que se obtienen sumando las vibraciones mutuamente 
% perpendiculares de frecuencias diferentes - Figuras de Lissajous

% formula de Lissajous:
% x = a1 * cos(w1*t + delta)
% y = a2 * cos(w2*t)

% definiendo constantes
w1 = 2; w2 = 3;     % frecuencias de señal
delta = pi;         % angulo de desfase
a1 = 1; a2 = 1;     % amplitudes [-1, 1]

% definiendo valores para t
t = 0:0.1:2*pi;

% definimos las funciones parametricas
x = a1*cos(w1*t + delta);
y = a2*cos(w2*t);

% grafica con valores calculados de la funcion
figure;
plot(x, y, "r");

hold on;
% generar el efecto de cometa
comet(x, y);

